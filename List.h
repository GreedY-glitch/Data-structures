#pragma once

#ifndef _list
#define _list


#include <memory>


template <class _Type, class T = unsigned long long,
	class Allocator = std::allocator<_Type>>
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
		size = 0;
	}
	~List() = default;

	// methods to work with list
	// _Type* get_value_of() const noexcept { return this->node->data; }
	bool is_empty() { return first == nullptr; }
	void push_back(_Type data);

private:

	// Correct implements of the node in the list 
	template <class _Type> class Node {
	public:
		Node* next;
		typename _Type data;

		Node() : data(_Type()), next(nullptr) { };
		Node(const _Type& data) : data(data), next(nullptr) { };
		Node(_Type& data) : data(data), next(nullptr) { };

		~Node() = default;

	};

	Node<_Type>* first;
	Node<_Type*> last;
};


template<class _Type, class T, 
	class Allocator>
inline void List<_Type, T, Allocator>::push_back(_Type data)
{
	Node<_Type>* p_node = new Node<_Type>(data);
}


#endif // _list

