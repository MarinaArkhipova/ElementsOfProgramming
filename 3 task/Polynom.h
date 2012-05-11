#include <vector>
#include <utility>
#include <ostream>
#include <cassert>
#include "Fraction.h"

using namespace std;

class Polynom {
private:
	vector<Fraction> polynom;

public:

	Polynom() : polynom(1, Fraction(0, 1)) { }

	Polynom(const Polynom& another) {
		polynom = another.polynom;
	}

	Polynom(vector<int>& another) {
		polynom.resize(another.size(), 0);
		for (size_t i = 0; i < another.size(); i++) {
			polynom[i] = another[i];
		}
		deleteZeros();
	}
	
	void deleteZeros() {	
		Fraction toSee = polynom.back();
		while ((polynom.size() > 1) && (polynom.back().getNumerator() == 0)) {
			polynom.pop_back();
		}
	}

	void deleteSignes() {
		for (int i = 0; i <= pow(); i++) {
			if (polynom[i].getNumerator() < 0 && polynom[i].getDenominator() < 0) {
				Fraction current(-1,-1);
				polynom[i] = polynom[i]*current;
			}	
		}
	}


	void FillZeros() {
		for (size_t i = 0; i < polynom.size(); i++)
			polynom[i] = 0;
	}

	pair<Polynom,Polynom> divide(const Polynom& another) const {
		pair<Polynom, Polynom> result(Polynom(), *this); 
		result.first.deleteZeros();
		result.second.deleteZeros();

		while (result.second.pow() >= another.pow() && (result.second.pow() != 0 || result.second[0] != 0)/* && result.second.polynom[0].getNumerator() != 0*/) {
			Polynom temp;
			int i = result.second.pow() - another.pow();
			temp.polynom.resize(i + 1, 0);
			temp.polynom[i] = result.second[result.second.pow()] / another[another.pow()];
			temp.deleteSignes();
			result.first = result.first + temp;
			result.second = result.second - temp*another;

			result.second.deleteZeros();
			result.first.deleteSignes();
			result.second.deleteSignes();			
		}
		return result;
	}

	int pow() const {
		return static_cast<int>(polynom.size()) - 1;
	}

	Polynom& operator = (const Polynom& another) {
		polynom = another.polynom;
		deleteZeros();
		return *this;
	}

	Polynom operator + (const Polynom& another) {
		Polynom result = *this;
		result.polynom.resize(max(pow(), another.pow()) + 1, Fraction(0, 1));
		
		for(int i = 0; i <= another.pow(); i++) 
			result.polynom[i] = result.polynom[i] + another.polynom[i]; 
		result.deleteZeros();
		return result;
	}

	Polynom operator - (const Polynom& another) {
		Polynom result = *this;
		result.polynom.resize(max(pow(), another.pow()) + 1, Fraction(0, 1)); 
		
		for(int i = 0; i <= another.pow(); i++)
			result.polynom[i] = result.polynom[i] - another.polynom[i];
		
		result.deleteZeros();
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
		if ((*this == Polynom() || (polynom[0].getNumerator() == 0)) && (another == 0))
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
		if (pow() == 0 && another.pow() == 0) {
			if (polynom[0] > another.polynom[0])
				return true;
			else return false;
		}

		if (pow() > another.pow())
			return true;
		if (pow() == another.pow()) {
			int power = pow();
			while (power != 0) { 
				if (polynom[power] > another.polynom[power])
					return true;
				if (polynom[power] == another.polynom[power])
					power--;
				else return false;
			}
			return polynom[power] > another.polynom[power];
		}
		else return false;
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
	friend std::ostream& operator<<(std::ostream& os, const Polynom& polynomial)
	{
		os << polynomial.pow() << " :";
		for (int i = 0; i <= polynomial.pow(); ++i) {
			os << " " << polynomial[i];
		}
		return os;
	}

};

