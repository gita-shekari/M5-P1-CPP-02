/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:31:50 by gshekari          #+#    #+#             */
/*   Updated: 2026/05/06 21:28:09 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}
Point::Point(const float n, const float m): x(n), y(m)
{
}
Point::Point(Point const &obj) : x(obj.x), y(obj.y)
{

}
Point::~Point()
{

}

Point &Point::operator=(const Point &obj)
{
	(void)obj;
	return *this;
}

Fixed Point::getX() const
{
	return this->x;
}

Fixed Point::getY() const
{
	return this->y;
}
