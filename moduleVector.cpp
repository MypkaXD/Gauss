#include <iostream>
#include "incVector.h"


double& Vector::operator[](int count) {
	return (m_data[count]);
}

double Vector::operator[](int count) const {
	return (m_data[count]);
}

void Vector::resize(int newSize) {
	double* newM_Data = new double[newSize];
	int minLenght = std::min(newSize, m_n);
	for (int count = 0; count < minLenght; count++) {
		newM_Data[count] = m_data[count];
	}

	delete[] m_data;
	m_data = newM_Data;

	for (int count = 0; count < newSize; count++) {
		newM_Data[count] = 0.0;
	}

	m_n = newSize;
}

Vector& Vector::operator=(const Vector& other) {
	resize(other.m_n);
	for (int count = 0; count < other.m_n; count++) {
		m_data[count] = other.m_data[count];
	}
	return *this;
}

Vector Vector::operator+(const Vector& other) const {
	if (other.m_n != m_n) {
		throw "ERROR";
	}
	Vector newVector(m_n);
	for (int count = 0; count < m_n; count++) {
		newVector.m_data[count] = m_data[count] + other.m_data[count];
	}
	return newVector;
}

Vector Vector::operator-(const Vector& other) const {
	if (other.m_n != m_n) {
		throw "ERROR";
	}
	Vector newVector(m_n);
	for (int count = 0; count < m_n; count++) {
		newVector.m_data[count] = m_data[count] - other.m_data[count];
	}
	return newVector;
}

Vector& Vector::operator+=(const Vector& other) {
	if (other.m_n != m_n) {
		throw "ERROR";
	}
	for (int count = 0; count < m_n; count++) {
		m_data[count] += other.m_data[count];
	}
	return *this;
}

Vector& Vector::operator-=(const Vector& other) {
	if (other.m_n != m_n) {
		throw "ERROR";
	}
	for (int count = 0; count < m_n; count++) {
		m_data[count] -= other.m_data[count];
	}
	return *this;
}

Vector& Vector::operator*=(double value) {
	for (int count = 0; count < m_n; count++) {
		m_data[count] *= value;
	}
	return *this;
}

Vector Vector::operator*(double value) const {
	Vector other(m_n);
	for (int count = 0; count < m_n; count++) {
		other.m_data[count] = m_data[count] * value;
	}
	return other;
}

double Vector::dot(const Vector& other) {
	double lenght = 0;
	for (int count = 0; count < m_n; count++)
	{
		lenght += other.m_data[count] * m_data[count];
	}
	return lenght;
}

void Vector::print() {
	std::cout << "{ ";
	for (int count = 0; count < m_n; count++) {
		std::cout << m_data[count] << " ";
	}
	std::cout << "}" << std::endl;
}
void Vector::setValueVector() {
	for (int count = 0; count < m_n; count++) {
		int value;
		std::cout << "Введите " << count << " элемент: " << std::endl;
		std::cin >> value;
		m_data[count] = value;
	}
}
int Vector::getLenght() const {
	return m_n;
}
