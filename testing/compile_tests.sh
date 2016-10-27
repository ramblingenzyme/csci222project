#!/bin/sh

g++ -o run_tests -std=c++11 attachment_test.cpp bug_test.cpp comment_test.cpp project_test.cpp user_test.cpp main.cpp -lcppunit -lpqxx
