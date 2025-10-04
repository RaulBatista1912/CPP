#include "Span.hpp"
#include <algorithm>

Span::Span() : _N(0) {

}

Span::Span(unsigned int N) : _N(N) {

}

Span::Span(const Span &other) : _N(other._N), vec(other.vec) {

}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_N = other._N;
		vec = other.vec;
	}
	return *this;
}

Span::~Span() {
	
}

void	Span::addNumber(int n) {
	if (vec.size() >= _N)
		throw ContainerFullException();
	vec.push_back(n);
}

int	Span::shortestSpan() {
	if (vec.size() <= 1)
		throw NotEnoughNumberInSpanException();
	std::vector<int> tmp = vec;
	std::sort(tmp.begin(), tmp.end());
	int	shortest = tmp[1] - tmp[0];
	for (unsigned int i = 0; i < (tmp.size() - 1); i++) {
		if ((tmp[i + 1] - tmp[i]) < shortest)
			shortest = (tmp[i + 1] - tmp[i]);
	}
	return (shortest);
}

int	Span::longestSpan() {
	if (vec.size() <= 1)
		throw NotEnoughNumberInSpanException();
	std::vector<int> tmp = vec;
	std::sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());

}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (vec.size() + std::distance(begin, end) > _N)
		throw ContainerFullException();
	vec.insert(vec.end(), begin, end);
}

const char* Span::ContainerFullException::what() const throw() {
	return "Container is full!";
}

const char* Span::NotEnoughNumberInSpanException::what() const throw() {
	return "Not enough Numbers in Span!";
}
