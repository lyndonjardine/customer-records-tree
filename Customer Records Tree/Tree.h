#pragma once
#include "Node.h"
#include <iostream>
class Tree
{
public:
	Tree();
	~Tree();
	//public functions the user uses
	//these functions will call the private functions
	void insert(int key, std::string customerName);
	Node *search(int key);
	void deleteTree();
	void deleteNode(int key);

private:
	//private functions to be called recursively
	void insert(int key, Node *leaf, std::string customerName);
	Node *search(int key, Node *leaf);//looks for a node based on key and returns it
	void deleteTree(Node *leaf);
	bool foundDuplicate(int key);//calls the search function, if search is null, returns false
	//void deleteNode(int key, Node *leaf); recursion is not needed since the node to delete is found through the search function
	Node *root;
};