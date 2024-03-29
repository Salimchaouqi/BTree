//============================================================================
// Name        : bTree.cpp
// Author      : Salim Chaouqi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "bTree.h"

bTree::bTree(int sizeOfNodes){
	sizeOfNodes = sizeOfNodes - 1; //Because originally i thought sizeOfNodes was the number of Elements so for my implementation size would be - 1
	this->size = sizeOfNodes;
	root = NULL;
}

bTree::~bTree(){
	if(root){
		delete root;
	}
}

bool bTree::insert(string key, string value){
	//first insert called on the tree
	if(root == NULL){
		//create the root node
		root= new node(size, true);
		root->insert(key,value);
		return true;
	}
	else{ //if the root has been created
		//first check if the root is full
		if(root->numElements == 2*size - 1){
			//create a new root
			node *a = new node(size, false);
			//Now we have to go and make the old root a child of the new root
			a->children[0] = root;
			//next we have to split the old root since its a tree and move a key to the new root
			a->splitChild(0, root);
			//now to properly place the keys/values into the new children
			int i = 0;
			if(a->keys[0] < key){
				i++;
			}
			bool didInsert; //return for the bool
			didInsert = a->children[i]->insert(key, value);
			//Last we have to change the root to the new node
			root = a;
			return didInsert;
		}
		else{ //The root is not full, so we can just insert the key/value using the node insert method
			return root->insert(key,value);
		}
	}
}

bool bTree::find(string key, string *value){
	if(root == NULL){ //if the root is null then it means that the tree is empty and to return false
		return false;
	}
	else{ //else it looks through the root to find the key if not root will look at its children until it is found or false if not found
		return root->find(key, value);
	}

}

bool bTree::delete_key(string key){
	if(!root){
		return false;
	}
	bool rtrBool = root->delete_key(key);

	//If the root node is now 0 keys, make its first child as the new root, else set root to NULL
	if(root->numElements == 0){
		node* tmp = root;
		if(root->leaf){
			root = NULL;
		}
		else{
			root = root->children[0];
		}
		//Free the memory space taken up by the old root
		delete tmp;
	}
	return rtrBool;
}


string bTree::toStr(){

	if(root != NULL){
		return root->toStr();
	}
	else{
		return " ";
	}
}

