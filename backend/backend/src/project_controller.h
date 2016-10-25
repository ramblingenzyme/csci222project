#ifndef PROJECT_CONTROLLER_H
#define PROJECT_CONTROLLER_H
#include "return_types.h"
#include "const.h" 
#include "database_connection.h"
#include <string>
#include <list>

class project_controller {
private: 
    project *data;
    statistics *statistic;
public:
    project_controller() { this->data = NULL; }
        
    ~project_controller() { 
        if (!this->isEmpty())
            delete data;
    }

    bool find_project_id(std::string project_id);
    bool find_statistics();

    //is empty
    bool isEmpty() { 
        if (this->data == NULL) 
            return true;
        return false;
    }

    //returns the comment
    project get_project() { return *data; };
    statistics get_statistics(){return *statistic; };

        
    //sets the stored comment to a given comment struct
    void set_project(project a) {
        if (this->data != NULL) 
            delete data; 
        data = new project ;
        *data = a; 
    }

    bool update_project();
    bool update_statistics();
};

///////////////////////////////////////
// Definition of project_controller //
///////////////////////////////////////

//finds project based on project_id, if found is stored as data member
bool project_controller::find_project_id(std::string project_id) {
    DatabaseConnection database;
    try {
        database.open_connection(CONNECTION_DETAILS);
    
        std::string sqlquery = "select * from PROJECT where project_id="+ project_id+";"; 
        pqxx::result results = database.query(sqlquery.c_str());
        pqxx::result::const_iterator c = results.begin();
        
        database.close_connection();
        
        if (c == results.end())
            return false;
        
        if (this->isEmpty())
            delete this->data;
        this->data = new project;
        
        this->data->project_name = c[0].as<std::string>();
        this->data->project_id = c[1].as<std::string>();

        return true; 
    } catch (...) {
        return false;
    }
}

bool project_controller::find_statistics() {
    DatabaseConnection database;
    try {
        database.open_connection(CONNECTION_DETAILS);
    
        std::string sqlquery = "select * from STATISTICS where project_id="+ this->data->project_id+";"; 
        pqxx::result results = database.query(sqlquery.c_str());
        pqxx::result::const_iterator c = results.begin();
        
        database.close_connection();
        
        if (c == results.end())
            return false;
        
        if (this->isEmpty())
            delete this->statistic;
        this->statistic = new statistics;
        
        this->statistic->project_id = c[0].as<std::string>();
        this->statistic->num_of_bugs = c[1].as<std::string>();
	this->statistic->num_of_resolved_bugs = c[2].as<std::string>();
	this->statistic->total_wait_time = c[3].as<std::string>();

	sqlquery = "select * from TOPDEVELOPERS where project_id="+ this->statistic->project_id+";";
	results = database.query(sqlquery.c_str());
	c = results.begin();

	while ( c != results.end()) {
		top_developer temp;
		temp.project_id = c[0].as<std::string>();
		temp.username = c[1].as<std::string>();
		temp.resolved_bugs = c[2].as<std::string>();

		this->statistic->top_developers.push_back(temp);
	}
	
	return true; 
    } catch (...) {
        return false;
    }
}

//Attempts to update project
bool project_controller::update_project(){
    if (this->isEmpty())
        return false;
            
    DatabaseConnection database;
    database.open_connection(CONNECTION_DETAILS);
    std::string sqlquery = "UPDATE PROJECT set project_name ='"
        + this->data->project_name + "', project_id="
        + this->data->project_id + " where project_id ="
        + this->data->project_id + ";";

    if (database.transaction(sqlquery))
        return true;
            
    sqlquery = "insert into PROJECT (project_name, project_id) values ('"
        + this->data->project_name + "',"
        + this->data->project_id + ");";
        
    database.transaction(sqlquery);
    database.close_connection();
    return true;
}

//deletes then inserts statistics and top developers
bool project_controller::update_statistics(){
    if (this->isEmpty())
        return false;
            
    DatabaseConnection database;
    database.open_connection(CONNECTION_DETAILS);
    
    std::string sqlquery = "delete from STATISTICS where project_id=" +this->statistic->project_id + ";";
    database.transaction(sqlquery);

    sqlquery = "insert into STATISTICS (project_id, num_of_bugs, num_of_resolved_bugs, total_wait_time) values ("
        + this->statistic->project_id + ","
        + this->statistic->num_of_bugs + ","
	+ this->statistic->num_of_resolved_bugs + ","
	+ this->statistic->total_wait_time + ");";
	
    database.transaction(sqlquery);
    
    sqlquery = "delete from TOPDEVELOPERS where project_id=" + this->statistic->project_id + ";";
    database.transaction(sqlquery);

    for (std::list<top_developer>::iterator it = this->statistic->top_developers.begin(); it != this->statistic->top_developers.end(); it++){
        sqlquery = "insert into TOPDEVELOPERS (project_id, username, resolved_bugs) values ("
	    + it->project_id + ","
	    + it->username + ","
	    + it->resolved_bugs + ";";
	database.transaction(sqlquery);
    }

    database.close_connection();
    return true;
}


     

#endif
