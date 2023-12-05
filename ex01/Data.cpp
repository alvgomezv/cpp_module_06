#include "Data.hpp"


Data::Data(void) : _name("default"), _age(0)
{
	// std::cout << "Data default constructor called" << std::endl;
	return ;
}

Data::Data(std::string name, int age) : _name(name), _age(age)
{
	// std::cout << "Data constructor called" << std::endl;
	return ;
}

Data::Data(Data const& other)
{
	// std::cout << "Data copy constructor called" << std::endl;
	*this = other;
	return ;
}

Data& Data::operator=(Data const& other)
{
	// std::cout << "Data assignation operator called" << std::endl;
	this->_name = other._name;
	this->_age = other._age;
	return *this;
}

Data::~Data(void)
{
	// std::cout << "Data destructor called" << std::endl;
	return ;
}

std::string Data::getName(void) const
{
	return this->_name;
}

int Data::getAge(void) const
{
	return this->_age;
}

