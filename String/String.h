#pragma once
#include <iostream>
#include <cstring>

class String {
private:
	class _it {
	private:
		char* ptr;
	public:
		_it(char* p);

		_it& operator++();

		_it& operator--();

		char& operator*();

		bool operator==(const _it& other);

		bool operator!=(const _it& other);
	};

	size_t capacity = 1;
	size_t size = 0;
	char* str = nullptr;

public:

	String();

	String(const char* p);

	String(const String& other);

	String(String&& other) noexcept;

	String(const size_t s, const char c);

	// �������� size
	size_t GetSize();

	// �������� capacity
	size_t GetCapacity();

	// �������� ������� � �����
	void push_back(const char c);

	// �������� ������� � �����
	void push_back(const char* c);

	// ����� �������
	int find(const char c);

	// ���������� ������� ����������
	int find_str(const char* c);

	// �������� ������
	_it begin();

	// �������� �����
	_it end();

	// �������� ������ �� ������
	bool empty();

	// �������� ������ �������� �������
	void swap(String& other);

	char& operator[](int index);

	String& operator=(const String& other);

	String& operator=(const char c);

	String& operator=(const char* c);

	String& operator=(String&& other) noexcept;

	String& operator +=(const String& other);

	String& operator +=(String&& other) noexcept;

	String& operator +=(const char* c);

	String& operator +=(const char c);

	String& operator *=(const int& a);

	~String();

	friend std::istream& operator >>(std::istream& is, String& c);
	friend std::ostream& operator <<(std::ostream& is, const String& c);
};
