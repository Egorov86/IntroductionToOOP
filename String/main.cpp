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
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	//                     Constructor:
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);

	~String();

	                            //     Operators:
	String& operator=(const String& other);

	                             //   Methods:
	
	void print()const;
};
int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
//                     Constructor:
String::String(int size) : size(size), str(new char[size] {}) //this->size=size
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << "DefaultConstructor:\t" << this << endl;
}
String::String(const char str[]):String(strlen(str) + 1)
{
	//this ->size =  strlen(str) + 1;  //Функция strlen () возвращает количество символов строки (без учета концевого нулевого байта).
	//this->str = new char[size] {};
	for (int i = 0; str[i]; i++) this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	// Deep copy
	//this->size = other.size;
	//this->str = new char[size] {};
	//for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyConstructor:\t" << this << endl;
}

String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t\t" << this << endl;
}

//     Operators:

String& String::operator=(const String& other)
{
	/*int a = 2;
	int b = 3;
	a = b;*/
	if (this == &other)return *this;
	this->~String();
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}

//   Methods:

void String::print()const
{
	cout << "Obj:\t" << this << "\t";
	cout << "Size:\t" << size << "\t";
	cout << "Addr:\t" << &str << "\t";
	cout << "Str:\t" << str << "\n";
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os <<obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String buffer (left.get_size() + right.get_size() - 1); //From int to Ctring
	for (int i = 0; i < left.get_size(); i++)
		buffer.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	buffer.print();
	return buffer;

}
#define CONSTRUCTORS_CHECK
//#define CAT_CHECK

void main()
{
	setlocale(LC_ALL, "rus");
#ifdef CONSTRUCTORS_CHECK


	String str1;    //Default Constructor
	str1.print();

	String str2(8);        // Single-Assinment Constructor
	str2.print();
	
	String str3 = "Hello";  // Single-Assinment Constructor
	str3.print();

	String str4();       // Здесь не создаётся объект, и не вызывается конструктор
	                     // в этом выражении объявляется функция str4()
	//str4.print();        // которая ничего не принимает, и возвращает объект класса 'String'.

	String str5{};
	str5.print();

	String str6{ str3 };  // CopyConstructor, в фигурных скобках то что передаем
	str6.print();


#endif // CONSTRUCTORS_CHECK

#ifdef CAT_CHECK
	String str;
	str.print();

	cout << delimitr << endl;

	String str1 = "Hello";
	String str2 = "World";
	//str1.print();
	//str2.print();
	//cout << str1 << endl;
	//cout << str2 << endl;
	//String str3 = str1 + str2; // СopyConstructor
	cout << delimitr << endl;
	String str3;
	str1 = str1;
	str3 = str1 + " " + str2; // СopyAssignment
	cout << delimitr << endl;
	str3.print();
	//str3.print();
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl; // Hello World
#endif // CAT_CHECK

}