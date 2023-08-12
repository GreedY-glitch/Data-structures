#include "List.h"
#include <iostream>


int main(int argc, char** argv)
{
	List<int> list;
	list.push_back(10);
	list.push_back(12);
	list.push_back(18);

	list.print();

	return 0;
}