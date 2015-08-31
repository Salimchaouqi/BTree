/*
 * bTree.h
 *
 *  Created on: Apr 6, 2015
 *      Author: nav
 */

#ifndef BTREE_H_
#define BTREE_H_

#include <iostream>
#include <string>
#include "node.h"
using namespace std;

class bTree {
private:
	//Your private stuff to implement the B Tree
	node* root; //Pointer that points to the root node
	int size;
	//int numElements;
public:
	//Constructor
	bTree(int sizeOfNodes);

	//Destructor
	~bTree();

	//Inserts the value pair into the tree
	bool insert(string key, string value);

	// Searches for the key in the tree, if found, it returns
	// true else returns false.
	// If the key is found, it stores the value in the *value variable
	bool find(string key, string *value);

	//Searches for the key and deletes it. Returns true if deletion was
	//successful, returns false if the key wasn't found
	bool delete_key(string key);

	// concatenates the contents of the tree from an inorder traversal
	// into an output stream with each string item followed by a
	// newline character in the stream
	string toStr();

};






#endif /* BTREE_H_ */
