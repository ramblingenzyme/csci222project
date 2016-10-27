#ifndef PROJECT_TEST
#define PROJECT_TEST

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../backend/backend/src/project_controller.h"

class project_test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(project_test);

    CPPUNIT_TEST(test_find_project_id);
    CPPUNIT_TEST(test_get_and_set_project);
    CPPUNIT_TEST(test_update_project);
    
    CPPUNIT_TEST_SUITE_END();
private:
    project_controller pc;
public:
    void setUp();
    void tearDown();
protected:
    void test_find_project_id();
    void test_get_and_set_project();
    void test_update_project();

    bool string_is_equal(std::string s1, std::string s2);
    project create_test_project();
    bool project_is_equal(project& p1, project& p2);
    // void test_empty();
    // void test_find_bug_id();
    // void test_get_bug_overview();
    // void test_get_complete_bug_info();
    // void test_set_bug_info();
    // void test_update_bug(); //stub
    //TODO : An implementation of test equals functions could be useful
};

#endif
