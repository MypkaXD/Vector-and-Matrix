#ifndef INC_MATRIX_H
#include "incVector.h"
#include <iostream>
#define INC_MATRIX_H

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
		m_lines = new Vector[m_line];
		for (int count = 0; count < m_column; count++) {
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
				out << other.m_lines[count][COUNT] << " ";
			}
			out << "\n";
		}
		return out;
	}
	friend std::istream& operator>>(std::istream& in, Matrix& other) {
		for (int count = 0; count < other.m_line; count++) {
			for (int COUNT = 0; COUNT < other.m_column; COUNT++) {
				in >> other.m_lines[count][COUNT];
			}
		}
		return in;
	}

	void setColumn(int column);
	void setLine(int line);
};

#endif // !INC_MATRIX_H