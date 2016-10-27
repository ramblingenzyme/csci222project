#ifndef COMMENT_CONTROLLER_H
#define COMMENT_CONTROLLER_H
#include "return_types.h"
#include "const.h" 
#include "database_connection.h"
#include <string>
#include <list>
#include "time_utility.h"
class comment_controller {
private: 
    comment *data;
public:
    comment_controller() { this->data = NULL; }
        
    ~comment_controller() { 
        if (!this->isEmpty())
            delete data;
    }

    inline bool find_comment_id(std::string comment_id);
    inline std::string generate_find_comment_id_query(std::string comment_id);

    //is empty
    inline bool isEmpty() { 
        if (this->data == NULL) 
            return true;
        return false;
    }

    //returns the comment
    inline comment get_comment() { return *data; };
        
    //sets the stored comment to a given comment struct
    inline void set_comment(comment a) {
        if (this->data != NULL) 
            delete data; 
        data = new comment;
        *data = a; 
    }

    inline void new_comment(const comment& partial);

    inline bool update_comment();
    inline std::string generate_update_comment_query();
    inline std::string generate_insert_comment_query();
};

///////////////////////////////////////
// Definition of comment_controller //
///////////////////////////////////////

//finds comment based on comment_id, if found is stored as data member
bool comment_controller::find_comment_id(std::string comment_id) {
    DatabaseConnection database;
    try {
        database.open_connection(CONNECTION_DETAILS);
    
        std::string sqlquery = generate_find_comment_id_query(comment_id); 
        pqxx::result results = database.query(sqlquery.c_str());
        pqxx::result::const_iterator c = results.begin();
        
        database.close_connection();
        
	pqxx::result empty;
        if (results == empty)
            return false;
        
        if (this->isEmpty())
            delete this->data;
        this->data = new comment;
        
        this->data->comment_id = c[0].as<std::string>();
        this->data->username = c[1].as<std::string>();
        this->data->bug_id = c[2].as<std::string>();
        this->data->creation_ts = c[3].as<std::string>();
        this->data->body = c[4].as<std::string>();
        this->data->attach_id = c[5].as<std::string>();

        return true; 
    } catch (...) {
        return false;
    }
}

std::string comment_controller::generate_find_comment_id_query(std::string comment_id) {
    return "select * from COMMENT where comment_id=" + comment_id + ";"; 
}

//Attempts to update a comment (I don't it'll ever need to be updated), if fails, then inserts 
bool comment_controller::update_comment(){
    if (this->isEmpty())
        return false;
            
    DatabaseConnection database;
    database.open_connection(CONNECTION_DETAILS);
    std::string sqlquery = generate_insert_comment_query();

    if (database.transaction(sqlquery))
        return true;
            
    sqlquery = generate_update_comment_query();
    database.transaction(sqlquery);
    database.close_connection();
    return true;
}

std::string comment_controller::generate_update_comment_query() {
    std::string query;
    query = "UPDATE comment set comment_id="
        + this->data->comment_id + ", username='"
        + this->data->username + "', bug_id="
        + this->data->bug_id + ", creation_ts='"
        + this->data->creation_ts + "', body='"
        + this->data->body + "', attach_id="
        + this->data->attach_id + " where comment_id="
        + this->data->comment_id + " AND bug_id="
        + this->data->bug_id + ";";

    return query;
}

std::string comment_controller::generate_insert_comment_query() {
    std::string query;
    query =  "insert into comment (comment_id, username,"
        "bug_id, creation_ts, body, attach_id) values ("
        + this->data->comment_id + ",'"
        + this->data->username + "',"
        + this->data->bug_id + ",'"
        + this->data->creation_ts + "','"
        + this->data->body + "',"
        + this->data->attach_id + ");";

    return query;
}

void comment_controller::new_comment(const comment& partial){
	this->set_comment(partial);

	DatabaseConnection database;
	database.open_connection(CONNECTION_DETAILS);

	std::string sqlQuery = "Select comment_id FROM COMMENTS ORDER BY comment_id ASC;";
	pqxx::result r = database.query(sqlQuery);
	database.close_connection();
	pqxx::result::const_iterator c = r.end();
	c--;

	std::string id_string = c[0].as<std::string>();
	double id = atof(id_string.c_str());
	id++;

	this->data->comment_id = std::to_string(id);

	timeUt t;
        this->data->creation_ts = t.get_current_time();
}

#endif

