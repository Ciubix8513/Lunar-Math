#pragma once
#ifndef _VECTOR3_H_
#define _VECTOR3_H_
#include "Vector2.h"

#define vec3 Vector3

namespace LunarMath
{
	struct Vector3int
	{
	public:
		Vector3int(int NewX, int NewY, int NewZ);
		Vector3int();
		int x, y, z;
		bool operator==(Vector3int other);
		friend	bool operator==(const Vector3int& lhs, const Vector3int& rhs);
		bool operator!= (Vector3int other);
	};

	class Vector3
	{
	public:
		std::string ToString() const;

#pragma region VectorCreation + Consts
		Vector3(float f);
		Vector3(float NewX, float NewY, float NewZ);
		Vector3(const Vector2& NewXY, float NewZ);
		Vector3(float NewX, const Vector2& NewYZ);
		Vector3();

		static Vector3 Up();
		static Vector3 Down();
		static Vector3 Forward();
		static Vector3 Backward();
		static Vector3 Right();
		static Vector3 Left();
		static Vector3 Zero();

#pragma endregion

#pragma region Functions

		float Length() const;
		static float Length(const Vector3& v);

		Vector3 Normalized() const;
		Vector3& Normalize();

		static Vector3 Normalized(const Vector3& v);
		static Vector3& Normalize(Vector3& v);

		static float DotProduct(const Vector3& a, const Vector3& b);

		static Vector3 CrossProduct(const Vector3& a, const Vector3& b);
		static Vector3 Lerp(const Vector3& a, const Vector3& b, float t);
#pragma endregion

#pragma region operators
		float operator[](const int& i) const;
		float& operator[](const int& i);

		Vector3& operator=(Vector3 v);

		Vector3 operator+(const Vector3& v) const;
		Vector3 operator-(const Vector3& v) const;
		Vector3 operator*(float c) const;
		Vector3 operator/(float c) const;

		float operator*(const Vector3& c) const;

		Vector3& operator+=(const Vector3& v);
		Vector3& operator-=(const Vector3& v);
		Vector3& operator*=(float c);
		Vector3& operator/=(float c);

		bool operator==(const Vector3& v) const;
		bool operator!=(const Vector3& v) const;
#pragma endregion

		float x, y, z;
	};
};
#endif
