#include <iostream>
using namespace std;
#define HOME_WORK
//#define DEBUG
//Функция подсчета длинны строки
int StrLenght(const char* str);
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
	//			Constructors
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
#ifdef DEBUG
		cout << "Constructor:\t" << this << endl;
#endif // DEBUG

	}
	String(const char string[])
	{
		this->size = StrLenght(string) + 1;
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
		cout << "Copy Constructor: \t" << this << endl;
#endif // DEBUG

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
		return *this;
	}
	friend String operator+(const String& Left, const String& Right);
};
//			Operators:

String operator+(const String& Left, const String& Right)
{
	int lefts = StrLenght(Left.str);
	int rights = StrLenght(Right.str);
	int tmps = lefts + rights + 1;
	String TMP(tmps);
	for (int i = 0; i < lefts; i++) TMP.str[i] = Left.str[i];
	for (int i = 0, j = lefts; i < rights; i++, j++) TMP.str[j] = Right.str[i];
	TMP.str[lefts + rights] = '\0';
	return TMP;
};

//				OUT
std::ostream& operator<<(ostream& out, const String& name)
{
	out << name.get_str();
	return out;
}
void main()
{
	setlocale(LC_ALL, "");
	//cout << "Hello String" << endl;
	//String str1;
	//str1.print();
#ifdef HOME_WORK
	String str1 = "Hello";
	str1 = str1;
	cout << str1 << endl;
	String str2 = "World";
	cout << str2 << endl;
	String str3 = str1 + str2;
	cout << str3 << endl;
#endif // HOME_WORK
}

int StrLenght(const char* str)
{
	int size = 0;
	while (str[size] != '\0') size++;
	return size;
}