/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:45:39 by gshekari          #+#    #+#             */
/*   Updated: 2026/05/06 21:44:31 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

int main(void)
{
	Point	a;
	Point	b(13, 10);
	Point	c(0, 10);
	Point	p(2, 5);

	Point p1(2.0f, 2.0f);
	Point p2(10.0f, 10.0f);
	Point p3(5.0f, 0.0f);

	std::cout << "p (inside): " << bsp(a, b, c, p) << std::endl;
	std::cout << "p1 (inside): " << bsp(a, b, c, p1) << std::endl;
	std::cout << "p2 (outside): " << bsp(a, b, c, p2) << std::endl;
	std::cout << "p3 (edge): " << bsp(a, b, c, p3) << std::endl;

	return 0;
}
