#!/bin/sh

g++ -o run_tests -std=c++11 attachment_test.cpp comment_test.cpp main.cpp -lcppunit -lpqxx
