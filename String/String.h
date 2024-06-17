#pragma once
//String 
#include<iostream>
using namespace std;
/////////////////////////////////////////////////////////////
//////////   O��������� ������ (Class declaration)     //////
/////////////////////////////////////////////////////////////
#define delimitr "\t-----------------------------\t"

class String //
{
	int size; //������ ������ � ������
	char* str; // ����� ������ � ������������ ������
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
/////   ����� o��������� ������ (Class declaration end) //////
/////////////////////////////////////////////////////////////
