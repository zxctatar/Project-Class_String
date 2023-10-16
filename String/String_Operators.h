#pragma once
#include <iostream>
#include <cstring>
#include "String.h"

String operator*(String a, const int& b) {
	a *= b;
	return a;
}

String operator+(String a, String& b) {
	a += b;
	return a;
}

String operator+(String a, const char b) {
	a += b;
	return a;
}

String operator+(String a, const char* b) {
	a += b;
	return a;
}