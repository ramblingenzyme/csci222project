#ifndef COMMENT_CONTROLLER_H
#define COMMENT_CONTROLLER_H
#include "return_types.h"
#include "const.h" 
#include "database_connection.h"
#include <string>
#include <list>

class comment_controller {
private: 
    comment *data;
public:
    comment_controller() { this->data = NULL; }
        
    ~comment_controller() { 
        if (!this->isEmpty())
            delete data;
    }

    bool find_comment_id(std::string comment_id);

    //is empty
    bool isEmpty() { 
        if (this->data == NULL) 
            return true;
        return false;
    }

    //returns the comment
    comment get_comment() { return *data; };
        
    //sets the stored comment to a given comment struct
    void set_comment(comment a) {
        if (this->data != NULL) 
            delete data; 
        data = new comment;
        *data = a; 
    }

    bool update_comment();
};

///////////////////////////////////////
// Definition of comment_controller //
///////////////////////////////////////

//finds comment based on comment_id, if found is stored as data member
bool comment_controller::find_comment_id(std::string comment_id) {
    DatabaseConnection database;
    try {
        database.open_connection(CONNECTION_DETAILS);
    
        std::string sqlquery = "select * from COMMENT where comment_id="+ comment_id+";"; 
        pqxx::result results = database.query(sqlquery.c_str());
        pqxx::result::const_iterator c = results.begin();
        
        database.close_connection();
        
        if (c == results.end())
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

//Attempts to update a comment (I don't it'll ever need to be updated), if fails, then inserts 
bool comment_controller::update_comment(){
    if (this->isEmpty())
        return false;
            
    DatabaseConnection database;
    database.open_connection(CONNECTION_DETAILS);
    std::string sqlquery = "UPDATE comment set comment_id ="
        + this->data->comment_id + ", username='"
        + this->data->username + "',bug_id ="
        + this->data->bug_id + ", creation_ts ='"
        + this->data->creation_ts + "', body = '"
        + this->data->body + "', attach_id="
        + this->data->attach_id + " where comment_id ="
        + this->data->comment_id + " AND bug_id = "
        + this->data->bug_id + ";";

    if (database.transaction(sqlquery))
        return true;
            
    sqlquery = "insert into comment (comment_id, username,"
        "bug_id, creation_ts, body, attach_id) values ("
        + this->data->comment_id + ",'"
        + this->data->username + "',"
        + this->data->bug_id + ",'"
        + this->data->creation_ts + "','"
        + this->data->body + "','"
        + this->data->attach_id + ");";
        
    database.transaction(sqlquery);
    database.close_connection();
    return true;
}


     

#endif
