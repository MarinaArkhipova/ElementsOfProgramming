#include <stdio.h>
#include <iostream>
#include "matrix.h"

using namespace std;

template <class Matrix>
class MatrixBinaryOperation 
{
public:
	MatrixBinaryOperation(int _size)
	{
		size = _size;
	}

	Matrix operator()(const Matrix& one, const Matrix& another)
	{
		return one*another;
	}

	Matrix unity() const
	{
		return Matrix::unitMatrix(size);
	}
private:
	int size;
}; 

template <class T>
class BinaryOperation 
{
public:

	T operator()(const T& a, const T& b) const {
		return a*b;
	}

	T unity() const {
		return T(1);
	}
};

template <class T, template <class> class BinaryOperations> 
T multiply(const T& a, size_t n, const BinaryOperations<T>& f) {
	T powA = a;
	size_t pos = 0;
	T res = f.unity();                                          

	while (static_cast<size_t>(1)<<pos <= n) {
		if (n & (1<<pos)) 
			res = res*powA;
		++pos;
		powA = powA * powA;
	}

	return res;
}

template <typename T>
T simple_multiply(const T& number, int stepen) {
	if (stepen == 0)
		return 1;

	T result = number;
	stepen--;
	
	while (stepen > 0) {
		stepen--;
		result = result*number;
	}
	return result;
}

void testIntegers()
{	
	for(int i = 0; i < 5; i++) {

        int stepen = rand()%10+1;
        int number = rand()%10+1;
        BinaryOperation<int> func;
    
        int result = multiply(number,stepen,func);
        int result_simple = simple_multiply(number,stepen);
		if (result != result_simple) {
			cout << "\n error with integers:\n result: " << result << "\n" << "result_simple: " << result_simple << "\n\n";
			assert(false);
		}
    }
}

void testMatrices()
{
	for (int y = 0; y < 5; y++) {

		int size = rand()%2+1;
		int stepen = rand()%5+1;
		int number = rand()%10+1;
		MatrixBinaryOperation<Matrix<int>> func(size);

		Matrix<int> a(size);
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				a[i][j] = number;

		Matrix<int> result = multiply(a,stepen,func);
		Matrix<int> result_simple = simple_multiply(a,stepen);
		
		if (result != result_simple) {
				cout << "error with matrixes:\n";
				result.print();
				cout << "\n\n";
				result_simple.print();
				cout << "\n\n";
				assert(false);
		}
	}
}

int main() {
	
	testIntegers();
	testMatrices();

	return 0;
}
