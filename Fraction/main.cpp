//Fraction
#include<iostream>
using namespace std;
using::cin;
using::cout;
using::endl;

class Fraction
{
private:
	int n, d;

public:
	/*int numer, denom;
	Fraction()
	{
		numer = n;
		denom = d;
	}*/
	int get_n()const
	{
		return n;
	}
	int get_d()const
	{
		return d;
	}
	void set_n(int n)
	{
		this->n = n;
	}
	void set_d(int d)
	{
		this->d = d;
	}
	Fraction( int set_n = 0, int set_d = 1) // если у числитель будет записано одно число, то получится целое
	{
	}
	/*int Fraction(const Fraction& other) const
	{
		int n_fraction = this->n;
		int d_fraction = this->d;
		return n_fraction / d_fraction;
	}

	Fraction operator+ (Fraction& other)
	{
		return
			Fraction(
			n * other.d + n * other.n,
			n * other.d);
	}*/


};

void main()
{
	setlocale(LC_ALL, "Rus");

	Fraction n, d;
	n.set_n(2);
	d.set_d(5);
	n.set_n(3);

	cout << "Числитель: = " << n.get_n() << endl;
	cout << "Знаменатель: = " << d.get_d() << endl;

}
