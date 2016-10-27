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
	void read_user(ptree::value_type &v);
	void read_comment(ptree::value_type &v);
};

void bug_xml::read_comment(ptree::value_type &v){
	comment temp;
	ptree commenttree = (ptree) v.second;

	temp.comment_id  = commenttree.get<std::string>("commentid");
	temp.username = commenttree.get<std::string>("who");
	temp.creation_ts = commenttree.get<std::string>("bug_when");
	temp.body = commenttree.get<std::string>("thetext");

	std::cout << "comment: " << temp.comment_id << " " << temp.username << "\n"
		<< temp.body << std::endl;
}
void bug_xml::read_user(ptree::value_type &v){
	user temp;
	ptree bugtree = (ptree) v.second;
	temp.username = bugtree.get<std::string>("assigned_to","");
	std::cout << "USER - username = " << temp.username << std::endl;
	temp.privilege_level = "2";
	
	temp.privilege_level = "1";
	temp.username = bugtree.get<std::string>("reporter","");
	std::cout << "USER - username = " << temp.username << std::endl;
	try { BOOST_FOREACH(ptree::value_type &f, bugtree.get_child("cc")){
		std::cout << f.first.data() << std::endl;
		temp.username = f.second.data();
		std::cerr << "USER - username = " << temp.username << std::endl;
	} } catch (...) { std::cout << "Thrown " << std::endl;} 

}
void bug_xml::read_bug(ptree::value_type &v){
	complete_bug_info temp;
	std::cout << std::endl<< std::endl;
	boost::property_tree::ptree bugtree = (boost::property_tree::ptree) v.second;
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
	temp.project_id = "nil";
	temp.votes = bugtree.get<std::string>("votes");
	
	std::cout << "bug id: " << temp.bug_id << "\n"
	     << "creation_ts: " << temp.creation_time << "\n"
	     << "delta_ts: "<< temp.delta_time << "\n"
	     << "title: " << temp.title << "\n"
	     << "description: " << temp.description << "\n"
	     << "product: " << temp.product << "\n"
	     << "component: " <<temp.component << "\n"
	     << "version: " << temp.version << "\n"
	     << "operating_system: " << temp.operating_system << "\n"
	     << "target_milestone: " << temp.target_milestone << "\n"
	     << "status: " << temp.status << "\n" 
	     << "duplicate_id: " << temp.duplicate_id << "\n"
	     << "priority: " << temp.priority << "\n"
	     << "severity: " << temp.severity << "\n"
	     << "assigned_to: " << temp.assigned_to << "\n"
	     << "project_id: " << temp.project_id << "\n"
	     << "votes: " << temp.votes << std::endl;
	
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
	//	BOOST_FOREACH(ptree::value_type &f, temp.get_child("long_desc")) {

	//		std::cout << f.first<< std::endl;
	//		read_comment(f);
	//	}
	}

}


