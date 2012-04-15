#pragma once
template <typename T>
class Matrix
{  
private:
	int height;
	int width;
	T** matrix;

public: 

	Matrix(int _height, int _width) 
	{
		this->width = _width;
		this->height = _height;

		this->matrix = new int*[this->height];             
		for (int i = 0; i < this->height; i++)
			this->matrix[i] = new int[this->width];  

		for (int i = 0; i < this->height; i++)
			for (int j = 0; j < this->width; j++)
				this->matrix[i][j] = 0;
	}

	Matrix(int _height, int _width, T** Values)
	{
		this->width = _width;
		this->height = _height;

		this->matrix = new T*[this->height];             
		for (int i = 0; i < this->height; i++)
			this->matrix[i] = new T[this->width];  

		for (int i = 0; i < this->height; i++)
		{
			for (int j = 0; j < this->width; j++)
				this->matrix[i][j] = Values[i][j];
		}
	}

	Matrix(const Matrix<T>& AnotherMatrix)          
	{
		this->height = AnotherMatrix.getHeight();
		this->width = AnotherMatrix.getWidth();
		matrix = new T*[AnotherMatrix.getHeight()];             
		for (int i = 0; i < AnotherMatrix.getHeight(); i++)
			matrix[i] = new T[AnotherMatrix.getWidth()];

		for (int i = 0; i < AnotherMatrix.getHeight(); i++)
		{
			for (int j = 0; j < AnotherMatrix.getWidth(); j++)
				matrix[i][j] = AnotherMatrix.matrix[i][j];
		} 
	}
	~Matrix<T>()
	{
		for(int i = 0; i < height; i++)
			delete [] matrix[i];
		delete [] matrix;
	}

	Matrix<T> operator * (const Matrix<T> &AnotherMatrix) const
	{
		Matrix<T> Mul(height, AnotherMatrix.getWidth());
		T  temp;
		for (int i = 0; i < height; i++)
		{	for (int j = 0; j < AnotherMatrix.getWidth(); j++)
			{
				temp = 0;
				for (int k = 0; k < width; k++)
					temp += matrix[i][k]*AnotherMatrix.matrix[k][j];

				Mul.Set(i, j, temp);
			}
		}

		return Mul;
	}

	Matrix<T> operator + (const Matrix<T>& AnotherMatrix) 
	{
		int sumheight = AnotherMatrix.getHeight();
		int sumwidth = AnotherMatrix.getWidth();
		Matrix<T> Sum(sumheight, sumwidth);

		for (int i = 0; i < sumheight; i++)
		{
			for (int j = 0; j < sumwidth; j++)
				Sum[i][j] = AnotherMatrix[i][j] + matrix[i][j];
		}
		return Sum;
	}

	bool operator == (const Matrix<T>& second)
	{
		for (int i = 0; i < this->height; i++)
			for (int j = 0; j < this->width; j++)
				if (this->matrix[i][j] != second[i][j])
					return false;
		return true;

	}

	Matrix<T> operator = (const Matrix<T> &_matrix) 
	{
		height = _matrix.getHeight();
		width = _matrix.getWidth();
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				matrix[i][j] = _matrix[i][j];
		return Matrix<T>(height,width,matrix);
	}

	bool operator != (const Matrix<T> AnotherMatrix) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++)
				if (matrix[i][j] != AnotherMatrix[i][j])
					return true;
		}
		return false;
	}


	Matrix<T> operator + (const int number)
	{
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				matrix[i][j] = matrix[i][j] + number;
		return Matrix<T>(height,width,matrix);
	}

	Matrix<T> operator * (const int number) const {
		Matrix<T> result(height, width);
		for (int i = 0; i < height; i++){
			for (int j = 0; j < width; j++)
				result[i][j] = matrix[i][j]*number;
		}
		return result; 
	}

	Matrix<T> operator % (int number) 
	{
		Matrix<T> result(height,width);
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				result[i][j] = matrix[i][j]%number;
		return result;
	}

	T* operator [](int x) 
	{
		return matrix[x];
	}

	const T* operator [] (int x) const // для присвоения матрицы к матрице. const
	{
		return matrix[x];
	}

	int getWidth() const
	{
		return width;
	}

	int getHeight() const
	{
		return height;
	}

	void Set(int i, int j, T Value)
	{
		matrix[i][j] = Value;
	}
};