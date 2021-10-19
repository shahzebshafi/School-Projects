/*
 * LLnode.h
 *
 *  Created on: Aug 30, 2020
 *      Author: shahzebshafi
 */
#include <iostream>
#include <string>
#include "Student.h"
using namespace std;
#ifndef LLNODE_H_
#define LLNODE_H_
template <class T>
class LL
{
private:
	struct LLnode
{
	LLnode *fwdPtr;
	T theData;

};

	LLnode* head;
public:
	LL (){head=nullptr;}// Constructor
	void push_front(T);
	void push_back(T );
	int list_length ();
	Student retrieve_front();
	Student retrieve_back();
	void display_list();
	void destroy_list();
	bool search_list(int);
	bool delete_node(int);

};
//**************************************************************************************************************************
//Function: push_front( T theData)

//Preconditions:
//	 Head: is passed in through the class so it doesn't need to be placed within the parameters
//	 Val: is a templated data type
//Postconditions:
//	Returns nothing
//Description:
//	 Fucntion either initializes the head pointer if the list is empty and enters the data into the head pointer, but if
//	 the list is not empty then it creates a new node, sets the new node to the header and links the new node to the previous
//	 header.
//***************************************************************************************************************************
template <class T>
void LL <T>:: push_front (T val) // This function pushes data in front of the linked list
{
	LLnode *temp= new LLnode;// Gets space for New Node
	temp -> theData=val;//This puts data within the new node that was created in the line above
	temp-> fwdPtr=head;
	head=temp;
	//cout <<"push_front success" << endl;
}
//**************************************************************************************************************************
//Function: push_back( T theData)

//Preconditions:
//	 Head: is passed in through the class so it doesn't need to be placed within the parameters
//	 Val: is a templated data type
//Postconditions:
//	 Returns nothing
//Description:
//	 Function creates a pointer to tranverse the list, and it tranverses through a while loop to find the last node, after
//	 finding a that last node, a new pointer is then created which will be the last node. The new pointer is set to null and
//	 has data placed within it. It then sets the pointer to the other pointer that tranversed the list, which places a brand
//	 new node at the end of the list.
//***************************************************************************************************************************
template <class T>
void LL <T>:: push_back(T val) //This function pushes data to the back of the linked list
{
LLnode *temp=head;// Create a Pointer to transverse the list
if(temp!=nullptr)
{
while(temp->fwdPtr !=nullptr) //This loop finds the last pointer
		{
			temp=temp->fwdPtr;
		}
LLnode *newnode= new LLnode; // Create a pointer which will hold the data
newnode->fwdPtr=nullptr; // Sets new node's forward pointer to Null
newnode->theData=val; //Adds data to the new node
temp->fwdPtr=newnode;// Set the node with the data to the pointer that found the end of the list
}
	else
	{
		head=nullptr; //This in in case the list is empty
	}
	//cout<<"push_back works"<< endl;
}
//**************************************************************************************************************************
//Function: list_length()

//Preconditions:
//	 Head: is passed in through the class so it doesn't need to be placed within the parameters
//Postconditions:
//	 Returns the length of the list through an integer called count which was created in the function
//Description:
//	 Function creates a pointer that is set to head, then creates an integer which will count the nodes, then uses a while
//	 loop to transverse the list. Also in the while loop is count and each time through the loop count has 1 added to it for
//	 each node. After finding the last node, it exits the while loop and returns count.
//***************************************************************************************************************************
template <class T>
int LL <T>:: list_length () // This function counts the amount of nodes in the linked list and returns the integer at the end
{
LLnode * temp=head;// Creates a pointer that is set to head, and this pointer will traverse the list
int count =0; // This integer is going to count the number of nodes in the list
while (temp!=nullptr) // This loop goes through the entire list
{
	count++; // Adds 1 to count through each iteration of the loop
	temp=temp->fwdPtr;
}
return count;
}
//**************************************************************************************************************************
//Function: retrieve_front()

//Preconditions:
//	 Head: is passed in through the class so it doesn't need to be placed within the parameters
//Postconditions:
//	 Returns the data that is within the first node
//Description:
//	 Function has an if-else statement, if the the list isn't empty it uses the head pointer that was passed in from the class
//	 to retrieve the data within the header node. if the list is empty, then the user is given an error message
//***************************************************************************************************************************
template <class T>
Student LL<T>:: retrieve_front()// This function retrieves the data that is in the front of the loop
{
	if(head != nullptr) // This is if the list is not empty
	{
		return head->theData; // It returns the data that is in the header node
	}
	else // Prints an error message if the list is empty
	{
		cout<<"Error: Your List is empty"<<endl;
	}

}
//**************************************************************************************************************************
//Function: retrieve_back()

//Preconditions:
//	 Head: is passed in through the class so it doesn't need to be placed within the parameters
//Postconditions:
//	 Returns the data that is within the last node
//Description:
//	 Function has an if-else statement, if the the list isn't empty it creates a pinter that is set to the head node, it then
//	 uses a while loop to transverse the list until it reaches the end, then it exits the loop. Since the pointer that was
//	 created is now pointing to the last node, it simply returns the data that is within that last node. If the list is empty
//	 the user is given an error message.
//***************************************************************************************************************************
template <class T>
Student LL <T>:: retrieve_back() // This function retrieves the data that is at the end of the loop
{
	if(head != nullptr) // This is if the list isn't empty
	{
		LLnode*temp=head; // Creates a new temp pointer that is pointing to head
		while(temp->fwdPtr !=nullptr) // This loop goes through the linked list to find the last node
		{
			temp=temp->fwdPtr;
		}
		return temp->theData; // returns the data that is in that last node
	}
	else // Prints an error message if the list is empty
	{
		cout<<"Error: Your List is empty"<<endl;
	}
}
//**************************************************************************************************************************
//Function: display_list()

//Preconditions:
//	 Head: is passed in through the class so it doesn't need to be placed within the parameters
//Postconditions:
//	 Displays the entire linked list with the node number (node number is found through an integer called count), address of
//	 the node, and the data within the nodes
//Description:
//	 Function creates a pointer that is set to the head, creates an integer called count that is set to zero, then uses a while
//	 loop to transverse the list. Through each iteration of the while loop the node that is being pointed to is displayed
//	 through a cout statement. Also one is added to count through each iteration of the while loop. After the cout statement
//	 is displayed and one is added to count, the pointer then points the the next node, and these steps are repeated until
//	 the entire list is displayed
//***************************************************************************************************************************
template <class T>
void LL <T>::display_list() // This function displays the whole linked list
{
LLnode *temp=head; // Creates a temp pointer that is pointing to the header
int count=0; // This integer shows the number of the node within the linked list
while(temp != nullptr) // Loop that goes through the whole Linked List
{
	cout<<"Node Number "<< " "<<count <<" "<< temp <<" " <<temp->theData.studentName <<" "<<temp->theData.studentID <<endl;
	count++;
	temp=temp->fwdPtr;
}
}
//**************************************************************************************************************************
//Function: destory_list()

//Preconditions:
//	 Head: is passed in through the class so it doesn't need to be placed within the parameters
//Postconditions:
//	 Destroys the whole list, leaving nothing because the whole list was deleted
//Description:
//	 Function creates a brand new pointer, then uses a while loop that will transverse the list while the list isn't empty,
//	 in the while loop head is set equal to temp, then uses head to advance to the next node. Then temp is deleted. This loop
//	 goes on until the whole list is deleted.
//***************************************************************************************************************************
template <class T>
void LL <T>::destroy_list()
{
LLnode *temp; //Creates pointer temp

while(head !=nullptr) // While loop while list isn't empty
{
	temp= head; //sets temp to the head node
	head=head->fwdPtr; // head then goes to next node
	delete temp; // temp is deleted
}
head=nullptr;
}
//**************************************************************************************************************************
//Function: search_list(theData.StudentID)

//Preconditions:
//	 Head: is passed in through the class so it doesn't need to be placed within the parameters
//	 Int n: this integer refers to the student ID that is within the student structure
//Postconditions:
//	 Returns true if the student ID searched for is found
//	 Returns false if the student ID searched for is not found
//Description:
//	 Function creates a brand new pointer that is set to the head node, then uses a while loop that has two conditions, one of
//	 of them being if the list isn't empty, and the other if the certain studentId is not found. Once the while loop is exited
//	 either the loop went through the whole list and the Student ID was not found in which case an if statement is used to
//	 return false. In the other case if the student Id is found then an else statement is used to return true.
//***************************************************************************************************************************
template <class T>
bool LL<T>::search_list(int n)
{
LLnode *temp= head;//Creates pointer temp set to head


while(temp != nullptr && n != temp->theData.studentID)//While loop with two conditions
{
	temp = temp->fwdPtr; //tranverses the list until it either goes through whole list or Student ID is found
}
if(temp == NULL) //If the while loop goes through whole list without finding student ID
	return false;
else //If the while loop finds StudentID
	return true;
}
//**************************************************************************************************************************
//Function: delete_node(theData.StudentID)

//Preconditions:
//	 Head: is passed in through the class so it doesn't need to be placed within the parameters
//	 Int n: this integer refers to the student ID that is within the student structure
//Postconditions:
//	 Returns true if the student ID searched for is found and deleted
//	 Returns false if the student ID searched for is not found therefore can't be deleted
//Description:
//	 Function creates two pointers, one pointer to transverse the list, the other pointer stays one node behind the pointer
//	 that tranverses the list. If list is empty then an error message is given to the user. If the Student Id that needs to be
//	 deleted is in the head, then it is deleted and temp is set to head. If the data that needs to be deleted is not in the
//	 head node, then head is set to temp, and a while loop is created to transverse the list with the two same conditions that
//	 were in the search function. Which is it tranvereses the list while the list isn't empty or the StudentId is not found.
//	 When the loop is exited either the Student ID was found, and it is then deleted through an if statement and returns true,if
//	 it is not found then the user is given an error message saying the Student Id they were looking for wasn't found.
//***************************************************************************************************************************
template <class T>
bool LL<T>::delete_node(int n)
{
LLnode*temp; //Temp pointer that will transverse the list
LLnode*previousnode =nullptr; // Pointer that will stay behind the temp pointer
if(head==nullptr) // If list is empty then an error message is given
{
	cout<<"Error: List is empty"<< endl;
	return false;
}
if (head -> theData.studentID==n)// If Student ID that needs to deleted is in head, it gets deleted in this statement
{
	temp=head->fwdPtr;
	delete head;
	head=temp;
	return true;
}
else // If student ID that needs to be deleted isn't in the head pointer it then goes here
{
	temp=head;
	while(temp != nullptr && temp -> theData.studentID !=n) // While loop with two conditions
	{
		previousnode=temp; // sets temp to previous node
		temp=temp->fwdPtr; // this is used to to point to the next node
	}
	if(temp) // If loop is exited and the Student Id that needs to be deleted is found it gets deleted in this if statement
	{
		previousnode->fwdPtr=temp->fwdPtr;
		delete temp;
		return true;
	}
	else // this is if the node that needs to be deleted was not found, it prints an error message
	{
		cout<<"Error: Not found"<< endl;
			return false;
	}
}
}



#endif /* LLNODE_H_ */
