#include <vector>
#include <utility>
#include <ostream>
#include "Fraction.h"

using namespace std;

class Polynom {
private:
	vector<Fraction> polynom;

public:

	Polynom() {
		polynom.resize(1, Fraction(0, 1));
	}

	Polynom(const Polynom& another) {
		polynom = another.polynom;
		delete_zeros();
	}

	Polynom(vector<int>& another) {
		polynom.resize(another.size(), 0);
		for (int i = 0; i < another.size(); i++) {
			polynom[i] = another[i];
		}
		delete_zeros();
	}
	
	void delete_zeros() {		
		while ((polynom.back() == 0) && (polynom.size() > 1)) {
			polynom.pop_back();
		}
	}

	void FillZeros() {
		for (int i = 0; i < polynom.size(); i++)
			polynom[i] = 0;
	}

	pair<Polynom,Polynom> divide(const Polynom& another) const {
		pair<Polynom, Polynom> result(Polynom(), *this); 
		result.first.delete_zeros();
		result.second.delete_zeros();

		while (result.second.pow() >= another.pow() && (result.second.pow() != 0 || result.second[0] != 0)) {
			Polynom temp;
			int i = result.second.pow() - another.pow();
			temp.polynom.resize(i + 1, 0);
			temp.polynom[i] = result.second[result.second.pow()] / another[another.pow()];
			result.first = result.first + temp;
			result.second = result.second - temp*another;
		}
		return result;
	}

	int pow() const {
		return polynom.size() - 1;
	}

	void operator = (const Polynom& another) {
		polynom = another.polynom;
		delete_zeros();
		//return *this;
	}

	Polynom operator + (const Polynom& another) {
		Polynom result = *this;
		result.polynom.resize(max(pow(), another.pow()) + 1, Fraction(0, 1));
		
		for(int i = 0; i <= another.pow(); i++) 
			result.polynom[i] = result.polynom[i] + another.polynom[i]; 
		result.delete_zeros();
		return result;
	}

	Polynom operator - (const Polynom& another) {
		Polynom result = *this;
		result.polynom.resize(max(pow(), another.pow()) + 1, Fraction(0, 1)); 
		
		for(int i = 0; i <= another.pow(); i++)
			result.polynom[i] = result.polynom[i] - another.polynom[i];
		
		result.delete_zeros();
		return result;
	}

	Polynom operator * (const Polynom& another) {
		Polynom result;
		result.polynom.resize(pow() + another.pow() + 1, Fraction(0, 1));
		for(int i = 0; i <= pow(); i++) {
			for(int j = 0; j <= another.pow(); j++) {
				result.polynom[i+j] = result.polynom[i+j] + polynom[i]*another.polynom[j];
			}
		}
		return result;
	}

	Polynom operator / (const Polynom& another)  {
		return divide(another).first;
	}

	Polynom operator % (const Polynom& another) const {
		return divide(another).second;
	}

	bool operator != (int another) const {
		if ((*this == Polynom()) && (another == 0))
			return false;
		else return true;
	}

	bool operator == (const Polynom& another) const {
		if (pow() != another.pow()) {
			return false;
		}
		for (int i = 0; i <= pow(); i++) {
			if (polynom[i] != another.polynom[i]) 
				return false;
		}
		return true;
	}

	bool operator != (const Polynom& another) {
		return !(*this == another);
	}

	bool operator > (const Polynom& another) {
		return pow() > another.pow();
	}

	bool operator < (const Polynom& another) const{
		return pow() < another.pow();
	}

	bool operator >= (const Polynom& another) {
		return pow() >= another.pow();
	}

	bool operator <= (const Polynom& another) {
		return pow() <= another.pow();
	}

	const Fraction& operator [] (int i) const {
		return polynom[i];
	}

	void Print() {
		bool notFirst = false;

		for (int i = pow(); i > 1; i--) {
			if (polynom[i] != 0) {
				if ((polynom[i] > 0) && notFirst) {
					cout << "+";
				}
				if (polynom[i] != 1) {
					polynom[i].Print();
					cout << "*";
				}

				cout << "x^" << i << " ";
			}
			notFirst = true;
		}

		if (pow() > 0) {
			if ((polynom[1] > 0) && notFirst) {
				cout << "+";
			}
			if (polynom[1] != 1) {
				polynom[1].Print();
				cout << "*";
			}
			cout << "x ";
		}

		if (polynom[0] > 0) {
			cout << "+";
			polynom[0].Print();
		} else 
			if (polynom[0] < 0) {
				polynom[0].Print();
			}
		}

};

