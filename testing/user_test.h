#ifndef USER_TEST
#define USER_TEST

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../backend/backend/src/user_controller.h"

class user_test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(user_test);

    // CPPUNIT_TEST(test_find_user_id);
    // CPPUNIT_TEST(test_get_user);
    // CPPUNIT_TEST(test_set_user);
    
    CPPUNIT_TEST_SUITE_END();
private:
    user_controller uc;
public:
    void setUp();
    void tearDown();
protected:
    void test_find_username();
    void test_authenticate();
    void test_get_user_info();
    void test_set_user_info();
    void test_update_user();
        
    // void test_empty();
    // void test_find_bug_id();
    // void test_get_bug_overview();
    // void test_get_complete_bug_info();
    // void test_set_bug_info();
    // void test_update_bug(); //stub
    //TODO : An implementation of test equals functions could be useful
};

#endif
