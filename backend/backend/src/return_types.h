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
    std::string bug_id;
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
    std::list<std::string> keywords;
    std::list<std::string> dependencies;
};

struct user {
    std::string username;
    std::string password;
    std::string email;
    std::string privilege_level;
};

struct top_developer {
    std::string project_id;
    std::string username;
    std::string resolved_bugs;
};

struct statistics {
    std::string project_id;
    std::string num_of_bugs;
    std::string num_of_resolved_bugs;
    std::string total_wait_time;
    std::list<top_developer> top_developers;
};
struct project {
    std::string project_name;
    std::string project_id;
    statistics statistic;
};

struct attachment {
    std::string attach_id;
    std::string creation_ts;
    std::string delta_ts;
    std::string description;
    std::string filename;
    std::string filesize;
    std::string file;
    std::string attacher;
};

struct comment {
    std::string comment_id;
    std::string username;
    std::string bug_id;
    std::string creation_ts;
    std::string body;
    std::string attach_id;
};



#endif
