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
		if (another > one) {
			int temp = another;
			another = one;
			one = temp;
		}
		int result = nod(one, another);
		if ((one % result != 0) || (another % result != 0))
			cout << "/nwrong result:/n" << "one: " << one << "\nanother: " << another << "\nresult: " << result << "\n"; 
	}
}

void testPolynoms() {
	for (int i = 0; i < 2; i++) {
		vector<int> first;
		vector<int> second;

		int first_size = getrand(5);
		int second_size = getrand(5);
		first.resize(first_size, 0);
		second.resize(second_size, 0);
		
		for (int i = 0; i < first_size; i++)
			first[i] = getrand(10);
		for (int i = 0; i < second_size; i++)
			second[i] = getrand(10);

		Polynom First_Polynom(first);
		Polynom Second_Polynom(second);
		if (Second_Polynom > First_Polynom) {
			Polynom temp(First_Polynom);
			First_Polynom = Second_Polynom;
			Second_Polynom = temp;
		}

   		Polynom First_Copy(First_Polynom);
		Polynom Second_Copy(Second_Polynom);
		Polynom result = First_Polynom % Second_Polynom;
		
		Polynom zero(result);
		zero.FillZeros();
		vector<int> unit;
		unit.push_back(0);
		Polynom unitZero(unit);

 		while (result != zero) {
			First_Polynom = Second_Polynom;
			Second_Polynom = result;
			result = First_Polynom % Second_Polynom;
			zero = result;
			zero.FillZeros();
		}

		if ((First_Copy % Second_Polynom != unitZero) || (Second_Copy % Second_Polynom != unitZero)) {
			cout << "\nfirst polynom: \n";
			First_Copy.Print();
			cout << "\nsecond polynom: \n"; 
			Second_Copy.Print();
			cout << "\nwrong result: \n";
			Second_Polynom.Print();  
			cout << "\n";
		}
	}
}


int main() {
	
	testPolynoms();
	

	return 0;
}