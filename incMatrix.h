#ifndef INC_MATRIX_H
#define INC_MATRIX_H
#include "incVector.h"
#include <iostream>

class Matrix {
	Vector* m_lines{ nullptr };
	int m_line{ 0 };
	int m_column{ 0 };
public:
	Matrix() {
		m_line = 0;
		m_column = 0;
		m_lines = nullptr;
	}
	Matrix(int line, int column) :
		m_line(line), m_column(column) {
		m_lines = new Vector [m_line];
		for (int count = 0; count < m_line; count++) {
			m_lines[count] = Vector(m_column);
		}
	}
	~Matrix() {
		delete[] m_lines;
	}
	Matrix(const Matrix& other) {
		m_line = other.m_line;
		m_column = other.m_column;
		m_lines = new Vector[m_line];
		for (int count = 0; count < m_line; count++) {
			m_lines[count] = other[count];
		}
	}


	Vector& operator[](int count) {
		return m_lines[count];
	}
	Vector operator[](int count) const {
		return m_lines[count];
	}

	Matrix operator=(const Matrix& other);
	Matrix operator+(const Matrix& other) const;
	Matrix operator-() const;
	Matrix operator-(const Matrix& other) const;
	Matrix operator*(const Matrix& other) const;
	Matrix operator*(double value) const;

	Matrix& operator*=(double value);
	Matrix& operator*=(const Matrix& other);
	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);

	friend Matrix operator*(double value, const Matrix& other) {
		Matrix newMatrix(other.m_line, other.m_column);
		for (int count = 0; count < other.m_line; count++) {
			newMatrix.m_lines[count] = value * other.m_lines[count];
		}
		return newMatrix;
	}


	bool operator==(const Matrix& other) const;
	bool operator!=(const Matrix& other);

	friend std::ostream& operator<<(std::ostream& out, const Matrix& other) {
		for (int count = 0; count < other.m_line; count++) {
			for (int COUNT = 0; COUNT < other.m_column; COUNT++) {
				out << other.m_lines[count][COUNT] << "\t";
			}
			out << "\n";
		}
		return out;
	}
	friend std::istream& operator>>(std::istream& in, Matrix& other) {
		std::cout << "Enter matrix: " << other.m_line << " x " << other.m_column << std::endl;
		for (int count = 0; count < other.m_line; count++) {
			for (int COUNT = 0; COUNT < other.m_column; COUNT++) {
				bool checker = true;
				std::cout << "Element[" << count << "][" << COUNT << "]: ";
				while (checker) {
					in >> other.m_lines[count][COUNT];
					if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
					{
						std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
						std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
						std::cout << "Error, retype element[" << count << "][" << COUNT << "] again: ";
					}
					else
						checker = false;
				}
			}
		}
		return in;
	}
	int getLine() const {
		return m_line;
	}
	int getColumn() const {
		return m_column;
	}
	void setColumn(int column);
	void setLine(int line);
};

#endif // !INC_MATRIX_H
