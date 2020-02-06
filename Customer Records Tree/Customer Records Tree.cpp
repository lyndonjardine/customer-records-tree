// Customer Records Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	Tree myTree;
	myTree.insert(5, "lyndon");
	myTree.insert(1, "drew");
	myTree.insert(10, "brandon");
	myTree.insert(105, "asdf");
	myTree.insert(9, "1234");
	myTree.insert(43, "asdfgjhkl");
	myTree.insert(432, "d3df42");
	myTree.insert(2, "two");
	//myTree.insert(2, "twotwo");

	Node *searchedNode = myTree.search(2);
	std::string name = searchedNode->getName();
	std::cout << "Found: " << name << std::endl;
	myTree.deleteNode(2);
	std::cout << "Should be null: " << myTree.search(20000)->getName() << std::endl;

	system("pause");
    return 0;
}

