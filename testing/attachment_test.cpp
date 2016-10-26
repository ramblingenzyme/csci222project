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
    a1.attach_id = "666";
    ac.set_attachment(a1);

    CPPUNIT_ASSERT(!ac.isEmpty());
}

void attachment_test::test_find_attach_id() {
    std::string test_id = "666";
    std::string test_query = "select * from ATTACHMENT where attach_id=666;";
    std::string returned_query;

    //Query should not be equal yet
    CPPUNIT_ASSERT(!string_is_equal(test_query, returned_query));
    
    returned_query = ac.generate_find_attach_id_query(test_id);

    //Query should now be equal
    CPPUNIT_ASSERT_EQUAL(test_query, returned_query);
}

void attachment_test::test_get_attachment() {
    //Set attachment to a test value, and add it to the object
    attachment a1, a2;
    a1.attach_id = 7;
    ac.set_attachment(a1);

    //Should not yet be equal
    CPPUNIT_ASSERT(!attachment_is_equal(a1, a2));

    a2 = ac.get_attachment();

    //Now should be equal
    CPPUNIT_ASSERT(attachment_is_equal(a1, a2));
}

void attachment_test::test_set_attachment() {
    attachment a1;
    a1.attach_id = "666";
    ac.set_attachment(a1);

    attachment a2;

    //Attachment id of first object should not match that of the second
    CPPUNIT_ASSERT(!ac.attachment_id_is_equal(a2.attach_id));

    a2 = ac.get_attachment();

    //Now it should
    CPPUNIT_ASSERT(ac.attachment_id_is_equal(a1.attach_id));
}

void attachment_test::test_update_attachment() {
    attachment a1 = generate_test_attachment();
    attachment a2;
    ac.set_attachment(a1);

    std::string query = ac.generate_update_attachment_query();

    a2.attach_id = "12345";
    ac.set_attachment(a2);

    std::string query2 = ac.generate_update_attachment_query();

    //The two queries should not be equal
    CPPUNIT_ASSERT(!string_is_equal(query, query2));

    a2 = generate_test_attachment();
    ac.set_attachment(a2);
    query2 = ac.generate_update_attachment_query();

    //Now the should be equal
    CPPUNIT_ASSERT(string_is_equal(query, query2));
}

bool attachment_test::attachment_is_equal(attachment& a1, attachment& a2) {
    if(a1.attach_id != a2.attach_id) return false;
    if(a1.creation_ts != a2.creation_ts) return false;
    if(a1.delta_ts != a2.delta_ts) return false;
    if(a1.description != a2.description) return false;
    if(a1.filename != a2.filename) return false;
    if(a1.filesize != a2.filesize) return false;
    if(a1.file != a2.file) return false;
    if(a1.attacher != a2.attacher) return false;

    return true;
}

attachment attachment_test::generate_test_attachment() {
    attachment a1;
    a1.attach_id = "666";
    a1.creation_ts = "0";
    a1.delta_ts = "0";
    a1.description = "none";
    a1.filename = "nothing.tar";
    a1.filesize = "0";
    a1.file = "55";
    a1.attacher = "billy";

    return a1;
}

     



