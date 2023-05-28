#include "stdafx.h"
#include "String.h"

int String::get_size()const
{
	return size;
}
char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
//			Constructors
String::String(int size) :size(size), str(new char[size] {})
{
#ifdef DEBUG
	cout << "Constructor:\t" << this << endl;
#endif // DEBUG

}
String::String(const char string[]) :String(strlen(string) + 1)
{
	for (int i = 0; i < size; i++) str[i] = string[i];
#ifdef DEBUG
	cout << "Constructor:\t" << this << endl;
#endif // DEBUG
}
String::String(const String& other) :String(other.str)
{
#ifdef DEBUG
	cout << "CopyConstructor:" << this << endl;
#endif // DEBUG

}
String::String(String&& other)noexcept :size(other.size), str(other.str)
{
	//Shallow Copy
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}
//			Destructor
String::~String()
{
	delete[] this->str;
#ifdef DEBUG
	cout << "Destructor:\t" << this << endl;
#endif // DEBUG

}
//			Methods
void String::print()const
{
	cout << "Size: " << size << endl;
	cout << "Str: " << str << endl;
}
//			Operators
String& String::operator=(const String& other)
{
	if (this->str == other.str) return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++) str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other) noexcept
{
	if (this->str == other.str) return *this;
	delete[]this->str;
	size = other.size;
	str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
	return *this;
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}
char String::operator[](int index) const
{
	return str[index];
}
char& String::operator[](int index)
{
	return str[index];
}
String operator+(const String& Left, const String& Right)
{
	int lefts = Left.get_size() - 1;
	int rights = Left.get_size() + 1;
	int tmps = lefts + rights;
	String TMP(tmps);
	for (int i = 0; i < lefts; i++) TMP[i] = Left[i];
	for (int i = 0, j = lefts; i < rights; i++, j++) TMP[j] = Right[i];
	return TMP;
};
//				OUT
std::ostream& operator<<(ostream& out, const String& name)
{
	return out << name.get_str();
}
