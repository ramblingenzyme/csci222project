#ifndef ATTACHMENT_TEST
#define ATTACHMENT_TEST

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../backend/backend/src/attachment_controller.h"

class attachment_test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(attachment_test);
    CPPUNIT_TEST(test_empty);
    CPPUNIT_TEST(test_get_attachment);
    CPPUNIT_TEST_SUITE_END();
private:
    attachment_controller ac;
public:
    void setUp();
    void tearDown();
protected:
    void test_empty();
    void test_get_attachment();
    //TODO : An implementation of test equals functions could be useful
};

#endif

