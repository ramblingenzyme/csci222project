#include "project_test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(project_test);

void project_test::setUp() {
    pc = project_controller(); 
}

void project_test::tearDown() {
    //cleanup if needed
}

void project_test::test_find_project_id() {
    std::string test_id = "666";
    std::string query1 = "select * from PROJECT where project_id=666;";
    std::string query2;

    CPPUNIT_ASSERT(!string_is_equal(query1, query2));

    query2 = pc.generate_find_project_id_query(test_id);

    CPPUNIT_ASSERT(string_is_equal(query1, query2));
}

void project_test::test_get_and_set_project() {
    project project1 = create_test_project();
    project project2;

    CPPUNIT_ASSERT(!project_is_equal(project1, project2));

    pc.set_project(project1);

    project2 = pc.get_project();

    CPPUNIT_ASSERT(project_is_equal(project1, project2));
}

void project_test::test_update_project() {
    project p = create_test_project();
    
    std::string query1 = "UPDATE PROJECT set project_name='aProject', project_id='666' where project_id='666';";
    std::string query2;

    CPPUNIT_ASSERT(!string_is_equal(query1, query2));

    pc.set_project(p);

    query2 = pc.generate_update_project_query();

    CPPUNIT_ASSERT(string_is_equal(query1, query2));
}

bool project_test::string_is_equal(std::string s1, std::string s2) {
        return s1 == s2;
}

project project_test::create_test_project() {
    project p;
    p.project_name = "aProject";
    p.project_id = "666";

    return p;
}

bool project_test::project_is_equal(project& p1, project& p2) {
    if(p1.project_name != p2.project_name) return false;
    if(p1.project_id != p2.project_id) return false;

    return true;
}
