#pragma once
#ifndef _VECTOR2_H_
#define _VECTOR2_H_
#include <math.h>
#include <sstream>
#include <string>
#include <exception>

//using namespace std;
#define Dot DotProduct 
#define norm Nomalize
#define normd Nomalized 
#define vec2 Vector2 

namespace LunarMath
{
#define Deg2Rad  0.0174532925f
#define PI (double) 3.1415926535897932384626433832795f	
	class  Vector2
	{
	public:
		std::string ToString() const;

#pragma region VectorCreation + Consts
		Vector2();
		Vector2(const float& f);
		Vector2(const float& NewX,const float& NewY);
		static Vector2 Up();
		static Vector2 Down();
		static Vector2 Right();
		static Vector2 Left();
		static Vector2 Zero();
#pragma endregion

#pragma region Functions
		float Length() const;
		static float Length(const Vector2& v);

		Vector2 Normalized() const;
		static Vector2 Normalized(const Vector2& v);

		static  Vector2& Normalize(Vector2& v);
		Vector2& Normalize();

		static float DotProduct(const Vector2& a,const Vector2& b);

#pragma endregion

#pragma region operators
		float operator[](const int& i) const;
		float& operator[](const int& i) ;
		Vector2& operator=(const Vector2& v);
		Vector2 operator+(const Vector2& v) const;
		Vector2 operator-(const Vector2& v) const;
		Vector2 operator*(const float& c) const;
		Vector2 operator/(const float& c) const;
		Vector2& operator+=(const Vector2& v);
		Vector2& operator-=(const Vector2& v);
		Vector2& operator*=(const float& c);
		Vector2& operator/=(const float& c);	

		bool operator!=(const Vector2& v) const;
		bool operator==(const Vector2& v) const;
#pragma endregion
		float x, y;
	};
};
#endif
