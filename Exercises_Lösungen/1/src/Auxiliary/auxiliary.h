/*
 * auxiliary.h
 *
 *  Created on: Aug 14, 2017
 *      Author: hpcochep
 */

#ifndef AUXILIARY_AUXILIARY_H_
#define AUXILIARY_AUXILIARY_H_

using namespace std;

#include <string>
#include <iostream>
#include <math.h>

string get_time_as_string(struct tm * time);
string get_time_with_displacement(struct tm * initial_time, int disp_in_secs);

template<typename T>
void init_with_zero(T* A, int m, int n) {
	for (int i = 0; i < m * n; i++)
		A[i] = 0;
}

template<typename T>
T get_el_ij(T* A, int i, int j, int n, int m) {
	return A[i * m + j];
}

template<typename T>
int get_el_ij_index(T* A, int i, int j, int n, int m) {
	int index = i * m + j;
	return index;
}

template<typename T>
void print_matrix(T* A, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << "[" << A[i * m + j] << "]" << "\t";
		cout << endl;
	}
	cout << endl;
}

template<typename T>
void print_matrix(T** A, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "[" << *A[i * m + j] << "]" << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

template<typename T1, typename T2>
void matrix_mult(T1* A, int n_A, int m_A, T2* B, int n_B, int m_B, float* C) {

	//
	// TODO: check of matrix sizes
	//

	for (int i = 0; i < n_A; i++) {
		for (int j = 0; j < m_B; j++) {
			float temp = 0;
			for (int k = 0; k < m_A; k++) {
				temp += A[i * m_A + k] * B[k * m_B + j];

//						get_el_ij<T1>(A, i, k, n_A, m_A)
//						* get_el_ij<T2>(B, k, j, n_B, m_B);

//				cout << A[i * m_A + k] << " x " << B[k * m_B + j] << " +  ";
			}
//			cout << endl;
			C[i * m_B + j] = temp;
		}
	}
}

template<typename T1, typename T2>
void matrix_mult(T1* A, int n_A, int m_A, T2** B, int n_B, int m_B, float* C) {

	//
	// TODO: check of matrix sizes
	//

	for (int i = 0; i < n_A; i++) {
		for (int j = 0; j < m_B; j++) {
			float temp = 0;
			for (int k = 0; k < m_A; k++) {
				temp += A[i * m_A + k] * *B[k * m_B + j];

//						get_el_ij<T1>(A, i, k, n_A, m_A)
//						* get_el_ij<T2>(B, k, j, n_B, m_B);

//				cout << A[i * m_A + k] << " x " << *B[k * m_B + j] << " +  ";
			}
//			cout << endl;
			C[i * m_B + j] = temp;
		}
	}
}

template<typename T>
void matrix_plus_matrix(int operand, T* A, int n_A, int m_A, T* B, T*C) {

//
// TODO: check of matrix sizes
//

	for (int i = 0; i < n_A; i++)
		for (int j = 0; j < m_A; j++)
			C[i * m_A + j] = A[i * m_A + j] + operand * B[i * m_A + j];
}

//функция вычеркивания строки и столбца
template<typename T>
void get_matr(T *A, int n_A, T *temp_matr, int indRow, int indCol) {

	int ki = 0;
	for (int i = 0; i < n_A; i++) {
		if (i != indRow) {
			for (int j = 0, kj = 0; j < n_A; j++) {
				if (j != indCol) {
					temp_matr[ki * n_A + kj] = A[i * n_A + j];
					kj++;
				}
			}
			ki++;
		}
	}
}

template<typename T>
T get_determinant(T *A, int n_A) {

	T temp = 0;   //временная переменная для хранения определителя
	int k = 1;      //степень

	if (n_A == 1)
		temp = A[0 + 0];
	else if (n_A == 2)
		temp = A[0 * n_A + 0] * A[1 * n_A + 1]
				- A[1 * n_A + 0] * A[0 * n_A + 1];
	else {
		for (int i = 0; i < n_A; i++) {
			int m = n_A - 1;
			T temp_matr[m * m];

			get_matr<T>(A, n_A, temp_matr, 0, i);

			temp = temp + k * A[0 * n_A + i] * get_determinant<T>(temp_matr, m);
			k = -k;
		}
	}
	return temp;
}

template<typename T>
void calculate_inverse_matrix(T* A, int n_A, T* B) {

//
// TODO: check of matrix sizes, check of determinant availability
//

	T temp_inverse_matr[n_A * n_A];

	T det = get_determinant<T>(A, n_A);

	if (det) {
		for (int i = 0; i < n_A; i++) {
			for (int j = 0; j < n_A; j++) {
				int m = n_A - 1;
				T temp_matr[m * m];

				get_matr<T>(A, n_A, temp_matr, i, j);

				temp_inverse_matr[i * n_A + j] = pow(-1.0, i + j + 2)
						* get_determinant<T>(temp_matr, m) / det;
			}
		}
	} else
		cout
				<< "Т.к. определитель матрицы = 0,\nто матрица вырожденная и обратной не имеет!!!"
				<< endl;

	for (int i = 0; i < n_A; i++)
		for (int j = 0; j < n_A; j++)
			B[j * n_A + i] = temp_inverse_matr[i * n_A + j];

}

string gen_file_name();
void create_output_file(string name_prefix, fstream& f);

#endif /* SRC_AUXILIARY_AUXILIARY_H_ */
