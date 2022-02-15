#include "CppUnitTest.h"
#include "../LunarMath.h"

using namespace LunarMath;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Vector2Tests)
	{
	public:

		
		TEST_METHOD(ConstructorTest)
		{
			auto v = Vector2();
			Assert::AreEqual(0.0f, v.x);
			Assert::AreEqual(0.0f, v.y);
			v = Vector2(1);
			Assert::AreEqual(1.0f, v.x);
			Assert::AreEqual(1.0f, v.y);
			v = Vector2(2, 2);
			Assert::AreEqual(2.0f, v.x);
			Assert::AreEqual(2.0f, v.y);
		};
		TEST_METHOD(AsignmentTest)
		{
			Vector2 v, v1;
			v = v1 = Vector2(1, 0);
			v == v1;
			Assert::AreEqual(v1, v);

		};

		TEST_METHOD(LengthTests)
		{
			auto v = Vector2();
			Assert::AreEqual(0.0f, v.Length());
			v = Vector2(1, 0);
			Assert::AreEqual(1.0f, v.Length());
			Assert::AreEqual(1.0f, Vector2::Length(v));
		};
		TEST_METHOD(NormalizeTests)
		{
			auto v = Vector2(10, 0);
			

		};	

		TEST_METHOD(EqualsTest)
		{
			Vector2 v = Vector2(1, 1);			
			Assert::IsTrue(v == v);
		};
		


	};
	/*TEST_CLASS(Vector3Tests)
	{
	public:
		TEST_METHOD(EqualsTest)
		{
			
		}
	};*/

}
