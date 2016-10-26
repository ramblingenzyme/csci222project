#ifndef USER_CONTROLLER_H
#define USER_CONTROLLER_H
#include "return_types.h"
#include "const.h" 
#include "database_connection.h"
#include <string>
#include <list>

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
    std::string generate_find_username_query(std::string username);

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
    std::string generate_update_user_query();
    std::string generate_insert_user_query();
};

///////////////////////////////////
// Definition of user_controller //
///////////////////////////////////

//finds a user in the database according to a username, and if found it stores as a data member
bool user_controller::find_username(std::string username) {
    DatabaseConnection database;
    database.open_connection(CONNECTION_DETAILS);
    
    std::string sqlquery = generate_find_username_query(username);
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

std::string user_controller::generate_find_username_query(std::string username) {
    return "SELECT * FROM USERS WHERE username='"+ username+"';"; 
}

//Attempts to UPDATE user, if the statement fails, it means it doesn't pre-exist in the database, so it inserts. 
bool user_controller::update_user(){
    if (this->isEmpty())
        return false;
            
    DatabaseConnection database;
    database.open_connection(CONNECTION_DETAILS);
    std::string sqlquery = generate_update_user_query();
    
    if (database.transaction(sqlquery))
        return true;
            
    sqlquery = generate_insert_user_query();
        
    database.transaction(sqlquery);
    database.close_connection();
    return true;
}

std::string user_controller::generate_update_user_query() {
    std::string query;
    query = "UPDATE users set username ='"
        + this->data->username + "', password ='"
        + this->data->password + "', email ='"
        + this->data->email + "', privilege_level"
        + this->data->privilege_level + " where username ='"
        + this->data->username + "';";

    return query;
}

std::string user_controller::generate_insert_user_query() {
    std::string query;
    query = "insert into users (username, password,"
        "email, privilege_level) values ('"
        + this->data->username + "','"
        + this->data->password + "','"
        + this->data->email + "',"
        + this->data->privilege_level + ");";

    return query;
}

#endif 
