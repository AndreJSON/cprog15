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

static class TestDescription_suite_MyTestSuite_test1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 17, "test1" ) {}
 void runTest() { suite_MyTestSuite.test1(); }
} testDescription_suite_MyTestSuite_test1;

static class TestDescription_suite_MyTestSuite_test2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test2() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 34, "test2" ) {}
 void runTest() { suite_MyTestSuite.test2(); }
} testDescription_suite_MyTestSuite_test2;

static class TestDescription_suite_MyTestSuite_test3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test3() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 48, "test3" ) {}
 void runTest() { suite_MyTestSuite.test3(); }
} testDescription_suite_MyTestSuite_test3;

static class TestDescription_suite_MyTestSuite_test4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test4() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 58, "test4" ) {}
 void runTest() { suite_MyTestSuite.test4(); }
} testDescription_suite_MyTestSuite_test4;

static class TestDescription_suite_MyTestSuite_test5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test5() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 108, "test5" ) {}
 void runTest() { suite_MyTestSuite.test5(); }
} testDescription_suite_MyTestSuite_test5;

static class TestDescription_suite_MyTestSuite_test6 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test6() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 140, "test6" ) {}
 void runTest() { suite_MyTestSuite.test6(); }
} testDescription_suite_MyTestSuite_test6;

static class TestDescription_suite_MyTestSuite_test7 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test7() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 170, "test7" ) {}
 void runTest() { suite_MyTestSuite.test7(); }
} testDescription_suite_MyTestSuite_test7;

static class TestDescription_suite_MyTestSuite_test8 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test8() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 197, "test8" ) {}
 void runTest() { suite_MyTestSuite.test8(); }
} testDescription_suite_MyTestSuite_test8;

static class TestDescription_suite_MyTestSuite_test9 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test9() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 231, "test9" ) {}
 void runTest() { suite_MyTestSuite.test9(); }
} testDescription_suite_MyTestSuite_test9;

static class TestDescription_suite_MyTestSuite_test10 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test10() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 245, "test10" ) {}
 void runTest() { suite_MyTestSuite.test10(); }
} testDescription_suite_MyTestSuite_test10;

static class TestDescription_suite_MyTestSuite_test11 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test11() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 300, "test11" ) {}
 void runTest() { suite_MyTestSuite.test11(); }
} testDescription_suite_MyTestSuite_test11;

static class TestDescription_suite_MyTestSuite_testX1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testX1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 314, "testX1" ) {}
 void runTest() { suite_MyTestSuite.testX1(); }
} testDescription_suite_MyTestSuite_testX1;

static class TestDescription_suite_MyTestSuite_testX2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testX2() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 325, "testX2" ) {}
 void runTest() { suite_MyTestSuite.testX2(); }
} testDescription_suite_MyTestSuite_testX2;

static class TestDescription_suite_MyTestSuite_testX3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testX3() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 336, "testX3" ) {}
 void runTest() { suite_MyTestSuite.testX3(); }
} testDescription_suite_MyTestSuite_testX3;

static class TestDescription_suite_MyTestSuite_testX4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testX4() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 347, "testX4" ) {}
 void runTest() { suite_MyTestSuite.testX4(); }
} testDescription_suite_MyTestSuite_testX4;

static class TestDescription_suite_MyTestSuite_testTodaysDate : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testTodaysDate() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 358, "testTodaysDate" ) {}
 void runTest() { suite_MyTestSuite.testTodaysDate(); }
} testDescription_suite_MyTestSuite_testTodaysDate;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
