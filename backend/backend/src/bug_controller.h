#ifndef BUG_CONTROLLER_H
#define BUG_CONTROLLER_H
#include "return_types.h"
#include "const.h"
#include "database_connection.h"
#include "comment_controller.h"
#include <string>
#include <list>
#include "time_utility.h"

//Bug_controller class

class Bug_Controller {
private:
    complete_bug_info *data;    //struct pointer;
public:
    Bug_Controller(){
        data = NULL;
    }

    ~Bug_Controller(){
        if (!this->isEmpty())
            delete data;
    }

    bool find_bug_id(std::string bugID);
    std::string generate_find_bug_id_query(std::string bugID);

    bug_overview get_bug_overview();
    void set_bug_info(complete_bug_info a);

    bool update_bug();
    std::string generate_update_bug_query();

    std::string generate_insert_bug_query();

    std::string generate_cc_list_query();

    //return the all info on the bug
    complete_bug_info get_bug_info(){ return *data;};

    // is it empty tho?
    void new_bug(const complete_bug_info&);
    bool isEmpty() { return data == NULL;};
};

//////////////////////////////////
// Definition of Bug_Controller //
//////////////////////////////////

//find_bug_id(string bugID) searches the database for a bug via bug_id, and it finds it, stores the bug as a data member
bool Bug_Controller::find_bug_id(std::string bugID) {
    DatabaseConnection database;
    try {
        database.open_connection(CONNECTION_DETAILS);

        //std::string sqlQuery = "SELECT * FROM BUGS WHERE BUG_ID="+ bugID +";";
        std::string sqlQuery = generate_find_bug_id_query(bugID);
        pqxx::result results = database.query(sqlQuery.c_str());
        pqxx::result::const_iterator c = results.begin();

        //if the select statement didn't find anything, return false
        pqxx::result empty;
        if (results == empty){
            database.close_connection();
            return false;
        }

        //refreshing *data
        if (this->isEmpty())
            delete this->data;
        this->data = new complete_bug_info;

        //storing the bug and additional data (cclist, dependencies, keywords)
        this->data->bug_id = c[0].as<std::string>();
        this->data->creation_time = c[1].as<std::string>();
        this->data->delta_time = c[2].as<std::string>();
	this->data->title = c[3].as<std::string>();
        this->data->description = c[4].as<std::string>();
        this->data->product = c[5].as<std::string>();
        this->data->component = c[6].as<std::string>();
        this->data->version = c[7].as<std::string>();
        this->data->operating_system = c[8].as<std::string>();
        this->data->target_milestone = c[9].as<std::string>();
        this->data->status = c[10].as<std::string>();
        this->data->duplicate_id = c[11].as<std::string>();
        this->data->priority = c[12].as<std::string>();
        this->data->severity = c[13].as<std::string>();
        this->data->reporter = c[14].as<std::string>();
        this->data->assigned_to = c[15].as<std::string>();
        this->data->project_id = c[16].as<std::string>();
        this->data->votes = c[17].as<std::string>();

        sqlQuery = "SELECT * FROM CCLIST WHERE BUG_ID="+ bugID +";";
        results = database.query(sqlQuery.c_str());
        c = results.begin();

        while (c != results.end()){
            this->data->cclist.push_back(c[1].as<std::string>());
            c++;
        }

        sqlQuery = "SELECT * FROM KEYWORDS WHERE BUG_ID="+ bugID +";";
        results = database.query(sqlQuery.c_str());
        c = results.begin();

        while (c != results.end()){
            this->data->keywords.push_back(c[1].as<std::string>());
            c++;
        }

        sqlQuery = "SELECT * FROM DEPENDENCIES WHERE BUG_ID="+ bugID +";";
        results = database.query(sqlQuery.c_str());
        c = results.begin();

        while (c != results.end()){
            this->data->dependencies.push_back(c[1].as<std::string>());
            c++;
        }

        sqlQuery = "SELECT comment_id FROM COMMENTS WHERE BUG_ID=" + bugID +";";
        results = database.query(sqlQuery.c_str());
        c = results.begin();

        database.close_connection();
        while (c!= results.end()){
            comment_controller temp;
            temp.find_comment_id(c[0].as<std::string>());
            this->data->comments.push_back(temp.get_comment());
            c++;
        }

        return true;
    } catch (...) {
    database.close_connection();
        return false;
    }
}

std::string Bug_Controller::generate_find_bug_id_query(std::string bugID) {
    return "SELECT * FROM BUGS WHERE BUG_ID=" + bugID + ";";
}

//return a summarised version of the info on the bug
bug_overview Bug_Controller::get_bug_overview() {
    bug_overview bug;

    bug.bug_id = this->data->bug_id;
    bug.title = this->data->title;
    bug.product = this->data->product;
    bug.component = this->data->component;
    bug.version = this->data->version;
    bug.priority = this->data->priority;
    bug.severity = this->data->severity;
    bug.status = this->data->status;

    return bug;
}

//takes a struct of bug info, and stores it as a data member
void Bug_Controller::set_bug_info(complete_bug_info a) {
    if (!this->isEmpty())
        delete data;
    data = new complete_bug_info;
    *data = a;
}

//attempts to UPDATE the bug database entry, if it fails, it means it doesn't prexist in the database, so is inserted.
bool Bug_Controller::update_bug(){
    if (this->isEmpty())
        return false;

    DatabaseConnection database;
    database.open_connection(CONNECTION_DETAILS);

    //update bug
    std::string sqlquery = generate_insert_bug_query();

    //if insert fails, then start update else, update the rest
    if (database.transaction(sqlquery)){
        //updating bug
        sqlquery = generate_update_bug_query();

        database.transaction(sqlquery);


	sqlquery = "delete from cclist where bug_id="
            + this->data->bug_id + ";";
        database.transaction(sqlquery);

        sqlquery = "delete from dependencies where bug_id="
            + this->data->bug_id + ";";
        database.transaction(sqlquery);

        sqlquery = "delete from keywords where bug_id="
            + this->data->bug_id + ";";
        database.transaction(sqlquery);

        //inserting cclist
        for (std::list<std::string>::iterator i= this->data->cclist.begin(); i != this->data->cclist.end(); i++) {
            sqlquery = "insert into cclist(bug_id, username"
                ") values ("
                + this->data->bug_id + ",'"
                + *i + "');";

            database.transaction(sqlquery);
        }

        //inserting dependencies
        for (std::list<std::string>::iterator i= this->data->dependencies.begin(); i != this->data->dependencies.end(); i++) {
            sqlquery = "insert into cclist(bug_id, dependency"
                ") values ("
                + this->data->bug_id + ","
                + *i + ");";

            database.transaction(sqlquery);
        }

        //inserting keywords
        for (std::list<std::string>::iterator i= this->data->keywords.begin(); i != this->data->keywords.end(); i++) {
            sqlquery = "insert into keywords(bug_id, word"
                ") values ("
                + this->data->bug_id + ",'"
                + *i + "');";

            database.transaction(sqlquery);
        }

        for (std::list<comment>::iterator i  = this->data->comments.begin(); i != this->data->comments.end();i++) {
            comment_controller controller;
            controller.set_comment(*i);
            controller.update_comment();
        }

        return true;
    }

        //inserting cclist
    for (std::list<std::string>::iterator i= this->data->cclist.begin(); i != this->data->cclist.end(); i++) {
        sqlquery = "insert into cclist(bug_id, username"
            ") values ("
            + this->data->bug_id + ",'"
            + *i + "');";

        database.transaction(sqlquery);
    }

    //inserting dependencies
    for (std::list<std::string>::iterator i= this->data->dependencies.begin(); i != this->data->dependencies.end(); i++) {
        sqlquery = "insert into cclist(bug_id, dependency"
            ") values ("
            + this->data->bug_id + ","
            + *i + ");";

        database.transaction(sqlquery);
    }

    //inserting keywords
    for (std::list<std::string>::iterator i= this->data->keywords.begin(); i != this->data->keywords.end(); i++) {
        sqlquery = "insert into keywords(bug_id, word"
            ") values ("
            + this->data->bug_id + ",'"
            + *i + "');";

        database.transaction(sqlquery);
    }

    //after a hard days work, closing the connection
    database.close_connection();

    for (std::list<comment>::iterator i  = this->data->comments.begin(); i != this->data->comments.end();i++) {
            comment_controller controller;
            controller.set_comment(*i);
            controller.update_comment();
    }

    return true;
}

std::string Bug_Controller::generate_update_bug_query() {
    std::string query;
    query = "UPDATE bugs set bug_id = '"
        + this->data->bug_id + "', creation_ts = '"
        + this->data->creation_time + "', delta_ts = '"
        + this->data->delta_time + "', title = '"
        + this->data->title + "', short_desc = '"
        + this->data->description + "', component = '"
        + this->data->component + "', version = '"
        + this->data->version + "', op_sys = '"
        + this->data->operating_system + "', bug_status = '"
        + this->data->status + "', dupl_id = '"
        + this->data->duplicate_id + "', bug_file_loc = '"
        + "NULL" + "', priority = '"
        + this->data->priority + "', severity = '"
        + this->data->severity + "', reporter = '"
        + this->data->reporter + "', assigned_to = '"
        + this->data->assigned_to + "', project_id = '"
        + this->data->project_id + "', votes = '"
        + this->data->votes + "' where bug_id = '"
        + this->data->bug_id + "';";

    return query;
}

std::string Bug_Controller::generate_insert_bug_query() {
    std::string query;

    query = "insert into bugs (bug_id, creation_ts,"
        "delta_ts, title, short_desc, component,"
        "version, op_sys, bug_status, dupl_id,"
        "bug_file_loc, priority, severity, reporter,"
        "assigned_to, project_id, votes) values ("
        + this->data->bug_id + ",'"
        + this->data->creation_time + "','"
        + this->data->delta_time + "','"
        + this->data->title + "','"
        + this->data->description + "','"
        + this->data->component + "','"
        + this->data->version + "','"
        + this->data->operating_system + "','"
        + this->data->status + "',"
        + this->data->duplicate_id + ","
        + "NULL" + ",'"
        + this->data->priority + "','"
        + this->data->reporter + "','"
        + this->data->severity + "','"
        + this->data->assigned_to + "',"
        + this->data->project_id + ","
        + this->data->votes + ");";

    return query;
}

void Bug_Controller::new_bug(const complete_bug_info& partial){
    this->set_bug_info(partial);

    DatabaseConnection database;
    database.open_connection(CONNECTION_DETAILS);

    std::string sqlQuery = "Select bug_id FROM BUGS ORDER BY bug_id ASC;";
    pqxx::result r = database.query(sqlQuery);
    database.close_connection();
    pqxx::result::const_iterator c = r.end();
    c--;

    std::string id_string = c[0].as<std::string>();
    double id = atof(id_string.c_str());
    id++;

    this->data->bug_id = std::to_string(id);
}

#endif
