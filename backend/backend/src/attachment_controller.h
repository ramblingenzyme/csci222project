#ifndef ATTACHMENT_CONTROLLER_H
#define ATTACHMENT_CONTROLLER_H
#include "return_types.h"
#include "const.h" 
#include "database_connection.h"
#include <string>
#include <list>

class attachment_controller {
private: 
    attachment *data;
public:
    attachment_controller() { this->data = NULL; }
        
    ~attachment_controller() { 
        if (!this->isEmpty())
            delete data;
    }

    bool find_attach_id(std::string attach_id);
    std::string generate_find_attach_id_query(std::string attach_id);

    //is empty
    bool isEmpty() { 
        if (this->data == NULL) 
            return true;
        return false;
    }

    //returns the comment
    attachment get_attachment() { return *data; };
        
    //sets the stored comment to a given comment struct
    void set_attachment(attachment a) {
        if (this->data != NULL) 
            delete data; 
        data = new attachment;
        *data = a; 
    }

    bool update_attachment();
    std::string generate_update_attachment_query();
    std::string generate_insert_attachment_query();



    ////////////////////////
    // unit testing only  //
    ////////////////////////
    
    bool attachment_id_is_equal(std::string attach_id) {
        return data->attach_id == attach_id;
    }
};

///////////////////////////////////////
// Definition of attachment_controller //
///////////////////////////////////////

//finds comment based on comment_id, if found is stored as data member
bool attachment_controller::find_attach_id(std::string attach_id) {
    DatabaseConnection database;
    try {
        database.open_connection(CONNECTION_DETAILS);
    
        std::string sqlquery = generate_find_attach_id_query(attach_id);
        pqxx::result results = database.query(sqlquery.c_str());
        pqxx::result::const_iterator c = results.begin();
        
        database.close_connection();
        
        if (c == results.end())
            return false;
        
        if (this->isEmpty())
            delete this->data;
        this->data = new attachment;
        
        this->data->attach_id = c[0].as<std::string>();
        this->data->creation_ts = c[1].as<std::string>();
        this->data->delta_ts = c[2].as<std::string>();
        this->data->description = c[3].as<std::string>();
        this->data->filename = c[4].as<std::string>();
        this->data->filesize = c[5].as<std::string>();
        this->data->file = c[6].as<std::string>();
        this->data->attacher = c[6].as<std::string>();

        return true; 
    } catch (...) {
        return false;
    }
}

std::string attachment_controller::generate_find_attach_id_query(std::string attach_id) {
    return "select * from ATTACHMENT where attach_id=" + attach_id + ";"; 
}

//Attempts to update attachement
bool attachment_controller::update_attachment(){
    if (this->isEmpty())
        return false;
            
    DatabaseConnection database;
    database.open_connection(CONNECTION_DETAILS);
    std::string sqlquery = generate_update_attachment_query();

    if (database.transaction(sqlquery))
        return true;
            
    sqlquery = generate_insert_attachment_query();
        
    database.transaction(sqlquery);
    database.close_connection();
    return true;
}

std::string attachment_controller::generate_update_attachment_query() {
    std::string query;
    query = "UPDATE ATTACHMENT set attach_id ="
        + this->data->attach_id + ", creation_ts='"
        + this->data->creation_ts + "',delta_ts ='"
        + this->data->delta_ts + ", description ='"
        + this->data->description + "', filename ='"
        + this->data->filename + "', filesize="
        + this->data->filesize +", file='"
        + this->data->file +"', attacher="
        + this->data->attacher + " where comment_id ="
        + this->data->attach_id + ";";

    return query;
}

std::string attachment_controller::generate_insert_attachment_query() {
    std::string query;
    query = "insert into ATTACHMENT (attach_id, creation_ts,"
        "delta_ts, description, filename, filesize, file, attacher) values ("
        + this->data->attach_id + ",'"
        + this->data->creation_ts + "',"
        + this->data->delta_ts + ",'"
        + this->data->filename + "',"
        + this->data->filesize + ",'"
        + this->data->file + "',"
        + this->data->attacher + ");";

    return query;
}


#endif
