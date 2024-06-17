#pragma once
//String 
#include<iostream>
using namespace std;
/////////////////////////////////////////////////////////////
//////////   Oбъ€вление класса (Class declaration)     //////
/////////////////////////////////////////////////////////////
#define delimitr "\t-----------------------------\t"

class String //
{
	int size; //размер строки в байтах
	char* str; // јдрес строки в динамической пам€ти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	//                     Constructor:
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);

	~String();

	String& operator=(const String& other);

	void print()const;
};

std::ostream& operator<<(std::ostream& os, const String& obj);
String operator+(const String& left, const String& right);
/////////////////////////////////////////////////////////////
/////    онец oбъ€влени€ класса (Class declaration end) //////
/////////////////////////////////////////////////////////////
