//Program: entitites.h
//Author: Ryan Herford
//Purpose: Define data structures for the system
//Notes: In congruence the ECB model, entities don't contain any control
//     methods, only setters and getters

#ifndef ENTITIES_H
#define ENTITIES_H
#include <string>

enum Rank {
    null,
    reporter,
    developer,
    reviewer,
    triager,
    superadmin
};

class Reporter {
    protected:
        std::string username;
        std::string password;
        std::string email;
        Rank privilege_level;
    public:
        Reporter();
        Reporter(const std::string, const std::string, const std::string);
        ~Reporter();

        std::string get_username();
        std::string get_password();
        std::string get_email();
        Rank get_privilege_level();

        void set_password(std::string);
};

class Reviewer: public Reporter {
    public:
        Reviewer(): Reporter() {this->privilege_level = reviewer;};
        Reviewer(const std::string a, const std::string b, const std::string c ): Reporter(a,b,c) {this->privilege_level = reviewer;};
};

class Developer: public Reporter {
    public:
        Developer(): Reporter() {this->privilege_level = developer;};
        Developer(const std::string a, const std::string b, const std::string c ): Reporter(a,b,c) {this->privilege_level = developer;};
};
class Triager: public Reporter {
    public:
        Triager(): Reporter() {this->privilege_level = triager;};
        Triager(const std::string a, const std::string b, const std::string c ): Reporter(a,b,c) {this->privilege_level = triager;};
};
class SuperAdmin: public Reporter {
    public:
        SuperAdmin(): Reporter() {this->privilege_level = superadmin;};
        SuperAdmin(const std::string a, const std::string b, const std::string c ): Reporter(a,b,c) {this->privilege_level = superadmin;};
};


#endif
