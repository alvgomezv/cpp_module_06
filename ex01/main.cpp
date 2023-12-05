#include "Serializer.hpp"

int main(void)
{
	Data* data = new Data("Pepe", 42);

	uintptr_t ptr = Serializer::serialize(data);

	std::cout << "ptr in hex: " << std::hex << ptr << std::endl;
	std::cout << "ptr in decimal: " << std::dec << ptr << std::endl;

	Data* data2 = Serializer::deserialize(ptr);

	std::cout << "data2 address: " << data2 << std::endl;
	std::cout << "data2 Name: " << data2->getName() << std::endl;
	std::cout << "data2 Age: " << data2->getAge() << std::endl;
}