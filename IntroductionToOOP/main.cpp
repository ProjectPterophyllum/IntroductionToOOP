#include <iostream>
using namespace std;

class Point
{
	double x;
	double y;
	double z;
public:
};
//#define STRUCT_POINT
void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT


	//type name
	int a; //Объявление переменной а, типа int
	Point A; //Объявление переменной А, типа Point. Объявление объекта А структуры Point, создание экземпляра А структура Point.
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	cout << sizeof(A) << endl;
	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

}