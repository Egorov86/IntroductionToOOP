//String
#include<iostream>
using namespace std;

class String //
{
	int size; //размер строки в байтах
	char* str; // Адрес строки в динамической памяти
public:
	//                     Constructor:
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}

	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}
	void print()const
	{

	}
};
	//              Methods:
	
void main()
{
	setlocale(LC_ALL, "");
	

}