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
        std::list<bug_overview> get_normal_search(const std::string& query);

	// *method: POST
	bool add_bug(const complete_bug_info& bug);

	// *method: POST
	bool add_user(const user& user_info);

	// *method: POST
	bool add_comment(const comment& comment_info);
};

#endif // BACKEND_H
