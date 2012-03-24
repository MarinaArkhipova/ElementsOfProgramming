#pragma once
#include <vector>
#include <iostream>

template <typename T>              
T count (T xo, int n) {
	T result = (xo*37 + xo*xo + 7)%n; 
	return result;
}

template<typename T>
int find(T& a, std::vector<T>& find_vector) {
	for (int i = 0; i < find_vector.size(); i++) {
		if (find_vector[i] == a)
			return i;
	}
	return -1;
}

template<typename T>
int another_function(const T& x0, const int n) {
	std::vector<T> myvector;
	T result = x0;
	int index = -1;
	while (index == -1) {
		myvector.push_back(result);
		result = count(result,n);
		index = find(result, myvector);
	}
	return index;
}

template <typename T>
int function(const T xo, const int n) {
	T xcur = xo;
	T x2 = xo;
	for (int i = 0; i < n+1; i++) {
		xcur = count(xcur,n);
	}

	T xcur2 = count(xcur,n);
	int ch = 1;

	while (xcur != xcur2) {
		xcur2 = count(xcur2,n);
		ch++;    // ch - length of cycle
	}
	
	T x3 = x2;
	for (int i = 0; i < ch; i++) {
		x3 = count(x3,n);
	}

	
	int last_count = 0;

	while (x2 != x3) {
	
		last_count++;
		x2 = count(x2,n);
		x3 = x2;
		for (int i = 0; i < ch; i++)
			x3 = count(x3,n);
	}

	return last_count; 
}
