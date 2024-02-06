/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:11:08 by code              #+#    #+#             */
/*   Updated: 2024/02/06 21:12:16 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// CANONICAL CLASS FORM =======================================================
Fixed::Fixed(): _number(0)
{
	std::cout << "Default constructor called" << std::endl;
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


// GET + SET ==================================================================
int Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return _number;
}

void Fixed::setRawBits( int const raw )
{
	_number = raw;
	std::cout << "setRawBits member function called" << std::endl;
}
// ============================================================================
