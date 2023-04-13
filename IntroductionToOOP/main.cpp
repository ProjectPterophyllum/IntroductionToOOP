#include <iostream>
#include <math.h>
using namespace std;

//#define STRUCT_POINT

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
		//cout << "Destructor: \t" << this << endl;
	}
	//Method
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << "\tZ = " << z << endl;
	}
	//Метод для нахождения дистанции от 0 до точки
	double distanceFromZero()const
	{
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}
	//Метод для нахождения дистанции до указанной точки
	double distance(Point name)const
	{
		return sqrt(pow(x - name.x, 2) + pow(y - name.y, 2) + pow(z - name.z, 2));
	}
	//Перегруженный метод для указания точки с помощью координат
	double distance(double x = 0, double y = 0, double z = 0)const
	{
		return sqrt(pow(this->x - x, 2) + pow(this->y - y, 2) + pow(this->z - z, 2));
	}
};

//Функция нахождения дистанции между двумя точками
double distance(Point Point1, Point Point2)
{
	return sqrt(pow(Point1.get_x() - Point2.get_x(), 2) + pow(Point1.get_y() - Point2.get_y(), 2) + pow(Point1.get_z() - Point2.get_z(), 2));
}

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
	Point A(1, 0, 2);
	//A.set_x(2);
	//A.set_y(3);
	//A.set_z(5);
	A.print();
	Point B(5, 0, 1);
	B.print();
	Point C(1, 2, 3);
	C.print();
	cout << "Дистанция до точки: " << A.distance(B) << endl;
	cout << "Дистанция от точки до указанных координат: " << A.distance() << endl;
	cout << "Дистанция между точками: " << distance(A, C) << endl;
}