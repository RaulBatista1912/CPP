#pragma once
#include <cstddef>

template <typename T>
class Array {
	private:
		T	*array;
		unsigned int	len;

	public:
		Array();
		Array(unsigned int n);
		Array(Array const &copy);
		~Array();

		Array	&operator=(Array const &copy);
		T		&operator[](unsigned int i);

		size_t	size() const;

		class OutOfBoundsException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};
#include "Array.tpp"