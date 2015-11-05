/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite_init = false;
#include "/home/andre/Coding/cpp/cprog15/lab-2/cxxtest_date.h"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "cxxtest_date.h", 8, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_testInitTime : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testInitTime() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 11, "testInitTime" ) {}
 void runTest() { suite_MyTestSuite.testInitTime(); }
} testDescription_suite_MyTestSuite_testInitTime;

static class TestDescription_suite_MyTestSuite_test1G : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test1G() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 17, "test1G" ) {}
 void runTest() { suite_MyTestSuite.test1G(); }
} testDescription_suite_MyTestSuite_test1G;

static class TestDescription_suite_MyTestSuite_test1J : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test1J() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 34, "test1J" ) {}
 void runTest() { suite_MyTestSuite.test1J(); }
} testDescription_suite_MyTestSuite_test1J;

static class TestDescription_suite_MyTestSuite_test2G : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test2G() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 50, "test2G" ) {}
 void runTest() { suite_MyTestSuite.test2G(); }
} testDescription_suite_MyTestSuite_test2G;

static class TestDescription_suite_MyTestSuite_test2J : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test2J() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 64, "test2J" ) {}
 void runTest() { suite_MyTestSuite.test2J(); }
} testDescription_suite_MyTestSuite_test2J;

static class TestDescription_suite_MyTestSuite_test3G : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test3G() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 78, "test3G" ) {}
 void runTest() { suite_MyTestSuite.test3G(); }
} testDescription_suite_MyTestSuite_test3G;

static class TestDescription_suite_MyTestSuite_test3J : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test3J() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 88, "test3J" ) {}
 void runTest() { suite_MyTestSuite.test3J(); }
} testDescription_suite_MyTestSuite_test3J;

static class TestDescription_suite_MyTestSuite_test4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test4() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 97, "test4" ) {}
 void runTest() { suite_MyTestSuite.test4(); }
} testDescription_suite_MyTestSuite_test4;

static class TestDescription_suite_MyTestSuite_test5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test5() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 147, "test5" ) {}
 void runTest() { suite_MyTestSuite.test5(); }
} testDescription_suite_MyTestSuite_test5;

static class TestDescription_suite_MyTestSuite_test6G : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test6G() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 179, "test6G" ) {}
 void runTest() { suite_MyTestSuite.test6G(); }
} testDescription_suite_MyTestSuite_test6G;

static class TestDescription_suite_MyTestSuite_test6J : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test6J() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 211, "test6J" ) {}
 void runTest() { suite_MyTestSuite.test6J(); }
} testDescription_suite_MyTestSuite_test6J;

static class TestDescription_suite_MyTestSuite_test7 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test7() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 243, "test7" ) {}
 void runTest() { suite_MyTestSuite.test7(); }
} testDescription_suite_MyTestSuite_test7;

static class TestDescription_suite_MyTestSuite_test8 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test8() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 270, "test8" ) {}
 void runTest() { suite_MyTestSuite.test8(); }
} testDescription_suite_MyTestSuite_test8;

static class TestDescription_suite_MyTestSuite_test9 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test9() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 304, "test9" ) {}
 void runTest() { suite_MyTestSuite.test9(); }
} testDescription_suite_MyTestSuite_test9;

static class TestDescription_suite_MyTestSuite_test10 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test10() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 318, "test10" ) {}
 void runTest() { suite_MyTestSuite.test10(); }
} testDescription_suite_MyTestSuite_test10;

static class TestDescription_suite_MyTestSuite_test11 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test11() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 373, "test11" ) {}
 void runTest() { suite_MyTestSuite.test11(); }
} testDescription_suite_MyTestSuite_test11;

static class TestDescription_suite_MyTestSuite_testX1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testX1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 387, "testX1" ) {}
 void runTest() { suite_MyTestSuite.testX1(); }
} testDescription_suite_MyTestSuite_testX1;

static class TestDescription_suite_MyTestSuite_testX2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testX2() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 400, "testX2" ) {}
 void runTest() { suite_MyTestSuite.testX2(); }
} testDescription_suite_MyTestSuite_testX2;

static class TestDescription_suite_MyTestSuite_testX3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testX3() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 411, "testX3" ) {}
 void runTest() { suite_MyTestSuite.testX3(); }
} testDescription_suite_MyTestSuite_testX3;

static class TestDescription_suite_MyTestSuite_testX4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testX4() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 422, "testX4" ) {}
 void runTest() { suite_MyTestSuite.testX4(); }
} testDescription_suite_MyTestSuite_testX4;

static class TestDescription_suite_MyTestSuite_testX5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testX5() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 433, "testX5" ) {}
 void runTest() { suite_MyTestSuite.testX5(); }
} testDescription_suite_MyTestSuite_testX5;

static class TestDescription_suite_MyTestSuite_testX6 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testX6() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 446, "testX6" ) {}
 void runTest() { suite_MyTestSuite.testX6(); }
} testDescription_suite_MyTestSuite_testX6;

static class TestDescription_suite_MyTestSuite_testTodaysDate : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testTodaysDate() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 479, "testTodaysDate" ) {}
 void runTest() { suite_MyTestSuite.testTodaysDate(); }
} testDescription_suite_MyTestSuite_testTodaysDate;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
