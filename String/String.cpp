#include "String.h"

String::_it::_it(char* p) : ptr(p) {}

String::_it& String::_it::operator++() {
	ptr++;
	return *this;
}

String::_it& String::_it::operator--() {
	ptr--;
	return *this;
}

char& String::_it::operator*() {
	return *ptr;
}

bool String::_it::operator==(const _it& other) {
	return ptr == other.ptr;
}

bool String::_it::operator!=(const _it& other) {
	return ptr != other.ptr;
}

String::String() : capacity(1), size(0), str(new char[capacity]) { str[size] = '\0'; }

String::String(const char* p) : capacity(strlen(p) + 1), size(strlen(p)), str(new char[capacity]) {
	memcpy(str, p, capacity);
	str[size] = '\0';
}

String::String(const String& other) : capacity(other.capacity), size(other.size), str(new char[capacity]) {
	memcpy(str, other.str, capacity);
	str[size] = '\0';
}

String::String(String&& other) noexcept : capacity(other.capacity), size(other.size), str(new char[capacity]) {
	memcpy(str, other.str, capacity);
	other.str = nullptr;
	str[size] = '\0';
}

String::String(const size_t s, const char c) : capacity(s + 1), size(s), str(new char[capacity]) {
	memset(str, c, capacity);
	str[size] = '\0';
}

size_t String::GetSize() {
	return size;
}

size_t String::GetCapacity() {
	return capacity;
}

void String::push_back(const char c) {
	if (size + 1 >= capacity) {
		capacity *= 2;
		char* temp = new char[capacity];
		memcpy(temp, str, size);
		temp[size] = c;
		delete[] str;
		str = temp;
	}
	else {
		str[size] = c;
	}
	size += 1;
	str[size] = '\0';
}

void String::push_back(const char* c) {
	if (size + strlen(c) >= capacity) {
		capacity *= 2;
		char* temp = new char[capacity];
		memcpy(temp, str, size);
		memcpy(temp + size, c, strlen(c));
		delete[] str;
		str = temp;
	}
	else {
		memcpy(str + size, c, strlen(c));
	}
	size += strlen(c);
	str[size] = '\0';
}

int String::find(const char c) {
	for (int i = 0; i < size; ++i) {
		if (str[i] == c) {
			return i;
		}
	}
	return -1;
}

int String::find_str(const char* c) {
	int j = 0;
	int i = 0;
	for (i = 0; i < size; ++i) {
		if (j == strlen(c)) {
			return i - j;
		}
		if (str[i] == c[j]) {
			j++;
		}
		else {
			j = 0;
		}
	}
	if (j == strlen(c)) {
		return i - j;
	}
	return -1;
}

String::_it String::begin() {
	return _it(str);
}

String::_it String::end() {
	return _it(str + size);
}

bool String::empty() {
	return size;
}

void String::swap(String& other) {
	std::swap(capacity, other.capacity);
	std::swap(size, other.size);
	std::swap(str, other.str);
}

char& String::operator[](int index) {
	if (index > size) {
		char a = ' ';
		return a;
	}
	return str[index];
}

String& String::operator=(const String& other) {
	size = other.size;
	capacity = other.capacity;
	delete[] str;
	str = new char[capacity];
	memcpy(str, other.str, capacity);
	return *this;
}

String& String::operator=(const char c) {
	size = 1;
	capacity = 2;
	delete[] str;
	str = new char[capacity];
	memcpy(str, &c, capacity);
	return *this;
}

String& String::operator=(const char* c) {
	size = strlen(c);
	capacity *= 2;
	delete[] str;
	str = new char[capacity];
	memcpy(str, c, capacity);
	return *this;
}

String& String::operator=(String&& other) noexcept {
	size = other.size;
	capacity = other.capacity;
	str = other.str;
	other.str = nullptr;
	return *this;
}

String& String::operator +=(const String& other) {
	if (capacity > size + other.size) {
		memcpy(str + size, other.str, other.size);
		size += other.size;
	}
	else {
		capacity *= 2;
		char* temp = new char[capacity];
		memcpy(temp, str, size);
		memcpy(temp + size, other.str, other.size);
		size += other.size;
		delete[] str;
		str = temp;
	}
	str[size] = '\0';
	return *this;
}

String& String::operator +=(String&& other) noexcept {
	if (capacity > size + other.size) {
		memcpy(str + size, other.str, other.size);
		size += other.size;
		other.str = nullptr;
	}
	else {
		capacity *= 2;
		char* temp = new char[capacity];
		memcpy(temp, str, size);
		memcpy(temp + size, other.str, other.size);
		size += other.size;
		other.str = nullptr;
		delete[] str;
		str = temp;
	}
	str[size] = '\0';
	return *this;
}

String& String::operator +=(const char* c) {
	if (capacity > size + strlen(c)) {
		memcpy(str + size, c, strlen(c));
		size += strlen(c);
	}
	else {
		capacity *= 2;
		char* temp = new char[capacity];
		memcpy(temp, str, size);
		memcpy(temp + size, c, strlen(c));
		size += strlen(c);
		delete[] str;
		str = temp;
	}
	str[size] = '\0';
	return *this;
}

String& String::operator +=(const char c) {
	if (capacity > size + 1) {
		str[size] = c;
		size += 1;
	}
	else {
		capacity *= 2;
		char* temp = new char[capacity];
		memcpy(temp, str, size);
		memcpy(temp + size, &c, 1);
		size += 1;
		delete[] str;
		str = temp;
	}
	str[size] = '\0';
	return *this;
}

String& String::operator *=(const int& a) {
	capacity = (capacity * a) + 1;
	char* temp = new char[capacity];
	for (int i = 0; i < a; ++i) {
		memcpy(temp + size * i, str, size);
	}
	delete[] str;
	str = temp;
	size *= a;
	str[size] = '\0';
	return *this;
}

String::~String() {
	delete[] str;
}