/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:09:18 by code              #+#    #+#             */
/*   Updated: 2024/02/06 21:15:07 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
		int _number;
		const int _num = 8;
    public:
	// CANONICAL CLASS FORM
		Fixed ();
		Fixed (const int num);
		Fixed (const float num);
	// CONTRUCT && BUT COPY AND MAKE NEW ONE
		Fixed(const Fixed& other);


	// DESTRUCT
		~Fixed ();

	// COPY TO EXISTING THING, SO NOT NEW ONE
		Fixed& operator=(const Fixed& other);

	//A-operators		
		float operator+(Fixed other)const;
		float operator-(Fixed other)const;
		float operator*(Fixed other)const;
		float operator/(Fixed other)const;
		
	//C-operators
		bool operator==(Fixed other)const;
		bool operator<=(Fixed other)const;
		bool operator>=(Fixed other)const;
		bool operator<(Fixed other)const;
		bool operator>(Fixed other)const;
		bool operator!=(Fixed other)const;


	// RETURN THE HIGHEST OR LOWEST
		static Fixed&min (Fixed &one, Fixed &two);
		static Fixed&max (Fixed &one, Fixed &two);
		
		static const Fixed&min (const Fixed &one, const Fixed &two);
		static const Fixed&max (const Fixed &one, const Fixed &two);

	// TO INT / TO FLOAT
		int toInt( void ) const;
		float toFloat( void ) const;
		
	// PRE
		Fixed operator++();
		Fixed operator--();
		
	//POST
		Fixed operator++(int);
		Fixed operator--(int);
		
	// GET + SET
		int getRawBits(void) const;
		void setRawBits(int const raw);
};


// OVERLOAD OSTREAM
std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif
