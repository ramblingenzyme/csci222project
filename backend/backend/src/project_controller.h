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

//Attempts to update project
bool project_controller::update_project(){
    if (this->isEmpty())
        return false;
            
    DatabaseConnection database;
    database.open_connection(CONNECTION_DETAILS);
    std::string sqlquery = "UPDATE PROJECT set project_name ='"
        + this->data->project_name + "', project_id="
        + this->data->project_id + "' where project_id ="
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


     

#endif
