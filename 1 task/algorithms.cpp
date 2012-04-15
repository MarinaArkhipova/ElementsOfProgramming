#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
class Transformation
{
public:              
	Transformation(size_t size) {
		size_ = size;
	}

	T operator () (const T& element) const { 
		return (element*37 + element*element + 7)%size_;
	}

	size_t size() const
	{
		return size_;
	}

private:
	size_t size_;
};

template <class T,  template <class> class Transformation>
int simplePreCycleLength(const T& startElement, const Transformation<T>& transform) {
	vector<T> _vector;
	T element = startElement;
	vector<T>::const_iterator it;
	do {
		_vector.push_back(element);
		element = transform(element);
		it = std::find(_vector.begin(), _vector.end(), element);
	} while (it == _vector.end());
	return it - _vector.begin();
}

template <class T, template <class> class Transformation>
T elementInCycle(const T& startElement, const Transformation<T>& transform) {
	T x_current = startElement;
	for (int i = 0; i < transform.size(); i++) {
		x_current = transform(x_current);
	}
	return x_current;
}

template <class T, template <class> class Transformation>
int cycleLength(T& elementInCycle, const Transformation<T>& transform) {
	T xRepeatInCycle = transform(elementInCycle);         
	int length = 1;

	while (elementInCycle != xRepeatInCycle) {
		xRepeatInCycle = transform(xRepeatInCycle);
		length++;    
	}
	return length;
}

template <class T, template <class> class  Transformation>
int preCycleLength(const T& startElement, const Transformation<T>& transform) {
	int preCycleLength = 0;
	T elemInCycle = elementInCycle(startElement,transform);
	int length = cycleLength(elemInCycle,transform);

	T element1 = startElement;	
	T element2 = element1;
	for (int i = 0; i < length; i++) {
		element2 = transform(element2);
	}	
	while (element1 != element2) {
		preCycleLength++;
		element1 = transform(element1);
		element2 = element1;
		for (int i = 0; i < length; i++)
			element2 = transform(element2);
	}
	return preCycleLength; 
}
