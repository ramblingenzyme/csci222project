#include "user_test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(user_test);

void user_test::setUp() {
    
    uc = user_controller(); 
}

void user_test::tearDown() {
    //cleanup if needed
}

void user_test::test_find_username() {
    std::string test_id = "666";

    uc.find_username(test_id);

    CPPUNIT_ASSERT(uc.username_is_equal(test_id));

    //TODO: insert more asserts
}

void user_test::test_get_user_info() {
    //user c = bc.create_test_user(): //TODO: Implement parent function

//No stored bug to compare to, so should not match yet
    //CPPUNIT_ASSERT(!cc.complete_bug_info_is_equal(c));

    //Should return test data that matches the above
    // cc.find_user_id(c.user_id);
    // CPPUNIT_ASSERT(cc.user_is_equal(c)); //TODO: Implement parent function
}

void user_test::test_set_user_info() {
    //stub

    // user c = cc.create_test_user(); //TODO: Implement parent

    //Stored user should be still empty, so they should not match
    //CPPUNIT_ASSERT(!cc.user_is_equal(c));

    // cc.set_user(c);

    // //Now the stored user and generated user should match
    // CPPUNIT_ASSERT(cc.complete_bug_info_is_equal(c));
}

void user_test::test_update_user() {
    //stub
}

// void void_test::test_set_bug_info() {
//     complete_bug_info bug = bc.create_test_complete_bug();

//     //Stored bug should be still empty, so they should not match
//     CPPUNIT_ASSERT(!bc.complete_bug_info_is_equal(bug));

//     bc.set_bug_info(bug);

//     //Now the stored bug and generated bug should match
//     CPPUNIT_ASSERT(bc.complete_bug_info_is_equal(bug));
// }

// void bug_test::test_get_complete_bug_info() {
//     complete_bug_info bug = bc.create_test_complete_bug();

//     //No stored bug to compare to, so should not match yet
//     CPPUNIT_ASSERT(!bc.complete_bug_info_is_equal(bug));

//     //Should return test data that matches the above
//     bc.find_bug_id(bug.bug_id);
//     CPPUNIT_ASSERT(bc.complete_bug_info_is_equal(bug));
// }

