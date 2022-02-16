#include "Vector2.h"

std::string LunarMath::Vector2::ToString() const
{
	std::ostringstream ss;
	ss << "LunarMath::Vector2(" << x << " , " << y << ')';
	return std::string(ss.str());
}

LunarMath::Vector2::Vector2()
{
	x = 0;
	y = 0;
}

LunarMath::Vector2::Vector2(const float& f)
{
	x = f; y = f;
}

LunarMath::Vector2::Vector2(const float& NewX, const float& NewY)
{
	x = NewX;
	y = NewY;
}

LunarMath::Vector2 LunarMath::Vector2::Up()
{
	return Vector2(0, 1);
}
LunarMath::Vector2 LunarMath::Vector2::Down()
{
	return Vector2(0, -1);
}
LunarMath::Vector2 LunarMath::Vector2::Right()
{
	return Vector2(1, 0);
}
LunarMath::Vector2 LunarMath::Vector2::Left()
{
	return Vector2(-1, 0);
}
LunarMath::Vector2 LunarMath::Vector2::Zero()
{
	return Vector2(0, 0);
}

float LunarMath::Vector2::Length() const
{
	return (float)sqrt(x * x + y * y);
}
float LunarMath::Vector2::Length(const Vector2& v)
{
	return (float)sqrt(v.x * v.x + v.y * v.y);
}

LunarMath::Vector2 LunarMath::Vector2::Normalized() const
{
	return Vector2(x, y) / Length();
}
LunarMath::Vector2 LunarMath::Vector2::Normalized(const Vector2& v)
{
	return v / v.Length();
}
LunarMath::Vector2& LunarMath::Vector2::Normalize(Vector2& v)
{
	v.Normalize();
	return v;
}
LunarMath::Vector2& LunarMath::Vector2::Normalize()
{
	float l = Length();
	x /= l;
	y /= l;

	return *this;
}

float LunarMath::Vector2::DotProduct(const Vector2& a, const Vector2& b)
{
	return a.x * b.x + a.y * b.y;
}

LunarMath::Vector2 LunarMath::Vector2::Lerp(const Vector2& a, const Vector2& b, float t)
{
	return a + ((b - a) * t);
}

float LunarMath::Vector2::operator[](const int& i) const
{
	int I = i;
#ifdef OVERFLOW_PROT
	I = i % 2;
#endif
	switch (I)
	{
	case 0:
		return x;
		break;
	case 1:
		return y;
		break;
	default:
		throw std::out_of_range("index was > 1");
		break;
	}

	return 0;
}

float& LunarMath::Vector2::operator[](const int& i)
{
	int I = i;
#ifdef OVERFLOW_PROT
	I = i % 2;
#endif
	switch (I)
	{
	case 0:
		return  x;
		break;
	case 1:
		return y;
		break;
	default:
		throw std::out_of_range("index was > 1");
		break;
	}

	return x;
}

LunarMath::Vector2& LunarMath::Vector2::operator=(const Vector2& v)
{
	x = v.x;
	y = v.y;
	return *this;
}

LunarMath::Vector2 LunarMath::Vector2::operator+(const Vector2& v) const
{
	return Vector2(x + v.x, y + v.y);
}
LunarMath::Vector2 LunarMath::Vector2::operator-(const Vector2& v) const
{
	return Vector2(x - v.x, y - v.y);
}
LunarMath::Vector2 LunarMath::Vector2::operator*(const float& c) const
{
	return Vector2(x * c, y * c);
}
LunarMath::Vector2 LunarMath::Vector2::operator/(const float& c) const
{
	return Vector2(x / c, y / c);
}

LunarMath::Vector2& LunarMath::Vector2::operator+=(const Vector2& v)
{
	x = x + v.x;
	y = y + v.y;
	return *this;
}
LunarMath::Vector2& LunarMath::Vector2::operator-=(const Vector2& v)
{
	x = x - v.x;
	y = y - v.y;
	return *this;
}
LunarMath::Vector2& LunarMath::Vector2::operator*=(const float& c)
{
	x = x * c;
	y = y * c;
	return *this;
}
LunarMath::Vector2& LunarMath::Vector2::operator/=(const float& c)
{
	x = x / c;
	y = y / c;
	return *this;
}

bool LunarMath::Vector2::operator!=(const Vector2& v) const
{
	return x != v.x || y != v.y;
}

bool LunarMath::Vector2::operator==(const Vector2& o) const
{
	return x == o.x && y == o.y;
}