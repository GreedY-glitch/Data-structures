#include "List.h"
#include <iostream>


int main(int argc, char** argv)
{
	List<const char*> list;
	list.push_back("Hello");
	list.print();

	return 0;
}