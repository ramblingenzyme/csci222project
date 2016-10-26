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
public:
    project_controller() { this->data = NULL; }
        
    ~project_controller() { 
        if (!this->isEmpty())
            delete data;
    }

    bool find_project_id(std::string project_id);
    std::string generate_find_project_id_query(std::string project_id);

    //is empty
    bool isEmpty() { 
        if (this->data == NULL) 
            return true;
        return false;
    }

    //returns the comment
    project get_project() { return *data; };
        
    //sets the stored comment to a given comment struct
    void set_project(project a) {
        if (this->data != NULL) 
            delete data; 
        data = new project ;
        *data = a; 
    }

    bool update_project();
    std::string generate_update_project_query();
    std::string generate_insert_project_query();
};

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

std::string project_controller::generate_find_project_id_query(std::string project_id) {
    return "select * from PROJECT where project_id="+ project_id+";"; 
}

//Attempts to update project
bool project_controller::update_project(){
    if (this->isEmpty())
        return false;
            
    DatabaseConnection database;
    database.open_connection(CONNECTION_DETAILS);
    std::string sqlquery = generate_update_project_query();

    if (database.transaction(sqlquery))
        return true;
            
    sqlquery = generate_insert_project_query();
        
    database.transaction(sqlquery);
    database.close_connection();
    return true;
}

std::string project_controller::generate_update_project_query() {
    std::string query;
    query = "UPDATE PROJECT set project_name ='"
        + this->data->project_name + "', project_id="
        + this->data->project_id + "' where project_id ="
        + this->data->project_id + ";";

    return query;
}

std::string project_controller::generate_insert_project_query() {
    std::string query;
    query = "insert into PROJECT (project_name, project_id) values ('"
        + this->data->project_name + "',"
        + this->data->project_id + ");";

    return query;
}


     

#endif
