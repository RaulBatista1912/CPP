#pragma once

template <typename T>
void	swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename U>
const U& min(const U &a, const U &b) {
	return (a < b ? a : b);
}

template <typename V>
const V& max(const V &a, const V &b) {
	return (a > b ? a : b);
}
