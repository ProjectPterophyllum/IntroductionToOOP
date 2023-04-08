#include <iostream>
using namespace std;

class Point
{
	double x;
	double y;
	double z;
public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	double get_z() const
	{
		return z;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	void set_z(double z)
	{
		this->z = z;
	}
	//Constructor
	Point()
	{
		x = y = z = 0;
		cout << "DefaultConstructor: \t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		this->z = 0;
		cout << "1ArgContructor: " << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		this->z = 0;
		cout << "2ArgContructor: " << endl;
	}
	Point(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		cout << "3ArgContructor: " << endl;
	}
	~Point()
	{
		cout << "Destructor: \t" << this << endl;
	}
	//Method
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << "\tZ = " << z << endl;
	}
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
	Point A;
	//A.set_x(2);
	//A.set_y(3);
	//A.set_z(5);
	A.print();
	Point B(5, 0);
	B.print();
	Point C(1, 2, 3);
	C.print();
}