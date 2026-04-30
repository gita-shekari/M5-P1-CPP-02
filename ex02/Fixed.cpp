/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:45:46 by gshekari          #+#    #+#             */
/*   Updated: 2026/04/30 20:26:59 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional = 8;

/**************constructors and destructor*******************/

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

/******************Copy assignment operator ************************/
Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->fixedPoint = obj.fixedPoint;
	return *this;
}
/***********************getter setter************************/
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

/***********************conversions************************/
float Fixed::toFloat( void ) const
{
	return ((float)this->fixedPoint / (1 << fractional));
}

int Fixed::toInt( void ) const
{
	return (this->fixedPoint >> fractional);
}

/***********************comparison operators***************/


bool Fixed::operator>(const Fixed &obj) const
{
	return (fixedPoint > obj.fixedPoint);
}

bool Fixed::operator<(const Fixed &obj) const
{
	return (fixedPoint < obj.fixedPoint);
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return (fixedPoint >= obj.fixedPoint);
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return (fixedPoint <= obj.fixedPoint);
}

bool Fixed::operator==(const Fixed &obj) const
{
	return (fixedPoint == obj.fixedPoint);
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return (fixedPoint != obj.fixedPoint);
}

/***********************arithmetic operators***************/


Fixed Fixed::operator+(const Fixed &other)
{
	Fixed result;
	result.setRawBits(fixedPoint + other.fixedPoint);
	return result;
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed result;
	result.setRawBits(fixedPoint - other.fixedPoint);
	return result;
}

Fixed Fixed::operator*(const Fixed &other)
{
	Fixed result;
	long temp = (long)fixedPoint * other.fixedPoint;
	result.setRawBits(temp >> fractional);
	return result;
}

Fixed Fixed::operator/(const Fixed &other)
{
	Fixed result;
	long temp = ((long)fixedPoint << fractional);
	result.setRawBits(temp / other.fixedPoint);
	return result;
}

/***********************increment and decrement************************/

Fixed &Fixed::operator++()
{
	fixedPoint += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	fixedPoint += 1;
	return temp;
}

Fixed &Fixed::operator--()
{
	fixedPoint -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	fixedPoint -= 1;
	return temp;
}

/***********************min max************************/
Fixed &Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1 < num2)
		return num1;
	return num2;
}

Fixed &Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1 > num2)
		return num1;
	return num2;
}

/***********************min max const************************/

const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2)
{
	if (num1 < num2)
		return num1;
	return num2;
}
const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2)
{
	if (num1 > num2)
		return num1;
	return num2;
}

/***********************stream operator************************/

std::ostream &operator<<(std::ostream &out,const Fixed &obj)
{
	out << obj.toFloat();
	return out;
}
