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
	else if (isFloat(str))
		ScalarConverter::toFloat(str);
	else if (isDouble(str))
		ScalarConverter::toDouble(str);
	else
		std::cout << "Conversion is impossible" << std::endl;
		
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
	try
	{
		i = std::stoi(str);
	}
	catch (std::exception &e)
	{
		return false;
	}
	return true;
}

bool ScalarConverter::isFloat(std::string str)
{
	int i = 0;
	int dot = 0;
	int f = 0;

	if (str == "nanf" || str == "-inff" || str == "+inff" || str == "inff")
		return true;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
			dot++;
		else if (str[i] == 'f')
			f++;
		else if (!isdigit(str[i]))
			return false;
		i++;
	}
	if (dot == 1 && f == 1)
	{
		try
		{
			float fl = std::stof(str);
			(void)fl;
			return true;
		}
		catch (std::exception &e)
		{
			return false;
		}
	}
	return false;
}

bool	ScalarConverter::isDouble(std::string str)
{
	int i = 0;
	int dot = 0;
	int f = 0;

	if (str == "nan" || str == "-inf" || str == "+inf" || str == "inf")
		return true;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
			dot++;
		else if (str[i] == 'f')
			f++;
		else if (!isdigit(str[i]))
			return false;
		i++;
	}
	if (dot == 1 && f == 0)
	{
		try
		{
			double d = std::stod(str);
			(void)d;
			return true;
		}
		catch (std::exception &e)
		{
			return false;
		}
	}
	return false;
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
	std::string str_f = ScalarConverter::floatFormat(f);

	// Double
	double d = static_cast<double>(c);
	std::string str_d = ScalarConverter::doubleFormat(d);

	ScalarConverter::printFormat(str_c, str_i, str_f, str_d);
}

void	ScalarConverter::toInt(std::string str)
{
	int i = static_cast<int>(std::stoi(str));
	std::string str_i = std::to_string(i);

	// Char
	char c = static_cast<char>(i);
	std::string str_c = "'" + std::string(1, c) + "'";
	if ((i >= 0 && i < 32) || (i > 126 && i <= 255))
		str_c = "Non displayable";
	else if (i == '\0' || i > 255 || i < 0)
		str_c = "impossible";

	// Float
	float f = static_cast<float>(i);
	std::string str_f = ScalarConverter::floatFormat(f);

	// Double
	double d = static_cast<double>(i);
	std::string str_d = ScalarConverter::doubleFormat(d);

	ScalarConverter::printFormat(str_c, str_i, str_f, str_d);
}

void	ScalarConverter::toFloat(std::string str)
{
	float f = static_cast<float>(std::stof(str));
	std::string str_f = ScalarConverter::floatFormat(f);

	// Char
	char c = static_cast<char>(f);
	std::string str_c = "'" + std::string(1, c) + "'";
	if ((f >= 0 && f < 32) || (f > 126 && f <= 255))
		str_c = "Non displayable";
	else if (c == '\0' || f > 255 || f < 0)
		str_c = "impossible";

	// Int
	int i = static_cast<int>(f);
	std::string str_i = std::to_string(i);
	if (f > INT_MAX || f < INT_MIN || i <= INT_MIN || i >= INT_MAX)
		str_i = "impossible";

	// Double
	double d = static_cast<double>(f);
	std::string str_d = ScalarConverter::doubleFormat(d);

	ScalarConverter::printFormat(str_c, str_i, str_f, str_d);
}

void	ScalarConverter::toDouble(std::string str)
{
	double d = static_cast<double>(std::stod(str));
	std::string str_d = ScalarConverter::doubleFormat(d);

	// Char
	char c = static_cast<char>(d);
	std::string str_c = "'" + std::string(1, c) + "'";
	if ((d >= 0 && d < 32) || (d > 126 && d <= 255))
		str_c = "Non displayable";
	else if (c == '\0' || d > 255 || d < 0)
		str_c = "impossible";

	// Int
	int i = static_cast<int>(d);
	std::string str_i = std::to_string(i);
	if (d > INT_MAX || d < INT_MIN || i <= INT_MIN || i >= INT_MAX)
		str_i = "impossible";

	// Float
	float f = static_cast<float>(d);
	std::string str_f;
	if (d > FLT_MAX || d < FLT_MIN)
		str_f = "impossible";
	else
		str_f = ScalarConverter::floatFormat(f);

	ScalarConverter::printFormat(str_c, str_i, str_f, str_d);
}


std::string ScalarConverter::floatFormat(float f)
{
	std::string str_f = std::to_string(f);
	if (str_f == "inf" || str_f == "+inf" || str_f == "-inf" || str_f == "nan")
		return str_f + "f";
	size_t decimalPos = str_f.find('.');
	str_f = str_f.substr(0, decimalPos + 2) + "f";
	return str_f;
}

std::string ScalarConverter::doubleFormat(double d)
{
	std::string str_d = std::to_string(d);
	if (str_d == "inf" || str_d == "+inf" || str_d == "-inf" || str_d == "nan")
		return str_d;
	size_t decimalPos = str_d.find('.');
	str_d = str_d.substr(0, decimalPos + 2);
	return str_d;
}





