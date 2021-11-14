// PRGB_Test.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <algorithm>

#include "../PRGB_Library/String.cpp"
#include "../PRGB_Library//UniquePointer.cpp"
#include "PRGB_Test.h"


#include <memory>

int main()
{
	TestString();

	TestUniquePointer();
}

void TestString()
{
	std::cout << "----------------------" << std::endl;
	std::cout << "Start Test for Strings" << std::endl;
	std::cout << "----------------------" << std::endl << std::endl;
	Str_Test1();
	Str_Test2();
	Str_Test3();

	std::cout << std::endl << std::endl;
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

void TestUniquePointer() {

	std::cout << "----------------------" << std::endl;
	std::cout << "Start Test for Strings" << std::endl;
	std::cout << "----------------------" << std::endl << std::endl;

	UniquePointer<Entity> entityPointer(new Entity);
	UniquePointer<String> stringPointer(new String("Hello World"));

	if (entityPointer)
		std::cout << "Entity is true" << std::endl;
	else
		std::cout << "Entity is false" << std::endl;

	std::cout << "Entity ID: " << entityPointer->id << std::endl;

	Entity* e = entityPointer.release();
	std::cout << "Released Entity ID: " << e->id << std::endl;

	if (entityPointer)
		std::cout << "Entity is true" << std::endl;
	else
		std::cout << "Entity is false" << std::endl;
	delete e; // prevent memory leak

	std::cout << "String Pointer: " << stringPointer->c_str() << std::endl;

	String* s = new String("Hello other World");
	stringPointer.swap(s);

	std::cout << "String Pointer: " << stringPointer->c_str() << std::endl;
	std::cout << "String: " << s->c_str() << std::endl;

	std::cout << "String Pointer Before Reset: " << std::addressof(*stringPointer) << std::endl;
	stringPointer.reset();
	std::cout << "String Pointer After Reset: " << std::addressof(*stringPointer) << std::endl;

	std::cout << std::endl << std::endl;
	delete s; // prevent memory leak
}