#include <iostream>
#include <math.h>
using namespace std;

using std::cin;
using std::cout;
using std::endl;
//#define STRUCT_POINT
#define constructors_check
//#define distance_check
#define delimiter "\n------------------------------------------\n"
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
	//CopyConstr
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
		cout << "CopyConstructor: \t " << this << endl;
	}
	//Destructor
	~Point()
	{
		cout << "Destructor: \t" << this << endl;
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
	double distance(const Point &name)const
	{
		return sqrt(pow(x - name.x, 2) + pow(y - name.y, 2) + pow(z - name.z, 2));
	}
	//Перегруженный метод для указания точки с помощью координат
	double distance(double x = 0, double y = 0, double z = 0)
	{
		return sqrt(pow(this->x - x, 2) + pow(this->y - y, 2) + pow(this->z - z, 2));
	}
};

//Функция нахождения дистанции между двумя точками
double distance(const Point &Point1, const Point &Point2)
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
	A.set_x(2);
	A.set_y(3);
	A.set_z(5);
#endif // STRUCT_POINT
#ifdef distance_check
	Point A(2, 3);
	A.print();
	cout << delimiter << endl;
	Point B(7, 8);
	B.print();
	cout << delimiter << endl;
	cout << "Дистанция до точки (метод): " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Дистанция от точки до указанных координат: " << A.distance() << endl;
	cout << delimiter << endl;
	cout << "Дистанция между точками (c помощью функции): " << distance(A, B) << endl;
	cout << delimiter << endl;
#endif // distance_check
#ifdef constructors_check
	Point A;//default constr
	A.print();
	Point B(5, 3);//two arg constr
	B.print();
	Point C(1, 2, 3);//three arg constr
	C.print();
	Point D = C;//copy constr
	D.print();
#endif // constructors_check
}