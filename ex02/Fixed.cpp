/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:11:08 by code              #+#    #+#             */
/*   Updated: 2024/02/06 20:57:36 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// CANONICAL CLASS FORM =======================================================
Fixed::Fixed(): _number(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	// std::cout << "const int constructor called" << std::endl;
	this->_number = num << this->_num;
}

Fixed::Fixed(const float num)
{
	// std::cout << "const float constructor called" << std::endl;
	this->_number = roundf(num * (1 << this->_num));
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	// std::cout << "destructor called" << std::endl;
}
// ============================================================================


// COPY TO EXISTING THING, SO NOT NEW ONE =====================================

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
		_number = other.getRawBits();
    return *this;
}
// ============================================================================


// A-operators ================================================================
float	Fixed::operator+(Fixed other)const
{
	return (this->toFloat() + other.toFloat());
}

float	Fixed::operator-(Fixed other)const
{
	return (this->toFloat() - other.toFloat());
}

float	Fixed::operator*(Fixed other)const
{
	return (this->toFloat() * other.toFloat());
}
float	Fixed::operator/(Fixed other)const
{
	return (this->toFloat() / other.toFloat());
}
// ============================================================================


// C-operators ================================================================
bool	Fixed::operator==(Fixed other)const
{
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator<=(Fixed other)const
{
	return (this->toFloat() <= other.toFloat());	
}

bool	Fixed::operator>=(Fixed other)const
{
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator<(Fixed other)const
{
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>(Fixed other)const
{
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator!=(Fixed other)const
{
	return (this->toFloat() != other.toFloat());
}
// ============================================================================


// RETURN THE HIGHEST OR LOWEST ===============================================
const Fixed	&Fixed::min(const Fixed &one, const Fixed &two)
{
	if (one.toFloat() >= two.toFloat())
		return (two);
	return (one);
}
const Fixed	&Fixed::max(const Fixed &one, const Fixed &two)
{
	if (one.toFloat() >= two.toFloat())
		return (one);
	return (two);
}

Fixed	&Fixed::min(Fixed &one, Fixed &two){
	if (one.toFloat() >= two.toFloat())
		return (two);
	return (one);
}

Fixed	&Fixed::max(Fixed &one, Fixed &two)
{
	if (one.toFloat() >= two.toFloat())
		return (one);
	return (two);
}
// ============================================================================


// TO INT / TO FLOAT ==========================================================
int Fixed::toInt( void ) const
{
	return (this->_number >> this->_num);
}

float Fixed::toFloat( void ) const
{
	return ((float)this->_number / (float)(1 << this->_num));
}
// ============================================================================


// PRE ========================================================================
Fixed	Fixed::operator++()
{
	this->_number++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->_number--;
	return (*this);
}

// ============================================================================


// POST =======================================================================
Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->_number;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->_number;
	return (temp);
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