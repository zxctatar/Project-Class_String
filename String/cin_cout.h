#pragma once
#include "String.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const String& c) {
	return os << c.str;
}

std::istream& operator >>(std::istream& is, String& c) {
	char* temp = new char[1024];
	is >> temp;
	c = temp;
	return is;
}