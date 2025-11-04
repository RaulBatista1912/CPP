#pragma once
#include <exception>
#include <vector>

class Span {
	private:
		unsigned int		_N;
		std::vector<int>	vec;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void	addNumber(int n);
		int	shortestSpan();
		int	longestSpan();
		void	addMultipleNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		class ContainerFullException : public std::exception {
			public :
				virtual const char *what() const throw();
		};

		class NotEnoughNumberInSpanException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
};