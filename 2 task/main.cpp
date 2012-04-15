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

	Matrix operator()(const Matrix& one, const Matrix& another) const
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
T multiply(const T& element, size_t power, const BinaryOperations<T>& f) {
	T powElement = element;
	size_t position = 0;
	T result = f.unity();                                          

	while (static_cast<size_t>(1)<<position <= power) {
		if (power & (1<<position)) 
			result = f(result, powElement);
		++position;
		powElement = f(powElement, powElement);
	}

	return result;
}

template <typename T>
T simpleMultiply(const T& number, int power) {
	if (power == 0)
		return 1;

	T result = number;
	power--;
	
	while (power > 0) {
		power--;
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
        int resultSimple = simpleMultiply(number,stepen);
		if (result != resultSimple) {
			cout << "\n error with integers:\n result: " << result << "\n" << "result_simple: " << resultSimple << "\n\n";
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
		Matrix<int> resultSimple = simpleMultiply(a,stepen);
		
		if (result != resultSimple) {
				cout << "error with matrixes:\n";
				result.print();
				cout << "\n\n";
				resultSimple.print();
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
