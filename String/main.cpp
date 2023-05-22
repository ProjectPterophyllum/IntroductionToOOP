#include <iostream>
using namespace std;
#define HOME_WORK
#define DEBUG
//Объявление класса
class String;
//Объявление операторов
std::ostream& operator<<(ostream& out, const String& name);
String operator+(const String& Left, const String& Right);

class String
{
	int size; //Размер строки в байтах
	char* str; //Адрес строки в динамической памяти
public:
	//get-set Методы
	int get_size()const
	{
		return size;
	}
	char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	//			Constructors
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
#ifdef DEBUG
		cout << "Constructor:\t" << this << endl;
#endif // DEBUG

	}
	String(const char string[])
	{
		this->size = (int)strlen(string) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) str[i] = string[i];
#ifdef DEBUG
		cout << "Constructor:\t" << this << endl;
#endif // DEBUG
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) str[i] = other.str[i];
#ifdef DEBUG
		cout << "CopyConstructor:" << this << endl;
#endif // DEBUG

	}
	String(String&& other) noexcept
	{
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor:\t" << this << endl;
	}
	//			Destructor
	~String()
	{
		delete[] this->str;
#ifdef DEBUG
		cout << "Destructor:\t" << this << endl;
#endif // DEBUG

	}
	//			Methods
	void print()const
	{
		cout << "Size: " << size << endl;
		cout << "Str: " << str << endl;
	}
	//			Operators
	String& operator=(const String& other)
	{
		if (this->str == other.str) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other) noexcept
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
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}
	char& operator[](int index)const
	{
		return str[index];
	}
};
//			Operators:

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
void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello String" << endl;
	String str7;
	str7.print();
#ifdef HOME_WORK
	String str1 = "Hello";
	str1 = str1;
	cout << str1 << endl;
	String str2 = "World";
	cout << str2 << endl;
	String str3 = str1;
	cout << str3 << endl;
	str1 += str2;
	cout << str1 << endl;
#endif // HOME_WORK
}