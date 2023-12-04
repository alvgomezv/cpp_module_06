#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		~ScalarConverter(void);

		static bool isChar(std::string str);
		static bool isInt(std::string str);
		// static bool isFloat(std::string str);
		// static bool isDouble(std::string str);
		
		static void toChar(std::string str);
		static void toInt(std::string str);
		// static void toFloat(std::string str);
		// static void toDouble(std::string str);

		static void printFormat(std::string str_c, std::string str_i, std::string str_f, std::string str_d);

	public:
		static void convert(std::string str);
};

#endif