#pragma once

class Vec2
{
private:
	float x, y;
public:
	Vec2();
	Vec2(const float &x, const float& y);
	void setX(const float& x);
	void setY(const float& y);
	float getX() const;
	float getY() const;
	Vec2 Lerp(float& t);
	Vec2 Lerp(Vec2 &other, float& t);
	Vec2 Down();
	Vec2 Up();
	Vec2 Abs();
	float Lenght();
	Vec2 operator*(const float &mult);
	Vec2 operator*(const Vec2& other);
	Vec2 operator-(const Vec2 &other);
	Vec2 operator+(const Vec2& other);
	Vec2 operator/(const Vec2& other);
};