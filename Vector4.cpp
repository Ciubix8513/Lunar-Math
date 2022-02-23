#include "Vector4.h"

std::string LunarMath::Vector4::ToString() const
{
	std::ostringstream ss;
	ss << "LunarMath::Vector4(" << x << " , " << y << " , " << z << " , " << w <<')';
	return std::string(ss.str());
}

LunarMath::Vector4::Vector4(float NewXYZW)
{
	x = NewXYZW;
	y = NewXYZW;
	z = NewXYZW;
	w = NewXYZW;
}

LunarMath::Vector4::Vector4(float NewX, float NewY, float NewZ, float NewW)
{
	x = NewX;
	y = NewY;
	z = NewZ;
	w = NewW;
}

LunarMath::Vector4::Vector4(const Vector2& NewXY, float NewZ, float NewW)
{
	x = NewXY.x;
	y = NewXY.y;
	z = NewZ;
	w = NewW;
}

LunarMath::Vector4::Vector4(const Vector2& NewXY,const Vector2& NewZW)
{
	x = NewXY.x;
	y = NewXY.y;
	z = NewZW.x;
	w = NewZW.y;
}

LunarMath::Vector4::Vector4(float NewX,const Vector2& NewYZ, float NewW)
{
	x = NewX;
	y = NewYZ.x;
	z = NewYZ.y;
	w = NewW;
}

LunarMath::Vector4::Vector4(float NewX, float NewY,const Vector2& NewZW)
{
	x = NewX;
	y = NewY;
	z = NewZW.x;
	w = NewZW.y;
}

LunarMath::Vector4::Vector4(float NewX,const Vector3& NewYZW)
{
	x = NewX;
	y = NewYZW.x;
	z = NewYZW.y;
	w = NewYZW.z;
}

LunarMath::Vector4::Vector4(const Vector3& NewXYZ, float NewW)
{
	x = NewXYZ.x;
	y = NewXYZ.y;
	z = NewXYZ.z;
	w = NewW;
}

LunarMath::Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

LunarMath::Vector4 LunarMath::Vector4::Up()
{
	return Vector4(0, 1, 0, 0);
}
LunarMath::Vector4 LunarMath::Vector4::Down()
{
	return Vector4(0, -1, 0, 0);
}
LunarMath::Vector4 LunarMath::Vector4::Forward()
{
	return Vector4(0, 0, 1, 0);
}
LunarMath::Vector4 LunarMath::Vector4::Backward()
{
	return Vector4(0, 0, -1, 0);
}
LunarMath::Vector4 LunarMath::Vector4::Right()
{
	return Vector4(1, 0, 0, 0);
}
LunarMath::Vector4 LunarMath::Vector4::Left()
{
	return Vector4(-1, 0, 0, 0);
}
LunarMath::Vector4 LunarMath::Vector4::Zero()
{
	return Vector4(0, 0, 0, 0);
}

float LunarMath::Vector4::Length() const
{
	return sqrt(x * x + y * y + z * z + w * w);
}
float LunarMath::Vector4::Length(const Vector4& v)
{
	return v.Length();
}

LunarMath::Vector4 LunarMath::Vector4::Normalized() const
{
	return Vector4(x, y, z, w) / Length();
}

LunarMath::Vector4 LunarMath::Vector4::Normalized(const Vector4& v)
{
	return v / v.Length();
}

LunarMath::Vector4& LunarMath::Vector4::Normalize(Vector4& v)
{
	v /= v.Length();
	return v;
}

LunarMath::Vector4& LunarMath::Vector4::Normalize()
{
	float l = Length();
	x /= l;
	y /= l;
	z /= l;
	w /= l;
	return *this;
}

float LunarMath::Vector4::DotProduct(const Vector4& a,const Vector4& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

LunarMath::Vector4 LunarMath::Vector4::Lerp(const Vector4& a, const Vector4& b, float t)
{
	if (t < 0)
		t = 0;
	if (t > 1)
		t = 1;
	return a + ((b - a) * t);
}

bool LunarMath::Vector4::operator==(const Vector4& v) const
{
	return x == v.x &&y == v.y&&z == v.z && w == v.w;
}

bool LunarMath::Vector4::operator!=(const Vector4& v) const
{
	return x == v.x || y == v.y || z == v.z || w == v.w;
}

LunarMath::Vector4 LunarMath::Vector4::operator+(const Vector4& v) const
{
	return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
}
LunarMath::Vector4 LunarMath::Vector4::operator-(const Vector4& v) const
{
	return Vector4(x - v.x, y - v.y, z - v.z, w - v.w);
}
LunarMath::Vector4 LunarMath::Vector4::operator*(float c) const
{
	return Vector4(x * c, y * c, z * c, w * c);
}
LunarMath::Vector4 LunarMath::Vector4::operator/(float c) const
{
	return Vector4(x / c, y / c, z / c, w * c);
}

float LunarMath::Vector4::operator*(const Vector4& v) const
{
	return x * v.x + y * v.y + z * v.z + w * v.w;
}


float LunarMath::Vector4::operator[](const int& i) const
{
	int I = i;
#ifdef OVERFLOW_PROT
	I = i % 4;
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
	case 3:
		return w;
		break;
	default:
		throw std::out_of_range("index was > 1");
		break;
	}

	return 0;
}

float& LunarMath::Vector4::operator[](const int& i)
{
	int I = i;
#ifdef OVERFLOW_PROT
	I = i % 4;
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
	case 3:
		return w;
		break;
	default:
		throw std::out_of_range("index was > 1");
		break;
	}

	return x;
}

LunarMath::Vector4& LunarMath::Vector4::operator+=(const Vector4& v)
{
	x = x + v.x;
	y = y + v.y;
	z = z + v.z;
	w = w + v.w;
	return *this;
}
LunarMath::Vector4& LunarMath::Vector4::operator-=(const Vector4& v)
{
	x = x - v.x;
	y = y - v.y;
	z = z - v.z;
	w = w - v.w;

	return *this;
}
LunarMath::Vector4& LunarMath::Vector4::operator*=(float c)
{
	x = x * c;
	y = y * c;
	z = z * c;
	w = w * c;
	return *this;
}
LunarMath::Vector4& LunarMath::Vector4::operator/=(float c)
{
	x = x / c;
	y = y / c;
	z = z / c;
	w = w * c;
	return *this;
}