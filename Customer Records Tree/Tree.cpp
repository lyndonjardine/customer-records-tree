#include "Tree.h"
#include "stdafx.h"

Tree::Tree()
{
	root = NULL;
}

Tree::~Tree()
{
	//TODO, take another look at the delete function, this does not call the deleteTree below because it is expecting a leaf pointer
	deleteTree();
}

void Tree::deleteTree()
{
	deleteTree(root);
}

//delete function recursively deletes nodes starting from the bottom, 
//the if condition stops it from being infinite
void Tree::deleteTree(Node *leaf)
{
	if (leaf != NULL)
	{
		//this will keep going until the bottom of the tree is reached, and then it will start deleting
		deleteTree(leaf->left);
		deleteTree(leaf->right);
		delete leaf;
	}
}

//public insert function
void Tree::insert(int key, std::string customerName)
{
	//before attempting to insert, check if a duplicate key exists
	if (foundDuplicate(key) == false)
	{
		//check if the first node exists
		if (root != NULL)
		{
			insert(key, root, customerName);
		}
		//there is not first node
		else
		{
			//if there is no first node, insert the key as the first node and have root point to it
			root = new Node(key, customerName);//constructor initializes left and right as null
		}
	}
	else
	{
		std::cout << "Insert Failed: duplicate keys are not permitted!" << std::endl;
	}
}

//private insert function, gets called recursively, customerName gets passed along each time until its time to insert the node
void Tree::insert(int key, Node *leaf, std::string customerName)
{
	//logic for insertion
	//if the key should go on the left
	if (key < leaf->key)
	{
		//if there already is a left node, recursively call the insert function on it
		if (leaf->left != NULL)
		{
			insert(key, leaf->left, customerName);
		}
		else //the end of the branch is reached, actually insert the new node
		{
			//node constructor initializes left and right as NULL
			leaf->left = new Node(key, customerName);
			//set the parent pointer to the current node
			leaf->left->parent = leaf;
		}
	}
	else if (key >= leaf->key)
	{
		//if a right node exists
		if (leaf->right != NULL)
		{
			//call the insert function
			insert(key, leaf->right, customerName);
		}
		else
		{
			//constructor initializes left and right as NULL
			leaf->right = new Node(key, customerName);
			leaf->right->parent = leaf;
		}
	}
}

//public search function, user inputs a key and the function returns the node with the match
Node *Tree::search(int key)
{
	Node *searchNode = NULL;
	searchNode = search(key, root);
	if (searchNode == NULL)
	{
		std::cout << "Search Error: Node not found!" << std::endl;
	}
	return searchNode;
}

//private search function, gets called recursively until either a match is found, or the end of the tree is reached
Node *Tree::search(int key, Node *leaf)
{
	//if the current node isnt null
	if (leaf != NULL)
	{
		//if a match
		if (key == leaf->key)
		{
			return leaf;
		}
		//if the key is less than the node's key
		else if (key < leaf->key)
		{
			//call search on the left node
			return search(key, leaf->left);
		}
		else
		{
			//call search on the right side
			return search(key, leaf->right);
		}
	}
	else
	{
		return NULL;
	}
}
//returns true if a duplicate key was found
bool Tree::foundDuplicate(int key)
{
	//call the search function to look for a node with the key you are attempting to insert
	//the node returned by the search function will be null if no matching key is found
	Node *duplicateNode = search(key);
	if (duplicateNode == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}



//the delete function utilizes the search function to find the node you want to delete, so recursion is not needed
void Tree::deleteNode(int key)
{
	Node *nodeToDelete = search(key);
	//if a node was found
	if (nodeToDelete != NULL)
	{
		//check if the node is a leaf node
		if (nodeToDelete->left == NULL && nodeToDelete->right == NULL)
		{
			//set the pointer pointing to the node to delete from the parent to null
			//check if the node you want to delete is the left or right node of the parent
			if (nodeToDelete->parent->left == nodeToDelete)
			{
				nodeToDelete->parent->left = NULL;
			}
			else
			{
				nodeToDelete->parent->right = NULL;
			}

			//delete the node, since this is a leaf node, nothing needs to be fixed
			delete nodeToDelete;
			
		}
		//optional, for deleting nodes that have a single child, copy the child 
		else if (nodeToDelete->left != NULL && nodeToDelete->right == NULL)
		{
			
		}
		else if (nodeToDelete->left == NULL && nodeToDelete->right != NULL)
		{

		}
	}

}
/*
void Tree::deleteNode(int key, Node *leaf)
{
	if (leaf->key == key)
	{

	}
	else
	{

	}
}
*/