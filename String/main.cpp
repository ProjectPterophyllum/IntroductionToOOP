#include "stdafx.h"
#include "String.h"
//			Operators:

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