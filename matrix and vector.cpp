#include "incVector.h"
#include "incMatrix.h"
#include <iostream>

int main() {
	setlocale(LC_ALL, "rus");
	Matrix first(2, 2);
	std::cin >> first;
	/*
	first[0][0] = 21;
	first[0][1] = 21;
	first[1][0] = 2;
	first[1][1] = -5;
	*/
	std::cout << "first:\n" << first << "------------------------------" << std::endl;

	Matrix second(2, 2);
	second[0][0] = 2;
	second[0][1] = 2;
	second[1][0] = 0;
	second[1][1] = -1;
	std::cout << "second:\n" << second << "------------------------------" << std::endl;

	std::cout << "first + second = \n" << first + second << "------------------------------" << std::endl;
	std::cout << "first - second = \n" << first - second << "------------------------------" << std::endl;
	std::cout << "first * 10 = \n" << first * 10 << "------------------------------" << std::endl;
	std::cout << "first * second = \n" << first * second << "------------------------------" << std::endl;
	std::cout << "second * first = \n" << second * first << "------------------------------" << std::endl;

	first *= second;
	std::cout << "first *= second: \n" << first << "------------------------------" << std::endl;

	first += second;
	std::cout << "first += second: \n" << first << "------------------------------" << std::endl;

	first -= second;
	std::cout << "first -= second: \n" << first << "------------------------------" << std::endl;

	Matrix third = first * second;
	std::cout << "third = first * second: \n" << third << "------------------------------" << std::endl;

	third = first - second;
	std::cout << "third = first - second: \n" << third << "------------------------------" << std::endl;
	std::cout << "-third: \n" << -third << "------------------------------" << std::endl;

	return 0;
}
