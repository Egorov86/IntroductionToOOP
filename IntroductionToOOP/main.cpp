//IntroductionToOOP
#include<iostream>
#include <cmath> // ��� �����
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
	/*double distance(const Point& AB) // �������� ����� 
	{
		return sqrt((B.get_x() - A.get_x()) * (B.get_x() - A.get_x()) + 
		(B.get_y() - A.get_y()) * (B.get_y() - A.get_y()));
	}*/
};
double distance(const Point& A, const Point& B) // ������� ���������� ����� �������
{
	return sqrt((B.get_x() - A.get_x()) * (B.get_x() - A.get_x()) +
		(B.get_y() - A.get_y()) * (B.get_y() - A.get_y()));
}

//#define STRUCT_POINT

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

	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point B;
	B.set_x(3);
	B.set_y(4);
	cout << B.get_x() << "\t" << B.get_y() << endl;

	double AB;
	AB = distance(A, B);
	cout << "���������� ����� ������� A � B: " << AB << endl;
}

/*
______________________________________


______________________________________
*/