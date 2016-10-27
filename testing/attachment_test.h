#ifndef ATTACHMENT_TEST
#define ATTACHMENT_TEST

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../backend/backend/src/attachment_controller.h"

class attachment_test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(attachment_test);

    CPPUNIT_TEST(test_find_attach_id);
    CPPUNIT_TEST(test_get_and_set_attachment);
    CPPUNIT_TEST(test_update_attachment); 

    CPPUNIT_TEST_SUITE_END();
private:
    attachment_controller ac;
public:
    void setUp();
    void tearDown();
protected:
    void test_empty();
    void test_find_attach_id();
    void test_get_and_set_attachment();
    void test_update_attachment();

    bool string_is_equal(std::string s1, std::string s2) {
        return s1 == s2;
    }

    bool attachment_is_equal(attachment& a1, attachment& a2);
    attachment generate_test_attachment();
};

#endif

