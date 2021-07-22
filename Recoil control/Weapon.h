#pragma once
#include "vector"
#include "Vec2.h"
#include "string"


class Weapon {
private:
	std::string name;
	std::vector<Vec2> pattern;
	std::vector<Vec2> rawPattern;
	unsigned RPM;
	unsigned magSize;
	unsigned entries;
public:
	Weapon() = default;
	Weapon(const std::string &name, const std::vector<Vec2> &pattern, const unsigned &RPM, const unsigned &magSize, const unsigned& entries);
	void applyMult(const float& mult);
	unsigned getMagSize() const;
	unsigned getRpm() const;
	unsigned getEntries() const;
	std::string getName() const;
	void setName(const std::string &name);
	void setPattern(const std::vector<Vec2> &pattern);
	void setRPM(const unsigned &RPM);
	void setMagSize(const unsigned &magSize);
	void setEntries(const unsigned &entries);
	Vec2 getPatternAtItr(const unsigned &itr) const;
	Vec2 getRawPatternAtItr(const unsigned &itr) const;
	Weapon operator=(Weapon& other);
};