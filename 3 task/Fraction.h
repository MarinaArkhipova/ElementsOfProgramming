#include <iostream>
#include <algorithm>

template <class T>
T nod(const T& a, const T& b) {
	T aCopy = a;
	T bCopy = b;	
	

	while (bCopy != 0) {
		if (aCopy > bCopy) {
			aCopy = aCopy % bCopy;
			swap(aCopy,bCopy);
		} else 
			swap(aCopy,bCopy);
	}
	return aCopy;
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

	Fraction& operator = (const Fraction& anotherFraction) {
		numerator = anotherFraction.numerator;
		denominator = anotherFraction.denominator;
		return *this;
	}

	Fraction operator + (const Fraction& anotherFraction){
		Fraction result = *this;
		result.numerator = result.numerator * anotherFraction.denominator;
		result.numerator = result.numerator  +  anotherFraction.numerator * denominator;
		result.denominator = result.denominator*anotherFraction.denominator;
		result.reduce();
		return result;
	}

	Fraction operator - (const Fraction& anotherFraction) {
		Fraction result = *this;
		result.numerator = result.numerator * anotherFraction.denominator;
		result.numerator = result.numerator - anotherFraction.numerator * denominator;
		result.denominator = result.denominator * anotherFraction.denominator;
		result.reduce();
		return result;
	}

	Fraction operator * (const Fraction& anotherFraction) {
		Fraction result = *this;
		result.numerator = result.numerator * anotherFraction.numerator;
		result.denominator = result.denominator * anotherFraction.denominator;
		result.reduce();
		return result;
	}

	Fraction operator / (const Fraction& anotherFraction) const {
		Fraction result = *this;
		result.numerator = result.numerator * anotherFraction.denominator;
		result.denominator = result.denominator * anotherFraction.numerator;
		result.reduce();
		return result;
	}

	bool operator == (const Fraction& anotherFraction) {
		if ((numerator == anotherFraction.numerator)&&(denominator == anotherFraction.denominator))
			return true;
		else return false;
	}

	bool operator != (const Fraction& anotherFraction) const {
		if ((numerator != anotherFraction.numerator)||(denominator != anotherFraction.denominator))
			return true;
		else return false;
	}

	bool operator > (const Fraction& anotherFraction) {
		if (numerator * anotherFraction.denominator > denominator * anotherFraction.numerator)
			return true;
		else return false;
	}

	bool operator < (const Fraction& anotherFraction) {
		if (numerator * anotherFraction.denominator < denominator * anotherFraction.numerator)
			return true;
		else return false;
	}

	bool operator >= (const Fraction& anotherFraction) {
		if (numerator * anotherFraction.denominator >= denominator * anotherFraction.numerator)
			return true;
		else return false;
	}

	bool operator <= (const Fraction& anotherFraction) {	
		if (numerator * anotherFraction.denominator <= denominator * anotherFraction.numerator)
			return true;
		else return false;
	}

	Fraction& operator = (int number) {
		return *this = Fraction(number, 1);
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
