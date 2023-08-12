#pragma once

#ifndef _list
#define _list


#include <memory>


template <class _Type, 
	class Allocator = std::allocator<_Type>>
class List
{
	using _Traits = std::allocator_traits<Allocator>;

public:
	List() = default;
	~List() = default;

private:

	template <class _Type> class Node {
		Node* next;

		typename _Type data;
	public:
		Node() = default;
		~Node() = default;

	};

	Node<_Type>* node;
};

#endif // _list