#pragma once

#ifndef _list
#define _list


/*
	The simpliest implementation of the list
*/


#include <memory>
#include <iostream>


// Correct implements of the node in the list 
template <class _Type> class Node {
private:
	typename _Type data;

public:
	Node* next;		// UNSAFE

	Node() : data(_Type()), next(nullptr) { };
	Node(const _Type& data) : data(data), next(nullptr) { };
	Node(_Type& data) : data(data), next(nullptr) { };

	~Node() = default;


	Node<_Type>* operator=(size_t t_size) const {
		return ::operator new (t_size * sizeof(Node<_Type>));
	}

	constexpr _Type get_value() const noexcept {
		return data;
	}
	
	constexpr Node* get_next() const noexcept { return next; }
};



template <class _Type, class T = unsigned long long,
	class Allocator = std::allocator<Node<_Type>>>
class List
{
	using _Traits = std::allocator_traits<Allocator>;
	using Type_size = T;

	Allocator alloc_1;
	Type_size size;

public:
	List() : first(nullptr), last(nullptr) {
		// using without allocator
		// this->node = _Traits::allocate(alloc_1, sizeof(Node<_Type>));
		size = sizeof(List<_Type>);
	}
	~List() = default;

	// methods to work with list
	// _Type* get_value_of() const noexcept { return this->node->data; }
	bool is_empty() { return first == nullptr; }
	void push_back(_Type data);
	void print() const;

	Node<_Type>* find(_Type elem) const;

private:
	Node<_Type>* first;
	Node<_Type>* last;
};


template<class _Type, class T, 
	class Allocator>
inline void List<_Type, T, Allocator>::push_back(_Type data)
{
	Node<_Type>* p_node = _Traits::allocate(alloc_1, 1);
	_Traits::construct(alloc_1, p_node, data);

	// std::cout << p_node->get_value() << std::endl;

	if (is_empty()) {
		first = p_node;
		last = p_node;
		return;
	}
	last->next = p_node;
	last = p_node;
}


template<class _Type, 
	class T, class Allocator>
inline void List<_Type, T, Allocator>::print() const
{
	if (first == nullptr) return;

	Node<_Type>* p = first;
	while (p)
	{
		std::cout << p->get_value() << " ";
		p = p->next;
	}
	std::cout << std::endl;
}


template<class _Type, 
	class T, class Allocator>
inline Node<_Type>* List<_Type, T, Allocator>::find(_Type elem) const
{
	Node<_Type>* p_node = first;

	while (p_node && p_node->get_value() != elem) p_node = p_node->next;
	return p_node ? p_node : nullptr;
}


#endif // _list

