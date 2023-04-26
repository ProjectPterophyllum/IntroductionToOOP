#include <iostream>
using namespace std;

//#define DEBUG
#define Test
#define tab "\t"
#define delimiter cout << "|----------------------------------------------------------------------------------------------------|" << endl;
//Объявление класса
class Fraction;
//Объявление перегруженных операторов
Fraction operator+(Fraction Left, Fraction Right);
Fraction operator-(Fraction Left, Fraction Right);
Fraction operator*(Fraction Left, Fraction Right);
Fraction operator/(const Fraction& Left, const Fraction& Right);
bool operator==(const Fraction& Left, const Fraction& Right);
bool operator==(const double Left, const Fraction& Right);
bool operator!=(const Fraction& Left, const Fraction& Right);
bool operator<(const Fraction& Left, const Fraction& Right);
bool operator>(const Fraction& Left, const Fraction& Right);
bool operator<=(const Fraction& Left, const Fraction& Right);
bool operator>=(const Fraction& Left, const Fraction& Right);
//Объявления функций тестирования
void Test_Calculation_Operators(const Fraction& Left, const Fraction& Right);
void Test_Comparision_Operators(const Fraction& Left, const Fraction& Right);
void Test_Increment_Decrement_Operators(Fraction name);

class Fraction
{
private:
	int integer; //Целая часть дроби
	int numerator; //Числитель дроби
	int denumerator; //Знаменатель дроби
public:

	//             get-set методы
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

	//              Constructor
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
	Fraction(double value)
	{
		denumerator = 10;
		integer = (int)((value * 10) / denumerator);
		numerator = (int)(value * 10) % denumerator;
#ifdef DEBUG
		cout << "DecimalConstructor was used\t" << this << endl;
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

	//              Method:
#ifdef DEBUG
	void Print() const
	{
		if (integer != 0)
			cout << integer << "|" << numerator << "/" << denumerator;
		else
			cout << numerator << "/" << denumerator;
		cout << endl;
	}
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
	//Упрощение дроби
	Fraction& simplify()
	{
		int gcd = calculateGCD(numerator, denumerator);
		numerator /= gcd;
		denumerator /= gcd;
		return *this;
	}
	//              Conversion Methods:
		//Преобразование из неправильной в смешаную
	Fraction& toMixed()
	{
		integer += numerator / denumerator;
		numerator = numerator % denumerator;
		return *this;
	}
	//Из смешаной в неправильную
	Fraction& toImproper()
	{
		if (integer > 0)
		{
			numerator += integer * denumerator;
			integer = 0;
		}
		return *this;
	}
	//В десятичную
	double todecimal() const
	{
		return (double)get_int() + ((double)get_num() / (double)get_denum());
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.toImproper();
		inverted.numerator ^= inverted.denumerator;
		inverted.denumerator ^= inverted.numerator;
		inverted.numerator ^= inverted.denumerator;
		return inverted;
	}
	//              Operators:
	//Оператор =
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denumerator = other.denumerator;
		return *this;
	}
	//Оператор +=
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	//Оператор -=
	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}
	//Оператор *=
	Fraction& operator*=(const Fraction& other)
	{
		this->numerator = (this->numerator + this->integer * this->denumerator) * (other.numerator + other.integer * other.denumerator);
		this->denumerator = this->denumerator * other.denumerator;
		simplify();
		toMixed();
		return *this;
	}
	//Оператор /=
	Fraction& operator/=(const Fraction& other)
	{
		this->numerator = (this->numerator + this->integer * this->denumerator) * other.denumerator;
		this->denumerator = this->denumerator * (other.numerator + other.integer * other.denumerator);
		simplify();
		toMixed();
		return *this;
	}
	Fraction& operator++()
	{
		toMixed();
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		toMixed();
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()
	{
		toMixed();
		integer--;
		return *this;
	}
	Fraction operator--(int)
	{
		toMixed();
		Fraction old = *this;
		integer--;
		return old;
	}
	//				In-out
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
	bool ifProper()const
	{
		return numerator < denumerator ? true : false;
	}
	//НОД
	int calculateGCD(const int num, const int denum)const
	{
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
	Fraction A(2, 5, 7);
	Fraction B(1, 1, 8);
	Fraction C(10, 40);
	Fraction F(3.434);
	cout << F << endl;
#ifdef Test
	delimiter;
	Test_Calculation_Operators(A, C);
	delimiter;
	Test_Comparision_Operators(A, C);
	delimiter;
	Test_Increment_Decrement_Operators(A);
	delimiter;
#endif // Test
}
//					Operators:
Fraction operator+(Fraction Left, Fraction Right)
{
	Left.toImproper();
	Right.toImproper();
	return Fraction
	(
		(Left.get_num() * Right.get_denum()) + (Right.get_num() * Left.get_denum()),
		Left.get_denum() * Right.get_denum()
	).simplify().toMixed();
}
Fraction operator-(Fraction Left, Fraction Right)
{
	Left.toImproper();
	Right.toImproper();
	return Fraction
	(
		(Left.get_num() * Right.get_denum()) - (Right.get_num() * Left.get_denum()),
		Left.get_denum() * Right.get_denum()
	).simplify().toMixed();
}
Fraction operator*(Fraction Left, Fraction Right)
{
	Left.toImproper();
	Right.toImproper();
	return Fraction
	(
		Left.get_num() * Right.get_num(), Left.get_denum() * Right.get_denum()
	).simplify().toMixed();
}
Fraction operator/(const Fraction& Left, const Fraction& Right)
{
	return Left * Right.inverted();
}
bool operator==(const Fraction& Left, const Fraction& Right)
{
	return (int)(Left.todecimal() * 10000) == (int)(Right.todecimal() * 10000) ? true : false;
}
bool operator==(const double Left, const Fraction& Right)
{
	return (int)(Left * 10000) == (int)(Right.todecimal() * 10000) ? true : false;
}
bool operator!=(const Fraction& Left, const Fraction& Right)
{
	return Left == Right ? false : true;
}
bool operator<(const Fraction& Left, const Fraction& Right)
{
	return Left.todecimal() < Right.todecimal() ? true : false;
}
bool operator>(const Fraction& Left, const Fraction& Right)
{
	return Left < Right ? false : true;
}
bool operator<=(const Fraction& Left, const Fraction& Right)
{
	return Left < Right || Left == Right ? true : false;
}
bool operator>=(const Fraction& Left, const Fraction& Right)
{
	return Left > Right || Left == Right ? true : false;
}
//Реализация функций тестирования
void Test_Calculation_Operators(const Fraction& Left, const Fraction& Right)
{
	cout << "Левый операнд: " << Left << tab << "Правый операнд: " << Right << endl;
	cout << "Оператор +: \t Результат: " << Left + Right << "\t" << (Left.todecimal() + Right.todecimal() == Left + Right ? " Correct " : " Wrong ") << endl;
	cout << "Оператор -: \t Результат: " << Left - Right << "\t" << (Left.todecimal() - Right.todecimal() == Left - Right ? " Correct " : " Wrong ") << endl;
	cout << "Оператор *: \t Результат: " << Left * Right << "\t" << (Left.todecimal() * Right.todecimal() == Left * Right ? " Correct " : " Wrong ") << endl;
	cout << "Оператор /: \t Результат: " << Left - Right << "\t" << (Left.todecimal() / Right.todecimal() == Left / Right ? " Correct " : " Wrong ") << endl;
}
void Test_Comparision_Operators(const Fraction& Left, const Fraction& Right)
{
	cout << "Левый операнд: " << Left << tab << "Правый операнд: " << Right << endl;
	cout << "Оператор ==: \t Результат: " << (Left == Right ? "Yes" : "No") << endl;
	cout << "Оператор !=: \t Результат: " << (Left != Right ? "Yes" : "No") << endl;
	cout << "Оператор <: \t Результат: " << (Left < Right ? "Yes" : "No") << endl;
	cout << "Оператор >: \t Результат: " << (Left > Right ? "Yes" : "No") << endl;
	cout << "Оператор <=: \t Результат: " << (Left <= Right ? "Yes" : "No") << endl;
	cout << "Оператор >=: \t Результат: " << (Left >= Right ? "Yes" : "No") << endl;
}
void Test_Increment_Decrement_Operators(Fraction name)
{
	cout << "Начальное значение: " << name << endl;
	cout << "Increment++: " << name++ << tab << " > " << name << endl;
	cout << "++Increment: " << ++name << endl;
	cout << "Decrement--: " << name-- << tab << " > " << name << endl;
	cout << "--Decrement: " << --name << endl;
}