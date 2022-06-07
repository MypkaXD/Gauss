#include "incMatrix.h"
#include "incVector.h"


Matrix Matrix::operator=(const Matrix& other) {
	if (*this == other) {
		return *this;
	}

	delete[] m_lines;
	m_line = other.m_line;
	m_column = other.m_column;
	m_lines = new Vector[m_line];
	for (int count = 0; count < m_line; count++) {
		m_lines[count] = other.m_lines[count];
	}
	return *this;
}


Matrix Matrix::operator*(const Matrix& other) const {
	if (m_column != other.m_line) {
		std::cout << "ERROR" << std::endl;
		exit(0);
	}

	Matrix newMatrix(m_line, other.m_column);
	for (int i = 0; i < newMatrix.m_line; i++) {
		for (int k = 0; k < m_column; k++){
			for (int j = 0; j < newMatrix.m_column; j++) {
				newMatrix[i][j] += m_lines[i][k] * other[k][j];
			}
		}
	}

	return newMatrix;
}


Matrix Matrix::operator+(const Matrix& other) const {
	if (m_line != other.m_line && m_column != other.m_column) {
		std::cout << "ERROR" << std::endl;
		exit(0);
	}

	Matrix newMatrix(m_line, m_column);
	for (int count = 0; count < m_line; count++) {
		for (int COUNT = 0; COUNT < m_column; COUNT++)
			newMatrix.m_lines[count][COUNT] = m_lines[count][COUNT] + other.m_lines[count][COUNT];
	}
	return newMatrix;
}


Matrix Matrix::operator-() const {
	return (* this * (-1));
}


Matrix Matrix::operator-(const Matrix& other) const {
	if (m_line != other.m_line && m_column != other.m_column) {
		std::cout << "ERROR" << std::endl;
		exit(0);
	}

	return (*this + (-other));
}


Matrix Matrix::operator*(double value) const {
	Matrix newMatrix(m_line, m_column);
	for (int count = 0; count < m_line; count++) {
		newMatrix.m_lines[count] = m_lines[count] * value;
	}
	return newMatrix;
}


Matrix& Matrix::operator*=(double value) {
	*this = *this * value;
	return *this;
}


Matrix& Matrix::operator*=(const Matrix& other) {
	if (m_line != other.m_line && m_column != other.m_column) {
		std::cout << "ERROR" << std::endl;
		exit(0);
	}
	*this = *this * other;
	return *this;
}


Matrix& Matrix::operator+=(const Matrix& other) {
	if (m_line != other.m_line && m_column != other.m_column) {
		std::cout << "ERROR" << std::endl;
		exit(0);
	}
	*this = *this + other;
	return *this;
}


Matrix& Matrix::operator-=(const Matrix& other) {
	if (m_line != other.m_line && m_column != other.m_column) {
		std::cout << "ERROR" << std::endl;
		exit(0);
	}
	*this = *this - other;
	return *this;
}


bool Matrix::operator==(const Matrix& other) const {
	if (m_column != other.m_column || m_line == other.m_line)
		return false;
	for (int count = 0; count < m_line; count++) {
		for (int COUNT = 0; COUNT < m_column; COUNT++) {
			if (m_lines[count][COUNT] != other.m_lines[count][COUNT])
				return false;
		}

	}
	return true;
}


bool Matrix::operator!=(const Matrix& other) {
	return !(*this == other);
}


void Matrix::setColumn(int column) {
	m_column = column;
}


void Matrix::setLine(int line) {
	m_line = line;
}
