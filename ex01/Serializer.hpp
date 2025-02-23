/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <alexm@live.be>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:25:44 by amylle            #+#    #+#             */
/*   Updated: 2025/02/23 19:36:28 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>

typedef struct	Data
{
	int	num;
}				Data;

class Serializer
{
public:
	static uintptr_t	serialize(Data *ptr);
	static Data*		deserialize(uintptr_t raw);

private:
	Serializer();
	~Serializer();
	Serializer(const Serializer &cpy);
	Serializer&	operator= (const Serializer &cpy);
};
