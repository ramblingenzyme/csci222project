#ifndef BUG_TEST
#define BUG_TEST

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../backend/backend/src/bug_controller.h"

class bug_test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(bug_test);
    CPPUNIT_TEST(test_empty);
    CPPUNIT_TEST_SUITE_END();
private:
    Bug_Controller bc;
public:
    void setUp();
    void tearDown();
protected:
    void test_empty();
    void test_get_bug_info();
    //TODO : An implementation of test equals functions could be useful
};

#endif

