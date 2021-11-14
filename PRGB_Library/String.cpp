#include "pch.h"
#include "String.h"
#include <iterator>


String::String() :
	_str(nullptr), _length(0) {
	_str = new char[1];
	_str[0] = '\0';
}

String::String(const char* val) :
	_str(nullptr), _length(0) {
	if (val == nullptr) {
		_str = new char[1];
		_str[0] = '\0';
	}
	else {
		_length = strlen(val);
		_str = new char[_length + 1];
		strcpy_s(_str, _length + 1, val);
	}
}

char* String::c_str() {
	return _str;
}

size_t String::getLength() {
	return _length;
}

void String::Concatenate(String s2)
{
	size_t length = getLength() + s2.getLength();

	char* buff = new char[length + 1];

	strcpy_s(buff, getLength() + 1, c_str());
	strcat_s(buff, length + 1, s2.c_str());

	delete[] _str;

	_length = length;
	_str = buff;
}

String& String::operator+=(const String& other)
{
	Concatenate(other);
	return *this;
}

String String::operator+(const String& other) const
{
	return String::Concatenate(*this, other);;
}

String::operator char* () const
{
	return _str;
}

String::String(const String& other)
{
	_length = strlen(other._str);
	_str = new char[_length + 1];
	strcpy_s(_str, _length + 1, other._str);
}

String::String(String&& other) noexcept
{
	_length = strlen(other._str);
	_str = other._str;
	other._str = nullptr;
}

String& String::operator=(const String& other)
{
	*this = String(other);
	return *this;
}

String& String::operator=(String&& source) noexcept
{
	std::swap(_str, source._str);
	return *this;
}

String::~String()
{
	if (_str != nullptr)
		delete[] _str;
}


String String::Concatenate(String s1, String s2) {
	size_t length = s1.getLength() + s2.getLength();

	char* buff = new char[length + 2];

	strcpy_s(buff, s1.getLength() + 1, s1.c_str());
	strcat_s(buff, length + 1, s2.c_str());

	String temp (buff);

	delete[] buff;

	return temp;
}

String::Iterator String::begin() const
{
	return Iterator(this->_str);
}

String::Iterator String::end() const
{
	return Iterator(this->_str + _length);
}

String::Iterator::Iterator(pointer ptr) : m_Ptr(ptr)
{
}

String::Iterator& String::Iterator::operator++()
{
	m_Ptr++;
	return *this;
}

String::Iterator& String::Iterator::operator++(int)
{
	Iterator iterator = *this;
	++(*this);
	return iterator;
}

String::Iterator& String::Iterator::operator--()
{
	m_Ptr--;
	return *this;
}

String::Iterator& String::Iterator::operator--(int)
{
	Iterator iterator = *this;
	--(*this);
	return iterator;
}

bool String::Iterator::operator==(const Iterator& other) const
{
	return m_Ptr == other.m_Ptr;
}

bool String::Iterator::operator!=(const Iterator& other) const
{
	return m_Ptr != other.m_Ptr;
}

String::Iterator::reference String::Iterator::operator[](int index)
{
	return *(m_Ptr + index);
}

String::Iterator::pointer String::Iterator::operator->()
{
	return m_Ptr;
}

String::Iterator::reference String::Iterator::operator*()
{
	return *m_Ptr;
}
