//Fraction
#include<iostream>
using namespace std;
using::cin;
using::cout;
using::endl;

class Fraction
{
private:
	int numerator;
	int integer;
	int denominator;

public:
	/*int numer, denom;
	Fraction()
	{
		numer = n;
		denom = d;
	}*/
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	 //  Constructors:
	Fraction()
	{
		integer = 0;
	    numerator = 0;
	    denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator); // фильтрация данных 0 преобразуем в 1
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//            Operator:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	Fraction& operator++ ()                //префиксный инкремент
	{
		numerator += denominator;
		to_proper();
		return *this;
	}
	Fraction operator++ (int)               //постфиксный инкремент
	{
		Fraction old = *this;
		numerator += denominator;
		to_proper();
		return old;
	}
	Fraction& operator-- ()                //префиксный декремент
	{
		numerator -= denominator;
		to_proper();
		return *this;
	}
	Fraction operator-- (int)               //постфиксный декремент
	{
		Fraction old = *this;
		numerator -= denominator;
		to_proper();
		return old;
	}

	Fraction operator += (const Fraction& other)
	{
		to_improper();
		numerator = numerator * other.denominator + other.numerator*denominator;
		denominator = denominator * other.denominator;
		to_proper();
		return *this;
	}

	Fraction operator -= (const Fraction& other)
	{
		to_improper();
		numerator = numerator * other.denominator - other.numerator * denominator;
		denominator = denominator * other.denominator;
		to_proper();
		return *this;
	}

	//       Method:
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()   // not const потому что изменяет поля класса(изменяет Объект)
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);   //swap - меняет местами числитель и знаменатель
		return inverted;
	}

	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}


};

Fraction operator*(Fraction left, Fraction right) // передаем по значению т.к. чтобы не 
{                                                 // изменять объекты а лишь менять его копии
	left.to_improper();
	right.to_improper();

	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}

Fraction operator/(const Fraction& left, const Fraction& right)    // Деление
{                                                 

	return left * right.inverted();
}

Fraction operator+(Fraction left, Fraction right)            // Сложение
{                                                 
	left.to_improper();
	right.to_improper();

	return Fraction
	(
		(left.get_numerator()*right.get_denominator())+ (right.get_numerator()* left.get_denominator()),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator-(Fraction left, Fraction right)             // Вычитание
{                                                 
	left.to_improper();
	right.to_improper();

	return Fraction
	(
		(left.get_numerator() * right.get_denominator()) - (right.get_numerator() * left.get_denominator()),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}

//#define CONSTRUCTORS_CHECK


void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;           //Default constructor
	A.print();
	
	Fraction B = 5;       //Single-argument constructor
	B.print();

	Fraction C(1, 2);     // Конструктор с 2-мя параметрами
	C.print();

	Fraction D(2, 3, 4);   // Конструктор с 3-мя параметрами
	D.print();

	Fraction E = D;        // Конструктор копирования
	E.print();              

	Fraction F;            // Конструктор присваивания
	F = E;
	F.print();
#endif // CONSTRUCTORS_CHECK

	/*Fraction A(2, 3, 4);
	A.to_improper();          //перевод дроби в неправильную дробь
	A.print();

	A.to_proper();            //перевод дроби в правильную дробь, выделение целой части
	A.print();*/

	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	Fraction C = A +B;
	C.print();

	A.print();
	B.print();

	B -= A;
	B.print();


}
