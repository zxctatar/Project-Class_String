#pragma once
#include "String.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const String& c);

std::istream& operator >>(std::istream& is, String& c);