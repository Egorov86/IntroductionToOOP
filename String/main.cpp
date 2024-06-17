#include"String.h"
//#include"String.cpp"

//////_________________________________________________////



//#define CONSTRUCTORS_CHECK
#define CAT_CHECK

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