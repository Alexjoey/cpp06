/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABC.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <alexm@live.be>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:00:15 by amylle            #+#    #+#             */
/*   Updated: 2025/02/23 20:13:57 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ABC.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

Base::Base(){}
Base::~Base(){}
A::A(){}
A::~A(){}
B::B(){}
B::~B(){}
C::C(){}
C::~C(){}

Base	*generate(void)
{
	std::srand(std::time(0));
	int	num = (std::rand() % 3);
	switch (num)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			return (NULL);
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "this is an A class" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "this is a B class" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "this is a C class" << std::endl;
	else
		std::cout << "this is a Base class" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "this is an A class ref" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "this is a B class ref" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "this is a C class ref" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {}
	std::cout << "this is a Base class" << std::endl;
}
