#include <iostream>
using namespace std;
#define DEBUG
class Matrix;
Matrix& operator+(const Matrix& Left, const Matrix& Right);
class Matrix
{
	int ROWS;
	int COLS;
	int** mtr;
public:
	int get_rows() const
	{
		return ROWS;
	}

	int get_cols() const
	{
		return COLS;
	}
	int** get_mtr() const
	{
		return mtr;
	}
	int** get_mtr()
	{
		return mtr;
	}
	//				Constructors:
	explicit Matrix(int r = 5, int c = 5)
	{
		this->ROWS = r;
		this->COLS = c;
		this->mtr = new int* [ROWS] {};
		for (int i = 0; i < ROWS; i++)
		{
			mtr[i] = new int[COLS] {};
		}
#ifdef DEBUG
		cout << "Constructor:\t" << this << endl;
#endif // DEBUG
	}
	//				Destructor:
	~Matrix()
	{
		/*Я видел такое, что вам, людям, и не снилось. 
		Атакующие корабли, пылающие над Орионом; 
		Лучи Си, разрезающие мрак у ворот Тангейзера. 
		Все эти мгновения затеряются во времени, как... слёзы в дожде... 
		Пришло время умирать.*/
		for (int i = 0; i < ROWS; i++)
		{
			delete[] mtr[i];
		}
		delete[] this->mtr;
#ifdef DEBUG
		cout << "Destructor:\t" << this << endl;
#endif // DEBUG
	}
	//				Methods:
	void Print() const
	{
		cout << "Matrix: " << this << endl;
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				cout << mtr[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void FillRandom(int start, int end)
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				mtr[i][j] = start + rand() % (end - start + 1);
			}
		}
	}
	void Fillcin()
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				cin >> mtr[i][j];
			}
			cout << endl;
		}
	}
	//				Operators:
};
void main()
{
	setlocale(LC_ALL, "");
	Matrix A;
	Matrix B;
	A.Print();
	//A.Fillcin();
	//A.Print();
	B.FillRandom(1, 25);
	B.Print();
}
Matrix& operator+(const Matrix& Left, const Matrix& Right)
{
	Matrix tmp;
	if (Left.get_rows() == Right.get_rows() && Left.get_cols() == Right.get_cols())
		for (int i = 0; i < Left.get_rows(); i++)
			for (int j = 0; j < Left.get_cols(); j++)
				tmp.get_mtr()[i][j] = Left.get_mtr()[i][j] + Right.get_mtr()[i][j];
	else
		cout << "Матрицы разные по размеру, сложение невозможно" << endl;
	return tmp;
}