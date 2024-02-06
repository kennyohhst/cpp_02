/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:09:18 by code              #+#    #+#             */
/*   Updated: 2024/02/06 21:12:56 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
		int _number;
		const int _num = 8;
    public:
	// CANONICAL CLASS FORM
		Fixed ();
		Fixed(const Fixed& other);
		~Fixed ();

	// COPY TO EXISTING THING, SO NOT NEW ONE
		Fixed& operator=(const Fixed& other);
		
	// GET + SET
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
