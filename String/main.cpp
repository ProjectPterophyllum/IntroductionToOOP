#include <iostream>
using namespace std;
#define HOME_WORK
class String;

class String
{
	int size; //Размер строки в байтах
	char* str; //адрес строки в динамической памяти
public:
	//			Constructors
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "Constructor:\t" << this << endl;
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
};

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