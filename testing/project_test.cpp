#include "project_test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(user_test);

void project_test::setUp() {
    uc = project_controller(); 
}

void project_test::tearDown() {
    //cleanup if needed
}

void project_test::test_find_project_id() {
    std::string test_id = "666";

    uc.find_projectname(test_id);

    CPPUNIT_ASSERT(uc.projectname_is_equal(test_id));

    //TODO: insert more asserts
}

void project_test::test_get_project() {
    //project c = bc.create_test_project(): //TODO: Implement parent function

//No stored bug to compare to, so should not match yet
    //CPPUNIT_ASSERT(!cc.complete_bug_info_is_equal(c));

    //Should return test data that matches the above
    // cc.find_project_id(c.project_id);
    // CPPUNIT_ASSERT(cc.project_is_equal(c)); //TODO: Implement parent function
}

void project_test::test_set_project() {
    //stub

    // project c = cc.create_test_project(); //TODO: Implement parent

    //Stored project should be still empty, so they should not match
    //CPPUNIT_ASSERT(!cc.project_is_equal(c));

    // cc.set_project(c);

    // //Now the stored project and generated project should match
    // CPPUNIT_ASSERT(cc.complete_bug_info_is_equal(c));
}

void project_test::test_update_project() {
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

