#include<iostream>
using namespace std;
class matrix {
private :
	int row, col, ** p;
	void alot()
	{
		p = new int* [row];
		for (int i = 0; i < row; i++)
		{
			p[i] = new int[col]();
		}
	}
public:
	matrix()
	{
		row = 0;
		col = 0;
		p = nullptr;
	}
	
	matrix(int r,int c)
	{
		row = r, col = c;
		this->alot();
	}
	matrix(const matrix& other)
	{
		row = other.row;
		col = other.col;
		this->alot();
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				p[i][j] = other.p[i][j];
			}
		}
	}
	matrix(matrix&& other)
	{
		p = other.p;
		col = other.col, row = other.row;
		other.row = 0, other.col = 0;
		other.p = nullptr;
	}
	matrix& operator =(const matrix& other)
	{
		if (this == &other)
		{
			return*this;
		}
		if (p != nullptr)
		{
			for (int i = 0; i < row; i++)
			{
				delete[]p[i];
				p[i] = nullptr;
			}
			delete[]p;
			p = nullptr;

		}
		row = other.row, col = other.col;
		this->alot();
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				p[i][j] = other.p[i][j];
			}
		}
		return *this;
	}
	matrix& operator =(matrix&& other)
	{
		if (this == &other)
		{
			return*this;
		}
		if (p != nullptr)
		{
			for (int i = 0; i < row; i++)
			{
				delete[]p[i];
				p[i] = nullptr;
			}
			delete[]p;
			p = nullptr;
		}
		p = other.p;
		other.p = nullptr;
		row = other.row, other.row = 0;
		col = other.col, other.col = 0;
		return*this;
	}
	~matrix()
	{
		for (int i = 0; i < row; i++)
		{
			delete[]p[i];
			p[i] = nullptr;
		}
		delete[]p;
		p = nullptr;
	}
	matrix operator+(const matrix& other) const
	{
		if (row != other.row || col != other.col)
			throw invalid_argument("Dimensions must match for addition.");
		matrix temp(row, col);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				temp.p[i][j] = p[i][j] + other.p[i][j];
			}
		}
		return temp;
	}
	matrix operator-(const matrix& other)const
	{
		if (row != other.row || col != other.col)
			throw invalid_argument("Dimensions must match for Subtraction.");
		matrix temp(row, col);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				temp.p[i][j] = p[i][j] - other.p[i][j];
			}
		}
		return temp;
	}
	matrix operator*(const matrix& other)const
	{
		matrix temp(row, other.col);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j <other.col; j++)
			{
				for (int k = 0; k < other.row; k++)
				{
					temp.p[i][j] += p[i][k] * other.p[k][j];
				}
			}
		}
		return temp;
	}
	matrix operator*(int val) const
	{
		matrix temp(row, col);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				temp.p[i][j] = val * p[i][j];
			}
		}
		return temp;
	}
	bool operator==(const matrix& other) const
	{
		if (row != other.row or col != other.col)
		{
			return false;
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (p[i][j] != other.p[i][j])
					return false;
			}
		}
		return true;
	}
	bool operator!=(const matrix& other) const
	{
		return !(*this == other);
	}
	bool canMultiply(const matrix& other) const 
	{
		return col == other.row;
	}
	friend matrix operator *(int val, const matrix& other)
	{
		matrix temp(other.row, other.col);
		for (int i = 0; i < other.row; i++)
		{
			for (int j = 0; j < other.col; j++)
			{
				temp.p[i][j] = other.p[i][j] * val;
			}
		}
		return temp;
	}
	matrix& operator+=(const matrix& other)
	{
		*this = *this + other;
		return *this;
	}
	matrix& operator-=(const matrix& other)
	{
		*this = *this - other;
		return *this;
	}
	matrix& operator*=(const matrix& other)
	{
		*this = *this * other;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const matrix& other)
	{
		out << "Number of Row : " << other.row << "\nNumber of Col :  " << other.col<<"\n";
		for (int i = 0; i < other.row; i++)
		{
			for (int j = 0; j < other.col; j++)
			{
				out << other.p[i][j]<<" ";
			}
			out << "\n";
		}
		return out;
	}
	friend istream& operator>>(istream& inp, matrix& other)
	{
		if (other.p != nullptr)
		{
			for (int i = 0; i < other.row; i++)
				delete[] other.p[i];
			delete[] other.p;
			other.p = nullptr;
		}
		cout << "\nEnter Number of Row : ";
		inp >> other.row;
		cout << "Enter Number of Col : ";
		inp >> other.col;
		other.alot();
		for (int i = 0; i < other.row; i++)
		{
			for (int j = 0; j < other.col; j++)
			{
				inp >> other.p[i][j];
			}
		}
		return inp;
	}
	
};
int main()
{
	cout << "=== Input Matrix A ===";
	matrix A;
	cin >> A;

	cout << "\n=== Input Matrix B (same size as A) ===";
	matrix B;
	cin >> B;

	cout << "\n--- Matrix A ---\n" << A;
	cout << "\n--- Matrix B ---\n" << B;

	matrix C(A);
	cout << "\n--- Matrix C (copy of A) ---\n" << C;

	cout << "\n=== Comparison ===\n";
	cout << "A == B : " << (A == B ? "true" : "false") << "\n";
	cout << "A == C : " << (A == C ? "true" : "false") << "\n";
	cout << "A != B : " << (A != B ? "true" : "false") << "\n";

	cout << "\n=== A + B ===\n" << A + B;
	cout << "\n=== A - B ===\n" << A - B;

	C += B;
	cout << "\n=== C += B ===\n" << C;
	C -= B;
	cout << "\n=== C -= B (back to A) ===\n" << C;

	cout << "\n=== A * 3 ===\n" << A * 3;
	cout << "\n=== 3 * A ===\n" << 3 * A;

	
	cout << "\n=== Input Matrix D (cols must equal A's rows) ===";
	matrix D;
	cin >> D;

	if (A.canMultiply(D))
	{
		cout << "\n=== A * D ===\n" << A * D;

		matrix E(A);
		E *= D;
		cout << "\n=== E = A, then E *= D ===\n" << E;
	}
	else
	{
		cout << "\nA and D cannot be multiplied (dimension mismatch).\n";
	}

	//  Move constructor
	matrix F(std::move(B));
	cout << "\n=== F (moved from B) ===\n" << F;

	//Self assignment (+=) 
	matrix G(A);
	G += G;
	cout << "\n=== G = A, then G += G (self add) ===\n" << G;

	// Exception handling
	cout << "\n=== Testing dimension mismatch exception ===\n";
	try
	{
		matrix X(2, 2), Y(3, 3);
		cin >> X >> Y;
		matrix Z = X + Y;   // should throw
	}
	catch (const invalid_argument& e)
	{
		cout << "Caught exception: " << e.what() << "\n";
	}

	return 0;
}
