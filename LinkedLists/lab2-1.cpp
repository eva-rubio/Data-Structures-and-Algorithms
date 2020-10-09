	// This program does some basic functionalities of using a linked list

// Author: Eva Rubio

	#include<iostream>
using namespace std;

	struct node				// This structure of each node
	{
		int num;			// A single integer field (called num)
		node * next;		// A pointer to the next node in the linked list
	};

	void print(node * first);
	void prependNode(int userNum, node * & first);
	void deleteFirst(node * & first);
	void findMax(node * & first);

	int main()
	{
	// Variable definitions
		node * first;				// Pointer to the first node in the linked list
		node * last;				// Pointer to the last node in the list
		char more_nodes = 'y';	// Control to know if the user wants to enter more
		int choice;
		int userNum;

	// Creates the first node
		first = new node;			// Create the first node
		cout << "What's the first number: ";
		cin >> first -> num;		// Put data in it
		first -> next = NULL;		// Point it to NULL (since it's the end)
		last = first;				// Point last to it (since it's the end)


	// This loop adds one new node, loads data into it, and updates pointers	
		while(more_nodes == 'y')		
		{
			last -> next = new node;	// Get a new node tacked onto the end of the list
			last = last -> next;		// Toggle last to point to this new node (since it's the new "last")
			cout << "What value do you want to put in the new box: ";
			cin >> last -> num;			// Put the data from the user into the new node (which is the last one in this case)
			last -> next = NULL;		// Point the new node to NULL
			
			print(first);

			cout << "Do you have more numbers to enter?";
			cin >> more_nodes;
		}

		do 
		{
			cout << "1. Print the list\n"
			<< "2. Print the biggest number in the list\n"
			<< "3. Prepend (add) a node to the beginning of the list\n"
			<< "4. Delete the first node\n"
			<< "5. Quit\n\n"
			<< "What do you want to do: ";
			cin >> choice;

			if (choice == 1)
			{
				print(first);
			}

			else if (choice == 2)
			{
				findMax(first);

			}
			else if (choice == 3)
			{
				cout << "Please introduce the number to prepend to the list: " << endl;
				cin >> userNum;
				prependNode(userNum, first);

			}	
			else if (choice == 4)
			{
				deleteFirst(first);

			}	
		} while (choice != 5);
		
		return 0;
	}

	void print(node * first)
	{
		// Print out the linked list by having a temporary pointer scroll through the entire list
		node * temp;				// Make a temporary (dummy) pointer
		temp = first;				// Point it to the first node in the list
		
		while(temp != NULL)		// Continue until temp reaches NULL (the end)
		{
			cout << temp -> num << endl;		// Print out temp's number
			temp = temp -> next;				// Move temp to the next node
		}

	}

	void prependNode(int userNum, node * & first){
		node * nodeToAdd;
		nodeToAdd = new node;
		nodeToAdd -> num = userNum;
		//nodeToAdd -> next = NULL;

		

		//if list is NOT empty
		if (first != NULL){
			nodeToAdd -> next = first;
			first = nodeToAdd;

			

			// if list is empty make the first node eual the node to add
		}else{
			nodeToAdd -> next = NULL;
			first = nodeToAdd;
			print(first);
			
		}
		print(first);
	}

	void deleteFirst(node * & first){
		//if list is not empty
		if(first != NULL){
			node * temp;
			temp = first; //now we have two pointers to the same thing
			first = first -> next;
			delete temp;
			print(first);
	
	}else{
		cout << "The list is already empty, cant delete anything!";
	}

}

void findMax(node * & first){
	int biggest = -1;
    while (first != NULL) {
 
        if (biggest < first->num)
            biggest = first->num;
        first = first->next;
    }
    cout << "The largest value in the list is: " << biggest << endl;

}