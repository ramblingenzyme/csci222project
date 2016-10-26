// This file generated by ngrestcg
// For more information, please visit: https://github.com/loentar/ngrest

#ifndef BACKEND_H
#define BACKEND_H

#include <list>

#include <ngrest/common/Service.h>

#include "return_types.h"
#include "database_connection.h"

// *interface.defaultInlineResult: true
class backend: public ngrest::Service {
public:
    backend()  {}
    ~backend() {}

    // *method: POST
    auth_response authenticate(const std::string& username, const std::string& password);

    // *method: POST
    complete_bug_info get_bug_page(const int& id);

    // *method: POST
    user get_user_page(const std::string& username);

    // *method: POST
    project get_project(const std::string& project_id);

    // *method: POST
    std::list<bug_overview> get_normal_search(const std::string& query, const int page);

    // *method: POST
    std::list<user> get_user_search(const std::string& query, const int page);

    // *method: POST
    std::list<user> get_developers();

    // *method: POST
    bool assign_developer(const std::string& bug_id, const std::string& developer_username, const std::string& triager_username);

    // *method: POST
    bool add_bug(const complete_bug_info& bug);

    // *method: POST
    bool add_user(const user& user_info);

    // *method: POST
    bool edit_user(const user& user_info, const user& user_editing);

    // *method: POST
    bool add_comment(const comment& comment_info);

    // *method: POST
    bool add_project(const std::string project_name);

    // *method: POST
    bool drop_database(const std::string password);

    // *method: POST
    bool create_database(const std::string password);
};

#endif // BACKEND_H
