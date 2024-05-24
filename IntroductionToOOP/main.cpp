//IntroductionToOOP
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//double distance(const Point& A, const Point& B);

//�������� ��������� ��� ����� �� ������� ����� ��� ������
class Point
{

	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this ->x = x;
	}
	void set_y(double y)
	{
		this ->y = y;
	}             
	          //
	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	          // Methods;

	double distance( Point other) // �������� ����� 
	{
		//this - ����
		//other - ������
		//this - ��� �����
		//other - �� �����

		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		return sqrt(x_distance * x_distance + y_distance * y_distance);
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(const Point& A, const Point& B) // ������� ���������� ����� �������
{
	double x_distantce = A.get_x() - B.get_x();
	double y_distantce = A.get_y() - B.get_y();
	return sqrt(x_distantce * x_distantce + y_distantce * y_distantce);
}

//#define STRUCT_POINT
#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT

	cout << "Hello OOP" << endl;
	int a; // ���������� ���������� '�' ���� int
	Point A; // ���������� ���������� 'A' ���� Point
	         // C������� ������� 'A' c�������� Point
	         // �������� ���������� 'A' c�������� Point
	cout << sizeof(A) << endl;
	cout << sizeof(Point) << endl;
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	Point* pA = &A; // Pointer to 'A'
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT
#ifdef DISTANCE_CHECK


	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;

	cout << "���������� �� ����� 'A' �� ����� 'B': " << A.distance(B) << endl;
	cout << "���������� �� ����� 'B' �� ����� 'A': " << B.distance(A) << endl;
	cout << "���������� ����� ������� 'A' � 'B': " << distance(A, B) << endl;
	cout << "���������� ����� ������� 'B' � 'A': " << distance(B, A) << endl;

#endif // DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHECK
	Point A; // Default constructor
	A.print();

	Point B = 5;
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C;
	D.print();
#endif // CONSTRUCTORS_CHECK


}


/*
______________________________________


______________________________________
*/