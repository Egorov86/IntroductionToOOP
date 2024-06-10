//String
#include<iostream>
using namespace std;
using std:: cin;
using std::cout;
using std::endl;
#define delimitr "\t-----------------------------\t"

class String //
{
	int size; //размер строки в байтах
	char* str; // Адрес строки в динамической памяти
public:
	const char* get_str()const
	{
		return str;
	}
	//                     Constructor:
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char str[])
	{
		this ->size =  strlen(str) + 1;  //Функция strlen () возвращает количество символов строки (без учета концевого нулевого байта).
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++) this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;
	}

	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}

	//                                Methods:
	
	/*String& operator+(const String& other)
	{
		String newSTR;

		int thislen = strlen(this->str);
		int otherlen = strlen(other.str);

		newSTR.str = new char[thislen + otherlen + 1];
		int i = 0;
		for (; i < thislen; i++)
		{
			newSTR.str[i] = this->str[i];
		}
		for (int j = 0; j < otherlen; j++,i++)
		{
			newSTR.str[i] = other.str[j];
		}
		newSTR.str[thislen + otherlen] = '\0';
		return newSTR;
	}*/
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os <<obj.get_str();
}

void main()
{
	setlocale(LC_ALL, "");
	
	String str;
	str.print();
	
	cout << delimitr << endl;

	String str1 = "Hello";
	String str2 = "World";
	//str1.print();
	//str2.print();
	cout << str1 << endl;
	cout << str2 << endl;
	
	/*cout << delimitr;
	String str3 = (str1 + str2);
	cout << str3 << endl;*/
	//str3.print();

}