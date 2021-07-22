#include "Weapon.h"
#include "iostream"


Weapon::Weapon(const std::string &name, const std::vector<Vec2> &pattern, const unsigned &RPM, const unsigned &magSize, const unsigned &entries) : name(name), pattern(pattern), RPM(RPM), magSize(magSize), entries(entries) {}

void Weapon::applyMult(const float& mult)
{
	for(auto &v : pattern)
	{
		v/mult;
	}
}

void Weapon::applyMultM(const float& mult)
{
	for (auto& v : pattern)
	{
		v * mult;
	}
}

void Weapon::printPattern() const
{
	for (auto& v : pattern)
	{
		std::cout << v.getX() << " ";
		std::cout << v.getY() << "\n";
	}
}


unsigned Weapon::getEntries() const
{
	return this->entries;
}

unsigned Weapon::getMagSize() const
{
	return this->magSize;
}

unsigned Weapon::getRpm() const
{
	return this->RPM;
}


Vec2 Weapon::getPatternAtItr(const unsigned &itr) const
{
	if(itr < this->entries)
	{
		return pattern[itr];
	}
	else
	{
		return pattern[entries-1];
	}
}

Vec2 Weapon::getRawPatternAtItr(const unsigned& itr) const 
{
	if (itr < this->entries)
	{
		return rawPattern[itr];
	}
	else
	{
		return rawPattern[entries - 1];
	}
}
	

std::string Weapon::getName() const {
	return this->name;
}

Weapon Weapon::operator=(Weapon& other)
{
	this->name = other.name;
	this->pattern = other.pattern;
	this->entries = other.entries;
	this->RPM = other.RPM;
	this->magSize = other.magSize;
	return *this;
}



void Weapon::setEntries(const unsigned& entries)
{
	this->entries = entries;
}

void Weapon::setMagSize(const unsigned& magSize)
{
	this->magSize = magSize;
}

void Weapon::setName(const std::string& name)
{
	this->name = name;
}

void Weapon::setPattern(const std::vector<Vec2>& pattern)
{
	this->pattern = pattern;
	this->rawPattern = pattern;
}

void Weapon::setRPM(const unsigned& RPM)
{
	this->RPM = RPM;
}


