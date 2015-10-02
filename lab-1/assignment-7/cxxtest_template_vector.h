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
			TS_ASSERT_EQUALS(a[0], (char)0);
			TS_ASSERT_EQUALS(a[5], (char)0);
			TS_ASSERT_EQUALS(a[16], (char)0);
			Vector<Vector<int>> b((size_t)10);
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

		void test9 () {
			Vector<unsigned int> a((size_t)10);
			auto count = 0;
			for (auto i = a.begin(); i != a.end(); i++) {
				count++;
			}
			TS_ASSERT_EQUALS(a.size(), count);
		}

		void test10 () { //Testing the find member function.
			Vector<int> a((size_t)10);
			a[0] = 13;
			a[7] = 6;
			a[9] = 1;
			TS_ASSERT_EQUALS(*(a.find(13)), 13);
			TS_ASSERT_EQUALS(*(a.find(6)), 6);
			TS_ASSERT_EQUALS(*(a.find(1)), 1);
			TS_ASSERT_EQUALS(a.find(55), a.end());
		}

		void test11 () { //Testing the operator[] overload on const objects.
			Vector<unsigned int> const a((size_t)10);
			//First and last element should be accesible and equal to 0.
			TS_ASSERT_EQUALS(a[0], 0);
			TS_ASSERT_EQUALS(a[9], 0);
			//Element at index 10 should be out of bounds since size is 10.
			TS_ASSERT_THROWS(a[10], std::out_of_range);
		}

		void test12 () { //Testing the operator[] overload
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

		void test13 () { //Testing the push_back member function.
			Vector<unsigned int> a((size_t)10);
			a[0] = (unsigned int)82;
			a[9] = (unsigned int)10005;
			TS_ASSERT_EQUALS(a[0], 82);
			TS_ASSERT_EQUALS(a[9], 10005);
			TS_ASSERT_THROWS(a[10], std::out_of_range);
			a.push_back((unsigned int)1337);
			TS_ASSERT_EQUALS(a[10], 1337);
		}

		void test14 () { //Testing the insert member function.
			Vector<int> a((size_t)10);
			a[0] = 3;
			a[5] = 7;
			a[9] = 6;
			TS_ASSERT_THROWS(a[10], std::out_of_range);
			TS_ASSERT_EQUALS(a.size(), 10);
			a.insert(5,10);
			TS_ASSERT_EQUALS(a[0], 3);
			TS_ASSERT_EQUALS(a[5], 10);
			TS_ASSERT_EQUALS(a[6], 7);
			TS_ASSERT_EQUALS(a[10], 6);
			TS_ASSERT_THROWS(a[11], std::out_of_range);
			TS_ASSERT_EQUALS(a.size(), 11);
			//Now try to insert at the last index.
			a.insert(10,55);
			TS_ASSERT_EQUALS(a[10], 55);
			TS_ASSERT_EQUALS(a[11], 6);
			TS_ASSERT_THROWS(a[12], std::out_of_range);
			TS_ASSERT_EQUALS(a.size(), 12);
			//Also insert at the first index.
			a.insert(0,13);
			TS_ASSERT_EQUALS(a[0], 13);
			TS_ASSERT_EQUALS(a[1], 3);
			TS_ASSERT_EQUALS(a.size(), 13);
			//Now try to insert outside of the array.
			TS_ASSERT_THROWS(a.insert(13, 67), std::out_of_range);
			TS_ASSERT_EQUALS(a.size(), 13);
		}

		void test15 () { //Testing the erase member function.
			Vector<int> a((size_t)10);
			a[0] = 3;
			a[1] = 5;
			a[7] = 7;
			a[8] = 1;
			a[9] = 6;
			a.erase(8);
			a.erase(8);
			a.erase(0);
			TS_ASSERT_EQUALS(a.size(), 7);
			TS_ASSERT_THROWS(a.erase(7), std::out_of_range);
			TS_ASSERT_EQUALS(a[6], 7);
			Vector<int> b;
			TS_ASSERT_THROWS(b.erase(0), std::out_of_range);
		}

		void test16 () { //Testing clear.
			Vector<int> a((size_t)10);
			a.clear();
			TS_ASSERT_THROWS(a[0], std::out_of_range);
		}

		void test17 () { //Testing reset.
			Vector<int> a((size_t)10);
			a[0] = 3;
			a[9] = 6;
			a.reset();
			TS_ASSERT_EQUALS(a[0], 0);
			TS_ASSERT_EQUALS(a[9], 0);
		}

		void test18 () {
			//Code copied from the lab directory, I'll deal with turning this into actual testcode later.
			/*Vector<double> v;           // ok: defaultkonstruktor ger vektor med flyttal
		    Vector<char> *a = new Vector<char>[3];  // dynamiskt allokerade ser ut så här
		    delete [] a;

		    assert(v.size() == 0);      // tom från början
		    v.push_back(3.14);          // lägg till ett element sist 
		    assert(v.size() == 1);      // nu ligger ett element i vektorn
		    v.insert(0, 2.10);          // lägg till före element 0, dvs först
		    assert(v[0] == 2.10 &&      // hamnade de rätt?
			   v[1] == 3.14);       
		    assert(v.size() == 2);      // nu ligger två element i vektorn
		    v.sort(false);              // sortera i fallande ordning
		    assert(v[0] == 3.14 &&      // hamnade de rätt?
			   v[1] == 2.10);       
		    assert(v.size() == 2);      // ingenting ändrat?
		    v[1] = 2.11;                // tilldelning av enstaka element;

		    const Vector<double> &vc = v;  // skapa konstant referens
		    assert(vc.size() == 2);     // ok: ändrar ej vektorn som är konstant
		    assert(vc[0] == 3.14 &&     // ok: ändrar ej vektorn som är konstant
			   vc[1] == 2.11);
		    
		    v.erase(0);                 // ta bort första elementet               
		    assert(v.size() == 1);      // rätt antal elelment
		    v.clear();                  // töm hela vektorn
		    assert(v.size() == 0);      // tom när alla element är borttagna
		    
		    
		    // kontrollera att följande rader inte går att kompilera
		    vc[0] = 3.1415;             // fel: tilldelning av konstant objekt
		    Vector<char> c = v;         // fel: tilldelning av olika typer*/
		}
};