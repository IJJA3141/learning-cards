#include "pair.hpp"

qz::pair::pair(std::string _theme, std::string _version, int _accuracy)
{
	this->theme = _theme;
	this->version = _version;
	this->accuracy = _accuracy;

	return;
}

bool qz::pair::operator<(const qz::pair& _pair)
{
	return this->accuracy < _pair.accuracy;
}

bool qz::pair::operator>(const qz::pair& _pair)
{
	return this->accuracy > _pair.accuracy;
}

bool qz::pair::operator==(const qz::pair& _pair)
{
	return this->accuracy == _pair.accuracy;
}

std::ostream& operator<<(std::ostream& _stream, const qz::pair& _pair)
{
	return _stream << _pair.theme << "\n" << _pair.version << "\n" << _pair.accuracy;
}