//Fraction
#include<iostream>
using namespace std;
using::cin;
using::cout;
using::endl;

class Fraction
{
private:
	int n, d; // дадим значения по умолчанию

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

};

Fraction operator+(const Fraction& left, const Fraction& right)  // сложение простых дробей
{
	Fraction result;
	result.set_n((left.get_n()* right.get_d()) + (right.get_n()* left.get_d()));
	result.set_d(left.get_d() * right.get_d());
	return result;
}

Fraction operator-(const Fraction& left, const Fraction& right)   // вычитание простых дробей
{
	Fraction result;
	result.set_n((left.get_n() * right.get_d()) - (right.get_n() * left.get_d()));
	result.set_d(left.get_d() * right.get_d());
	return result;
}

Fraction operator*(const Fraction& left, const Fraction& right)  // умножение простых дробей
{
	Fraction result;
	result.set_n(left.get_n() * right.get_n());
	result.set_d(left.get_d() * right.get_d());
	return result;
}

Fraction operator/(const Fraction& left, const Fraction& right)  // деление простых дробей
{
	Fraction result; 
	result.set_n(left.get_n() * right.get_d());
	result.set_d(left.get_d() * right.get_n());
	return result;
}
void main()
{
	setlocale(LC_ALL, "Rus");

	Fraction A;
	A.set_n(2);
	A.set_d(3);

	Fraction B;
	B.set_n(1);
	B.set_d(4);

	cout << "Первая дробь     Числитель: = " << A.get_n() << "  Знаменатель: = " << A.get_d() << endl;
	cout << "Вторая дробь     Числитель: = " << B.get_n() << "  Знаменатель: = " << B.get_d() << endl;

	Fraction C = A + B;
	cout << "Сложение дробей  Числитель: = " << C.get_n() << "  Знаменатель: = " << C.get_d() << endl;

	Fraction D = A - B;
	cout << "Вычитание дробей Числитель: = " << D.get_n() << "  Знаменатель: = " << D.get_d() << endl;

	Fraction N = A * B;
	cout << "Умножение дробей Числитель: = " << N.get_n() << "  Знаменатель: = " << N.get_d() << endl;

	Fraction M = A / B;
	cout << "Деление дробей   Числитель: = " << M.get_n() << "  Знаменатель: = " << M.get_d() << endl;

}
