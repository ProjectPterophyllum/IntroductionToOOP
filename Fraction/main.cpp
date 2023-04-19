#include <iostream>
using namespace std;

//#define DEBUG

class Fraction
{
private:
	int integer;//Целая часть дроби
	int numerator;//Числитель дроби
	int denumerator;//Знаменатель дроби
public:
	//            get-set методы
	int get_int()const
	{
		return integer;
	}
	int get_num()const
	{
		return numerator;
	}
	int get_denum()const
	{
		return denumerator;
	}
	void set_int(int integer)
	{
		this->integer = integer;
	}
	void set_num(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denum(int denumerator)
	{
		denumerator != 0 ? this->denumerator = denumerator : this->denumerator = 1;
	}
	//             Constructor
	Fraction()
	{
		integer = 0;
		numerator = 0;
		denumerator = 1;
	}
	Fraction(int numerator, int denumerator)
	{
		integer = 0;
		this->numerator = numerator;
		set_denum(denumerator);
#ifdef DEBUG
		cout << "Num / Denum constructor was used" << endl;
#endif // DEBUG
	}
	Fraction(int integer, int numerator, int denumerator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denum(denumerator);
#ifdef DEBUG
		cout << "Integer + Num / Denum constructor was used" << endl;
#endif // DEBUG
	}
	//Конструктор копирования
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denumerator = other.denumerator;
#ifdef DEBUG
		cout << "CopyConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Fraction()
	{
#ifdef DEBUG
		cout << "Destructor: \t" << this << endl;
#endif // DEBUG
	}
	//             Method:
#ifdef DEBUG
	void Print() const
	{
		if (integer != 0)
			cout << integer << "|" << numerator << "/" << denumerator;
		else
			cout << numerator << "/" << denumerator;
		cout << endl;
	}
#endif // DEBUG
	//Упрощение дроби
	void simplify()
	{
		int gcd = calculateGCD(numerator, denumerator);
		numerator /= gcd;
		denumerator /= gcd;
	}
	//Преобразование из неправильной в смешаную
	void conversion()
	{
		if (!properFraction())
		{
			integer += numerator / denumerator;
			numerator = numerator % denumerator;
		}
	}
	//Из смешаной в неправильную
	void reverseconversion()
	{
		if (integer > 0)
		{
			numerator += integer * denumerator;
			integer = 0;
		}
	}
#ifdef DEBUG
	//Может сказать какая это дробь.
	string whichFraction() const
	{
		string result;
		if (integer > 0)
			return result = "Дробь смешанная";
		else if (properFraction())
			return result = "Дробь правильная";
		else
			return result = "Дробь неправильная";
	}
#endif // DEBUG

	//              Operators
	//Оператор +
	Fraction& operator+(const Fraction& other)
	{
		if (this->denumerator != other.denumerator)
		{
			int lcm = calculateLCM(this->denumerator, other.denumerator);
			this->numerator = (this->numerator * lcm / this->denumerator) + (other.numerator * lcm / other.denumerator);
			this->denumerator = (this->denumerator * lcm / this->denumerator);
		}
		else
			this->numerator += other.numerator;
		this->integer += other.integer;
		simplify();
		conversion();
		return *this;
	}
	//Оператор -
	Fraction& operator-(const Fraction& other)
	{
		if (this->denumerator != other.denumerator)
		{
			int lcm = calculateLCM(this->denumerator, other.denumerator);
			this->numerator = (this->numerator * lcm / this->denumerator) - (other.numerator * lcm / other.denumerator);
			this->denumerator = (this->denumerator * lcm / this->denumerator);
		}
		else
			this->numerator -= other.numerator;
		this->integer -= other.integer;
		simplify();
		conversion();
		return *this;
	}
	//Оператор *
	Fraction& operator*(const Fraction& other)
	{
		this->numerator = (this->numerator + this->integer * this->denumerator) * (other.numerator + other.integer * other.denumerator);
		this->denumerator = this->denumerator * other.denumerator;
		simplify();
		conversion();
		return *this;
	}
	//Оператор /
	Fraction& operator/(const Fraction& other)
	{
		this->numerator = (this->numerator + this->integer * this->denumerator) * other.denumerator;
		this->denumerator = this->denumerator * (other.numerator + other.integer * other.denumerator);
		simplify();
		conversion();
		return *this;
	}
	//In-out
	friend istream& operator>>(istream& in, Fraction& name)
	{
		char slash = '/';
		char space = '|';
		in >> name.integer >> space >> name.numerator >> slash >> name.denumerator;
		return in;
	}
	friend ostream& operator<<(ostream& out, const Fraction& name)
	{
		if (name.integer != 0)
			out << name.integer << "|" << name.numerator << "/" << name.denumerator;
		else
			out << name.numerator << "/" << name.denumerator;
		return out;
	}
private:
	//Проверяет правильная дробь или неправильная
	bool properFraction()const
	{
		return numerator < denumerator ? true : false;
	}
	//НОД
	int calculateGCD(const int num, const int denum)const {
		if (denum == 0) {
			return num;
		}
		return calculateGCD(denum, num % denum);
	}
	//НОК
	int calculateLCM(const int num, const int denum)const
	{
		int gcd = calculateGCD(num, denum);
		return (num * denum) / gcd;
	}
};
void main()
{
	setlocale(LC_ALL, "");
	Fraction C;
	Fraction A(13, 8);
	Fraction B(1, 1, 8);
	A = A / B;
	cout << A << endl;
	cin >> C;
	cout << C;
}