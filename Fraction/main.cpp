//Fraction
#include<iostream>
#pragma warning(disable:4326)
using namespace std;
using::cin;
using::cout;
using::endl;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

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

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this*other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	Fraction& operator++ ()                //префиксный инкремент выс приро
	{
		integer++;
		return *this;
	}
	Fraction operator++ (int)               //постфиксный инкремент   низк приор
	{
		Fraction old = *this;
		integer ++;
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

	/*Fraction operator += (const Fraction& other)
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
	}*/

	//       Method:
	Fraction& reduce()
	{
		int more, less, rest;
		if (numerator > denominator)more = numerator, less = denominator;
		else more = denominator, less = numerator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more; //GDD - Greatest Common Divesor
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
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
	).to_proper().reduce();
}

Fraction operator/(const Fraction& left, const Fraction& right)    // Деление
{                                                 

	return left * right.inverted();
}
   //              Comperisan operator
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return 
		left.get_numerator() * right.get_denominator() == 
		right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction left, const Fraction right)
{
	return!(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator< (Fraction left, Fraction right)
{
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);  // побитовые операции всегда быстрее обрабаотываются процессором
	//return left < right || left == right;
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
	//return left > right || left == right;
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

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0) os << 0;
	return os;
}

std::istream& operator>>(std::istream& cin, Fraction& obj)         //Класс istream  обеспечивает работу потоков соответственно ввода.
{                                                          
	int integer, numerator, denominator;
	cin >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	return cin.;
}

//#define CONSTRUCTORS_CHECK
//#define ARIFMETICAL_OPERATORS_CHEK
//#define COMPARISON_OPERATORS_CHECK
#define STREAMS_CHECK

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

#ifdef ARIFMETICAL_OPERATORS_CHEK


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

	/*(C++).print();
	C.print();*/

	/*int a = 2;
	++++++++++++++++++++++a;
	a++++++++++++++++++++++;
	cout << a << endl;*/
	A*= B;
	A.print();

	A/= B;
	A.print();
#endif // ARIFMETICAL_OPERATORS_CHEK

#ifdef COMPARISON_OPERATORS_CHECK


	cout << (2 == 3) << endl;
	cout << (Fraction(1, 3) >= Fraction(5, 11)) << endl;
#endif // COMPARISON_OPERATORS_CHECK

#ifdef STREAMS_CHECK


	Fraction A(2, 3, 4);
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;


#endif // STREAMS_CHECK

}
