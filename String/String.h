#pragma once
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
	int get_size()const;
	char* get_str()const;
	char* get_str();
	//			Constructors
	explicit String(int size = 80);
	String(const char string[]);
	String(const String& other);
	String(String&& other)noexcept;
	//			Destructor
	~String();
	//			Methods
	void print()const;
	//			Operators
	String& operator=(const String& other);
	String& operator=(String&& other) noexcept;
	String& operator+=(const String& other);
	char operator[](int index) const;
	char& operator[](int index);
};