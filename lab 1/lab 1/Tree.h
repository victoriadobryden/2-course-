#pragma once
#include "Graph.h"

template<typename T>
class Tree: public Graph<T>
{
private:
	using Graph<T>::length;
	using Graph<T>::vertex;
	int root;
public:
	Tree();
	Tree(int n);
	~Tree();
};

template<typename T>
Tree<T>::Tree()
{
	root = 0;
	length = 0;
}

template<typename T>
Tree<T>::Tree(int n)
{
	root = 0;
	length = n;
}

template<typename T>
Tree<T>::~Tree()
{
	for (int i = 0; i < length; ++i)
		delete vertex[i];
	vertex.clear();
}

