#include "pair.hpp"

qz::Pair::Pair(std::string _theme, std::string _version, int _accuracy)
{
	this->theme = _theme;
	this->version = _version;
	this->accuracy = _accuracy;

	return;
}

bool qz::Pair::operator<(const Pair& _pair)
{
	return this->accuracy < _pair.accuracy;
}

bool qz::Pair::operator>(const Pair& _pair)
{
	return this->accuracy > _pair.accuracy;
}

bool qz::Pair::operator==(const Pair& _pair)
{
	return this->accuracy == _pair.accuracy;
}

std::ostream& operator<<(std::ostream& _stream, const qz::Pair& _pair)
{
	return _stream << _pair.theme << "\n" << _pair.version << "\n" << _pair.accuracy;
}