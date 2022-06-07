#ifndef INCVECTOR_H
#define INCVECTOR_H
#include <iostream>

class Vector {
	int m_n{ 0 };														//длина массива
	double* m_data{ nullptr };
public:
	Vector() {
		m_n = 0;
		m_data = nullptr;
	}
	Vector(int n) :														//конструктор с параметром длины массива m_data
		m_n(n)
	{
		m_data = new double[m_n];
		for (int count = 0; count < m_n; count++) {
			m_data[count] = 0.0;
		}
	}
	~Vector() {
		delete[] m_data;
		m_data = nullptr;
		m_n = 0;
	}
	Vector(const Vector& other) {
		m_n = other.m_n;
		m_data = new double[m_n];
		for (int count = 0; count < m_n; count++) {
			m_data[count] = other.m_data[count];
		}
	}

	double& operator[](int count);

	double operator[](int count) const;

	void resize(int newSize);

	Vector& operator=(const Vector& other);

	Vector operator+(const Vector& other) const;

	Vector operator-(const Vector& other) const;

	Vector& operator+=(const Vector& other);

	Vector& operator-=(const Vector& other);

	Vector& operator*=(double value);

	Vector operator*(double value) const;

	double dot(const Vector& other);

	void print();
	void setValueVector();
	int getLenght() const;

	friend std::ostream& operator<<(std::ostream& out, const Vector& other) {
		out << "{ ";
		for (int count = 0; count < other.m_n; count++) {
			out << other.m_data[count] << " ";
		}
		out << "}";
		return out;
	}
	friend std::istream& operator>>(std::istream& in, Vector& other) {
		for (int count = 0; count < other.m_n; count++) {
			std::cout << "Enter the first[" << count << "]: ";
			in >> other.m_data[count];
		}
		return in;
	}

	friend Vector operator*(double value, const Vector& other) {
		for (int count = 0; count < other.m_n; count++) {
			other.m_data[count] = value * other.m_data[count];
		}
		return other;
	}
};

#endif // !INCVECTOR_H
