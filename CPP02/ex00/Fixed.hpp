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

		int	getRawBits() const;
		void	setRawBits(int const raw);
};

#endif