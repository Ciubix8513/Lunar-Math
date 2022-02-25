#include "Quarernion.h"

LunarMath::Quaternion::Quaternion()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

LunarMath::Quaternion::Quaternion(const Vector4& xyzw)
{
	x = xyzw.x;
	y = xyzw.y;
	z = xyzw.z;
	w = xyzw.w;
}

LunarMath::Quaternion::Quaternion(float XYZW)
{
	x = y = z = w = XYZW;
}

LunarMath::Quaternion::Quaternion(const Vector2& XY, float Z, float W)
{
	x = XY.x;
	y = XY.y;
	z = Z;
	w = W;
}

LunarMath::Quaternion::Quaternion(float X, const Vector2& YZ, float W)
{
	x = X;
	y = YZ.x;
	z = YZ.y;
	w = W;
}

LunarMath::Quaternion::Quaternion(float X, float Y, const Vector2& ZW)
{
	x = X;
	y = Y;
	z = ZW.x;
	w = ZW.y;
}

LunarMath::Quaternion::Quaternion(const Vector2& XY, const Vector2& ZW)
{
	x = XY.x;
	y = XY.y;
	z = ZW.x;
	w = ZW.y;
}

LunarMath::Quaternion::Quaternion(float X, const Vector3& YZW)
{
	x = X;
	y = YZW.x;
	z = YZW.y;
	w = YZW.z;
}

LunarMath::Quaternion::Quaternion(const Vector3& XYZ, float W)
{
	x = XYZ.x;
	y = XYZ.y;
	z = XYZ.z;
	w = W;
}

LunarMath::Quaternion::Quaternion(float X, float Y, float Z, float W)
{
	x = X;
	y = Y;
	z = Z;
	w = W;
}

LunarMath::Quaternion::Quaternion(const Vector3& eulerAngles)
{
	Vector3 rot = eulerAngles * Deg2Rad;
	float cy = (float)cos(rot.y * 0.5);
	float sy = (float)sin(rot.y * 0.5);
	float cp = (float)cos(rot.x * 0.5);
	float sp = (float)sin(rot.x * 0.5);
	float cr = (float)cos(rot.z * 0.5);
	float sr = (float)sin(rot.z * 0.5);

	w = cr * cp * cy + sr * sp * sy;
	x = sr * cp * cy - cr * sp * sy;
	y = cr * sp * cy + sr * cp * sy;
	z = cr * cp * sy - sr * sp * cy;
}

LunarMath::Quaternion::Quaternion(float X, float Y, float Z)
{
	Vector3 rot = Vector3(X, Y, Z) * Deg2Rad;
	float cy = (float)cos(rot.y * 0.5);
	float sy = (float)sin(rot.y * 0.5);
	float cp = (float)cos(rot.x * 0.5);
	float sp = (float)sin(rot.x * 0.5);
	float cr = (float)cos(rot.z * 0.5);
	float sr = (float)sin(rot.z * 0.5);

	w = cr * cp * cy + sr * sp * sy;
	x = sr * cp * cy - cr * sp * sy;
	y = cr * sp * cy + sr * cp * sy;
	z = cr * cp * sy - sr * sp * cy;
}

//Stole some code from euclidianspace.com but shhhh.... don't tell anyone lol  :)
//Honestly I have NO idea how this works
LunarMath::Quaternion LunarMath::Quaternion::Slerp(const Quaternion& qa, const Quaternion& qb, float t)
{
	//Clamp t
	if (t > 1) t = 1;
	if (t < 0) t = 0;

	// quaternion to return
	Quaternion qm;
	// Calculate angle between them.
	double cosHalfTheta = qa.w * qb.w + qa.x * qb.x + qa.y * qb.y + qa.z * qb.z;
	// if qa=qb or qa=-qb then theta = 0 and we can return qa
	if (abs(cosHalfTheta) >= 1.0) {
		qm.w = qa.w; qm.x = qa.x; qm.y = qa.y; qm.z = qa.z;
		return qm;
	}
	// Calculate temporary values.
	double halfTheta = acos(cosHalfTheta);
	double sinHalfTheta = sqrt(1.0 - cosHalfTheta * cosHalfTheta);
	// if theta = 180 degrees then result is not fully defined
	// we could rotate around any axis normal to qa or qb
	if (fabs(sinHalfTheta) < 0.001) { // fabs is floating point absolute
		qm.w = (qa.w * 0.5 + qb.w * 0.5);
		qm.x = (qa.x * 0.5 + qb.x * 0.5);
		qm.y = (qa.y * 0.5 + qb.y * 0.5);
		qm.z = (qa.z * 0.5 + qb.z * 0.5);
		return qm;
	}
	double ratioA = sin((1 - t) * halfTheta) / sinHalfTheta;
	double ratioB = sin(t * halfTheta) / sinHalfTheta;
	//calculate Quaternion.
	qm.w = (qa.w * ratioA + qb.w * ratioB);
	qm.x = (qa.x * ratioA + qb.x * ratioB);
	qm.y = (qa.y * ratioA + qb.y * ratioB);
	qm.z = (qa.z * ratioA + qb.z * ratioB);
	return qm;
}

LunarMath::Vector3 LunarMath::Quaternion::Euler() const
{
	Vector3 angles;
	double sinr_cosp = 2 * (w * x + y * z);
	double cosr_cosp = 1 - 2 * (x * x + y * y);
	angles.z = std::atan2(sinr_cosp, cosr_cosp);

	// x (y-axis rotation)
	double sinp = 2 * (w * y - z * x);
	if (std::abs(sinp) >= 1)
		angles.x = std::copysign(PI / 2, sinp); // use 90 degrees if out of range
	else
		angles.x = std::asin(sinp);

	// y (z-axis rotation)
	double siny_cosp = 2 * (w * z + x * y);
	double cosy_cosp = 1 - 2 * (y * y + z * z);
	angles.y = std::atan2(siny_cosp, cosy_cosp);

	return angles * (PI * 2);
}

LunarMath::Vector3 LunarMath::Quaternion::Euler(const Quaternion& q)
{
	return q.Euler();
}

LunarMath::Quaternion LunarMath::Quaternion::Inverse() const
{
	float m = Length();
	return Conjugated() / (m * m);
}

LunarMath::Quaternion LunarMath::Quaternion::Inverse(const Quaternion& q)
{
	return q.Inverse();
}

LunarMath::Quaternion& LunarMath::Quaternion::Invert()
{
	float m = Length();
	Conjugate() /= m * m;
	return *this;
}

LunarMath::Quaternion& LunarMath::Quaternion::Invert(Quaternion& q)
{
	return q.Invert();
}

LunarMath::Quaternion LunarMath::Quaternion::Conjugated() const
{
	return Quaternion(-x, -y, -z, w);
}

LunarMath::Quaternion& LunarMath::Quaternion::Conjugate()
{
	x *= -1;
	y *= -1;
	z *= -1;
	return *this;
}

float LunarMath::Quaternion::Length() const
{
	return sqrt(x * x + y * y + z * z + w * w);
}

float LunarMath::Quaternion::Length(const Quaternion& q)
{
	return  q.Length();
}

bool LunarMath::Quaternion::operator==(const Quaternion& other) const
{
	return x == other.x && y == other.y && z == other.z && w == other.w;
}

bool LunarMath::Quaternion::operator!=(const Quaternion& o) const
{
	return x != o.x || y != o.y || z != o.z || w != o.w;
}

LunarMath::Quaternion& LunarMath::Quaternion::operator/=(float f)
{
	x /= f;
	y /= f;
	z /= f;
	w /= f;
	return *this;
}

LunarMath::Quaternion& LunarMath::Quaternion::operator*=(const Quaternion& o)
{
	x = w * o.x + x * o.w + y * o.z - z * o.y;// i
	y = w * o.y - x * o.z + y * o.w + z * o.x;// j
	z = w * o.z + x * o.y - y * o.x + z * o.w;// k
	w = w * o.w - x * o.x - y * o.y - z * o.z;// 1
	return *this;
}

LunarMath::Quaternion& LunarMath::Quaternion::operator*=(float f)
{
	x *= f;
	y *= f;
	z *= f;
	w *= f;
	return *this;
}

LunarMath::Quaternion& LunarMath::Quaternion::operator+=(const Quaternion& b)
{
	x += b.x;
	y += b.y;
	z += b.z;
	w += b.w;
	return *this;
}

LunarMath::Quaternion& LunarMath::Quaternion::operator-=(const Quaternion& q)
{
	x -= q.x;
	y -= q.y;
	z -= q.z;
	w -= q.w;
	return *this;
}

float LunarMath::Quaternion::operator[](const int& i) const
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

float& LunarMath::Quaternion::operator[](const int& i)
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

LunarMath::Quaternion LunarMath::Quaternion::operator/(float f) const
{
	return Quaternion(x / f, y / f, z / f, w / f);
}

LunarMath::Quaternion LunarMath::Quaternion::operator*(const Quaternion& o) const
{
	return Quaternion(
		w * o.x + x * o.w + y * o.z - z * o.y,   // i
		w * o.y - x * o.z + y * o.w + z * o.x,   // j
		w * o.z + x * o.y - y * o.x + z * o.w,   // k
		w * o.w - x * o.x - y * o.y - z * o.z);  // 1
}

LunarMath::Quaternion LunarMath::Quaternion::operator*(float f) const
{
	return Quaternion(x * f, y * f, z * f, w * f);
}

LunarMath::Quaternion LunarMath::Quaternion::operator+(const Quaternion& b) const
{
	return Quaternion(x + b.x, y + b.y, z + b.z, w + b.w);
}

LunarMath::Quaternion LunarMath::Quaternion::operator-(const Quaternion& q) const
{
	return Quaternion(x -q.x,y-q.y,z-q.z,w-q.w);
}

