/*
 * BST.h
 *
 *  Created on: Nov 2, 2020
 *      Author: shahzebshafi
 */

#ifndef BST_H_
#define BST_H_
#include <iostream>
using namespace std;

template <class T>
struct Treenode
{
     T nodeValue;
     Treenode <T> * Lchild;
     Treenode <T> * Rchild;
};
template<class T>
class BinarySearchTree
{
private:
	Treenode <T> *treeRoot;
	void bstDeleteInternal(Treenode<T> * &);
	void bstInOrderInternal(Treenode<T> * ) const;
	void bstPreOrderInternal(Treenode<T> * ) const;
	void bstPostOrderInternal(Treenode<T> * ) const;
	void printFlatInternal(Treenode<T> *, int );
public:
	BinarySearchTree();
	bool bstSearch(const T & si) const;
	void bstInsert(const T & ii);
	void bstUDelete(const T & di);
	void printFlat();
	void bstInOrderTraversal()const;
	void bstPreOrderTraversal() const;
	void bstPostOrderTraversal() const;

};
//*****************************************************************************************
// Function: BinarySearchTree()
//Preconditions
//	treeRoot
//Postconditions
//	Sets the treeRoot to a null pointer
//Description
//	This function is the constructor, so it creates the Binary Search Tree's root, and sets
//	it a null pointer, so values can be inserted
//*****************************************************************************************
template <class T>
BinarySearchTree <T>::BinarySearchTree()
{
	treeRoot = nullptr;
}
//*****************************************************************************************
// Function to print binary tree in 2D
// It does reverse inorder traversal
//*****************************************************************************************
template <class T>
void BinarySearchTree<T>::printFlatInternal(Treenode<T> *root, int space)
{
	int COUNT=5;
    if (root == NULL)
        return;
    space += COUNT;
    printFlatInternal(root->Rchild, space);		// process right (top of page)
    cout<< endl;						// display node after spacing
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->nodeValue<<"\n";
    printFlatInternal(root->Lchild, space);		// process left (bottom of page)


}
//*****************************************************************************************
//	Function for printFlat that is available to user
//	Calls printFlatInternal
//*****************************************************************************************
template <class T>
void BinarySearchTree<T>::printFlat()
{
    printFlatInternal(treeRoot, 0);
}
//*****************************************************************************************
// Function: bstSearch(const T &)
//Preconditions
//	si- the data given by the user that is to be searched for
//Postconditions
//	Returns true if item given by user is found
//	Returns false is item given by user is not found
//Description
//	This function is the search function for the Binary Search Tree. It creates a pointer
//	that will be set to the treeRoot. It first checks to see if the tree is empty and prints
//	an error message is it is. If the tree isn't empty it goes through while loop to search
//	the tree and find the certain nodeValue
//*****************************************************************************************
template<class T>
bool BinarySearchTree <T>:: bstSearch(const T & si) const
{
	Treenode <T> * curr;
	bool found = false;
	if( treeRoot == nullptr)
	{
		cout <<"Error- Tree is empty"<< endl;
	}
	else
	{
		curr = treeRoot;
		while(curr != nullptr && ! found)
		{
			if(curr->nodeValue == si)
				found=true;
			else if (curr->nodeValue > si)
				curr = curr->Lchild;
			else
				curr = curr->Rchild;

		}
	}
	return found;
}
//*****************************************************************************************
// Function: bstSearch(const T &)
//Preconditions
//	ii- the data given by the user that is to be inserted
//Postconditions
//	If node value is not a duplicate of a value already in the tree, then a new node is created
//	and it's put in it's correct position
//Description
//	This function is the insert function for the Binary Search Tree. It creates three
//	pointers, two of which are to find the insertion point, and the final one is to create
//	a new node. The new node is given the value inserted by the user, and it's right and left
//	child are both set to null. The function first checks to see it the tree is empty
//	and if it is, it sets the new node equal to the treeRoot. If the tree is not empty
//	then a pointer is used to find the point of insertion within the tree, and once it's found
//	the value is inserted in to it's appropriate position.
//*****************************************************************************************
template<class T>
void BinarySearchTree <T>:: bstInsert(const T & ii)
{
	Treenode <T> * curr;
	Treenode <T> * trailing;
	Treenode <T> * newNode;
	newNode = new Treenode <T>;

	newNode-> nodeValue = ii;
	newNode-> Lchild = nullptr;
	newNode-> Rchild = nullptr;
	if (treeRoot == nullptr)
	{
		treeRoot = newNode;
	}
	else
	{
		curr = treeRoot;
		while (curr != nullptr)
		{
			trailing = curr;
			if(curr->nodeValue == ii)
				cout <<"Error- Tried to insert a value that was already in the tree"<< endl;
			else if (curr->nodeValue > ii)
				curr = curr->Lchild;
			else
				curr = curr->Rchild;
		}
		if(trailing->nodeValue > ii)
			trailing ->Lchild = newNode;
		else
			trailing ->Rchild = newNode;
	}
}
//*****************************************************************************************
// Function: bstDeleteInternal(Treenode <T> *&)
//Preconditions
//	ptr- pointer which points to the node to be deleted
//Postconditions
//	Deletes the node that ptr is pointing to
//Description
//	This function is the delete internal function for the Binary Search Tree. Creates
//	three pointers. Checks to see if node to be deleted is there. If it is, then the function
//	checks four cases. It checks if the node needing to be deleted has a leaf, if the node
//	needing to be deleted has only a left subtree, if the node needing to be deleted has only
//	a right subtree, or if the node needing to be deleted has both a right and left subtree.
//	Depending on which case is satisfied, the node is deleted so it doesn't upset the order
//	of the Binary Search Tree.
//*****************************************************************************************
template <class T>
void BinarySearchTree <T>::bstDeleteInternal(Treenode <T> * &ptr)
{
	Treenode <T> * curr;
	Treenode <T> * trailing;
	Treenode <T> * deleteNode;
	if (ptr == nullptr)
	{
		cout <<"Error"<< endl;
	}
	else if(ptr -> Lchild == nullptr && ptr -> Rchild == nullptr)
	{
		deleteNode = ptr;
		ptr= nullptr;
		delete deleteNode;
	}
	else if(ptr->Lchild == nullptr)
	{
		deleteNode = ptr;
		ptr= deleteNode -> Rchild;
		delete deleteNode;
	}
	else if(ptr->Rchild == nullptr)
	{
		deleteNode = ptr;
		ptr= deleteNode -> Lchild;
		delete deleteNode;
	}
	else
	{
		curr = ptr->Lchild;
		trailing = nullptr;
		while (curr->Rchild != nullptr)
		{
			trailing = curr;
			curr = curr -> Rchild;
		}
		ptr -> nodeValue = curr -> nodeValue;
		if(trailing == nullptr)
			ptr->Lchild = curr->Lchild;
		else
			trailing-> Rchild = curr->Lchild;
		delete curr;
	}
}
//*****************************************************************************************
// Function: bsUDelete(const T &)
//Preconditions
//	di- the data given by the user that is to be deleted
//Postconditions
//	If node value is found in the tree, it is then deleted
//Description
//	This function is the delete function for the Binary Search Tree (available to the tree).
//	The function checks to see if the tree is empty, if the tree is empty and error message
//	is given. Then if the tree is not empty, the pointers are used to traverse the tree
//	and find the value that needs to be deleted. If the value is not found, an error message
//	is given, but if it is found it's send to the delete internal function to be deleted.
//	where the node is deleted
//*****************************************************************************************
template <class T>
void BinarySearchTree <T>:: bstUDelete(const T & di)
{
	Treenode <T> * curr;
	Treenode <T> * trailing;
	bool found = false;
	if( treeRoot == nullptr)
	{
		cout <<"Error- Tree is empty"<< endl;
	}
	else
	{
		curr = treeRoot;
		trailing = treeRoot;
		while( curr != nullptr && !found)
		{
			if(curr->nodeValue == di)
			{
				found = true;
			}
			else
			{
				trailing = curr;
				if(curr->nodeValue > di)
					curr = curr-> Lchild;
				else
					curr = curr ->Rchild;

			}
		}
		if (curr == nullptr)
		{
			cout <<"Error- Item you are trying to delete is not in tree"<< endl;
		}
		else if(found)
		{
			if(curr == treeRoot)
				bstDeleteInternal(treeRoot);
			else if(trailing-> nodeValue > di)
				bstDeleteInternal(trailing ->Lchild);
			else
				bstDeleteInternal(trailing->Rchild);
		}
	}
}
//*****************************************************************************************
// Function: bstInOrderInternal(Treenode <T> *) const
//Preconditions
//	ptr- points to the treeRoot
//Postconditions
//	Does a In Order traversal of the tree and prints the tree "In Order"
//Description
//	This function is the In Order Internal function of the Binary Search Tree. It checks
//	if the ptr is not equal to null. It then goes to left subtree, it then displays that node,
//	then it goes to the right subtree. This goes on through recursion until the whole tree has
//	been traversed through.
//*****************************************************************************************
template < class T>
void BinarySearchTree <T>:: bstInOrderInternal(Treenode<T> * ptr) const
{
	if(ptr != nullptr)
	{
		bstInOrderInternal(ptr->Lchild);
		cout << ptr-> nodeValue << endl;
		bstInOrderInternal(ptr->Rchild);
	}
}
//*****************************************************************************************
// Function: bstInOrderTraversal() const
//Preconditions
//	None
//Postconditions
//	Does a In Order traversal of the tree and prints the tree "In Order"
//Description
//	This function calls the bstInOrderInternal to do the traversal and print the tree
//*****************************************************************************************
template <class T>
void BinarySearchTree<T> :: bstInOrderTraversal() const
{
	bstInOrderInternal(treeRoot);
}
//*****************************************************************************************
// Function: bstPreOrderInternal(Treenode <T> *) const
//Preconditions
//	ptr- points to the treeRoot
//Postconditions
//	Does a Pre Order traversal of the tree and prints the tree in "Pre Order"
//Description
//	This function is the In Order Internal function of the Binary Search Tree. It checks
//	if the ptr is not equal to null. It displays the treeRoot, it then goes to left subtree,
//	then goes to the right subtree. This goes on through recursion until the whole tree has
//	been traversed through.
//*****************************************************************************************
template < class T>
void BinarySearchTree <T>:: bstPreOrderInternal(Treenode<T> * ptr) const
{
	if(ptr != nullptr)
	{
		cout << ptr->nodeValue << endl;
		bstPreOrderInternal( ptr->Lchild);
		bstPreOrderInternal(ptr-> Rchild);
	}
}
//*****************************************************************************************
// Function: bstPreOrderTraversal() const
//Preconditions
//	None
//Postconditions
//	Does a Pre Order traversal of the tree and prints the tree in "Pre Order"
//Description
//	This function calls the bstPreOrderInternal to do the traversal and print the tree
//*****************************************************************************************
template <class T>
void BinarySearchTree<T> :: bstPreOrderTraversal() const
{
	bstPreOrderInternal(treeRoot);
}
//*****************************************************************************************
// Function: bstPostOrderInternal(Treenode <T> *) const
//Preconditions
//	ptr- points to the treeRoot
//Postconditions
//	Does a Post Order traversal of the tree and prints the tree in "Post Order"
//Description
//	This function is the Post Order Internal function of the Binary Search Tree. It checks
//	if the ptr is not equal to null. It goes to left subtree, then it goes to the right subtree,
//	then it displays the node value. This goes on through recursion until the whole tree has
//	been traversed through.
//*****************************************************************************************
template < class T>
void BinarySearchTree <T>:: bstPostOrderInternal(Treenode<T> * ptr) const
{
	if(ptr != nullptr)
	{
		bstPostOrderInternal(ptr->Lchild);
		bstPostOrderInternal(ptr->Rchild);
		cout<< ptr-> nodeValue << endl;
	}
}
//*****************************************************************************************
// Function: bstPostOrderTraversal() const
//Preconditions
//	None
//Postconditions
//	Does a Post Order traversal of the tree and prints the tree in "Post Order"
//Description
//	This function calls the bstPostOrderInternal to do the traversal and print the tree
//*****************************************************************************************
template <class T>
void BinarySearchTree<T> :: bstPostOrderTraversal() const
{
	bstPostOrderInternal(treeRoot);
}
#endif /* BST_H_ */
