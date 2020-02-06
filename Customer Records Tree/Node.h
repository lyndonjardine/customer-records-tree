#pragma once
#include <iostream>
class Node
{
public:
	Node();
	Node(int key, std::string name);
	~Node();
	std::string getName();
	friend class Tree;
private:
	int key;
	std::string name;
	Node *left;
	Node *right;
	Node *parent;
};
