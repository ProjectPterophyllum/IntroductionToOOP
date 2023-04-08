#include <iostream>
using namespace std;

struct Point
{
	double x;
	double y;
	double z;
};

void main()
{
	setlocale(LC_ALL, "");
	//type name
	int a; //Объявление переменной а, типа int
	Point A; //Объявление переменной А, типа Point. Объявление объекта А структуры Point, создание экземпляра А структура Point.
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	cout << sizeof(A) << endl;
	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
}