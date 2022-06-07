#ifndef INCGAUSS_H
#define INCGAUSS_H

class GaussSolver {
	int state;
	std::vector<Vector> solutions;
	std::vector<int> dep, indep;
	double accuracy;

public:
	GaussSolver(double value);

	std::vector<Vector> Solve(const Matrix& first, const Vector& second) {
		Matrix A = first;
		Vector B = second;
		Vector onlysolution(A.getColumn());
		bool flag;

		for (int count = 0; count < std::min<int>(A.getColumn(), A.getLine()); count++) {
			flag = true;
			if (abs(A[count][count]) > accuracy) {
				flag = false;
				obnuleniye(A, B, count);
				indep.push_back(count);
			}
			else if (nonullcounter(A, B, count) && count < A.getColumn() - 1) {
				flag = false;
				indep.push_back(count);
				swap(A, B, count);
				obnuleniye(A, B, count);
			}
			if (flag)
				dep.push_back(count);
		}

		if (A.getLine() > A.getColumn())
			for (int count = A.getColumn(); count < A.getLine(); count++)
				dep.push_back(count);

		if (mutual(A, B)) {
			if (counterofnonull(A) == A.getLine()) {
				std::cout << "Only one reshenie" << std::endl;
				for (int count = 0; count < A.getLine(); count++) {
					onlysolution[count] = B[count];
				}
				solutions.push_back(onlysolution);
				state = 1;
			}
			else {
				std::cout << "Many resheniy" << std::endl;
				state = 2;
				Vector v(A.getLine() + 1);
				for (int count = 0; count < A.getColumn(); count++) {
					if (abs(A[count][count] > accuracy)) {
						for (int COUNT = 0; COUNT < A.getLine(); count++)
							v[COUNT] = count == COUNT ? 0 : -A[count][COUNT];
						v[A.getLine()] = B[count];
						solutions.push_back(v);
					}

				}
				for (int count = 0; count < dep.size(); count++) {
					for (int COUNT = 0; COUNT < A.getLine(); COUNT++) {
						v[COUNT] = COUNT == dep[count] ? 1 : 0;
					}
					v[A.getLine()] = 0;
					solutions.push_back(v);
				}
			}
		}
		else {
			std::cout << "Resheniy don't exist" << std::endl;
			state = 0;
		}

		return solutions;

	}

	bool nonullcounter(const Matrix& first, const Vector& other, int value);

	int counterofnonull(const Matrix& other);

	bool mutual(const Matrix& first, const Vector& other);

	void obnuleniye(Matrix& first, Vector& other, int value);

	void print();

	void swap(Matrix& first, Vector& other, int value);

	bool testofresult(const Matrix& first, const Vector& second);
};

#endif // !INCGAUSS_H
