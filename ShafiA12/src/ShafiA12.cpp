//============================================================================
// Name        : ShafiA12.cpp
// Author      : Shahzeb Shafi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "AVL.h"
using namespace std;
int main() {
	BinarySearchTree <int> mytree;
	int i;
	//int array[6]={30,20,40,35,50,60};
	int array[14] = {60,50,70,30,53,80,35,57,75,32,40,77,48,45};
	for (i=0;i<6;i++)
	{
		mytree.bstInsert(array[i]);
	}
	cout << "******************************************" << endl;
	cout << "original tree" << endl;
	mytree.printFlat();
	cout << "height of original tree " << mytree.height() << endl;
	cout << "******************************************" << endl;
	cout << "tree with BF" << endl;
	mytree.setallBF();
	mytree.printFlat();
	cout <<"largest BF " << mytree.returnLargestBF() << endl;
	cout << "******************************************" << endl;
	cout << "now trying delete 35, then delete 45" << endl;
	i = 35;
	mytree.bstUDelete (i);
	i = 45;
	mytree.bstUDelete (i);
	mytree.setallBF();
	mytree.printFlat();
	cout <<" largest BF " << mytree.returnLargestBF() << endl;
	return 0;
}


