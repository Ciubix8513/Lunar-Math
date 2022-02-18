#include "Vector3.h"

std::string LunarMath::Vector3::ToString() const
{
	std::ostringstream ss;
	ss << "LunarMath::Vector3(" << x << " , " << y << " , " << z << ')';
	return std::string(ss.str());
}

LunarMath::Vector3::Vector3(float f)
{
	x = y = z = f;
}

LunarMath::Vector3::Vector3(float NewX, float NewY, float NewZ)
{
	x = NewX;
	y = NewY;
	z = NewZ;
}
LunarMath::Vector3::Vector3(const Vector2& NewXY, float NewZ)
{
	x = NewXY.x;
	y = NewXY.y;
	z = NewZ;
}
LunarMath::Vector3::Vector3(float NewX, const Vector2& NewYZ)
{
	x = NewX;
	y = NewYZ.x;
	z = NewYZ.y;
}
LunarMath::Vector3::Vector3()
{
	x = y = z = 0;
}

LunarMath::Vector3 LunarMath::Vector3::Up()
{
	return Vector3(0, 1, 0);
}
LunarMath::Vector3 LunarMath::Vector3::Down()
{
	return Vector3(0, -1, 0);
}
LunarMath::Vector3 LunarMath::Vector3::Forward()
{
	return Vector3(0, 0, 1);
}
LunarMath::Vector3 LunarMath::Vector3::Backward()
{
	return Vector3(0, 0, -1);
}
LunarMath::Vector3 LunarMath::Vector3::Right()
{
	return Vector3(1, 0, 0);
}
LunarMath::Vector3 LunarMath::Vector3::Left()
{
	return Vector3(-1, 0, 0);
}
LunarMath::Vector3 LunarMath::Vector3::Zero()
{
	return Vector3(0, 0, 0);
}

float LunarMath::Vector3::Length() const
{
	return sqrt(x * x + y * y + z * z);
}
float LunarMath::Vector3::Length(const Vector3& v)
{
	return v.Length();
}

LunarMath::Vector3 LunarMath::Vector3::Normalized() const
{
	return Vector3(x, y, z) / Length();
}

LunarMath::Vector3& LunarMath::Vector3::Normalize()
{
	float l = Length();
	x /= l;
	y /= l;
	z /= l;
	return *this;
}

LunarMath::Vector3 LunarMath::Vector3::Normalized(const Vector3& v)
{
	return v.Normalized();
}

LunarMath::Vector3& LunarMath::Vector3::Normalize(Vector3& v)
{
	return v.Normalize();
}

float LunarMath::Vector3::DotProduct(const Vector3& a, const Vector3& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
LunarMath::Vector3 LunarMath::Vector3::CrossProduct(const Vector3& a, const Vector3& b)
{
	return Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

LunarMath::Vector3 LunarMath::Vector3::Lerp(const Vector3& a, const Vector3& b, float t)
{
	if (t < 0)
		t = 0;
	if (t > 1)
		t = 1;
	return a + ((b - a) * t);
}

float LunarMath::Vector3::operator[](const int& i) const
{
	int I = i;
#ifdef OVERFLOW_PROT
	I = i % 3;
#endif
	switch (I)
	{
	case 0:
		return x;
		break;
	case 1:
		return y;
		break;
	case 2:
		return z;
		break;
	default:
		throw std::out_of_range("index was > 1");
		break;
	}

	return 0;
}

float& LunarMath::Vector3::operator[](const int& i)
{
	int I = i;
#ifdef OVERFLOW_PROT
	I = i % 3;
#endif
	switch (I)
	{
	case 0:
		return  x;
		break;
	case 1:
		return y;
		break;
	case 2:
		return z;
		break;
	default:
		throw std::out_of_range("index was > 1");
		break;
	}

	return x;
}
LunarMath::Vector3& LunarMath::Vector3::operator=(Vector3 v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

LunarMath::Vector3 LunarMath::Vector3::operator+(const Vector3& v) const
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}
LunarMath::Vector3 LunarMath::Vector3::operator-(const Vector3& v) const
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}
LunarMath::Vector3 LunarMath::Vector3::operator*(float c) const
{
	return Vector3(x * c, y * c, z * c);
}
float LunarMath::Vector3::operator*(const Vector3& c) const
{
	return DotProduct(Vector3(x, y, z), c);
}
LunarMath::Vector3 LunarMath::Vector3::operator/(float c) const
{
	return Vector3(x / c, y / c, z / c);
}

LunarMath::Vector3& LunarMath::Vector3::operator+=(const Vector3& v)
{
	x = x + v.x;
	y = y + v.y;
	z = z + v.z;
	return *this;
}
LunarMath::Vector3& LunarMath::Vector3::operator-=(const Vector3& v)
{
	x = x - v.x;
	y = y - v.y;
	z = z - v.z;
	return *this;
}
LunarMath::Vector3& LunarMath::Vector3::operator*=(float c)
{
	x = x * c;
	y = y * c;
	z = z * c;
	return *this;
}
LunarMath::Vector3& LunarMath::Vector3::operator/=(float c)
{
	x = x / c;
	y = y / c;
	z = z / c;
	return *this;
}

bool LunarMath::Vector3::operator==(const Vector3& v) const
{
	return x == v.x && y == v.y && z == v.z;
}

bool LunarMath::Vector3::operator!=(const Vector3& v) const
{
	return x != v.x || y != v.y || z != v.z;
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