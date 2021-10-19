//============================================================================
// Name        : ShafiA2.cpp
// Author      : Shahzeb Shafi
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================
#include "LLnode.h"
#include "Student.h"
#include <iostream>
#include <string>

using namespace std;
int main() {
	LL <Student> ll1;
	cout << "main: length of empty list - " << ll1.list_length() << endl;
	ll1.display_list();
	Student temp;
	temp.studentName = "aaaaa";
	temp.studentID = 12345;
	ll1.push_front(temp);
	temp.studentName = "bbbbb";
	temp.studentID = 23456;
	ll1.push_back(temp);
	temp.studentName = "before aaaaa";
	temp.studentID = 34567;
	ll1.push_front(temp);
	temp.studentName = "after bbbbb";
	temp.studentID = 45678;
	ll1.push_back(temp);
	cout << "main: length of list after 4 pushes - " << ll1.list_length() << endl;
	ll1.display_list();
	cout << endl;

	bool b;
	b = ll1.search_list (23456);
	if (b)
		cout << "main: node with ID 23456 found" << endl;
	else
		cout << "main: node with ID 23456 not found - that's an error" << endl;

	b = ll1.search_list (23457);
	if (b)
		cout << "main: node with ID 23457 found - that's an error" << endl;
	else
		cout << "main: node with ID 23457 not found" << endl;

	b = ll1.delete_node (23456);
	if (b)
		cout << "main: node with ID 23456 deleted" << endl;
	else
		cout << "main: node with ID 23456 not deleted - that's an error" << endl;

	cout << "main: length of list after delete - " << ll1.list_length() << endl;
	cout << "main: display of list after delete" << endl;
	ll1.display_list();

	ll1.destroy_list();
	cout << "main: length of list after destroy - " << ll1.list_length() << endl;
	cout << "main: display of list after destroy" << endl;
	ll1.display_list();
	cout << endl;

	LL <string> ll2;

	ll2.push_front("33333");
	ll2.push_front("22222");
	ll2.push_front("11111");
	ll2.push_back("44444");
	ll2.push_back("55555");
	ll2.push_back("66666");
	cout << "main: length of ll2 after 6 pushes: " << ll2.list_length() << endl;
	ll2.destroy_list();
	cout << "main: length of ll2 after destroy: " << ll2.list_length() << endl;

	return 0;
}

