#include "pch.h"
#include "CppUnitTest.h"
#include "../Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			MATRIX<int> A(1, 1);
			A.SetMij(1, 1, 2);
			MATRIX<int> B(1, 1);
			B.SetMij(1, 1, 2);
			Assert::AreEqual(A, B);
		}
	};
}
