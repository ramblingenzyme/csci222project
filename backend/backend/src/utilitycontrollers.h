#include "database_connection.h"
#include <fstream>
#include <iostream>
#include <string>
#include "const.h"

class Database_Utility {
public:
	std::string sqlQuery; 
private:
	database_utility() {};
	~database_utility() {};

	bool create_database();
	bool drop_database();
	bool database_empty();
}

bool Database_Utility::create_database() {
	DatabaseConnection database;
	database.open_connection(CONNECTION_DETAILS);

	if (!database_empty()){
		return false;
	}

	if (database.transaction(CREATE_DATABASE))
		return true;
	else
		return false;
}
bool Database_Utility::drop_database(){
	DatabaseConnection database;
	database.open_connection(CONNECTION_DETAILS);

	if(database.transaction(DROP_TABLES)
		return true;
	else
		return false;
}
bool database_empty(){
	DatabaseConnection database;
	database.open_connection(CONNECTION_DETAILS);
	
	std::string sqlQuery ="Select * from pg_tables where tablename ='USERS';";
	pqxx::result r = database.query(sqlQuery);

	if (pqxx::result q == r)
		return true;
	
	sqlQuery = "Select * from pg_tables where tablename ='TOPDEVELOPERS';";
	r = database.query(sqlQuery);
	if (pqxx:result q == r)
		return true;

	return false;
}
