#include "parser.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
	cout << "reading" << endl;
	bug_xml reader;
	string filename = "BugReports.xml";
	reader.load(filename);
	return 0;
}
