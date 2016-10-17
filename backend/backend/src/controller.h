#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "return_types.h"
#include "database_connection.h"
#include <string>
#include <list>

//Bug_controller class

const std::string CONNECTION_DETAILS="dbname=bugtracker user=postgres password=csci222password host=csci222-ass2.cy0af74vuu5h.ap-southeast-2.rds.amazonaws.com";
class Bug_Controller {
private:
    complete_bug_info *data;    //struct pointer; 
public:
    Bug_Controller(){
        data = NULL;
    }

    ~Bug_Controller(){
        if (!this->isEmpty())
            delete data;
    }

    bool find_bug_id(std::string bugID);
    bug_overview get_bug_overview();
    void set_bug_info(complete_bug_info a);
    bool update_bug();

    //return the all info on the bug
    complete_bug_info get_bug_info(){ return *data;};
        
    // is it empty tho?
    bool isEmpty() { return data == NULL;};
};

class user_controller {
private: 
    user *data;
public:
    user_controller() { this->data = NULL;};
        
    ~user_controller() {
        if (!this->isEmpty())
            delete data;
    }

    bool find_username(std::string username);

    //Checks if empty
    bool isEmpty() { 
        if (this->data == NULL) 
            return true;
        return false;
    }

    //Checks a given password against the stored password of a user
    bool authenticate(std::string password) {
        if (this->data->password == password) 
            return true;
        return false; 
    }
    //returns the users info
    user get_user_info() { return *data; };
        
    //sets the *data member to a given user struct
    void set_user_info(user a) {
        if (this->data != NULL) 
            delete data; 
        data = new user;
        *data = a; 
    }

    bool update_user();
};

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
//halfway done
#endif

//////////////////////////////////
// Definition of Bug_Controller //
//////////////////////////////////

//find_bug_id(string bugID) searches the database for a bug via bug_id, and it finds it, stores the bug as a data member
bool Bug_Controller::find_bug_id(std::string bugID) {
    DatabaseConnection database;
    try {

        database.open_connection(CONNECTION_DETAILS);
    
        std::string sqlQuery = "SELECT * FROM BUGS WHERE BUG_ID="+ bugID +";"; 
        pqxx::result results = database.query(sqlQuery.c_str());
        pqxx::result::const_iterator c = results.begin();
            
        //if the select statement didn't find anything, return false
        if (c == results.end()){
            database.close_connection();
            return false; 
        }
            
        //refreshing *data
        if (this->isEmpty())
            delete this->data;
        this->data = new complete_bug_info;
            
        //storing the bug and additional data (cclist, dependencies, keywords) 
        this->data->bug_id = c[0].as<std::string>();
        this->data->creation_time = c[1].as<std::string>();
        this->data->delta_time = c[2].as<std::string>();
        this->data->description = c[3].as<std::string>(); 
        this->data->product = c[4].as<std::string>();
        this->data->component = c[5].as<std::string>(); 
        this->data->version = c[6].as<std::string>(); 
        this->data->operating_system = c[7].as<std::string>(); 
        this->data->target_milestone = c[8].as<std::string>(); 
        this->data->status = c[9].as<std::string>(); 
        this->data->duplicate_id = c[10].as<std::string>();
        this->data->priority = c[11].as<std::string>(); 
        this->data->severity = c[12].as<std::string>();
        this->data->reporter = c[13].as<std::string>(); 
        this->data->assigned_to = c[14].as<std::string>(); 
        this->data->project_id = c[15].as<std::string>();
        this->data->votes = c[16].as<std::string>(); 
    
        sqlQuery = "SELECT * FROM CCLIST WHERE BUG_ID="+ bugID +";"; 
        results = database.query(sqlQuery.c_str());
        c = results.begin();
    
        while (c != results.end()){
            this->data->cclist.push_back(c[1].as<std::string>());
            c++;
        }
            
        sqlQuery = "SELECT * FROM KEYWORDS WHERE BUG_ID="+ bugID +";"; 
        results = database.query(sqlQuery.c_str());
        c = results.begin();

        while (c != results.end()){
            this->data->keywords.push_back(c[1].as<std::string>());
            c++;
        }

        sqlQuery = "SELECT * FROM DEPENDENCIES WHERE BUG_ID="+ bugID +";"; 
        results = database.query(sqlQuery.c_str());
        c = results.begin();

        while (c != results.end()){
            this->data->dependencies.push_back(c[1].as<std::string>());
            c++;
        }

        return true; 
    } catch (...) {
        return false;
    }   
}

//return a summarised version of the info on the bug
bug_overview Bug_Controller::get_bug_overview() {
    bug_overview bug; 

    bug.bug_id = this->data->bug_id;
    bug.title = this->data->title;
    bug.product = this->data->product;
    bug.component = this->data->component;
    bug.version = this->data->version;
    bug.priority = this->data->priority;
    bug.severity = this->data->severity;
    bug.status = this->data->status; 
    
    return bug; 
}

//takes a struct of bug info, and stores it as a data member
void Bug_Controller::set_bug_info(complete_bug_info a) {
    if (!this->isEmpty())
        delete data;
    data = new complete_bug_info;
    *data = a; 
}

//attempts to UPDATE the bug database entry, if it fails, it means it doesn't prexist in the database, so is inserted.
bool Bug_Controller::update_bug(){
    if (this->isEmpty())
        return false;
            
    DatabaseConnection database;
    database.open_connection(CONNECTION_DETAILS);

    //update bug
    std::string sqlquery = "UPDATE bugs set bug_id ="
        + this->data->bug_id + ", creation_ts ='"
        + this->data->creation_time + "', delta_ts = '"
        + this->data->delta_time + "', title = '"
        + this->data->title + "', short_desc = '"
        + this->data->description + "', component = '"
        + this->data->component + "', version = '"
        + this->data->version + "' , op_sys ='"
        + this->data->operating_system + "', bug_status ='"
        + this->data->status + "', dupl_id ='"
        + this->data->duplicate_id + ", bug_file_loc ='"
        + "NULL" + "', priority ="
        + this->data->priority + ", severity ="
        + this->data->severity + ", reporter ="
        + this->data->reporter + ", assigned_to ="
        + this->data->assigned_to + ", project_id ="
        + this->data->project_id + ", votes ="
        + this->data->votes + " where bug_id = "
        + this->data->bug_id + ";";

    //if update fails, then start inserting else, update the rest
    if (database.transaction(sqlquery)){
        sqlquery = "delete from cclist where bug_id="
            + this->data->bug_id + ";";
        database.transaction(sqlquery); 
            
        sqlquery = "delete from dependencies where bug_id="
            + this->data->bug_id + ";";
        database.transaction(sqlquery);

        sqlquery = "delete from keywords where bug_id="
            + this->data->bug_id + ";";
        database.transaction(sqlquery);


        //inserting cclist
        for (std::list<std::string>::iterator i= this->data->cclist.begin(); i != this->data->cclist.end(); i++) {
            sqlquery = "insert into cclist(bug_id, username"
                ") values ("
                + this->data->bug_id + ",'"
                + *i + "');";
        
            database.transaction(sqlquery);
        }
                    
        //inserting dependencies
        for (std::list<std::string>::iterator i= this->data->dependencies.begin(); i != this->data->dependencies.end(); i++) {
            sqlquery = "insert into cclist(bug_id, dependency"
                ") values ("
                + this->data->bug_id + ","
                + *i + ");";
        
            database.transaction(sqlquery);
        }

        //inserting keywords
        for (std::list<std::string>::iterator i= this->data->keywords.begin(); i != this->data->keywords.end(); i++) {
            sqlquery = "insert into keywords(bug_id, word"
                ") values ("
                + this->data->bug_id + ",'"
                + *i + "');";
        
            database.transaction(sqlquery);
        }
                
        return true;
    }

    //inserting bug
    sqlquery = "insert into bugs (bug_id, creation_ts,"
        "delta_ts, title, short_desc, component,"
        "version, op_sys, bug_status, dupl_id,"
        "bug_file_loc, priority, severity, reporter,"
        "assigned_to, project_id, votes) values ("
        + this->data->bug_id + ",'"
        + this->data->creation_time + "','"
        + this->data->delta_time + "','"
        + this->data->title + "','"
        + this->data->description + "','"
        + this->data->component + "','"
        + this->data->version + "','"
        + this->data->operating_system + "',"
        + this->data->status + ","
        + this->data->duplicate_id + ","
        + "NULL" + ","
        + this->data->priority + ","
        + this->data->reporter + ","
        + this->data->severity + ","
        + this->data->assigned_to + ","
        + this->data->project_id + ","
        + this->data->votes + ");";
        
    database.transaction(sqlquery);

    //inserting cclist
    for (std::list<std::string>::iterator i= this->data->cclist.begin(); i != this->data->cclist.end(); i++) {
        sqlquery = "insert into cclist(bug_id, username"
            ") values ("
            + this->data->bug_id + ",'"
            + *i + "');";
        
        database.transaction(sqlquery);
    }
        
    //inserting dependencies
    for (std::list<std::string>::iterator i= this->data->dependencies.begin(); i != this->data->dependencies.end(); i++) {
        sqlquery = "insert into cclist(bug_id, dependency"
            ") values ("
            + this->data->bug_id + ","
            + *i + ");";
        
        database.transaction(sqlquery);
    }

    //inserting keywords
    for (std::list<std::string>::iterator i= this->data->keywords.begin(); i != this->data->keywords.end(); i++) {
        sqlquery = "insert into keywords(bug_id, word"
            ") values ("
            + this->data->bug_id + ",'"
            + *i + "');";
        
        database.transaction(sqlquery);
    }
            
    //after a hard days work, closing the connection
    database.close_connection();
            
    return true;
}

///////////////////////////////////
// Definition of user_controller //
///////////////////////////////////

//finds a user in the database according to a username, and if found it stores as a data member
bool user_controller::find_username(std::string username) {
    DatabaseConnection database;
    database.open_connection(CONNECTION_DETAILS);
    
    std::string sqlquery = "SELECT * FROM USERS WHERE username='"+ username+"';"; 
    pqxx::result results = database.query(sqlquery.c_str());
    pqxx::result::const_iterator c = results.begin();
        
    database.close_connection();
        
    if (c == results.end())
        return false;
        
    if (this->isEmpty())
        delete this->data;
    this->data = new user;
        
    this->data->username = c[0].as<std::string>();
    this->data->password = c[1].as<std::string>();
    this->data->email = c[2].as<std::string>();
    this->data->privilege_level = c[3].as<std::string>(); 
            
    return true; 
}

//Attempts to UPDATE user, if the statement fails, it means it doesn't pre-exist in the database, so it inserts. 
bool user_controller::update_user(){
    if (this->isEmpty())
        return false;
            
    DatabaseConnection database;
    database.open_connection(CONNECTION_DETAILS);
    std::string sqlquery = "UPDATE users set username ='"
        + this->data->username + "', password ='"
        + this->data->password + "', email ='"
        + this->data->email + "', privilege_level"
        + this->data->privilege_level + " where username ='"
        + this->data->username + "';"; 
    
    if (database.transaction(sqlquery))
        return true;
            
    sqlquery = "insert into users (username, password,"
        "email, privilege_level) values ('"
        + this->data->username + "','"
        + this->data->password + "','"
        + this->data->email + "',"
        + this->data->privilege_level + ");"; 
        
    database.transaction(sqlquery);
    database.close_connection();
    return true;
}

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
        + this->data->creation_ts + "',"
        + this->data->body + "','"
        + this->data->attach_id + ");";
        
    database.transaction(sqlquery);
    database.close_connection();
    return true;
}


        

