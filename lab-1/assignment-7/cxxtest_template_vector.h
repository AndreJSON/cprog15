#include "kth_cprog_template_container.hpp"


class MyTestSuite : public CxxTest::TestSuite {
	public:
		void test1 () {
			Vector<std::string> a;
			TS_ASSERT_EQUALS(a.size(), 0);
		}

		void test2 () { //Testing the size_t constructor.
			Vector<char> a((size_t)17);
			TS_ASSERT_EQUALS(a.size(), 17);
		}

		void test3 () { //Testing the (size_t, value) constructor.
			Vector<int> a((size_t)17, 5);
			TS_ASSERT_EQUALS(a.size(), 17);
			TS_ASSERT_EQUALS(a[0], 5);
			TS_ASSERT_EQUALS(a[3], 5);
			TS_ASSERT_EQUALS(a[16], 5);
		}

		void test4 () { //Testing the initializer_list constructor.
			Vector<int> a = {1,3,-1,0};
			TS_ASSERT_EQUALS(a.size(), 4);
			TS_ASSERT_EQUALS(a[0], 1);
			TS_ASSERT_EQUALS(a[2], -1);
			TS_ASSERT_EQUALS(a[3], 0);
			TS_ASSERT_THROWS(a[4], std::out_of_range);
		}

		void testX () { //Testing the operator[] overload
			Vector<unsigned int> a((size_t)10);
			a[0] = (unsigned int)82;
			a[5] = (unsigned int)99;
			a[9] = (unsigned int)10005;
			TS_ASSERT_EQUALS(a[0], 82);
			TS_ASSERT_EQUALS(a[5], 99);
			TS_ASSERT_EQUALS(a[9], 10005);
			a.reset();
			TS_ASSERT_EQUALS(a[0], 0);
			TS_ASSERT_EQUALS(a[0], 0);
			TS_ASSERT_EQUALS(a[0], 0);
		}
};


