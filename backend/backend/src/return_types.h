#ifndef RETURN_TYPES_H
#define RETURN_TYPES_H
#include <string>

struct auth_response {
    bool authed;
    std::string role;
    std::string username;
};

#endif
