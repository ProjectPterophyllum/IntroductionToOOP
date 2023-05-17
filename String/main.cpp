#include <iostream>
using namespace std;
#define HOME_WORK
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
	void set_size(int size)
	{
		this->size = size;
	}
	void set_str(char* str)
	{
		this->str = str;
	}
	//			Constructors
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "Constructor:\t" << this << endl;
	}
	String(const char string[])
	{
		this->size = StrLenght(string) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			str[i] = string[i];
		}
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			str[i] = other.str[i];
		}
		cout << "Copy Constructor: \t" << this << endl;
	}
	//			Destructor
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
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
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			str[i] = other.str[i];
		}
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
	for (int i = 0, j = lefts; i < lefts; i++, j++)
	{
		TMP.str[i] = Left.str[i];
		TMP.str[j] = Right.str[i];
	}
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
	while (str[size] != '\0')
	{
		size++;
	}
	return size;
}