#include "List.h"
#include <iostream>


int main(int argc, char** argv)
{
	List<int> list;
	if (list.is_empty()) std::cout << "List is empty!\n";
	list.push_back(10);

	return 0;
}