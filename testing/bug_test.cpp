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

void bug_test::test_find_bug_id() {
    std::string test_id = "666";
    std::string query1 = "SELECT * FROM BUGS WHERE BUG_ID=666;";
    std::string query2;

    CPPUNIT_ASSERT(!string_is_equal(query1, query2));

    query2 = bc.generate_find_bug_id_query(test_id);

    CPPUNIT_ASSERT(string_is_equal(query1, query2));
}

void bug_test::test_get_bug_overview() {
    bug_overview bug1 = create_test_bug_overview();
    bug_overview bug2;
    complete_bug_info cbi;
    
    CPPUNIT_ASSERT(!bug_overview_is_equal(bug1, bug2));

    cbi = create_test_complete_bug();
    bc.set_bug_info(cbi);
    bug2 = bc.get_bug_overview();

    CPPUNIT_ASSERT(bug_overview_is_equal(bug1, bug2));
}

void bug_test::test_get_complete_bug_info() {
    complete_bug_info bug1 = create_test_complete_bug();
    complete_bug_info bug2;

    CPPUNIT_ASSERT(!complete_bug_info_is_equal(bug1, bug2));

    bug2 = create_test_complete_bug();

    CPPUNIT_ASSERT(complete_bug_info_is_equal(bug1, bug2));
}

void bug_test::test_set_bug_info() {
    complete_bug_info bug1 = create_test_complete_bug();
    complete_bug_info bug2;

    CPPUNIT_ASSERT(complete_bug_info_is_equal(bug1, bug2));

    bc.set_bug_info(bug1);
    bug2 = bc.get_bug_info();

    CPPUNIT_ASSERT(complete_bug_info_is_equal(bug1, bug2));
}

void bug_test::test_update_bug() {
    complete_bug_info bug1 = create_test_complete_bug();
    complete_bug_info bug2;

    bc.set_bug_info(bug1);

    std::string query = bc.generate_update_bug_query();

    bug2.bug_id = "12345";
    bc.set_bug_info(bug2);

    std::string query2 = bc.generate_update_bug_query();

    //The two queries should not be equal
    CPPUNIT_ASSERT(!string_is_equal(query, query2));

    bug2 = create_test_complete_bug();
    bc.set_bug_info(bug2);
    query2 = bc.generate_update_bug_query();

    //Now they should be equal
    CPPUNIT_ASSERT(string_is_equal(query, query2));
}

complete_bug_info bug_test::create_test_complete_bug() {
    complete_bug_info cbug;
    cbug.bug_id = "666";
    cbug.creation_time = "0"; 
    cbug.delta_time = "0";
    cbug.title = "aTitle";
    cbug.description = "aDescription";
    cbug.product = "aProduct";
    cbug.component = "aComponent";
    cbug.version = "aVersion";
    cbug.operating_system = "gentoo";
    cbug.target_milestone = "aMilestone"; 
    cbug.status = "normal";
    cbug.duplicate_id = "NULL"; 
    cbug.priority = "normal";
    cbug.severity = "normal";
    cbug.reporter = "aReporter"; 
    cbug.assigned_to = "billyBob"; 
    cbug.project_id = "555";
    cbug.votes = "0";

    return cbug;
}

bug_overview bug_test::create_test_bug_overview() {
    bug_overview bugo;

    bugo.bug_id = "666";
    bugo.title = "aTitle";
    bugo.product = "aProduct";
    bugo.component = "aComponent";
    bugo.version = "aVersion";
    bugo.priority = "normal";
    bugo.severity = "normal";
    bugo.status = "normal";

    return bugo;
}

bool bug_test::bug_overview_is_equal(bug_overview& bo1, bug_overview& bo2) {
    if(bo1.bug_id != bo2.bug_id)
        return false;
    if(bo1.title != bo2.title)
        return false;
    if(bo1.product != bo2.product)
        return false;
    if(bo1.component != bo2.component)
        return false;
    if(bo1.version != bo2.version)
        return false;
    if(bo1.priority != bo2.priority)
        return false;
    if(bo1.severity != bo2.severity)
        return false;
    if(bo1.status != bo2.status)
        return false;

    return true;
}

bool bug_test::complete_bug_info_is_equal(complete_bug_info& cbug1, complete_bug_info& cbug2) {
    if(cbug1.bug_id != cbug2.bug_id)
        return false;
    if(cbug1.creation_time != cbug2.creation_time)
        return false;
    if(cbug1.delta_time != cbug2.delta_time)
        return false;
    if(cbug1.title != cbug2.title)
        return false;
    if(cbug1.description != cbug2.description)
        return false;
    if(cbug1.product != cbug2.product)
        return false;
    if(cbug1.component != cbug2.component)
        return false;
    if(cbug1.version != cbug2.version)
        return false;
    if(cbug1.operating_system != cbug2.operating_system)
        return false;
    if(cbug1.target_milestone != cbug2.target_milestone)
        return false;
    if(cbug1.status != cbug2.status)
        return false;
    if(cbug1.duplicate_id != cbug2.duplicate_id)
        return false;
    if(cbug1.priority != cbug2.priority)
        return false;
    if(cbug1.severity != cbug2.severity)
        return false;
    if(cbug1.reporter != cbug2.reporter)
        return false;
    if(cbug1.assigned_to != cbug2.assigned_to)
        return false;
    if(cbug1.project_id != cbug2.project_id)
        return false;
    if(cbug1.votes != cbug2.votes)
        return false;

    return true;
}

bool bug_test::string_is_equal(std::string s1, std::string s2) {
        return s1 == s2;
}




