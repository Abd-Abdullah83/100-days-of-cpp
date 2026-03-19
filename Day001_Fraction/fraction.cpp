#include <iostream>
#include <cmath>
using namespace std;

class fraction
{
private:
	int num, denum;

	int gcd(int a, int b) const
	{
		a = abs(a);
		b = abs(b);
		while (b != 0)
		{
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}

	void simplify()
	{
		if (denum < 0)
		{
			num = -num;
			denum = -denum;
		}
		if (num == 0)
		{
			denum = 1;
			return;
		}
		int common = gcd(abs(num), abs(denum));
		num /= common;
		denum /= common;
	}

public:
	
	fraction()
	{
		num = 0;
		denum = 1;
		cout << "Default Constructor\n";
	}

	fraction(int n, int d) : num(n), denum(d)
	{
		if (denum == 0)
		{
			cout << "Error: denominator cannot be zero! Setting to 0/1\n";
			num = 0;
			denum = 1;
		}
		else
			simplify();
		cout << "Parametric Constructor\n";
	}

	fraction(const fraction& other)
	{
		num = other.num;
		denum = other.denum;
		cout << "Copy Constructor\n";
	}

	fraction(fraction&& other)
	{
		num = other.num;
		denum = other.denum;
		other.num = 0;
		other.denum = 1;
		cout << "Move Constructor\n";
	}
	fraction& operator=(const fraction& other)
	{
		cout << "Copy Assignment\n";
		if (this == &other)
			return *this;
		num = other.num;
		denum = other.denum;
		return *this;
	}

	fraction& operator=(fraction&& other)
	{
		cout << "Move Assignment\n";
		if (this == &other)
			return *this;
		num = other.num;
		denum = other.denum;
		other.num = 0;
		other.denum = 1;
		return *this;
	}

	
	~fraction()
	{
		cout << "Destructor\n";
	}

	fraction operator+(const fraction& other) const
	{
		fraction result(other.denum * num + other.num * denum, denum * other.denum);
		result.simplify();
		return result;
	}

	fraction operator-(const fraction& other) const
	{
		fraction result(other.denum * num - denum * other.num, denum * other.denum);
		result.simplify();
		return result;
	}

	fraction operator*(const fraction& other) const
	{
		fraction result(num * other.num, denum * other.denum);
		result.simplify();
		return result;
	}

	fraction operator/(const fraction& other) const
	{
		if (other.num == 0)
		{
			cout << "Error: division by zero! Returning 0/1\n";
			return fraction();
		}
		fraction result(num * other.denum, denum * other.num);
		result.simplify();
		return result;
	}

	fraction operator+(int val) const
	{
		fraction result(num + denum * val, denum);
		result.simplify();
		return result;
	}

	fraction operator-(int val) const
	{
		fraction result(num - denum * val, denum);
		result.simplify();
		return result;
	}

	fraction operator*(int val) const
	{
		fraction result(num * val, denum);
		result.simplify();
		return result;
	}

	fraction operator/(int val) const
	{
		if (val == 0)
		{
			cout << "Error: division by zero! Returning 0/1\n";
			return fraction();
		}
		fraction result(num, denum * val);
		result.simplify();
		return result;
	}
	friend fraction operator+(int val, const fraction& other)
	{
		fraction result(other.denum * val + other.num, other.denum);
		result.simplify();
		return result;
	}

	friend fraction operator-(int val, const fraction& other)
	{
		fraction result(other.denum * val - other.num, other.denum);
		result.simplify();
		return result;
	}

	friend fraction operator*(int val, const fraction& other)
	{
		fraction result(other.num * val, other.denum);
		result.simplify();
		return result;
	}

	friend fraction operator/(int val, const fraction& other)
	{
		if (other.num == 0)
		{
			cout << "Error: division by zero! Returning 0/1\n";
			return fraction();
		}
		fraction result(other.denum * val, other.num);
		result.simplify();
		return result;
	}

	fraction& operator+=(const fraction& other)
	{
		num = num * other.denum + other.num * denum;
		denum = denum * other.denum;
		simplify();
		return *this;
	}

	fraction& operator-=(const fraction& other)
	{
		num = num * other.denum - other.num * denum;
		denum = denum * other.denum;
		simplify();
		return *this;
	}

	fraction& operator*=(const fraction& other)
	{
		num = num * other.num;
		denum = denum * other.denum;
		simplify();
		return *this;
	}

	fraction& operator/=(const fraction& other)
	{
		if (other.num == 0)
		{
			cout << "Error: division by zero! No change made\n";
			return *this;
		}
		num = num * other.denum;
		denum = denum * other.num;
		simplify();
		return *this;
	}
	fraction& operator++()         
	{
		num += denum;
		simplify();
		return *this;
	}

	fraction operator++(int)      
	{
		fraction temp = *this;
		++(*this);
		return temp;
	}

	fraction& operator--()         
	{
		num -= denum;
		simplify();
		return *this;
	}

	fraction operator--(int)      
	{
		fraction temp = *this;
		--(*this);
		return temp;
	}

	
	fraction operator-() const
	{
		return fraction(-num, denum);
	}

	
	bool operator==(const fraction& other) const
	{
		return (num * other.denum == other.num * denum);  // cross multiply
	}

	bool operator!=(const fraction& other) const
	{
		return !(*this == other);
	}

	bool operator<(const fraction& other) const
	{
		return (num * other.denum < other.num * denum);   
	}

	bool operator>(const fraction& other) const
	{
		return (other < *this);
	}

	bool operator<=(const fraction& other) const
	{
		return !(other < *this);
	}

	bool operator>=(const fraction& other) const
	{
		return !(*this < other);
	}

	
	friend ostream& operator<<(ostream& out, const fraction& other);
	friend istream& operator>>(istream& inp, fraction& other);

	
	double toDouble() const
	{
		return static_cast<double>(num) / denum;
	}

	int getNumerator()   const { return num; }
	int getDenominator() const { return denum; }
};

ostream& operator<<(ostream& out, const fraction& other)
{
	if (other.denum == 1)
		out << other.num;   
	else
		out << other.num << "/" << other.denum;
	return out;
}

istream& operator>>(istream& inp, fraction& other)
{
	char slash;
	inp >> other.num >> slash >> other.denum;
	if (other.denum == 0)
	{
		cout << "Error: denominator cannot be zero! Setting to 0/1\n";
		other.num = 0;
		other.denum = 1;
	}
	else
		other.simplify();           
	return inp;
}

int main()
{
	cout << "===== Construction =====\n";
	fraction a(1, 2);  
	fraction b(2, 4);  
	fraction c(3, 6);   

	cout << "\na = " << a << "\n";
	cout << "b = " << b << "\n";
	cout << "c = " << c << "\n";

	cout << "\n===== Arithmetic =====\n";
	cout << "a + b = " << a + b << "\n";   
	cout << "a - b = " << a - b << "\n";  
	cout << "a * b = " << a * b << "\n";  
	cout << "a / b = " << a / b << "\n";  

	cout << "\n===== Int Arithmetic =====\n";
	cout << "a + 1 = " << a + 1 << "\n";  
	cout << "2 * a = " << 2 * a << "\n"; 
	cout << "3 - a = " << 3 - a << "\n"; 

	cout << "\n===== Comparison =====\n";
	cout << "a == b : " << (a == b) << "\n";
	cout << "a != c : " << (a != c) << "\n"; 

	fraction d(1, 3);
	cout << "a > d  : " << (a > d) << "\n";   
	cout << "d < a  : " << (d < a) << "\n";  

	cout << "\n===== Increment =====\n";
	fraction e(1, 4);
	cout << "e      = " << e << "\n";   
	cout << "e++    = " << e++ << "\n"; 
	cout << "e now  = " << e << "\n";   
	cout << "++e    = " << ++e << "\n";

	cout << "\n===== toDouble =====\n";
	cout << "a as double = " << a.toDouble() << "\n"; 

	cout << "\n===== Division by Zero =====\n";
	fraction zero(0, 1);
	fraction f = a / zero;
	cout << "a / 0 = " << f << "\n";

	return 0;
}
