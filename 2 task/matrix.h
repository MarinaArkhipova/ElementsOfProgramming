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

	Matrix(int _size, const T** values)  
	{
		size = _size;
		this->matrix = new T*[size];             
		for (int i = 0; i < size; i++)
			this->matrix[i] = new T[size];  

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				this->matrix[i][j] = values[i][j];
		}
	}
              
	Matrix(const Matrix<T>& anotherMatrix)          
	{
		size = anotherMatrix.size;
		matrix = new T*[size];             
		for (int i = 0; i < size; i++)
			matrix[i] = new T[size];

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				matrix[i][j] = anotherMatrix.matrix[i][j];
		} 
	}

	bool operator != (Matrix<T> anotherMatrix) const
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				if (matrix[i][j] != anotherMatrix[i][j])
					return true;
		return false;
	}

	Matrix<T> operator*(Matrix<T> const &anotherMatrix) const
	{
		Matrix<T> Mul(anotherMatrix.size);
		T  temp;
		for (int i = 0; i < anotherMatrix.size; i++)
		{	for (int j = 0; j < anotherMatrix.size; j++)
			{
				temp = 0;
				for (int k = 0; k < anotherMatrix.size; k++)
					temp += matrix[i][k]*anotherMatrix.matrix[k][j];

				Mul.Set(i, j, temp);
			}
		}
		return Mul;
	}

	Matrix<T>& operator = (const Matrix<T> anotherMatrix)
	{
		size = anotherMatrix.size;
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] = anotherMatrix[i][j];
		return *this;
	}

	void print() const
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

	void Set(int i, int j, T Value) const
	{
		matrix[i][j] = Value;
	}
};