#ifndef RETURN_TYPES_H
#define RETURN_TYPES_H
#include <list>
#include <string>

struct auth_response {
    bool authed;
    std::string role;
    std::string username;
};

struct bug_overview {
    std::string title;
    std::string product;
    std::string component;
    std::string version;
    std::string priority;
    std::string severity;
    std::string status;
};

struct complete_bug_info {
    std::string bug_id;
    std::string creation_time;
    std::string delta_time;
    std::string title;
    std::string description;
    std::string product;
    std::string component;
    std::string version;
    std::string operating_system;
    std::string target_milestone;
    std::string status;
    std::string duplicate_id;
    std::string priority;
    std::string severity;
    std::string reporter;
    std::string assigned_to;
    std::string project_id;
    std::string votes;

    std::list<std::string> cclist;
};

#endif
