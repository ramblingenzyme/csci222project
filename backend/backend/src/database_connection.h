#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H
#include <string>
#include <pqxx/pqxx>

/* This may need to become a singleton instead */
class DatabaseConnection {
    public:
        DatabaseConnection() {
            /* if connection isn't open and there are details reconnect */
        }

        ~DatabaseConnection() {
            /* Should be nothing, I think. */
        }

        void open_connection(const std::string connection_details) {
            connection_details_ = connection_details;
            /* open connection */
        }

        void close_connection() {
            /* close connection */
        }

        pqxx::result query(const std::string query) {
            // needs to be refactored to be more defensive
            reconnect_if_needed();

            pqxx::nontransaction N(db_connection_);

            pqxx::result results( N.exec(query.c_str()) );

            return results;
        }

    private:
        void reconnect_if_needed() {
            if (!db_connection_.is_open()) {
                /* reopen db connection */
            }
        }

        static std::string connection_details_;
        static pqxx::connection db_connection_;
};

#endif
