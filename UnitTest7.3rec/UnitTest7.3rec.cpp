#include "pch.h"
#include "CppUnitTest.h"
#include "../Project7.3REC/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73rec
{
	TEST_CLASS(UnitTest73rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int colCount = 3;
			int row[] = { 1, 2, 3 }; 
			int result = SumPositiveElements(row, colCount);
			Assert::AreEqual(2, result);
		}
	};
}
