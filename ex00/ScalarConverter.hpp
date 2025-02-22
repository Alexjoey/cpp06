/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <alexm@live.be>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:38:08 by amylle            #+#    #+#             */
/*   Updated: 2025/02/22 21:59:31 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

typedef enum e_input_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID,
	SPECIAL
}	input_type;

class ScalarConverter
{

public:
	static void	convert(const std::string& str);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	~ScalarConverter();
	ScalarConverter &operator= (const ScalarConverter &copy);

	static input_type get_input_type(const std::string& str);
	static void	printSpecial(const std::string &str);
	static void	printDouble(const std::string &str);
	static void	printFloat(const std::string &str);
	static void	printInt(const std::string &str);
	static void	printChar(const std::string &str);
};
