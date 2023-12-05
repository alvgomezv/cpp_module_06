#include "Base.hpp"
#include <cstdlib>
#include <ctime> 

Base*	generate(void)
{
	int		i;
	Base	*base;

	std::srand(static_cast<unsigned>(std::time(0)));
	int random_variable = std::rand();
	i = random_variable % 3;
	if (i == 0)
		base = new A;
	else if (i == 1)
		base = new B;
	else
		base = new C;
	return base;
}

void	identify_from_pointer(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "The type is: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "The type is: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "The type is: C" << std::endl;
	else
		std::cout << "Error" << std::endl;
}

void	identify_from_reference(Base &p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "The type is: A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "The type is: B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "The type is: C" << std::endl;
	else
		std::cout << "Error" << std::endl;
}

int main(void)
{
	Base	*base;
	
	base = generate();

	identify_from_pointer(base);
	identify_from_reference(*base);
}