#include <iostream>
#include <vector>
#include <cmath>
#include "incMatrix.h"
#include "incVector.h"
#include "incGauss.h"

int checkGet() {
	while (true) {
		std::cout << "Enter a double value: ";
		int value;
		std::cin >> value;

		if (std::cin.fail()){
			std::cin.clear(); 
			std::cin.ignore(32767, '\n');
		}
		else
			return value;
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	int line = checkGet();
	int column = checkGet();
	Matrix A(line, column);
	std::cin >> A;
	std::cout << A;
	Vector B(column);
	std::cin >> B;
	std::cout << B;
	double accuracy{10e-15};
	GaussSolver AB(accuracy);

	AB.Solve(A, B);
	AB.print();


	AB.testofresult(A, B) ? std::cout << "Test completed" : std::cout << "Test failed";


	return 0;
}
