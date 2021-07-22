#include "Vec2.h"
#include "cmath"
#include <algorithm>

Vec2::Vec2() {
	this->x = 0.0f;
	this->y = 0.0f;
}

void Vec2::setX(const float& x)
{
	this->x = x;
}

void Vec2::setY(const float& y)
{
	this->y = y;
}

float Vec2::getX() const
{
	return this->x;
}

float Vec2::getY() const
{
	return this->y;
}

Vec2::Vec2(const float& x, const float& y) : x(x), y(y){}


Vec2 Vec2::operator*(const float &mult)
{
	this->x *= mult;
	this->y *= mult;
	return *this;
}

Vec2 Vec2::Abs() {
	this->x = fabs(x);
	this->y = fabs(y);
	return *this;
}

Vec2 Vec2::Down() {
	this->x = std::floor(x);
	this->y = std::floor(y);
	return *this;
}

Vec2 Vec2::Up() {
	this->x = std::ceil(x);
	this->y = std::ceil(y);
	return *this;
}

float Vec2::Lenght() {
	return sqrt(pow(x, 2) + pow(y, 2));
}

Vec2 Vec2::Lerp(float& t) {
	t = std::clamp(t, 0.0f, 1.0f);
	return {x * t,	y * t};
}

Vec2 Vec2::Lerp(Vec2& other, float& t) { // FIX
	t = std::clamp(t, 0.0f, 1.0f);
	Vec2 d(0.0f, 0.0f);
	this->x = x + (other.getX() - x) * t;
	this->y = y + (other.getY() - y) * t;
	return *this;
}

Vec2 Vec2::operator-(const Vec2& other) {
	this->x = x - other.getX();
	this->y = y - other.getY();
	return *this;
}

Vec2 Vec2::operator+(const Vec2& other) {
	this->x = x + other.getX();
	this->y = y + other.getY();
	return *this;
}