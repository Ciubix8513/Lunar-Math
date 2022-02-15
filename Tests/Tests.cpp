#include "CppUnitTest.h"
#include "../LunarMath.h"

using namespace LunarMath;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<> static std::wstring ToString<Vector2>(const class Vector2& v)
			{
				auto s = v.ToString();
				return std::wstring(s.begin(), s.end());
			}
		}
	}
}

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
			Vector2 v1 = Vector2::Normalized(v);
			Assert::AreEqual(v1, Vector2(1, 0));
			v1 = v.Normalized();
			Assert::AreEqual(v1, Vector2(1, 0));
			v1 = v.Normalize();
			Assert::AreEqual(v, Vector2(1, 0));
			Assert::AreEqual(v1, Vector2(1, 0));
			v = Vector2(2, 0);
			v1 = Vector2::Normalize(v);
			Assert::AreEqual(v, Vector2(1, 0));
			Assert::AreEqual(v1, Vector2(1, 0));
		};

		TEST_METHOD(DotProductTest)
		{
			Assert::AreEqual(vec2::Dot(vec2(1, 0), vec2(0, 1)), 0.0f);
			Assert::AreEqual(vec2::Dot(vec2(1, 0), vec2(1, 0)), 1.0f);
		};

		TEST_METHOD(EqualsTest)
		{
			Vector2 v = Vector2(1, 1);
			Assert::IsTrue(v == v);
		};

		TEST_METHOD(FloatOperatorsTest)
		{
			auto v = Vector2(2, 0);
			Assert::AreEqual(Vector2(1, 0), v / 2);
			Assert::AreEqual(Vector2(1, 0), v * .5f);
			auto v1 = v /= 2.0f;
			Assert::AreEqual(Vector2(1, 0), v1);
			Assert::AreEqual(Vector2(1, 0), v);

			v1 = v *= 2.0f;
			Assert::AreEqual(Vector2(2, 0), v1);
			Assert::AreEqual(Vector2(2, 0), v);
		};
		TEST_METHOD(VectorOperatorsTest)
		{
			auto v = Vector2(2, 0);
			Assert::AreEqual(Vector2(1, 0), v - Vector2(1, 0));
			Assert::AreEqual(Vector2(1, 0), v + Vector2(-1, 0));
			auto v1 = v -= Vector2(1, 0);
			Assert::AreEqual(Vector2(1, 0), v1);
			Assert::AreEqual(Vector2(1, 0), v);

			v1 = v += Vector2(1, 0);
			Assert::AreEqual(Vector2(2, 0), v1);
			Assert::AreEqual(Vector2(2, 0), v);
		}

		TEST_METHOD(VectorSubscriptTest)
		{
			auto v = Vector2(1, 2);
			Assert::AreEqual(1.0f, v[0]);
			Assert::AreEqual(2.0f, v[1]);

			v[0] += 1;
			Assert::AreEqual(2.0f, v[0]);
		}
	};
	/*TEST_CLASS(Vector3Tests)
	{
	public:
		TEST_METHOD(EqualsTest)
		{
		}
	};*/
}