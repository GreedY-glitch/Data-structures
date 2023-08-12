#include "List.h"
#include <iostream>


int main(int argc, char** argv)
{
	List<const char*> list;
	list.push_back("Hello");
	list.push_back("World!");
	list.push_back("World!");
	list.push_back("World!");
	list.push_back("World!");
	list.push_back("World!");
	list.push_back("World!");

	list.print();
	std::cout << list.find("Hello") << std::endl;
	std::cout << list.find("World!") << std::endl;
	list.pop_front();
	list.pop_back();

	list.print();

	return 0;
}