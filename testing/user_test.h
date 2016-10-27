#ifndef USER_TEST
#define USER_TEST

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../backend/backend/src/user_controller.h"

class user_test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(user_test);

    CPPUNIT_TEST(test_find_username);
    CPPUNIT_TEST(test_get_and_set_user_info);
    CPPUNIT_TEST(test_update_user);
    
    CPPUNIT_TEST_SUITE_END();
private:
    user_controller uc;
public:
    void setUp();
    void tearDown();
protected:
    void test_find_username();
    void test_get_and_set_user_info();
    void test_update_user();

    bool string_is_equal(std::string s1, std::string s2);
    user create_test_user();
    bool user_is_equal(user& u1, user& u2);
};

#endif
