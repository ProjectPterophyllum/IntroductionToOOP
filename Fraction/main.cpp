#include <iostream>
using namespace std;

class Fraction
{
private:
	double integer;//Целая часть дроби
	double numerator;//Числитель дроби
	double denumerator;//Знаменатель дроби
public:
	//            get-set методы
	double get_int()const
	{
		return integer;
	}
	double get_num()const
	{
		return numerator;
	}
	double get_denum()const
	{
		return denumerator;
	}
	void set_int(double integer)
	{
		this->integer = integer;
	}
	void set_num(double numerator)
	{
		this->numerator = numerator;
	}
	void set_denum(double denumerator)
	{
		this->denumerator = denumerator;
	}
	//             Constructor
	Fraction(double numerator, double denumerator)
	{
		integer = 0;
		this->numerator = numerator;
		denumerator != 0 ? this->denumerator = denumerator : this->denumerator = 1;
		cout << "Num / Denum constructor was used" << endl;
	}
	Fraction(double integer, double numerator, double denumerator)
	{
		this->integer = integer;
		this->numerator = numerator;
		denumerator != 0 ? this->denumerator = denumerator : this->denumerator = 1;
		cout << "Integer + Num / Denum constructor was used" << endl;
	}
	~Fraction()
	{
		cout << "Destructor: \t" << this;
	}
	//             Method:
	void Print() const
	{
		if (integer != 0)
			cout << integer << "|" << numerator << "/" << denumerator;
		else
			cout << numerator << "/" << denumerator;
		cout << endl;
	}
};
void main()
{
	setlocale(LC_ALL, "");
	Fraction A(3, 10, 3);
	A.Print();
}