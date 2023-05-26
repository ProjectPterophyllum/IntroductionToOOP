#include <iostream>
using namespace std;
#define DEBUG
class Matrix;
Matrix operator+(const Matrix& Left, const Matrix& Right);
Matrix operator-(const Matrix& Left, const Matrix& Right);
Matrix operator*(const Matrix& Left, const Matrix& Right);
Matrix operator/(const Matrix& Left, const Matrix& Right);
class Matrix
{
	int ROWS;
	int COLS;
	double** mtr;
public:
	int get_rows() const
	{
		return ROWS;
	}

	int get_cols() const
	{
		return COLS;
	}
	double** get_mtr() const
	{
		return mtr;
	}
	double** get_mtr()
	{
		return mtr;
	}
	//				Constructors:
	explicit Matrix()
	{
		ROWS = COLS = 0;
		mtr = nullptr;
	}
	Matrix(int r, int c)
	{
		this->ROWS = r;
		this->COLS = c;
		this->mtr = new double* [ROWS] {};
		for (int i = 0; i < ROWS; i++)
			mtr[i] = new double[COLS] {};
#ifdef DEBUG
		cout << "Constructor:\t" << this << endl;
#endif // DEBUG
	}
	Matrix(const Matrix& other)
	{
		this->ROWS = other.ROWS;
		this->COLS = other.COLS;
		this->mtr = new double* [ROWS] {};
		for (int i = 0; i < ROWS; i++)
			mtr[i] = new double[COLS] {};
		for (int i = 0; i < ROWS; i++)
			for (int j = 0; j < COLS; j++)
				mtr[i][j] = other.mtr[i][j];
#ifdef DEBUG
		cout << "CopyConstructor: " << this << endl;
#endif // DEBUG

	}
	Matrix(Matrix&& other) noexcept
	{
		this->ROWS = other.ROWS;
		this->COLS = other.COLS;
		this->mtr = other.mtr;
		other.ROWS = 0;
		other.COLS = 0;
		other.mtr = nullptr;

#ifdef DEBUG
		cout << "MoveConstructor: " << this << endl;
#endif // DEBUG

	}
	//				Destructor:
	~Matrix()
	{
		for (int i = 0; i < ROWS; i++)
			delete[] mtr[i];
		delete[] this->mtr;
#ifdef DEBUG
		cout << "Destructor:\t" << this << endl;
#endif // DEBUG
	}
	//				Methods:
	void print() const
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
	void fillRandom(double start, double end)
	{
		for (int i = 0; i < ROWS; i++)
			for (int j = 0; j < COLS; j++)
				mtr[i][j] = start + ((double)rand() / (double)RAND_MAX) * (end - start + 0.01);
	}
	void fillCin()
	{
		for (int i = 0; i < ROWS; i++)
			for (int j = 0; j < COLS; j++)
				cin >> mtr[i][j];
	}
	//				Operators:
	Matrix& operator=(const Matrix& other)
	{
		if (this->mtr == other.mtr)
			return *this;
		for (int i = 0; i < ROWS; i++)
			delete[] mtr[i];
		delete[] this->mtr;
		this->ROWS = other.ROWS;
		this->COLS = other.COLS;
		this->mtr = new double* [ROWS] {};
		for (int i = 0; i < ROWS; i++)
			mtr[i] = new double[COLS] {};
		for (int i = 0; i < ROWS; i++)
			for (int j = 0; j < COLS; j++)
				mtr[i][j] = other.mtr[i][j];
#ifdef DEBUG
		cout << "CopyAssignment: " << this << endl;
#endif // DEBUG
		return *this;
	}
	Matrix& operator=(Matrix&& other) noexcept
	{
		if (this->mtr == other.mtr)
			return *this;
		this->ROWS = other.ROWS;
		this->COLS = other.COLS;
		this->mtr = other.mtr;
		other.ROWS = 0;
		other.COLS = 0;
		other.mtr = nullptr;
#ifdef DEBUG
		cout << "MoveAssignment: " << this << endl;
#endif // DEBUG
		return *this;
	}
};
void main()
{
	setlocale(LC_ALL, "");
	Matrix A(3, 3);
	Matrix B(3, 3);
	A.print();
	A.print();
	B.fillRandom(1.00, 25.00);
	B.print();
	Matrix C;
	C = A * B;
}
Matrix operator+(const Matrix& Left, const Matrix& Right)
{
	if (Left.get_rows() != Right.get_rows() && Left.get_cols() != Right.get_cols())
		return Matrix();
	Matrix tmp(Left.get_rows(), Left.get_cols());
	for (int i = 0; i < Left.get_rows(); i++)
		for (int j = 0; j < Left.get_cols(); j++)
			tmp.get_mtr()[i][j] = Left.get_mtr()[i][j] + Right.get_mtr()[i][j];
	return tmp;
}
Matrix operator-(const Matrix& Left, const Matrix& Right)
{
	if (Left.get_rows() != Right.get_rows() && Left.get_cols() != Right.get_cols())
		return Matrix();
	Matrix tmp(Left.get_rows(), Left.get_cols());
	for (int i = 0; i < Left.get_rows(); i++)
		for (int j = 0; j < Left.get_cols(); j++)
			tmp.get_mtr()[i][j] = Left.get_mtr()[i][j] - Right.get_mtr()[i][j];
	return tmp;
}
Matrix operator*(const Matrix& Left, const Matrix& Right)
{
	if (Left.get_cols() != Right.get_rows())
		return Matrix();
	Matrix tmp(Left.get_rows(), Right.get_cols());
	for (int i = 0; i < Left.get_rows(); i++)
		for (int j = 0; j < Right.get_cols(); j++)
			for (int k = 0; k < Left.get_cols(); k++)
				tmp.get_mtr()[i][j] += Left.get_mtr()[i][k] * Right.get_mtr()[k][j];
	return tmp;
}
Matrix operator/(const Matrix& Left, const Matrix& Right)
{
	return Matrix();
}