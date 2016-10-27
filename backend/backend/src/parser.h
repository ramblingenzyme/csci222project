#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <string>
#include "return_types.h"
#include <iostream>


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
};

void bug_xml::read_comment(ptree::value_type &v, std::string bug_id){
    comment temp;

    BOOST_FOREACH(ptree::value_type const& f, v.second) {
        if(f.first == "long_desc") {
            temp.comment_id  = f.second.get<std::string>("commentid");
            temp.username = f.second.get<std::string>("who");
            temp.bug_id = bug_id;
            temp.creation_ts = f.second.get<std::string>("bug_when");
            temp.body = f.second.get<std::string>("thetext");
        }
    }

    print_comment(temp);
}

    std::cout << "comment: " << temp.comment_id << " " << temp.username << "\n"
        << temp.body << std::endl;
}
void bug_xml::read_user(ptree::value_type &v){
    user temp;
    ptree bugtree = (ptree) v.second;
    temp.username = bugtree.get<std::string>("assigned_to","");
    std::cout << "USER - username = " << temp.username << std::endl;
    temp.privilege_level = "developer";
    
    temp.privilege_level = "reporter";
    temp.username = bugtree.get<std::string>("reporter","");
    std::cout << "USER - username = " << temp.username << std::endl;
    try { BOOST_FOREACH(ptree::value_type &f, bugtree.get_child("cc")){
        std::cout << f.first.data() << std::endl;
        temp.username = f.second.data();
        std::cerr << "USER - username = " << temp.username << std::endl;
    } } catch (...) { std::cout << "Thrown " << std::endl;} 

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
    temp.project_id = "000000"; 
    temp.votes = bugtree.get<std::string>("votes");
    temp.keywords.push_back(bugtree.get<std::string>("keywords"));

    read_bug_cclist(v, temp);

    print_bug(temp);
}

void bug_xml::read_bug_cclist(ptree::value_type& v, complete_bug_info& temp) {
    BOOST_FOREACH(ptree::value_type const& f, v.second) {
        if(f.first == "cc") {
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
        //BOOST_FOREACH(ptree::value_type &f, pt.get_child("bug")
        std::cout << v.first << std::endl;
    //  BOOST_FOREACH(ptree::value_type &f, temp.get_child("long_desc")) {

    //      std::cout << f.first<< std::endl;
    //      read_comment(f);
    //  }
    }

}


