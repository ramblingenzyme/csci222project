#ifndef SEARCH_CONTROLLER_H
#define SEARCH_CONTROLLER_H
#include "return_types.h" 
#include "database_connection.h"
#include "const.h"
#include "bug_controller.h"
#include "user_controller.h"
#include <string>
#include <list>
#include <exception>

class Search_Controller {
	private: 
	public: 
		Search_Controller() {};
		~Search_Controller() {};
		std::list<bug_overview> bug_search(const std::string&, int);
		std::list<user> user_search(const std::string&, int);

		std::list<bug_overview> project_search(const std::string&, int);
		std::list<user> developer_search();
		std::list<bug_overview> unassigned_bugs_search(const int);
		std::list<bug_overview> get_assigned_bugs(const std::string&, int);
		std::list<project> get_projects();
};

#endif

std::list<bug_overview> Search_Controller::bug_search(const std::string& query, int page) {
	std::list<bug_overview> result;
	DatabaseConnection database;
	database.open_connection(CONNECTION_DETAILS);

	std::string sqlQuery = 	"SELECT * FROM (SELECT BUG_ID FROM BUGS WHERE title LIKE "
				"'%" + query +"%'" 
				" UNION "
				"SELECT BUG_ID FROM KEYWORDS WHERE word LIKE "
				"'%" + query +"%'"
				" UNION "
				"SELECT BUG_ID FROM BUGS WHERE short_desc LIKE "
				"'%" + query + "%') LIMIT " + std::to_string(PAGE_LIMIT) +
				" OFFSET " + std::to_string(PAGE_LIMIT * page) + ";";
	try {
		pqxx::result r = database.query(sqlQuery);
		database.close_connection();

		for (pqxx::result::const_iterator c = r.begin(); c!= r.end(); c++){
		    Bug_Controller temp;
		    temp.find_bug_id(c[0].as<std::string>());
		    result.push_back(temp.get_bug_overview());
		}
	} catch (std::exception &e) {
	    return result;
	}
	return result;
}

std::list<user> Search_Controller::user_search(const std::string& query, int page) {
	std::list<user> result;
	DatabaseConnection database;
	database.open_connection(CONNECTION_DETAILS);

	std::string sqlQuery = 	"SELECT * FROM (SELECT username FROM USERS WHERE username LIKE "
				"'%" + query +"%') LIMIT " + std::to_string(PAGE_LIMIT) +
				" OFFSET " + std::to_string(PAGE_LIMIT * page) + ";";
	try {
		pqxx::result r = database.query(sqlQuery);
		database.close_connection();
		for (pqxx::result::const_iterator c = r.begin(); c!= r.end(); c++){
		    user_controller temp;
		    temp.find_username(c[0].as<std::string>());
		    result.push_back(temp.get_user_info());
		}
	} catch (std::exception &e) {
	    return result;
	}
	return result;
}

std::list<bug_overview> Search_Controller::project_search(const std::string &query, int page) {
	std::list<bug_overview> result;
	DatabaseConnection database;
	database.open_connection(CONNECTION_DETAILS);

	std::string sqlQuery = 	"SELECT * FROM (SELECT BUG_ID FROM BUGS WHERE project_id ="
				+ query + ") LIMIT " + std::to_string(PAGE_LIMIT) +
				" OFFSET " + std::to_string(PAGE_LIMIT * page) + ";";
	try {
		pqxx::result r = database.query(sqlQuery);
		database.close_connection();

		for (pqxx::result::const_iterator c = r.begin(); c!= r.end(); c++){
		    Bug_Controller temp;
		    temp.find_bug_id(c[0].as<std::string>());
		    result.push_back(temp.get_bug_overview());
		}
	} catch (std::exception &e) {
	    return result;
	}
	return result;
}

std::list<user> Search_Controller::developer_search() {
	std::list<user> result;
	DatabaseConnection database;
	database.open_connection(CONNECTION_DETAILS);

	std::string sqlQuery = 	"SELECT * FROM (SELECT username FROM USERS"
		" WHERE privilege_level ='Developer';";
	try {
		pqxx::result r = database.query(sqlQuery);
		database.close_connection();
		for (pqxx::result::const_iterator c = r.begin(); c!= r.end(); c++){
		    user_controller temp;
		    temp.find_username(c[0].as<std::string>());
		    result.push_back(temp.get_user_info());
		}
	} catch (std::exception &e) {
	    return result;
	}
	return result;
}
std::list<bug_overview> Search_Controller::unassigned_bugs_search(const int page){
	std::list<bug_overview> result;
	DatabaseConnection database;
	database.open_connection(CONNECTION_DETAILS);

	std::string sqlQuery = "SELECT * FROM (SELECT bug_id FROM BUGS"
			"WHERE assigned_to IS NULL) LIMIT " + std::to_string(PAGE_LIMIT)
			+ " OFFSET " + std::to_string(PAGE_LIMIT*page) + ";";
	try {
		pqxx::result r = database.query(sqlQuery);
		database.close_connection();
		for (pqxx::result::const_iterator c = r.begin(); c!= r.end(); c++){
		    Bug_Controller temp;
		    temp.find_bug_id(c[0].as<std::string>());
		    result.push_back(temp.get_bug_overview());
		}

	} catch (std::exception &e) {
	    return result;
	}
	return result;
}
std::list<bug_overview> Search_Controller::get_assigned_bugs(const std::string& query, const int page){
        std::list<bug_overview> result;
	DatabaseConnection database;
	database.open_connection(CONNECTION_DETAILS);

	std::string sqlQuery = "SELECT * FROM (SELECT bug_id FROM BUGS"
			"WHERE assigned_to='"+ query +"') LIMIT " + std::to_string(PAGE_LIMIT)
			+ " OFFSET " + std::to_string(PAGE_LIMIT*page) + ";";
	try {
		pqxx::result r = database.query(sqlQuery);
		database.close_connection();
		for (pqxx::result::const_iterator c = r.begin(); c!= r.end(); c++){
		    Bug_Controller temp;
		    temp.find_bug_id(c[0].as<std::string>());
		    result.push_back(temp.get_bug_overview());
		}

	} catch (std::exception &e) {
	    return result;
	}
	return result;

}

std::list<project> Search_Controller::get_projects(){
	std::list<project> result;
	DatabaseConnection database;
	database.open_connection(CONNECTION_DETAILS);

	std::string sqlQuery = "SELECT * FROM (SELECT project_id FROM PROJECTS"
			");";
	try {
		pqxx::result r = database.query(sqlQuery);
		database.close_connection();
		for (pqxx::result::const_iterator c = r.begin(); c!= r.end(); c++){
		    project_controller temp;
		    temp.find_project_id(c[0].as<std::string>());
		    result.push_back(temp.get_project());
		}

	} catch (std::exception &e) {
	    return result;
	}
	return result;
}


