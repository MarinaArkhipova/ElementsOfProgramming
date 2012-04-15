#pragma once
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include "matrix.cpp"
#include "algorithms.cpp"
#include "matrix.cpp"


int getrand(int number) {
	return (rand()%number)+1;
}

void errorNotice(const int result1, const int result2, int code) {
	if (result1 != result2) {
		if (code == 1)
			std::cout << "wrong answer in result with the same numbers:\n" << "function: " << result1 << " \n" << "simple_function: " << result2 << "\n";
		if (code == 2)
			std::cout << "wrong answer in result with the different numbers:\n" << "function: " << result1 << " \n" << "simple_function: " << result2 << "\n";
		exit(1);
	}
}

void checkingFunction() 
{
	Matrix<int> testMatrix(3,1);
	const size_t MOD = 1000;
	size_t n = getrand(MOD);
	int number = getrand(MOD);

	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 1; j++)
			testMatrix[i][j] = getrand(MOD); 

	Transformation<Matrix<int>> transform(n); 
	int result = preCycleLength(testMatrix,transform);
	int resultSimple = simplePreCycleLength(testMatrix,transform);

	errorNotice(result, resultSimple,1);	

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 1;  j++)
			testMatrix[i][j] = number;
	int resultForSameNumbers = preCycleLength(testMatrix,transform);
	int resultSimpleForSameNumbers = simplePreCycleLength(testMatrix,transform);
	errorNotice(resultForSameNumbers, resultSimpleForSameNumbers,2);	
}

int main() {

	for (int i = 0; i < 10; i++) {
		checkingFunction();
	}
	std::cout << "Everything is OK!\n";
	return 0;
}