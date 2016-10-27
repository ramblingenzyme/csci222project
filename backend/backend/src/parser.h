#ifndef PARSER_H
#define PARSER_H

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <string>
#include "return_types.h"
#include <iostream>
#include "bug_controller.h"
#include "comment_controller.h"
#include "user_controller.h"


using boost::property_tree::ptree;

struct bug_xml
{
    void load(const std::string &filename);
    void save(const std::string &filename);
    void read_bug(ptree::value_type &f);
    void read_bug_cclist(ptree::value_type& v, complete_bug_info& temp);
    void read_user(ptree::value_type &v);
    void read_comment(ptree::value_type &v, std::string bug_id);

    void print_bug(complete_bug_info& bug);
    void print_comment(comment& c);
};

void bug_xml::read_comment(ptree::value_type &v, std::string bug_id){
    comment temp;

    BOOST_FOREACH(ptree::value_type const& f, v.second) {
        if(f.first == "long_desc") {
	    //add user here, check if exists, if does, forget, if don't eh
	    user u;
	    u.username = f.second.get<std::string>("who");
	    user_controller u_controller;
	    if (!u_controller.find_username(u.username)){
		u_controller.set_user_info(u);
		std::cout << "added user: " <<u_controller.update_user() << std::endl;
	    }


            temp.comment_id  = f.second.get<std::string>("commentid");
            temp.username = f.second.get<std::string>("who");
            temp.bug_id = bug_id;
            temp.creation_ts = f.second.get<std::string>("bug_when");
            temp.body = f.second.get<std::string>("thetext");

            comment_controller c_controller;
	    c_controller.set_comment(temp);
	    std::cout << "added comment: " << c_controller.update_comment() << std::endl;
	    //print_comment(temp);
        }
    }
}

void bug_xml::print_comment(comment& c) {
    std::cout << "comment_id: " << c.comment_id << '\n'
              << "username: " << c.username << '\n'
              << "bug_id: " << c.bug_id << '\n'
              << "creation_ts: " << c.creation_ts << '\n'
              << "body: " << c.body << '\n';
}

void bug_xml::read_user(ptree::value_type &v){
    user u;
    ptree bugtree = (ptree) v.second;
    u.username = bugtree.get<std::string>("assigned_to","");
    u.privilege_level = "Developer";

    //TODO: Push/queue above user to database
    user_controller a_controller;
    a_controller.set_user_info(u);
    std::cout << "added/updated user: " << a_controller.update_user() << std::endl;

    
    u.privilege_level = "Reporter";
    u.username = bugtree.get<std::string>("reporter","");
    if (!a_controller.find_username(u.username)) {
	a_controller.set_user_info(u);
	std::cout << "added/updated user: " << a_controller.update_user() << std::endl;;
    }
    //TODO: Push/queue above user to database
}

void bug_xml::read_bug(ptree::value_type &v){
    std::cout << std::endl<< std::endl;

    boost::property_tree::ptree bugtree = (boost::property_tree::ptree) v.second;

    complete_bug_info temp;
    temp.bug_id = bugtree.get<std::string>("bug_id");
    temp.creation_time = bugtree.get<std::string>("creation_ts");
    temp.description = bugtree.get<std::string>("short_desc");
    temp.delta_time = bugtree.get<std::string>("delta_ts");
    temp.title = bugtree.get<std::string>("short_desc");
    temp.version = bugtree.get<std::string>("version");
    temp.operating_system = bugtree.get<std::string>("target_milestone");
    temp.status = bugtree.get<std::string>("bug_status");
    temp.duplicate_id = bugtree.get<std::string>("dup_id", "0");
    temp.priority= bugtree.get<std::string>("priority");
    temp.severity = bugtree.get<std::string>("bug_severity");
    temp.reporter = bugtree.get<std::string>("reporter", "0");
    temp.assigned_to = bugtree.get<std::string>("assigned_to", "0");
    temp.project_id = "0"; 
    temp.votes = bugtree.get<std::string>("votes");
    temp.keywords.push_back(bugtree.get<std::string>("keywords"));
    
    Bug_Controller b_controller;
    b_controller.set_bug_info(temp);

    std::cout << "Added bug: " << b_controller.update_bug() << std::endl;

    read_bug_cclist(v, temp);

    b_controller.set_bug_info(temp);
    std::cout << "Added bug: " << b_controller.update_bug() << std::endl;;

    read_comment(v, temp.bug_id);

    //print_bug(temp);

    //TODO: Insert push bug functionality
}

void bug_xml::read_bug_cclist(ptree::value_type& v, complete_bug_info& temp) {
    BOOST_FOREACH(ptree::value_type const& f, v.second) {
        if(f.first == "cc") {
	    user_controller u_controller;
	    user u;
	    u.username = f.second.data();
	    u_controller.set_user_info(u);
	    u_controller.update_user();

            temp.cclist.push_back(f.second.data());
        }
    }
}

void bug_xml::print_bug(complete_bug_info& bug) {
    std::cout << "bug id: " << bug.bug_id << "\n"
              << "creation_ts: " << bug.creation_time << "\n"
              << "delta_ts: "<< bug.delta_time << "\n"
              << "title: " << bug.title << "\n"
              << "description: " << bug.description << "\n"
              << "product: " << bug.product << "\n"
              << "component: " <<bug.component << "\n"
              << "version: " << bug.version << "\n"
              << "operating_system: " << bug.operating_system << "\n"
              << "target_milestone: " << bug.target_milestone << "\n"
              << "status: " << bug.status << "\n" 
              << "duplicate_id: " << bug.duplicate_id << "\n"
              << "priority: " << bug.priority << "\n"
              << "severity: " << bug.severity << "\n"
              << "assigned_to: " << bug.assigned_to << "\n"
              << "project_id: " << bug.project_id << "\n"
              << "votes: " << bug.votes << std::endl;

    std::cout << "keywords: ";
    for(auto const& output : bug.keywords) {
        std::cout << output << ' ';
    }

    std::cout << "\ncclist: ";
    for(auto const& output : bug.cclist) {
        std::cout << output << ' ';
    }
}

void bug_xml::load(const std::string &filename)
{
    ptree pt;
    read_xml(filename, pt);
    BOOST_FOREACH(ptree::value_type &v, pt.get_child("bugs")) {
        read_user(v);
        read_bug(v);
        ptree temp = (ptree) v.second;
        std::cout << v.first << std::endl;
    }
}

#endif
