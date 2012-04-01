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

	T operator () (T xo) const { 
		return (xo*37 + xo*xo + 7)%size_;
	}

	size_t size() const
	{
		return size_;
	}

private:
	size_t size_;
};

template <class T,  template <class> class Transformation>
int simple_PreCycleLength(const T& x0, Transformation<T>& transform) {
	vector<T> myvector;
	T result = x0;
	vector<T>::const_iterator it;
	do {
		myvector.push_back(result);
		result = transform(result);
		it = std::find(myvector.begin(), myvector.end(), result);
	} while (it == myvector.end());
	return it - myvector.begin();
}

template <class T, template <class> class Transformation>
T ElementInCycle(const T& xo, Transformation<T>& transform) {
	T x_current = xo;
	for (int i = 0; i < transform.size(); i++) {
		x_current = transform(x_current);
	}
	return x_current;
}

template <class T, template <class> class Transformation>
int CycleLength(T& element_in_cycle, Transformation<T>& transform) {
	T x_repeat_in_cycle = transform(element_in_cycle);         
	int length = 1;

	while (element_in_cycle != x_repeat_in_cycle) {
		x_repeat_in_cycle = transform(x_repeat_in_cycle);
		length++;    
	}
	return length;
}

template <class T, template <class> class  Transformation>
int PreCycleLength(const T& xo, Transformation<T>& transform) {
	int pre_cycle_length = 0;
	T elem_in_cycle = ElementInCycle(xo,transform);
	int length = CycleLength(elem_in_cycle,transform);

	T x1 = xo;	
	T x2 = x1;
	for (int i = 0; i < length; i++) {
		x2 = transform(x2);
	}	
	while (x1 != x2) {
		pre_cycle_length++;
		x1 = transform(x1);
		x2 = x1;
		for (int i = 0; i < length; i++)
			x2 = transform(x2);
	}
	return pre_cycle_length; 
}
