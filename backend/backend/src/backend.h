// This file generated by ngrestcg
// For more information, please visit: https://github.com/loentar/ngrest

#ifndef BACKEND_H
#define BACKEND_H

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
};

#endif // BACKEND_H
