#include "entities.h" 
#include <string> 

using namespace std;

/*REPORTER*/

Reporter::Reporter(){
	this->username = "";
	this->password = "";
	this->email = "";
	this->privilege_level = reporter;
}

Reporter::Reporter(const string u, const string p,
		   const string e){
	this->username = u;
	this->password = p;
	this->email = e;
	this->privilege_level = reporter;
}

Reporter::~Reporter(){}

string Reporter::get_username(){
	return this->username;
}

string Reporter::get_password(){
	return this->password;
}

string Reporter::get_email(){
	return this->email;
}

Rank Reporter::get_privilege_level(){
	return this->privilege_level;
}

void Reporter::set_password(string pass){
	this->password = pass; 
}


