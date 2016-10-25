#include "database_connection.h"
#include <fstream>
#include <iostream>
#include <string>
#include "const.h"

class Database_Utility {
 
public:
	Database_Utility() {};
	~Database_Utility() {};

	bool create_database();
	bool drop_database();
	bool database_empty();
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
	std::string sqlQuery ="Select * from pg_tables where tablename ='USERS';";
	pqxx::result r = database.query(sqlQuery);
	sqlQuery = "Select * from pg_tables where tablename ='TOPDEVELOPERS';";
	pqxx::result s = database.query(sqlQuery);
	pqxx::result q; //empty result
	database.close_connection();

	if (q == r && q == s) return true;
	return false;
}
