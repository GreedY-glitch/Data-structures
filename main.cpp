#include "List.h"
#include <iostream>


int main(int argc, char** argv)
{
	List<const char*> list;
	list.push_back("Hello");
	list.push_back("World!");
	list.print();
	std::cout << list.find("Hello") << std::endl;
	std::cout << list.find("World!") << std::endl;

	return 0;
}