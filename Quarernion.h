#ifndef  _QUATERNION_H_
#define  _QUATERNION_H_
#include "Vector4.h"

namespace LunarMath
{
	class Quaternion
	{
	public:
		Quaternion(const Vector3& eulerAngles);
		Quaternion(float X, float Y, float Z);

		Quaternion();
		Quaternion(float X, float Y, float Z, float W);
		Quaternion(const Vector4& xyzw);
		Quaternion(float XYZW);
		Quaternion(const Vector2& XY, float Z, float W);
		Quaternion(float X, const  Vector2& YZ, float W);
		Quaternion(float X, float Y, const Vector2& ZW);
		Quaternion(const Vector2& XY, const Vector2& ZW);
		Quaternion(float X, const Vector3& YZW);
		Quaternion(const Vector3& XYZ, float W);

		static Quaternion Slerp(const Quaternion& a, const Quaternion& b, float t);

		Vector3 Euler() const;
		static Vector3 Euler(const Quaternion& q);

		Quaternion Inverse() const;
		static Quaternion Inverse(const Quaternion& q);

		Quaternion& Invert();
		static Quaternion& Invert(Quaternion& q);

		Quaternion Conjugated() const;
		Quaternion& Conjugate();

		float Length() const;
		static float Length(const Quaternion& q);

		bool operator==(const Quaternion& o) const;
		bool operator!=(const Quaternion& o) const;

		Quaternion& operator/=(float f);
		Quaternion& operator*=(const Quaternion& o);
		Quaternion& operator*=(float f);
		Quaternion& operator+=(const Quaternion& q);
		Quaternion& operator-=(const Quaternion& q);

		float operator[](const int& i) const;
		float& operator[](const int& i);

		Quaternion operator/ (float f) const;
		Quaternion operator*(const Quaternion& o) const;
		Quaternion operator*(float f) const;
		Quaternion operator+(const Quaternion& b) const;
		Quaternion operator-(const Quaternion& q) const;		
	public:
		float x, y, z, w;
	};
};
#endif
