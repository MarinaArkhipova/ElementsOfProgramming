#include "Polynom.h"
#include <iostream>
#include <vector>

using namespace std;

int randomModulo(int number) {
	return (rand()%number)+1;
}

void testIntegers() {
	bool flag = true;
	for (int i = 0; i < 30; i++) {
		int one = randomModulo(1000);
		int another = randomModulo(1000);
		int result = nod(one, another);
		if ((one % result != 0) || (another % result != 0)) {
			cout << "/nwrong result:/n" << "one: " << one << "\nanother: " << another << "\nresult: " << result << "\n"; 
			flag = false;
		}
	}
	if (flag)
		cout << "Integer test completed\n";
}

void testPolynoms() {
	bool flag = true;
	for (int j = 0; j < 3000; j++) {

		vector<int> first;
		vector<int> second;

		int firstSize = randomModulo(3);
		int secondSize = randomModulo(3);
		first.resize
			(firstSize, 0);
		second.resize(secondSize, 0);
		
		for (int i = 0; i < firstSize; i++)
			first[i] = randomModulo(5);
		for (int i = 0; i < secondSize; i++)
			second[i] = randomModulo(5);

		Polynom firstPolynom(first);
		Polynom secondPolynom(second);
		firstPolynom.deleteSignes();
		secondPolynom.deleteSignes();
		
		Polynom result = nod(firstPolynom, secondPolynom);
		Polynom current1 = firstPolynom/result*result; 
		current1.deleteSignes();
		Polynom current2 = secondPolynom/result*result;
		current2.deleteSignes();

		if (!(current1 == firstPolynom && current2 == secondPolynom)) {
			cout << firstPolynom << endl;
			cout << secondPolynom << endl;
			cout << result << endl;
			cout << current1 << endl;
			cout << current2 << endl;
			//cout << current1 << endl;
			cout << "wrong answer " << j << "\n";
			flag = false;
		}			
	} 
	if (flag)
		cout << "Polynom test completed\n";
}

int main() {

	testIntegers();
	testPolynoms();
	
	return 0;
}