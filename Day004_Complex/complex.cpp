#include<iostream>
using namespace std;
#include <cmath>
class complex 
{
private:
	double real, img;
public:
	complex()
	{
		real = 0, img = 0;
	}
	complex(double r, double i)
	{
		real = r, img = i;
	}
	complex(double r)
	{
		real = r;
		img = 0;
	}
	complex(const complex& other)
	{
		real = other.real, img = other.img;
	}
	complex& operator=(const complex& other)
	{
		if (this == &other)
		{
			return*this;
		}
		real = other.real;
		img = other.img;
		return *this;
	}
	double getReal() const 
	{ 
		return real;
	}
	double getImag() const
	{ 
		return img;
	}
	complex(complex&& other)
	{
		real = other.real, img = other.img;
		other.real=0,other.img=0;
	}
	complex& operator=(complex&& other)
	{
		if (this == &other)
		{
			return*this;
		}
		real = other.real, other.real = 0;
		img = other.img, other.img = 0;
		return *this;
	}
	~complex() = default;
	complex operator+(const complex& other) const
	{
		return complex(real + other.real, img + other.img);
	}
	complex operator-(const complex& other) const
	{
		return complex(real - other.real, img - other.img);
	}
	complex operator*(const complex& other) const
	{
		return complex(real * other.real - img * other.img, img * other.real + other.img * real);
	}

	complex operator/(const complex& other) const
	{
		if (other.real == 0 && other.img == 0)
		{
			cout << "\nDivision not possible ";
			return complex();
		}
		double denom = other.real * other.real + other.img * other.img;
		return complex((real * other.real + img * other.img) / denom,(img * other.real - real * other.img) / denom);
	}
	bool operator==(const complex& other) const
	{
		return (real == other.real && img == other.img);
	}
	bool operator!=(const complex& other) const
	{
		return !(*this == other);
	}
	double magnitude() const
	{
		double mag;
		mag = real * real + img * img;
			return sqrt(mag);
	}
	complex conjugate() const
	{
		return complex(real, -img);
	}
	complex& operator +=(const complex& other)
	{
		img = img + other.img;
		real = real + other.real;
		return *this;
	}
	complex operator-()
	{
		return complex(-real, - img);
	}
	complex& operator-=(const complex& other)
	{
		real = real - other.real;
		img = img - other.img;
		return*this;
	}
	complex& operator*=(const complex& other)
	{
		double r = real;
		double i = img;
		real = r * other.real - i * other.img;
		img = r * other.img + i * other.real;
		return *this;
	}
	complex& operator/=(const complex& other)
	{
		if (other.real == 0 && other.img == 0)
		{
			cout << "\nDivision Not possible!";
			return*this;
		}
		double denom = other.real * other.real + other.img * other.img;
		double r = real;
		double i = img;
		real = (r * other.real + i * other.img) / denom;
		img = (i * other.real - r * other.img) / denom;
		return *this;
	}
	friend complex operator+(double val,const complex &other);
	friend complex operator-(double val, const complex& other);
	friend complex operator*(double val, const complex& other);
	friend ostream& operator<<(ostream& out, const complex& other);
	friend istream& operator>>(istream& inp, complex& other);
	complex operator+(double val);
	complex operator-(double val);
	complex operator*(double val);
};
complex complex:: operator+(double val)
{
	return complex(real + val, img);
}
complex complex :: operator-(double val)
{
	return complex(real - val, img);
}
complex complex :: operator*(double val)
{
	return complex(real * val, img * val);
}
complex operator+(double val, const complex& other)
{
	return complex(other.real + val, other.img);
}
complex operator -(double val, const complex& other)
{
	return complex(val - other.real, other.img);
}
complex operator *(double val, const complex& other)
{
	return complex(val * other.real, val * other.img);
}
ostream& operator<< (ostream & out, const complex & other)
{
	
	out << other.real<< (other.img >= 0 ? " + " : " - ")<< abs(other.img)<< "i\n";
	return out;
}
istream& operator>>(istream& inp, complex& other)
{
	inp >> other.real >> other.img;
	return inp;
}

int main()
{
	complex c1, c2;

	cout << "Enter c1 (real img): ";
	cin >> c1;

	cout << "Enter c2 (real img): ";
	cin >> c2;

	cout << "\n--- Initial Values ---\n";
	cout << "c1 = " << c1;
	cout << "c2 = " << c2;

	cout << "\n--- Arithmetic Operations ---\n";
	cout << "c1 + c2 = " << (c1 + c2);
	cout << "c1 - c2 = " << (c1 - c2);
	cout << "c1 * c2 = " << (c1 * c2);
	cout << "c1 / c2 = " << (c1 / c2);
	complex temp = c1;
	temp += c2;
	cout << "\n(c1 += c2) = " << temp;
	temp = c1;
	temp -= c2;
	cout << "(c1 -= c2) = " << temp;
	temp = c1;
	temp *= c2;
	cout << "(c1 *= c2) = " << temp;
	temp = c1;
	temp /= c2;
	cout << "(c1 /= c2) = " << temp;
	cout << "\n--- Unary ---\n";
	cout << "-c1 = " << (-c1);
	cout << "\n--- Comparison ---\n";
	if (c1 == c2)
		cout << "c1 == c2\n";
	else
		cout << "c1 != c2\n";
	cout << "\n--- Utility Functions ---\n";
	cout << "|c1| = " << c1.magnitude() << endl;
	cout << "Conjugate of c1 = " << c1.conjugate();
	double val = 3;
	cout << "\n--- Operations with double (3) ---\n";
	cout << "c1 + 3 = " << (c1 + val);
	cout << "3 + c1 = " << (val + c1);
	cout << "c1 - 3 = " << (c1 - val);
	cout << "3 - c1 = " << (val - c1);
	cout << "c1 * 3 = " << (c1 * val);
	cout << "3 * c1 = " << (val * c1);
	cout << "\n--- Copy & Move ---\n";
	complex c3 = c1; 
	cout << "c3 (copy of c1) = " << c3;
	complex c4 = std::move(c2);
	cout << "c4 (moved from c2) = " << c4;
	cout << "\n--- End of Program ---\n";
	return 0;
}
