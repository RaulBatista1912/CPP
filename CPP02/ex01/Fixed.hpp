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
		Fixed& operator=(const Fixed& other);
		~Fixed();
		Fixed(int const n);
		Fixed(float const f);

		int	getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int	toInt() const;
};

std::ostream& operator<<(std::ostream& os, Fixed const& fixed);

#endif