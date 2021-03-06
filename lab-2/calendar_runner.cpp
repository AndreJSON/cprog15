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
#include "/home/andre/Coding/cpp/cprog15/lab-2/cxxtest_calendar.h"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "cxxtest_calendar.h", 9, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_testInitTime : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testInitTime() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 12, "testInitTime" ) {}
 void runTest() { suite_MyTestSuite.testInitTime(); }
} testDescription_suite_MyTestSuite_testInitTime;

static class TestDescription_suite_MyTestSuite_test1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 18, "test1" ) {}
 void runTest() { suite_MyTestSuite.test1(); }
} testDescription_suite_MyTestSuite_test1;

static class TestDescription_suite_MyTestSuite_test2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test2() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 26, "test2" ) {}
 void runTest() { suite_MyTestSuite.test2(); }
} testDescription_suite_MyTestSuite_test2;

static class TestDescription_suite_MyTestSuite_test3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test3() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 41, "test3" ) {}
 void runTest() { suite_MyTestSuite.test3(); }
} testDescription_suite_MyTestSuite_test3;

static class TestDescription_suite_MyTestSuite_testSpecific1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testSpecific1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 60, "testSpecific1" ) {}
 void runTest() { suite_MyTestSuite.testSpecific1(); }
} testDescription_suite_MyTestSuite_testSpecific1;

static class TestDescription_suite_MyTestSuite_testSpecific2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testSpecific2() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 74, "testSpecific2" ) {}
 void runTest() { suite_MyTestSuite.testSpecific2(); }
} testDescription_suite_MyTestSuite_testSpecific2;

static class TestDescription_suite_MyTestSuite_testSpecific3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testSpecific3() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 85, "testSpecific3" ) {}
 void runTest() { suite_MyTestSuite.testSpecific3(); }
} testDescription_suite_MyTestSuite_testSpecific3;

static class TestDescription_suite_MyTestSuite_testMem1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMem1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 94, "testMem1" ) {}
 void runTest() { suite_MyTestSuite.testMem1(); }
} testDescription_suite_MyTestSuite_testMem1;

static class TestDescription_suite_MyTestSuite_testMem2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMem2() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 107, "testMem2" ) {}
 void runTest() { suite_MyTestSuite.testMem2(); }
} testDescription_suite_MyTestSuite_testMem2;

static class TestDescription_suite_MyTestSuite_testPrint : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testPrint() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 114, "testPrint" ) {}
 void runTest() { suite_MyTestSuite.testPrint(); }
} testDescription_suite_MyTestSuite_testPrint;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
