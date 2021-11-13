// PRGB_Test.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>

#include "../PRGB_Library/String.h"
#include "../PRGB_Library/String.cpp"
#include "PRGB_Test.h"

int main()
{
	TestString();
}

void TestString()
{
	Str_Test1();
	Str_Test2();
	Str_Test3();
}

void Str_Test1()
{
	std::cout << "Start Test for Part 1" << std::endl << std::endl;

	String myString("Hello");
	myString.Concatenate("World");
	myString.Concatenate(myString);

	String otherString(myString);
	String yetAnotherString("AnotherWorld");
	otherString = yetAnotherString;

	std::cout << myString.c_str() << std::endl;
	std::cout << otherString.c_str() << std::endl;
	std::cout << yetAnotherString.c_str() << std::endl;

	std::cout << std::endl << "Test for Part 1 complete" << std::endl << std::endl;
}

void Str_Test2() {
	std::cout << "Start Test for Part 2" << std::endl << std::endl;

	String s1("Hello");
	const String s2("World");
	s1 += s2;
	String s3 = s1 + s2;
	s3 += "Hello";
	const String s4 = s3 + "World";
	puts(s4);

	std::cout << std::endl << "Test for Part 2 complete" << std::endl << std::endl << std::endl;
}

void Str_Test3() {
	std::cout << "Start Test for Part 3" << std::endl << std::endl;

	const String test("Hello World");

	std::cout << "for Iterator: ";
	for (String::Iterator it = test.begin(); it != test.end(); ++it) { std::cout << *it; }
	std::cout << std::endl;

	std::cout << "foreach Iterator: ";
	for (char c : test) { std::cout << c; }
	std::cout << std::endl;

	std::cout << "for Iterator reversed: ";
	for (String::Iterator it = test.end(); it != test.begin(); --it) {
		String::Iterator it2 = it;
		it2--;
		std::cout << *it2;
	}
	std::cout << std::endl;

	std::cout << "Find W in String: ";
	std::cout << (std::find(test.begin(), test.end(), 'W') != test.end()) << std::endl;

	std::cout << std::endl << "Test for Part 3 complete" << std::endl << std::endl << std::endl;
}