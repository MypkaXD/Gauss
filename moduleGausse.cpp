#include <iostream>
#include <vector>
#include <cmath>
#include "incVector.h"
#include "incMatrix.h"
#include "incGauss.h"


GaussSolver::GaussSolver(double value) {
	accuracy = value;
}

bool GaussSolver::nonullcounter(const Matrix& first, const Vector& other, int value) {
	for (int count = value + 1; count < first.getColumn(); count++) {
		if (abs(first[count][value]) > accuracy)
			return true;
	}
	return false;
}

int GaussSolver::counterofnonull(const Matrix& other) {
	int n{ 0 };
	bool flag{ false };
	for (int count = 0; count < other.getColumn(); count++) {
		flag = true;
		for (int COUNT = 0; COUNT < other.getLine(); COUNT++)
			if (abs(other[count][COUNT]) > accuracy) {
				flag = false;
				break;
			}
		if (!flag)
			n++;
	}
	return n;
}

bool GaussSolver::mutual(const Matrix& first, const Vector& other) {
	bool flag{ false };
	for (int count = 0; count < first.getColumn(); count++) {
		flag = true;
		for (int COUNT = 0; COUNT < first.getLine(); COUNT++) {
			if (abs(first[count][COUNT]) > accuracy) {
				flag = false;
				break;
			}
		}
		if (flag && abs(other[count]) > accuracy)
			return false;
	}
	return true;
}

void GaussSolver::obnuleniye(Matrix& first, Vector& other, int value) {
	double r, r2 = 1 / first[value][value];
	other[value] *= r2;
	first[value] *= r2;
	for (int count = 0; count < first.getColumn(); count++) {
		if (count != value) {
			r = first[count][value];
			first[count] -= first[value] * r;
			other[count] -= other[value] * r;
		}
	}
}

void GaussSolver::print() {
	std::cout << std::endl;
	if (!state)
		std::cout << "Resheniy don't exist" << std::endl;

	else if (state == 1)
		std::cout << "The vector of resheniy: " << solutions[0] << std::endl;

	else {
		for (int count = 0; count < indep.size(); count++) {
			std::cout << "x" << indep[count] + 1 << " = " << solutions[count][solutions[count].getLenght() - 1];

			for (int COUNT= 0; COUNT < dep.size(); COUNT++)
				if (solutions[count][dep[COUNT]])
					std::cout << " + " << solutions[count][dep[COUNT]] << "x" << dep[COUNT] + 1;

			std::cout << std::endl;
		}
	}
}

void GaussSolver::swap(Matrix& first, Vector& other, int value) {
	Vector tmp; double tmp2;
	for (int count = value + 1; count < first.getColumn(); count++)
		if (abs(first[count][value]) > accuracy) {
			tmp = first[count];
			tmp2 = other[count];
			first[count] = first[value];
			other[count] = other[value];
			first[value] = tmp;
			other[value] = tmp2;
			break;
		}
}

bool GaussSolver::testofresult(const Matrix& first, const Vector& second) {
	Vector solutions_temp(solutions[0].getLenght());

	if (!state)
		return false;
	else if (state == 1)
		solutions_temp = solutions[0];
	else {
		solutions_temp.resize(solutions.size());
		for (int count = 0; count < indep.size(); count++)
			solutions_temp[indep[count]] = solutions[count][solutions.size()];
	}




	Matrix first_temp(solutions_temp.getLenght(), 1);
	for (int count = 0; count < solutions_temp.getLenght(); count++)
		first_temp[count][0] = solutions_temp[count];
	Matrix temp = first * first_temp;



	double norm = 0, norm2 = 0;
	for (int count = 0; count < second.getLenght(); count++) {
		norm += second[count] * second[count];
		norm2 += temp[count][0] * temp[count][0];
	}
	if (abs(pow(norm, 0.5) - pow(norm2, 0.5)) < accuracy)
		return true;

	return false;
}