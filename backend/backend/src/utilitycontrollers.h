#include "database_connection.h"
#include <fstream>
#include <iostream>
#include <string>
#include "const.h"
#include "project_controller.h"

class Database_Utility {
 
public:
    Database_Utility() {};
    ~Database_Utility() {};

    bool create_database();
    bool drop_database();

    bool database_empty();
    std::string generate_users_query();
    std::string generate_topdevelopers_query();
};

bool Database_Utility::create_database() {
    DatabaseConnection database;
    database.open_connection(CONNECTION_DETAILS);

    if (!database_empty()){
        database.close_connection();    
        return false;
    }
    bool flag = database.transaction(CREATE_DATABASE);
    database.close_connection();

 

 
    return flag? true : false;
}
bool Database_Utility::drop_database(){
    DatabaseConnection database;
    database.open_connection(CONNECTION_DETAILS);

    bool flag = database.transaction(DROP_TABLES);
    database.close_connection();

    

    return flag? true : false;
}
bool Database_Utility::database_empty(){
    DatabaseConnection database;
    database.open_connection(CONNECTION_DETAILS);

    //Checks if first table declared and last table declared are in the database
    std::string sqlQuery = generate_users_query();
    pqxx::result r = database.query(sqlQuery);

    sqlQuery = generate_topdevelopers_query();
    pqxx::result s = database.query(sqlQuery);

    pqxx::result q; //empty result
    database.close_connection();

    if (q == r && q == s) return true;
    return false;
}

std::string Database_Utility::generate_users_query() {
    return "Select * from pg_tables where tablename ='USERS';";
}

std::string Database_Utility::generate_topdevelopers_query() {
    return "Select * from pg_tables where tablename ='TOPDEVELOPERS';";
}


