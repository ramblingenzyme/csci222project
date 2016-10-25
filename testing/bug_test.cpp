#include "bug_test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(bug_test);

void bug_test::setUp() {
    
    bc = Bug_Controller(); 
}

void bug_test::tearDown() {
    //cleanup if needed
}

void bug_test::test_empty() {
    CPPUNIT_ASSERT(bc.isEmpty());

    complete_bug_info cbi;
    cbi.title = "kwijibo";
    bc.set_bug_info(cbi);

    CPPUNIT_ASSERT(!bc.isEmpty());
}

void bug_test::test_get_bug_info() {
    CPPUNIT_ASSERT(bc.isEmpty());

    complete_bug_info cbi;
    cbi.title = "kwijibo";
    bc.set_bug_info(cbi);

    complete_bug_info cbi2 = bc.get_bug_info();
    CPPUNIT_ASSERT(!bc.isEmpty()); 
}
