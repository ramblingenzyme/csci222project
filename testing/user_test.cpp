#include "user_test.h"
#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION(user_test);

void user_test::setUp() {
    
    uc = user_controller(); 
}

void user_test::tearDown() {
    //cleanup if needed
}

void user_test::test_find_username() {
    std::string test_id = "666";
    std::string query1 = "SELECT * FROM USERS WHERE username='666';";
    std::string query2;

    CPPUNIT_ASSERT(!string_is_equal(query1, query2));

    query2 = uc.generate_find_username_query(test_id);

    CPPUNIT_ASSERT(string_is_equal(query1, query2));
}

void user_test::test_get_and_set_user_info() {
    user user1 = create_test_user();
    user user2;

    CPPUNIT_ASSERT(!user_is_equal(user1, user2));

    uc.set_user_info(user1);

    user2 = uc.get_user_info();

    CPPUNIT_ASSERT(user_is_equal(user1, user2));
}

void user_test::test_update_user() {
    user u = create_test_user();

    std::string query1 = "UPDATE users set username ='joey', password ='hunter2', email ='hunter2@hunter2.com', privilege_level ='0' where username ='joey';";
    std::string query2;
    
    CPPUNIT_ASSERT(!string_is_equal(query1, query2));

    uc.set_user_info(u);

    query2 = uc.generate_update_user_query();

    CPPUNIT_ASSERT(string_is_equal(query1, query2));
}

bool user_test::string_is_equal(std::string s1, std::string s2) {
        return s1 == s2;
}

user user_test::create_test_user() {
    user u;
    u.username = "joey";
    u.password = "hunter2";
    u.email = "hunter2@hunter2.com";
    u.privilege_level = "0";

    return u;
}

 bool user_test::user_is_equal(user& u1, user& u2) {
     if(u1.username != u2.username) return false;
     if(u1.password != u2.password) return false;
     if(u1.email != u2.email) return false;
     if(u1.privilege_level != u2.privilege_level) return false;

     return true;
 }


