#include "Vector4.h"

LunarMath::Vector4::Vector4(float NewX, float NewY, float NewZ, float NewW)
{
	x = NewX;
	y = NewY;
	z = NewZ;
	w = NewW;
}

LunarMath::Vector4::Vector4(Vector2 NewXY, float NewZ, float NewW)
{
	x = NewXY.x;
	y = NewXY.y;
	z = NewZ;
	w = NewW;
}

LunarMath::Vector4::Vector4(Vector2 NewXY, Vector2 NewZW)
{
	x = NewXY.x;
	y = NewXY.y;
	z = NewZW.x;
	w = NewZW.y;
}

LunarMath::Vector4::Vector4(float NewX, Vector2 NewYZ, float NewW)
{
	x = NewX;
	y = NewYZ.x;
	z = NewYZ.y;
	w = NewW;
}

LunarMath::Vector4::Vector4(float NewX, float NewY, Vector2 NewZW)
{
	x = NewX;
	y = NewY;
	z = NewZW.x;
	w = NewZW.y;
}

LunarMath::Vector4::Vector4(float NewX, Vector3 NewYZW)
{
	x = NewX;
	y = NewYZW.x;
	z = NewYZW.y;
	w = NewYZW.z;
}

LunarMath::Vector4::Vector4(Vector3 NewXYZ, float NewW)
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

Vector4 LunarMath::Vector4::Up()
{
	return Vector4(0, 1, 0, 0);
}
Vector4 LunarMath::Vector4::Down()
{
	return Vector4(0, -1, 0, 0);
}
Vector4 LunarMath::Vector4::Forward()
{
	return Vector4(0, 0, 1, 0);
}
Vector4 LunarMath::Vector4::Backward()
{
	return Vector4(0, 0, -1, 0);
}
Vector4 LunarMath::Vector4::Right()
{
	return Vector4(1, 0, 0, 0);
}
Vector4 LunarMath::Vector4::Left()
{
	return Vector4(-1, 0, 0, 0);
}
Vector4 LunarMath::Vector4::Zero()
{
	return Vector4(0, 0, 0, 0);
}

float LunarMath::Vector4::Length()
{
	return (float)sqrt(((double)x) * ((double)x) + ((double)y) * ((double)y) + ((double)z) * ((double)z) + ((double)w) * ((double)w));
}
float LunarMath::Vector4::Length(Vector4& v)
{
	return v.Length();
}

LunarMath::Vector4 LunarMath::Vector4::Normalized()
{
	return Vector4(x, y, z, w) / Length();
}
void LunarMath::Vector4::Normalize(Vector4& v)
{
	v /= v.Length();
	return;
}
void LunarMath::Vector4::Normalize()
{
	x /= Length();
	y /= Length();
	z /= Length();
	w /= Length();
	return;
}

float LunarMath::Vector4::DotProduct(Vector4 a, Vector4 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

Vector3 LunarMath::Vector4::XYZ()
{
	return Vector3(x, y, z);
}

Vector2 LunarMath::Vector4::XY()
{
	return Vector2(x, y);
}

Vector4 LunarMath::Vector4::operator+(Vector4 v)
{
	return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
}
Vector4 LunarMath::Vector4::operator-(Vector4 v)
{
	return Vector4(x - v.x, y - v.y, z - v.z, w - v.w);
}
Vector4 LunarMath::Vector4::operator*(float c)
{
	return Vector4(x * c, y * c, z * c, w * c);
}
Vector4 LunarMath::Vector4::operator/(float c)
{
	return Vector4(x / c, y / c, z / c, w * c);
}

float LunarMath::Vector4::operator*(Vector4 v)
{
	return x * v.x + y * v.y + z * v.z + w * v.w;
}

float LunarMath::Vector4::operator[](int index)
{
	sizeof(size_t);

	switch (index)
	{
	case 0:
		return x;
	case 1:
		return y;
	case 2:
		return z;
	case 3:
		return w;
	default:
		throw std::exception("wrong index value");
		break;
	}
	return -10000000000000000000.0f;
}

void LunarMath::Vector4::operator+=(Vector3 v)
{
	x = x + v.x;
	y = y + v.y;
	z = z + v.z;
	w = w;
	return;
}

void LunarMath::Vector4::operator+=(Vector4 v)
{
	x = x + v.x;
	y = y + v.y;
	z = z + v.z;
	w = w + v.w;
	return;
}
void LunarMath::Vector4::operator-=(Vector4 v)
{
	x = x - v.x;
	y = y - v.y;
	z = z - v.z;
	w = w - v.w;

	return;
}
void LunarMath::Vector4::operator*=(float c)
{
	x = x * c;
	y = y * c;
	z = z * c;
	w = w * c;
	return;
}
void LunarMath::Vector4::operator/=(float c)
{
	x = x / c;
	y = y / c;
	z = z / c;
	w = w * c;
	return;
}

LunarMath::Vector4::operator DirectX::XMFLOAT4()
{
	return DirectX::XMFLOAT4(x, y, z, w);
}