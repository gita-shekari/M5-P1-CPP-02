/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:44:41 by gshekari          #+#    #+#             */
/*   Updated: 2026/05/06 21:38:12 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// formula : area = (x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)) / 2
static Fixed area(Point const v1, Point const v2, Point const v3)
{
	return (v1.getX() * (v2.getY() - v3.getY())
		  + v2.getX() * (v3.getY() - v1.getY())
		  + v3.getX() * (v1.getY() - v2.getY())) / Fixed(2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed S1 = area(point, a, b);
	Fixed S2 = area(point, b, c);
	Fixed S3 = area(point, c, a);
	if (S1 == 0 || S2 == 0 || S3 == 0)
		return false;
	bool allPositive = (S1 > 0 && S2 > 0 && S3 > 0);
	bool allNegative = (S1 < 0 && S2 < 0 && S3 < 0);
	return (allPositive || allNegative);
}
