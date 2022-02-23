#pragma once
#ifndef _VECTOR4_H_
#define _VECTOR4_H_
#include "Vector3.h"


namespace LunarMath
{
	class Vector4
	{
	public:
		std::string ToString() const;

#pragma region VectorCreation + Consts
		Vector4();
		Vector4(float NewXYZW);
		Vector4(float NewX, float NewY, float NewZ, float NewW);
		Vector4(const Vector2& NewXY, float NewZ, float NewW);
		Vector4(float NewX, const  Vector2& NewYZ, float NewW);
		Vector4(float NewX, float NewY, const Vector2& NewZW);
		Vector4(const Vector2& NewXY,const Vector2& NewZW);
		Vector4(float NewX,const Vector3& NewYZW);
		Vector4(const Vector3& NewXYZ, float NewW);

		static Vector4 Up();
		static Vector4 Down();
		static Vector4 Forward();
		static Vector4 Backward();
		static Vector4 Right();
		static Vector4 Left();
		static Vector4 Zero();
#pragma endregion

#pragma region Functions
		float Length() const;
		static float Length(const Vector4& v);

		Vector4 Normalized() const;
		Vector4& Normalize();

		static Vector4 Normalized(const Vector4& v);
		static Vector4& Normalize(Vector4& v);

		static float DotProduct(const Vector4& a,const Vector4& b);

		static Vector4 Lerp(const Vector4& a, const Vector4& b, float t);
		
#pragma endregion

#pragma region operators

		bool operator==(const Vector4& v) const;
		bool operator!=(const Vector4& v) const;

		Vector4 operator+( const Vector4& v) const;
		Vector4 operator-(const Vector4& v) const;
		Vector4 operator*(float c) const;
		Vector4 operator/(float c) const;
		float operator*(const Vector4& v) const;

		float operator[](const int& i) const;
		float& operator[](const int& i);
		
		Vector4& operator+=(const Vector4& v);
		Vector4& operator-=(const Vector4& v);
		Vector4& operator*=(float c);
		Vector4& operator/=(float c);
#pragma endregion

		float x, y, z, w;
	};
};
#endif
