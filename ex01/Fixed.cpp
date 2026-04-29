/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:45:46 by gshekari          #+#    #+#             */
/*   Updated: 2026/04/29 19:59:37 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = n * 256;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = roundf(n * 256);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPoint = obj.fixedPoint;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->fixedPoint = obj.fixedPoint;
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPoint);
}
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPoint = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->fixedPoint / (1 << fractional));
}

int Fixed::toInt( void ) const
{
	return (this->fixedPoint >> fractional);
}

std::ostream &operator<<(std::ostream &out,const Fixed &obj)
{
	out << obj.toFloat();
	return out;
}
