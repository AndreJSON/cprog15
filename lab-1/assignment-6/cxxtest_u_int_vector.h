#include "u_int_vector.h"


class MyTestSuite : public CxxTest::TestSuite {
  public:
    void test1 () { //Testing the regular constructor.
      UIntVector a((size_t)10);
      //The size should obviously be 10 here.
      TS_ASSERT_EQUALS(a.size(), 10);
      //Just testing on some of the elements that they are indeed initialized to 0.
      TS_ASSERT_EQUALS(a[0], 0);
      TS_ASSERT_EQUALS(a[5], 0);
      TS_ASSERT_EQUALS(a[9], 0);
    }

    void test2 () { //Testing the copy constructor.
      UIntVector a((size_t)10);
      UIntVector b = a;
      UIntVector c(b);
      //They should have the same size.
      TS_ASSERT_EQUALS(a.size(),b.size());
      TS_ASSERT_EQUALS(b.size(),c.size());
      //They should have the same elements in the same positions as well. Only testing a few here though.
      TS_ASSERT_EQUALS(a[0], b[0]);
      TS_ASSERT_EQUALS(a[7], c[7]);
      TS_ASSERT_EQUALS(b[9], c[9]);
    }

    void test3 () { //Testing the move constructor.
      UIntVector a((size_t)10);
      a[0] = (unsigned int)82;
      a[5] = (unsigned int)99;
      a[9] = (unsigned int)10005;
      UIntVector b = std::move(a);
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

    void test4 () { //Testing the copy-assignment operator.
      UIntVector a((size_t)10);
      a[0] = (unsigned int)82;
      a[5] = (unsigned int)99;
      a[9] = (unsigned int)10005;
      UIntVector b((size_t)99);
      UIntVector c((size_t)2);
      c = a;
      b = a;
      a = a; //copy-ssigning a to itself.
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

    void test5 () {
      UIntVector a((size_t)10);
      a[0] = (unsigned int)82;
      a[5] = (unsigned int)99;
      a[9] = (unsigned int)10005;
      UIntVector b((size_t)99);
      UIntVector c((size_t)2);
      c = std::move(a);
      b = std::move(a);
      a = std::move(a); //move-assigning a to itself.
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

    void test6 () { //Testing the operator[] overload on const objects.
      UIntVector const a((size_t)10);
      //First and last element should be accesible and equal to 0.
      TS_ASSERT_EQUALS(a[0], 0);
      TS_ASSERT_EQUALS(a[9], 0);
      //Element at index 10 should be out of bounds since size is 10.
      TS_ASSERT_THROWS(a[10], std::out_of_range);
    }

    void test7 () { //Testing the operator[] overload
      UIntVector a((size_t)10);
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

    void test8 () { //Testing the reset member function.
      UIntVector a((size_t)10);
      a[0] = (unsigned int)82;
      a[5] = (unsigned int)99;
      a[9] = (unsigned int)10005;
      a.reset();
      //Now checking that the values have indeed been reset to 0.
      TS_ASSERT_EQUALS(a[0], 0);
      TS_ASSERT_EQUALS(a[5], 0);
      TS_ASSERT_EQUALS(a[9], 0);
      //Also checking that the size hasn't been modified.
      TS_ASSERT_THROWS(a[10], std::out_of_range);
    }

    void test9 () { //Testing the size member function.
      UIntVector a((size_t)0);
      UIntVector b((size_t)1);
      UIntVector c((size_t)10);
      UIntVector d((size_t)10000000);
      //They should now have size 0,1,10 respectively 10000000
      TS_ASSERT_EQUALS(a.size(),0);
      TS_ASSERT_EQUALS(b.size(),1);
      TS_ASSERT_EQUALS(c.size(),10);
      TS_ASSERT_EQUALS(d.size(),10000000);
    }

    void test10 () { //Just random testing.
      UIntVector a((size_t)10);
      a[0]++;
      TS_ASSERT_EQUALS(a[0],1);

      UIntVector const b((size_t)10);
      //b[0]++; //When not commented out this should give a compile error.
      b = b; //Not sure if this goes through compiler. it shouldnt do that i think.
      TS_ASSERT_EQUALS(b.size(),10);
      TS_ASSERT_EQUALS(b[0], 0);
    }

};


