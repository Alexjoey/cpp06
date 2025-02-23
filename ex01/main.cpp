/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <alexm@live.be>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:39:10 by amylle            #+#    #+#             */
/*   Updated: 2025/02/23 19:39:33 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <ostream>

int	main(void)
{
	Data		*dt = new Data;
	Data		*ptr;
	uintptr_t	raw_ptr;

	dt->num = 5;
	std::cout << "beginning pointer is: " << dt << std::endl;
	raw_ptr = Serializer::serialize(dt);
	std::cout << "raw serialized pointer is: " << raw_ptr << std::endl;
	ptr = Serializer::deserialize(raw_ptr);
	std::cout << "deserialized pointer is: " << ptr << std::endl;
	std::cout << "value of Data->num is: " << ptr->num << std::endl;
	std::cout << "value of newptr->num is: " << ptr->num << std::endl;
	delete dt;
}
