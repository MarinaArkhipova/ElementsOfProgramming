#include <iostream>
#include <algorithm>

template <class T>
T nod(const T& a, const T& b) {
	T aCopy = a;
	T bCopy = b;	
	
	if (aCopy == bCopy)
		return aCopy;
	while (!(bCopy == T())) {
		if (aCopy > bCopy) {
			aCopy = aCopy % bCopy;
			swap(aCopy,bCopy);
		} else 
			swap(aCopy,bCopy);
	}
	return aCopy;
}

long long abs(long long x)
{
	if (x < 0) x = -x;
	return x;
}

class Fraction {
private:
	long long numerator;
	long long denominator;

public:
	Fraction(long long a, long long b) : numerator(a), denominator(b)
	{	
		reduce();
	}

	Fraction(const Fraction& another) {
		numerator = another.numerator;
		denominator = another.denominator;
	}

	Fraction(long long number) : numerator(number), denominator(1)
	{
		reduce();
	}

	void reduce() {
		if (denominator <  0) {
			denominator *= -1;
			numerator *= -1;
		}
		long long divider = nod(abs(numerator), denominator);
		numerator = numerator/divider;
		denominator = denominator/divider;
	}

	Fraction& operator = (const Fraction& anotherFraction) {
		numerator = anotherFraction.numerator;
		denominator = anotherFraction.denominator;
		return *this;
	}

	Fraction operator + (const Fraction& anotherFraction)
	{
		return Fraction(numerator * anotherFraction.denominator +
						anotherFraction.numerator * denominator,
						denominator*anotherFraction.denominator);
	}

	Fraction operator - (const Fraction& anotherFraction) {
		return Fraction(numerator * anotherFraction.denominator -
						anotherFraction.numerator * denominator,
						denominator*anotherFraction.denominator);
	}

	Fraction operator * (const Fraction& anotherFraction) {
		return Fraction(numerator * anotherFraction.numerator,
						denominator * anotherFraction.denominator);
	}

	Fraction operator / (const Fraction& anotherFraction) const {
		return Fraction(numerator * anotherFraction.denominator,
						denominator * anotherFraction.numerator);
	}

	bool operator == (const Fraction& anotherFraction) const {
		if ((numerator == anotherFraction.numerator)&&(denominator == anotherFraction.denominator))
			return true;
		else return false;
	}

	bool operator != (const Fraction& anotherFraction) const {
		if ((numerator != anotherFraction.numerator)||(denominator != anotherFraction.denominator))
			return true;
		else return false;
	}

	bool operator > (const Fraction& anotherFraction) const {
		if (numerator * anotherFraction.denominator > denominator * anotherFraction.numerator)
			return true;
		else return false;
	}

	bool operator < (const Fraction& anotherFraction) const {
		if (numerator * anotherFraction.denominator < denominator * anotherFraction.numerator)
			return true;
		else return false;
	}

	bool operator >= (const Fraction& anotherFraction) const {
		if (numerator * anotherFraction.denominator >= denominator * anotherFraction.numerator)
			return true;
		else return false;
	}

	bool operator <= (const Fraction& anotherFraction) const {	
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

	long long getNumerator() const {
		return numerator;
	}

	long long getDenominator() const {
		return denominator;
	}

// FIXME operator<<
	void Print() {
		if(getDenominator() != 1) 
			std::cout << "(" << getNumerator() << "/" << getDenominator() << ")";
		else
			std::cout << getNumerator();
	}
	friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction)
	{
		os << fraction.getNumerator() << "/" << fraction.getDenominator();
		return os;
	}
};
