#include "attachment_test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(attachment_test);

void attachment_test::setUp() {
    
    ac = attachment_controller(); //TODO: possibly wrong
}

void attachment_test::tearDown() {
    //cleanup if needed
}

void attachment_test::test_empty() {
    CPPUNIT_ASSERT(ac.isEmpty());

    attachment a1;
    a1.attach_id = 7;
    ac.set_attachment(a1);

    CPPUNIT_ASSERT(!ac.isEmpty());
}

void attachment_test::test_get_attachment() {
    CPPUNIT_ASSERT(ac.isEmpty());

    //set attachment to a test value, and add it to the object
    attachment a1;
    a1.attach_id = 7;
    ac.set_attachment(a1);
    CPPUNIT_ASSERT(!ac.isEmpty());

    //get attachment, and reset attachment controller object back to its initial state
    attachment a2 = ac.get_attachment();

    ac = attachment_controller();
    CPPUNIT_ASSERT(ac.isEmpty());

    ac.set_attachment(a2);
    CPPUNIT_ASSERT(!ac.isEmpty());

    //TODO: Should be a test equals or something here
}
