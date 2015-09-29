#include "kth_cprog_template_container.hpp"


class MyTestSuite : public CxxTest::TestSuite {
	public:
		void test1 () { //Testing the regular constructor.
			UIntVector<char> a((size_t)17);
		}
};


