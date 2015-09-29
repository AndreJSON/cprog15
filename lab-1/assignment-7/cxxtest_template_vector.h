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

		void test5 () { //Testing the copy constructor.
			Vector<char> a((size_t)10);
			Vector<char> b = a;
			Vector<char> c(b);
			//They should have the same size.
			TS_ASSERT_EQUALS(a.size(),b.size());
			TS_ASSERT_EQUALS(b.size(),c.size());
			//They should have the same elements in the same positions as well. Only testing a few here though.
			TS_ASSERT_EQUALS(a[0], b[0]);
			TS_ASSERT_EQUALS(a[7], c[7]);
			TS_ASSERT_EQUALS(b[9], c[9]);
		}

		void test6 () { //Testing the move constructor.
			Vector<unsigned int> a((size_t)10);
			a[0] = (unsigned int)82;
			a[5] = (unsigned int)99;
			a[9] = (unsigned int)10005;
			Vector<unsigned int> b = std::move(a);
			TS_ASSERT_EQUALS(b[0], 82);
			TS_ASSERT_EQUALS(b[5], 99);
			TS_ASSERT_EQUALS(b[9], 10005);
			//Change values of the moved UIntVector and then check that it still behaves properly.
			b[0] = (unsigned int)0;
			b[5] = (unsigned int)1;
			b[9] = (unsigned int)2;
			TS_ASSERT_EQUALS(b[0], 0);
			TS_ASSERT_EQUALS(b[5], 1);
			TS_ASSERT_EQUALS(b[9], 2);
		}

		void test7 () { //Testing the copy-assignment operator.
			Vector<unsigned int> a((size_t)10);
			a[0] = (unsigned int)82;
			a[5] = (unsigned int)99;
			a[9] = (unsigned int)10005;
			Vector<unsigned int> b((size_t)99);
			Vector<unsigned int> c((size_t)2);
			c = a;
			b = a;
			a = a; //copy-assigning a to itself.
			//Now test so that all values are what they should be.
			TS_ASSERT_EQUALS(a[0], 82);
			TS_ASSERT_EQUALS(a[5], 99);
			TS_ASSERT_EQUALS(a[9], 10005);
			TS_ASSERT_EQUALS(b[0], 82);
			TS_ASSERT_EQUALS(b[5], 99);
			TS_ASSERT_EQUALS(b[9], 10005);
			TS_ASSERT_EQUALS(c[0], 82);
			TS_ASSERT_EQUALS(c[5], 99);
			TS_ASSERT_EQUALS(c[9], 10005);
			//Also make sure b has been downsized to the size of a.
			TS_ASSERT_THROWS(b[10], std::out_of_range);
			TS_ASSERT_EQUALS(b.size(), 10);
		}

		void test8 () { //Testing the move-assignment operator.
			Vector<unsigned int> a((size_t)10);
			a[0] = (unsigned int)82;
			a[5] = (unsigned int)99;
			a[9] = (unsigned int)10005;
			Vector<unsigned int> b((size_t)99);
			Vector<unsigned int> c((size_t)2);
			c = std::move(a);
			b = std::move(a);
			a = std::move(a); //move-assigning a to itself.
			//Now test so that all values are what they should be.
			TS_ASSERT_EQUALS(c[0], 82);
			TS_ASSERT_EQUALS(c[5], 99);
			TS_ASSERT_EQUALS(c[9], 10005);
			TS_ASSERT_EQUALS(b.size(), 0);
			TS_ASSERT_EQUALS(a.size(), 0);
			TS_ASSERT_THROWS(a[0], std::out_of_range);
			TS_ASSERT_THROWS(b[0], std::out_of_range);
			//Also make sure b has been downsized to the size of a.
			TS_ASSERT_THROWS(c[10], std::out_of_range);
			TS_ASSERT_EQUALS(c.size(), 10);
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


