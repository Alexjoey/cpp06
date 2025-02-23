/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABC.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <alexm@live.be>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:57:27 by amylle            #+#    #+#             */
/*   Updated: 2025/02/23 20:07:42 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Base
{
public:
	Base();
	virtual ~Base();
};

class A: public Base
{
public:
	A();
	~A();
};

class B: public Base
{
public:
	B();
	~B();
};

class C: public Base
{
public:
	C();
	~C();
};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);
