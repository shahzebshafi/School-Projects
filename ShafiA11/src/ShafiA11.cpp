//============================================================================
// Name        : ShafiA11.cpp
// Author      : Shahzeb Shafi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BST.h"
using namespace std;

int main() {

	BinarySearchTree <int> mytree;
	int i;

	i=5;
	mytree.bstInsert(i);
	i=3;					// gaddis p. 1162
	mytree.bstInsert(i);
	i=8;
	mytree.bstInsert(i);
	i=12;
	mytree.bstInsert(i);
	i=9;
	mytree.bstInsert(i);
	mytree.printFlat();
	cout << "in order" << endl;
	mytree.bstInOrderTraversal();
	cout << "pre order" << endl;
	mytree.bstPreOrderTraversal();
	cout << "post order" << endl;
	mytree.bstPostOrderTraversal();
	i = 12;
	bool b;
	b=mytree.bstSearch(i);
	if (b)
	{
		cout << "found" << endl;
	}
	else
	{
		cout << "not found" << endl;
	}
	i = 4;
	mytree.bstInsert(i);
	cout << "--------------------------------------------------------------" << endl;
	mytree.printFlat();
	i = 12;
	mytree.bstUDelete(i);
	cout << "--------------------------------------------------------------" << endl;
	mytree.printFlat();
	cout << "--------------------------------------------------------------" << endl;

	BinarySearchTree <int> myOtherTree;
	int array[14] = {50,55,30,35,15,20,5,6,21};	// malik p. 622
	for (int i=0;i<9;i++)
	{
		myOtherTree.bstInsert(array[i]);
	}
	myOtherTree.printFlat();
	cout << "in order" << endl;
	myOtherTree.bstInOrderTraversal();
		cout << "pre order" << endl;
		myOtherTree.bstPreOrderTraversal();
		cout << "post order" << endl;
		myOtherTree.bstPostOrderTraversal();
	return 0;
}
