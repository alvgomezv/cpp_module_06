#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	return ;
}

ScalarConverter::~ScalarConverter(void)
{
	return ;
}

void ScalarConverter::convert(std::string str)
{
	if (isChar(str))
		ScalarConverter::toChar(str);
	else if (isInt(str))
		ScalarConverter::toInt(str);
		
}

void ScalarConverter::printFormat(std::string str_c, std::string str_i, std::string str_f, std::string str_d)
{
	std::cout << "char: " << str_c << std::endl;
	std::cout << "int: " << str_i << std::endl;
	std::cout << "float: " << str_f << std::endl;
	std::cout << "double: " << str_d << std::endl;
}

bool ScalarConverter::isChar(std::string str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return true;
	return false;
}

bool ScalarConverter::isInt(std::string str)
{
	int i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

// std::string ScalarConverter::toChar(std::string str)
// {
// 	char chr;

// 	try
// 	{
// 		chr = static_cast<char>(std::stoi(str));
// 		value = "'" + std::string(1, chr) + "'";
// 	}
// 	catch (std::exception &e)
// 	{
// 		value = "impossible";
// 		return value;
// 	}
// 	if (chr < 32 || chr > 126)
// 		value = "Non displayable";
// 	return value;
// }

void	ScalarConverter::toChar(std::string str)
{
	char c;

	c = static_cast<char>(str[0]);
	std::string str_c = "'" + std::string(1, c) + "'";

	// Int
	int i = static_cast<int>(c);
	std::string str_i = std::to_string(i);

	// Float
	float f = static_cast<float>(c);
	std::string str_f = std::to_string(f) + "f";

	// Double
	double d = static_cast<double>(c);
	std::string str_d = std::to_string(d);

	ScalarConverter::printFormat(str_c, str_i, str_f, str_d);
}

void	ScalarConverter::toInt(std::string str)
{
	int i = static_cast<int>(std::stoi(str));
	std::string str_i = std::to_string(i);

	// Char
	char c = static_cast<char>(i);
	std::string str_c = "'" + std::string(1, c) + "'";
	if (c < 32 || c > 126)
		str_c = "Non displayable";

	// Float
	float f = static_cast<float>(i);
	std::string str_f = std::to_string(f) + "f";

	// Double
	double d = static_cast<double>(i);
	std::string str_d = std::to_string(d);

	ScalarConverter::printFormat(str_c, str_i, str_f, str_d);
}






