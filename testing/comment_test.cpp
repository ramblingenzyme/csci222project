#include "comment_test.h"
#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION(comment_test);

void comment_test::setUp() {
    
    cc = comment_controller(); 
}

void comment_test::tearDown() {
    //cleanup if needed
}

void comment_test::test_find_comment_id() {
    std::string test_id = "666";
    std::string query1 = "select * from COMMENT where comment_id=666;";
    std::string query2;

    CPPUNIT_ASSERT(!string_is_equal(query1, query2));

    query2 = cc.generate_find_comment_id_query(test_id);

    CPPUNIT_ASSERT(string_is_equal(query1, query2));
}

void comment_test::test_get_and_set_comment() {
    comment c1 = create_test_comment();
    comment c2;

    CPPUNIT_ASSERT(!comment_is_equal(c1, c2));

    cc.set_comment(c1);
    c2 = cc.get_comment();

    CPPUNIT_ASSERT(comment_is_equal(c1, c2));
}

void comment_test::test_update_comment() {
    comment comment = create_test_comment();

    std::string query1 = "UPDATE comment set comment_id=666, username='aUsername', bug_id=555, creation_ts='0', body='Yep, this is a comment', attach_id=0 where comment_id=666 AND bug_id=555;";
    std::string query2;

    CPPUNIT_ASSERT(!string_is_equal(query1, query2));

    cc.set_comment(comment);

    query2 = cc.generate_update_comment_query();

    CPPUNIT_ASSERT(string_is_equal(query1, query2));
}

 bool comment_test::string_is_equal(std::string s1, std::string s2) {
     return s1 == s2;
 }

comment comment_test::create_test_comment() {
    comment c;
    c.comment_id = "666";
    c.username = "aUsername";
    c.bug_id = "555";
    c.creation_ts = "0";
    c.body = "Yep, this is a comment";
    c.attach_id = "0";

    return c;
}

bool comment_test::comment_is_equal(comment& c1, comment& c2) {
    if(c1.comment_id != c2.comment_id) return false;
    if(c1.username != c2.username) return false;
    if(c1.bug_id != c2.bug_id) return false;
    if(c1.creation_ts != c2.creation_ts) return false;
    if(c1.body != c2.body) return false;
    if(c1.attach_id != c2.attach_id) return false;

    return true;
}

