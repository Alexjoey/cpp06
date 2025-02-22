/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <alexm@live.be>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:42:15 by amylle            #+#    #+#             */
/*   Updated: 2025/02/22 22:31:17 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <sstream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator= (const ScalarConverter &copy)
{
	(void) copy;
	return (*this);
}

static bool	isInt(const std::string &str)
{
	std::stringstream	ss(str);
	int					i;

	ss >> i;
	return (ss.eof() && !ss.fail());
}

static bool	isFloat(const std::string &str)
{
	std::stringstream	ss(str);
	float				flt;
	std::string			tmp;

	ss >> flt;
	if (ss.fail())
		return (false);
	ss >> tmp;
	if (tmp.length() == 1 && tmp[0] == 'f')
		return (true);
	return (false);
}

static bool	isDouble(const std::string &str)
{
	std::stringstream	ss(str);
	double					dbl;

	ss >> dbl;
	return (ss.eof() && !ss.fail());
}

static bool	isSpecial(const std::string &str)
{
	return (str == "-inf" || str == "+inf" || str == "-inff" || str == "+inff" || str == "nan");
}

void	ScalarConverter::printChar(const std::string &str)
{
	if (isprint(str[0]))
		std::cout << "char: " << str << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(str[0]) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
}

void	ScalarConverter::printInt(const std::string &str)
{
	int	i;

	i = std::atoi(str.c_str());
	if (i >= 0 && i <= 127 && isprint(i))
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	else if (i >= 0 && i <= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void	ScalarConverter::printFloat(const std::string &str)
{
	float	f;

	f = std::strtof(str.c_str(), NULL);
	if (f >= 0 && f <= 127 && isprint(static_cast<int>(f)))
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	else if (static_cast<int>(f) >= 0 && static_cast<int>(f) <= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;
	if (f > static_cast<float>(std::numeric_limits<int>::max()) || f < static_cast<float>(std::numeric_limits<int>::min()))
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	ScalarConverter::printDouble(const std::string &str)
{
	double	d;

	d = std::strtod(str.c_str(), NULL);
	if (d >= 0 && d <= 127 && isprint(static_cast<int>(d)))
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	else if (static_cast<int>(d) >= 0 && static_cast<int>(d) <= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;
	if (d > static_cast<double>(std::numeric_limits<int>::max()) || d < static_cast<double>(std::numeric_limits<int>::min()))
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (d > static_cast<double>(std::numeric_limits<float>::max()) || d < static_cast<double>(std::numeric_limits<float>::min()))
		std::cout << "float: Impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << 'f' << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::printSpecial(const std::string &str)
{
	if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: Impossible" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}

input_type	ScalarConverter::get_input_type(const std::string& str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return (CHAR);
	else if (isInt(str))
		return (INT);
	else if (isFloat(str))
		return (FLOAT);
	else if (isDouble(str))
		return (DOUBLE);
	else if (isSpecial(str))
		return (SPECIAL);
	else
		return (INVALID);
}

void	ScalarConverter::convert(const std::string& str)
{
	input_type	type;

	type = ScalarConverter::get_input_type(str);
	switch (type)
	{
		case CHAR:
			printChar(str);
			break;
		case INT:
			printInt(str);
			break;
		case FLOAT:
			printFloat(str);
			break;
		case DOUBLE:
			printDouble(str);
			break;
		case SPECIAL:
			printSpecial(str);
			break;
		case INVALID:
			std::cout << "Invalid input." << std::endl;
	}
}
