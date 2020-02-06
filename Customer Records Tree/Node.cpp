#include "Node.h"
#include "stdafx.h"

Node::Node()
{
	key = 0;
	name = "";
	left = NULL;
	right = NULL;
	parent = NULL;//parent node is used for deletion
}
Node::~Node()
{
}

//constructor for name and key, sets left and right nodes to null
Node::Node(int tempKey, std::string tempName)
{
	key = tempKey;
	name = tempName;
	left = NULL;
	right = NULL;
	parent = NULL;
}

//function for returning the name contained in the node
std::string Node::getName()
{
	//if trying to display from a node that does not exist
	if (this == NULL)
	{
		std::cout << "Error: Key not found!" << std::endl;
		return "";
	}
	else
	{
		return name;
	}
	
}