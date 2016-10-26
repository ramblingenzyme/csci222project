#ifndef BUG_TEST
#define BUG_TEST

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../backend/backend/src/bug_controller.h"

class bug_test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(bug_test);
    CPPUNIT_TEST(test_empty);
    CPPUNIT_TEST(test_find_bug_id);
    CPPUNIT_TEST(test_get_bug_overview);
    CPPUNIT_TEST_SUITE_END();
private:
    Bug_Controller bc;
public:
    void setUp();
    void tearDown();
protected:
    void test_empty();
    void test_find_bug_id();
    void test_get_bug_overview();
    void test_get_complete_bug_info();
    void test_set_bug_info();
    void test_update_bug();

    bool string_is_equal(std::string, std::string);
    complete_bug_info create_test_complete_bug();
    bug_overview create_test_bug_overview();
    bool bug_overview_is_equal(bug_overview& bo1, bug_overview& bo2);
    bool complete_bug_info_is_equal(complete_bug_info& cbug1, complete_bug_info& cbug2);
};

#endif

