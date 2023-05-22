#include <iostream>
using namespace std;
#define DEBUG
class Matrix;

class Matrix
{
	int ROWS;
	int COLS;
	int** mtr;
public:
	//				Constructors:
	Matrix(int r = 5, int c = 5)
	{
		this->ROWS = r;
		this->COLS = c;
		this->mtr = new int* [ROWS] {};
		for (int i = 0; i < ROWS; i++)
		{
			mtr[i] = new int[COLS] {};
		}
#ifdef DEBUG
		cout << "Constructor:\t" << endl;
#endif // DEBUG
	}
	//				Destructor:
	~Matrix()
	{
		for (int i = 0; i < ROWS; i++)
		{
			delete[] mtr[i];
		}
		delete[] this->mtr;
#ifdef DEBUG
		cout << "Destructor:\t" << endl;
#endif // DEBUG
	}
	//				Methods:
	void Print() const
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				cout << mtr[i][j] << "\t";
			}
			cout << endl;
		}
	}
};
void main()
{
	setlocale(LC_ALL, "");
	Matrix A;
	A.Print();
}