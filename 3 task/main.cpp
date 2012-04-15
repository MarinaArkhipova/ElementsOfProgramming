#include "Polynom.h"
#include <iostream>
#include <vector>

using namespace std;

int getrand(int number) {
	return (rand()%number)+1;
}

void testIntegers() {
	for (int i = 0; i < 10; i++) {
		int one = getrand(1000);
		int another = getrand(1000);
		int result = nod(one, another);
		if ((one % result != 0) || (another % result != 0))
			cout << "/nwrong result:/n" << "one: " << one << "\nanother: " << another << "\nresult: " << result << "\n"; 
	}
}

void testPolynoms() {
	for (int i = 0; i < 1; i++) {
		vector<int> first;
		vector<int> second;

		int firstSize = getrand(5);
		int secondSize = getrand(5);
		first.resize(firstSize, 0);
		second.resize(secondSize, 0);
		
		for (int i = 0; i < firstSize; i++)
			first[i] = getrand(10);
		for (int i = 0; i < secondSize; i++)
			second[i] = getrand(10);

		Polynom firstPolynom(first);
		Polynom secondPolynom(second);
		
		Polynom result = nod(firstPolynom, secondPolynom);
		if (!(firstPolynom / result*result == firstPolynom && secondPolynom / result*result == secondPolynom))
			cout << "wrong answer\n";
			
	} 
}


int main() {
	
	testIntegers();
	testPolynoms();
	
	return 0;
}