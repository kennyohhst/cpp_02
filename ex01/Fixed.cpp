/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:11:08 by code              #+#    #+#             */
/*   Updated: 2024/02/06 21:08:52 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// CANONICAL CLASS FORM =======================================================
Fixed::Fixed(): _number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "int constructor called" << std::endl;
	this->_number = num << this->_num;
}


Fixed::Fixed(const float num)
{
	std::cout << "float constructor called" << std::endl;
	this->_number = roundf(num * (1 << this->_num));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "destructor called" << std::endl;
}
// ============================================================================


// COPY TO EXISTING THING, SO NOT NEW ONE =====================================
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
		_number = other.getRawBits();
    return *this;
}
// ============================================================================


// TO INT / TO FLOAT ==========================================================
int Fixed::toInt( void ) const
{
	// std::cout << "toInt called" << std::endl;
	return (this->_number >> this->_num);
}

float Fixed::toFloat( void ) const
{
	// std::cout << "toFloat called" << std::endl;
	return ((float)this->_number / (float)(1 << this->_num));
}
// ============================================================================


// GET + SET ==================================================================
int Fixed::getRawBits(void) const 
{
	// std::cout << "getRawBits member function called" << std::endl;
	return _number;
}

void Fixed::setRawBits( int const raw )
{
	_number = raw;
	// std::cout << "setRawBits member function called" << std::endl;
}
// ============================================================================


// OVERLOAD OSTREAM ===========================================================
std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
// ============================================================================