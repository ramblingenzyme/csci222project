#ifndef PROJECT_CONTROLLER_H
#define PROJECT_CONTROLLER_H
#include "return_types.h"
#include "const.h" 
#include "database_connection.h"
#include <string>
#include <list>
#include <stdlib.h>

class project_controller {
private: 
    project *data;
    statistics *statistic;
public:
    project_controller() { this->data = NULL; this->statistic = NULL;}
        
    ~project_controller() { 
        if (!this->isEmpty())
            delete data;
    }

    bool find_project_id(std::string project_id);
    std::string generate_find_project_id_query(std::string project_id);
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
        this->data = new project ;
        *data = a; 
    }
    void new_project(const std::string);
    bool update_project();
    std::string generate_update_project_query();
    std::string generate_insert_project_query();

    void calculate_statistics(); 
    bool update_statistics();
    void set_statistics(statistics a) {
	if (this->statistic != NULL)
	    delete statistic;
	this->statistic = new statistics;
	*statistic = a;
	this->calculate_statistics();
    }

};

#endif

///////////////////////////////////////
// Definition of project_controller //
///////////////////////////////////////

//finds project based on project_id, if found is stored as data member
bool project_controller::find_project_id(std::string project_id) {
    DatabaseConnection database;
    try {
        database.open_connection(CONNECTION_DETAILS);
    
        std::string sqlquery = generate_find_project_id_query(project_id);
        pqxx::result results = database.query(sqlquery.c_str());
        pqxx::result::const_iterator c = results.begin();
        
        database.close_connection();
       	
	pqxx::result empty;
        if (results == empty)
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

std::string project_controller::generate_find_project_id_query(std::string project_id) {
    return "select * from PROJECT where project_id="+ project_id+";";
}

bool project_controller::find_statistics() {
    DatabaseConnection database;
    try {
        database.open_connection(CONNECTION_DETAILS);
    
        std::string sqlquery = "select * from STATISTICS where project_id="+ this->data->project_id+";"; 
        pqxx::result results = database.query(sqlquery.c_str());
        pqxx::result::const_iterator c = results.begin();
        
        database.close_connection();
         
	pqxx::result empty;
        if (empty == results)
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
	if (results != empty ){
            while ( c != results.end()) {
                top_developer temp;
                temp.project_id = c[0].as<std::string>();
                temp.username = c[1].as<std::string>();
                temp.resolved_bugs = c[2].as<std::string>();

                this->statistic->top_developers.push_back(temp);
            }
	}
        return true; 
    } catch (...) {
        return false;
    }
}
void project_controller::new_project(const std::string project_name){
	DatabaseConnection database;
	database.open_connection(CONNECTION_DETAILS);

	std::string sqlQuery = "Select project_id from PROJECTS ORDER BY project_id ASC;";
	pqxx::result r = database.query(sqlQuery);
	
	database.close_connection();
	pqxx::result::const_iterator c = r.end();
	c--;

	project new_project;
	new_project.project_name = project_name;
	std::string id_string = c[1].as<std::string>();
	double id = atof(id_string.c_str());
	id++;
	new_project.project_id = std::to_string(id);

	this->set_project(new_project);
}
//Attempts to update project
bool project_controller::update_project(){
    if (this->isEmpty())
        return false;
            
    DatabaseConnection database;
    database.open_connection(CONNECTION_DETAILS);
    std::string sqlquery = generate_insert_project_query();

    if (database.transaction(sqlquery))
        return true;
            
    sqlquery = generate_update_project_query();
        
    database.transaction(sqlquery);
    database.close_connection();
    return true;
}

std::string project_controller::generate_update_project_query() {
    std::string query;
    query = "UPDATE PROJECT set project_name='"
        + this->data->project_name + "', project_id='"
        + this->data->project_id + "' where project_id='"
        + this->data->project_id + "';";

    return query;
}

std::string project_controller::generate_insert_project_query() {
    std::string query;
    query = "insert into PROJECT (project_name, project_id) values ('"
        + this->data->project_name + "',"
        + this->data->project_id + ");";

    return query;
}
//deletes then inserts statistics and top developers
bool project_controller::update_statistics(){
    if (this->isEmpty())
        return false;
    this->calculate_statistics();
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

void project_controller::calculate_statistics(){
    DatabaseConnection database;
    database.open_connection(CONNECTION_DETAILS);
    
    std::string sqlQuery = "Select count(*) from BUGS where project_id="
	    + this->statistic->project_id + ";";
    pqxx::result results= database.query(sqlQuery);
    pqxx::result::const_iterator c = results.begin();

    this->statistic->num_of_bugs = c[0].as<std::string>(); 

    sqlQuery = "select count(*) from BUGS where project_id="
	    + this->statistic->project_id +" and status='RESOLVED';";
    results = database.query(sqlQuery);
    c = results.begin();

    this->statistic->num_of_resolved_bugs = c[0].as<std::string>();
    this->statistic->total_wait_time = "0";
}
#endif
