#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H
#include <string>
#include <pqxx/pqxx>
#include <iostream>

/* This may need to become a singleton instead */
class DatabaseConnection {
    private:
        void reconnect_if_needed() {
            if (!db_connection_->is_open()) {
                if (db_connection_ != NULL)
		    delete db_connection_;
		db_connection_ = new pqxx::connection(connection_details_); 
            }
	
        };

        std::string connection_details_;
        pqxx::connection *db_connection_;
    public:
        DatabaseConnection() {
            if (!connection_details_.empty()) {
                db_connection_ = new pqxx::connection(connection_details_);
	    } else {
	        db_connection_ = NULL; 
	    }
        };

        ~DatabaseConnection() {
            if (db_connection_->is_open()){
	        close_connection();
	    }
	    if (db_connection_ != NULL) 
	       delete db_connection_;
        };

        void open_connection(const std::string connection_details) {
            connection_details_ = connection_details;
            if (db_connection_ != NULL) 
	        delete db_connection_; 

	    db_connection_ = new pqxx::connection(connection_details_); 
        };

        void close_connection() {
            if (db_connection_->is_open()) {
	        db_connection_->disconnect();    
	    }
        };

        pqxx::result query(const std::string query) {
            // needs to be refactored to be more defensive
            try {
		reconnect_if_needed();

                pqxx::nontransaction N(*db_connection_);
	   
         	pqxx::result results( N.exec(query.c_str()) );

            	return results;
	    }catch(std::exception &e) {
		
		throw(e);
		pqxx::result results;
		return results;
	    }
        };

	bool transaction(const std::string query){ 
	    try{
	        reconnect_if_needed();

	        pqxx::work W(*db_connection_);
	        W.exec(query.c_str());
		W.commit();
		return true;
	    } catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return false; 
	    }
	}

   };

#endif
