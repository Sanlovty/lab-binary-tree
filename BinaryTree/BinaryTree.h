#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Node.h"
#include <iostream>
using std::exception;
using std::cout;
using std::endl;


class BinaryTree
{
	Node* head_;
	void addMethod_(Node* node, const int& data);
	Node* getStrictNode_(Node* node);
	void strictMethod_(Node* previousNode);
	void printMethod_(Node* root, int spaceBefore, const int& spaceBetween);

public:
	BinaryTree();
	bool isEmpty() const;
	void add(const int& data);
	void toStrict();


	void print(const int& spaceBefore, const int& spaceBetween);
};

#endif
