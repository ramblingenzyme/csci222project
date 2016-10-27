#ifndef COMMENT_TEST
#define COMMENT_TEST

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../backend/backend/src/comment_controller.h"

class comment_test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(comment_test);

    CPPUNIT_TEST(test_find_comment_id);
    CPPUNIT_TEST(test_get_and_set_comment);
    CPPUNIT_TEST(test_update_comment);

    CPPUNIT_TEST_SUITE_END();
private:
    comment_controller cc;
public:
    void setUp();
    void tearDown();
protected:
    void test_find_comment_id();
    void test_get_and_set_comment();
    void test_update_comment();

    //Utility functions
    bool string_is_equal(std::string s1, std::string s2);
    comment create_test_comment();
    bool comment_is_equal(comment& c1, comment& c2);
};

#endif
