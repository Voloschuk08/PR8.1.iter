#include "pch.h"

#include "CppUnitTest.h"
#include "../PR8.1/PR8.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81
{
	TEST_CLASS(UnitTest81)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Тест заміни "no" на "***"
			char str1[] = "hello no world";

			ReplaceNoWithStars(str1);

			Assert::AreEqual("hello no world", str1);
		}
	};
}
