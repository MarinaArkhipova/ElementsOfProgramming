#include <iostream>

template <typename T>
T nod(const T& a, const T& b) {
	if(a < b) {
		nod(b,a);
	} else {
		if	(b == 0) 
			return a;
		else 
		nod(b, a%b);
	}
}

class Fraction {
private:
	int numerator;
	int denominator;

public:
	Fraction(int a, int b) {
		numerator = a;
		denominator = b;	
		reduce();
	}

	Fraction(const Fraction& another) {
		numerator = another.numerator;
		denominator = another.denominator;
	}

	Fraction(const int another) {
		Fraction(another, 1);
	}

	void reduce() {
		int divider = nod(abs(numerator), abs(denominator));
		numerator = numerator/divider;
		denominator = denominator/divider;
	}

	Fraction& operator = (const Fraction& another_fraction) {
		numerator = another_fraction.numerator;
		denominator = another_fraction.denominator;
		return *this;
	}

	Fraction operator + (const Fraction& another_fraction){
		Fraction result = *this;
		result.numerator = result.numerator * another_fraction.denominator;
		result.numerator = result.numerator  +  another_fraction.numerator * denominator;
		result.denominator = result.denominator*another_fraction.denominator;
		result.reduce();
		return result;
	}

	Fraction operator - (const Fraction& another_fraction) {
		Fraction result = *this;
		result.numerator = result.numerator * another_fraction.denominator;
		result.numerator = result.numerator - another_fraction.numerator * denominator;
		result.denominator = result.denominator * another_fraction.denominator;
		result.reduce();
		return result;
	}

	Fraction operator * (const Fraction& another_fraction) {
		Fraction result = *this;
		result.numerator = result.numerator * another_fraction.numerator;
		result.denominator = result.denominator * another_fraction.denominator;
		result.reduce();
		return result;
	}

	Fraction operator / (const Fraction& another_fraction) const {
		Fraction result = *this;
		result.numerator = result.numerator * another_fraction.denominator;
		result.denominator = result.denominator * another_fraction.numerator;
		result.reduce();
		return result;
	}

	bool operator == (const Fraction& another_fraction) {
		if ((numerator == another_fraction.numerator)&&(denominator == another_fraction.denominator))
			return true;
		else return false;
	}

	bool operator != (const Fraction& another_fraction) const {
		if ((numerator != another_fraction.numerator)||(denominator != another_fraction.denominator))
			return true;
		else return false;
	}

	bool operator > (const Fraction& another_fraction) {
		if (numerator * another_fraction.denominator > denominator * another_fraction.numerator)
			return true;
		else return false;
	}

	bool operator < (const Fraction& another_fraction) {
		if (numerator * another_fraction.denominator < denominator * another_fraction.numerator)
			return true;
		else return false;
	}

	bool operator >= (const Fraction& another_fraction) {
		if (numerator * another_fraction.denominator >= denominator * another_fraction.numerator)
			return true;
		else return false;
	}

	bool operator <= (const Fraction& another_fraction) {	
		if (numerator * another_fraction.denominator <= denominator * another_fraction.numerator)
			return true;
		else return false;
	}

	Fraction& operator = (int number) {
		*this = Fraction(number, 1);
		return *this;
	}

	Fraction operator + (int number) {
		return *this + Fraction(number, 1);
	}

	Fraction operator - (int number) {
		return *this - Fraction(number, 1);;
	}

	Fraction operator * (int number) {
		return *this*Fraction(number, 1);
	}

	Fraction operator / (int number) const {
		return *this/Fraction(number, 1);
	}

	bool operator == (int number) {
		if (*this == Fraction(number, 1))
			return true;
		else return false;
	}

	bool operator != (int number) const {
		if (*this != Fraction(number, 1))
			return true;
		else return false;
	}

	int getNumerator() const {
		return numerator;
	}

	int getDenominator() const {
		return denominator;
	}

	void Print() {
		if(getDenominator() != 1) 
			std::cout << "(" << getNumerator() << "/" << getDenominator() << ")";
		else 
			std::cout << getNumerator();
	}
};
