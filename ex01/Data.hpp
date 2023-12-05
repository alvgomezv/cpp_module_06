#ifndef Data_HPP
# define Data_HPP

#include <iostream>
#include <string>

class Data
{
	private:
		std::string		_name;
		int				_age;
	
	public:
		Data(void);
		Data(std::string name, int age);
		Data(Data const& other);
		Data& operator=(Data const& other);
		~Data(void);

		std::string getName(void) const;
		int getAge(void) const;
};

#endif