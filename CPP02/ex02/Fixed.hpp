#include <ostream>

#ifndef FIXED_HPP
#define FIXED_HPP

class	Fixed {
	private:
		int	value;
		static const int	fracBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(int const n);
		Fixed(float const f);
		~Fixed();

		Fixed& operator=(const Fixed& other);

		//comparison
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		//arithmetic
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		//incr and decr
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		//min and max
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

		int		getRawBits() const;
		void	setRawBits(int const raw);

		float	toFloat() const;
		int		toInt() const;
		
};

std::ostream& operator<<(std::ostream& os, Fixed const& fixed);

#endif