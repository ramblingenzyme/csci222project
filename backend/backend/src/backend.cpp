// This file generated by ngrestcg
// For more information, please visit: https://github.com/loentar/ngrest
//

#include <pqxx/pqxx>
#include <cppunit/extensions/HelperMacros.h>
#include <ostream>
#include "backend.h"
#include "bug_controller.h"
#include "user_controller.h"
#include "comment_controller.h"
#include "attachment_controller.h"
#include "project_controller.h"
#include "utilitycontrollers.h"
#include "search_controller.h"

auth_response backend::authenticate(const std::string& username, const std::string& password) {
    //SELECT * FROM USER WHERE USERNAME =$USERNAME - generalising
    user_controller temp;
    auth_response result;

    if (!temp.find_username(username)) {
        result.authed = false;
        result.role = "null";
        result.username = username;
    } else {
        if (temp.authenticate(password)) {
            result.authed = true;
            result.role = temp.get_user_info().privilege_level;
            result.username = username;     
        } else {
            result.authed = false;
            result.role = "null";
            result.username = username;
        }
    }

    return result;
}

complete_bug_info backend::get_bug_page(const int& id) {
    Bug_Controller controller;
   
    controller.find_bug_id(std::to_string(id));
    if (!controller.isEmpty()){
        return controller.get_bug_info();
    } else {
        complete_bug_info result;
        result.bug_id = "0";

        return result;
    }
}

user backend::get_user_page(const std::string& username){
    user_controller controller;

    controller.find_username(username);
    if (!controller.isEmpty()){
        return controller.get_user_info();
    } else { 
        user result;
        return result;
    }
}

std::list<bug_overview> backend::get_normal_search(const std::string& query, const int page){
    Search_Controller search;
    return search.bug_search(query,page);
}
std::list<user> backend::get_user_search(const std::string& query, const int page) {
    Search_Controller search;
    return search.user_search(query, page);
}
bool backend::add_bug(const complete_bug_info& bug){
    Bug_Controller controller;
    controller.set_bug_info(bug);

    if (controller.update_bug())
        return true;
    else 
        return false;
}

bool backend::add_user(const user& user_info){
    user_controller controller;
    controller.set_user_info(user_info);

    if (controller.update_user())
        return true;
    else 
        return false;
}
bool backend::edit_user(const user& user_info, const user& user_editing){
    user_controller edit;
    user_controller user;

    if (!edit.find_username(user_info.username)||!user.find_username(user_editing.username)) return false;
    edit.set_user_info(user_info);
    if (user.get_user_info().username == edit.get_user_info().username){
	edit.update_user();
	return true;
    } else if (user.get_user_info().privilege_level == "Superadmin"){
	edit.update_user();
	return true;
    } else 
	return false;
}

bool backend::add_comment(const comment& comment_info){
    comment_controller controller;
    controller.set_comment(comment_info);

    if (controller.update_comment())
        return true;
    else 
        return false;
}

bool backend::drop_database(const std::string password){
    if (password != "satvik no") return false;
    Database_Utility util;

    return util.drop_database();
}

bool backend::create_database(const std::string password){
    if (password != "satvik no") return false;
    Database_Utility util;

    return util.create_database();
}



