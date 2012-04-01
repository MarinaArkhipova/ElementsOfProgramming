#include <malloc.h>
#include <assert.h>

template <typename T>
class Matrix
{  
private:
	int size;
	T** matrix;

public: 
	static Matrix<T> unitMatrix(int _size)   
	{
		Matrix<T> unit_Matrix(_size);
		for (int i = 0; i < _size; i++) 
			unit_Matrix[i][i] = 1;

		return unit_Matrix;
	}

	Matrix(int _size) 
	{
		size = _size;
		this->matrix = new T*[size];             
		for (int i = 0; i < size; i++)
			this->matrix[i] = new T[size];  

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				this->matrix[i][j] = 0;
		}
	}

	Matrix(int _size, T** Values)  
	{
		size = _size;
		this->matrix = new T*[size];             
		for (int i = 0; i < size; i++)
			this->matrix[i] = new T[size];  

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				this->matrix[i][j] = Values[i][j];
		}
	}
              
	Matrix(const Matrix<T>& AnotherMatrix)          
	{
		size = AnotherMatrix.size;
		matrix = new T*[size];             
		for (int i = 0; i < size; i++)
			matrix[i] = new T[size];

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				matrix[i][j] = AnotherMatrix.matrix[i][j];
		} 
	}

	bool operator != (Matrix<T> AnotherMatrix)
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				if (matrix[i][j] != AnotherMatrix[i][j])
					return true;
		return false;
	}

	Matrix<T> operator*(Matrix<T> const &AnotherMatrix) const
	{
		Matrix<T> Mul(AnotherMatrix.size);
		T  temp;
		for (int i = 0; i < AnotherMatrix.size; i++)
		{	for (int j = 0; j < AnotherMatrix.size; j++)
			{
				temp = 0;
				for (int k = 0; k < AnotherMatrix.size; k++)
					temp += matrix[i][k]*AnotherMatrix.matrix[k][j];

				Mul.Set(i, j, temp);
			}
		}

		return Mul;
	}

	Matrix<T>& operator = (const Matrix<T> _matrix) 
	{
		size = _matrix.size;
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] = _matrix[i][j];
		return *this;
	}

	void print()
	{
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
				std::cout << matrix[i][j] << " ";
			std::cout << "\n";
		}
	}

	T* operator[](int x) 
	{
		return matrix[x];
	}

	const T* operator[](int x) const 
	{
		return matrix[x];
	}

	void Set(int i, int j, T Value)
	{
		matrix[i][j] = Value;
	}
};