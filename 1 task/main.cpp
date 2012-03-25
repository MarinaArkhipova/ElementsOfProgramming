#pragma once
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include "matrix.cpp"
#include "algorithms.cpp"
#include "matrix.cpp"
#include "algorithms.cpp"

int getrand(const int number) {
	return (rand()%number)+1;
}

void error_notice(const int result1, const int result2, int code) {
	try {
	if (result1 != result2) throw 1;
	}
	catch(int) {
		if (code == 1)
			std::cout << "wrong answer in result with the same numbers:\n" << "function: " << result1 << " \n" << "simple_function: " << result2 << "\n";
		if (code == 2)
			std::cout << "wrong answer in result with the different numbers:\n" << "function: " << result1 << " \n" << "simple_function: " << result2 << "\n";
	}
}

void cheking_function() 
{
	Matrix<int> testMatrix(3,1);
	int n = getrand(1000);
	int number = getrand(1000);

	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 1; j++)
			testMatrix[i][j] = getrand(1000); 

	int result = function(testMatrix,n);
	int result_simple = another_function(testMatrix,n);

	error_notice(result, result_simple,1);	

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 1;  j++)
			testMatrix[i][j] = number;
	int result_for_same_numbers = function(testMatrix,n);
	int result_simple_for_same_numbers = another_function(number,n);	

	error_notice(result_for_same_numbers, result_simple_for_same_numbers,2);
	}

int main() {

	for (int i = 0; i < 10; i++) {
		cheking_function();
	}
	std::cout << "Everything is OK!\n";
	return 0;
}