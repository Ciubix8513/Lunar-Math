#include "Vector3.h"

Vector3::Vector3(float NewX, float NewY, float NewZ)
{
	x = NewX;
	y = NewY;
	z = NewZ;
}
Vector3::Vector3(Vector2 NewXY, float NewZ)
{
	x = NewXY.x;
	y = NewXY.y;
	z = NewZ;
}
Vector3::Vector3(float NewX, Vector2 NewYZ)
{
	x = NewX;
	y = NewYZ.x;
	z = NewYZ.y;
}
LunarMath::Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}
Vector3 LunarMath::Vector3::Up()
{
	return Vector3(0, 1, 0);
}
Vector3 LunarMath::Vector3::Down()
{
	return Vector3(0, -1, 0);
}
Vector3 LunarMath::Vector3::Forward()
{
	return Vector3(0, 0, 1);
}
Vector3 LunarMath::Vector3::Backward()
{
	return Vector3(0, 0, -1);
}
Vector3 LunarMath::Vector3::Right()
{
	return Vector3(1, 0, 0);
}
Vector3 LunarMath::Vector3::Left()
{
	return Vector3(-1, 0, 0);
}
Vector3 LunarMath::Vector3::Zero()
{
	return Vector3(0, 0, 0);
}

float LunarMath::Vector3::Length()
{
	return (float)sqrt(((double)x) * ((double)x) + ((double)y) * ((double)y) + ((double)z) * ((double)z));
}
float LunarMath::Vector3::Length(Vector3& v)
{
	return v.Length();
}

LunarMath::Vector3 LunarMath::Vector3::Normalized()
{
	return Vector3(x, y, z) / Length();
}

void LunarMath::Vector3::Normalize()
{
	x /= Length();
	y /= Length();
	z /= Length();
	return;
}

float LunarMath::Vector3::DotProduct(Vector3 a, Vector3 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
Vector3 LunarMath::Vector3::CrossProdut(Vector3 a, Vector3 b)
{
	return Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

Vector3 LunarMath::Vector3::Lerp(Vector3 a, Vector3 b, float t)
{
	if (t < 0)
		t = 0;
	if (t > 1)
		t = 1;
	return a * (1 - t) + b * t;
}

Vector3 LunarMath::Vector3::operator+(Vector3 v)
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}
Vector3 LunarMath::Vector3::operator-(Vector3 v)
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}
Vector3 LunarMath::Vector3::operator-(float c)
{
	return Vector3(x - c, y - c, z - c);
}
Vector3 LunarMath::Vector3::operator*(float c)
{
	return Vector3(x * c, y * c, z * c);
}
float LunarMath::Vector3::operator*(Vector3 c)
{
	return DotProduct(Vector3(x, y, z), c);
}
Vector3 LunarMath::Vector3::operator/(float c)
{
	return Vector3(x / c, y / c, z / c);
}

void LunarMath::Vector3::operator+=(Vector3 v)
{
	x = x + v.x;
	y = y + v.y;
	z = z + v.z;
	return;
}
void LunarMath::Vector3::operator-=(Vector3 v)
{
	x = x - v.x;
	y = y - v.y;
	z = z - v.z;
	return;
}
void LunarMath::Vector3::operator*=(float c)
{
	x = x * c;
	y = y * c;
	z = z * c;
	return;
}
void LunarMath::Vector3::operator/=(float c)
{
	x = x / c;
	y = y / c;
	z = z / c;
	return;
}

LunarMath::Vector3::operator DirectX::XMFLOAT3()
{
	return DirectX::XMFLOAT3(x, y, z);
}

bool LunarMath::Vector3::operator!=(Vector3 v)
{
	if (x == v.x && z == v.z && y == v.y)
		return false;
	return true;
}

LunarMath::Vector3int::Vector3int(int NewX, int NewY, int NewZ)
{
	x = NewX;
	y = NewY;
	z = NewZ;
}

LunarMath::Vector3int::Vector3int()
{
	x = 0;
	y = 0;
	z = 0;
}

bool LunarMath::Vector3int::operator==(Vector3int other)
{
	return x == other.x && y == other.y && z == other.z;
}

bool LunarMath::Vector3int::operator!=(Vector3int other)
{
	return x != other.x || y != other.y || z != other.z;
}

bool LunarMath::operator==(const Vector3int& lhs, const Vector3int& rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}