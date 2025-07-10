#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : value(other.value) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(int const n) {
	std::cout << "Int constructor called" << std::endl;
	value = n << fracBits;
}

Fixed::Fixed(float const f) {
	std::cout << "Float constructor called" << std::endl;
	value = (int)roundf(f * (1 << fracBits));
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.value;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void	Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float	Fixed::toFloat() const {
	return ((float)value) / (1 << fracBits);
}

int	Fixed::toInt() const {
	return value >> fracBits;
}

std::ostream& operator<<(std::ostream& os, Fixed const& fixed) {
	os << fixed.toFloat();
	return os;
}