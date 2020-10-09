//============================================================================
// File name    : linkedlist.cpp
// Author       : Eva Rubio
// Description  : Program #2 - Linked Lists
// Importing data from: class_list.txt
// This program manages a database in a linked list.
// I wasnt able to input the data from the file into the linked list, I tried everything (left some of my tries commented out).
//The rest of the program works and compiles, so I decided to input the data manually instead of submitting something that did not compile. Sorry!
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

struct node {
	int numID;			// A single integer field (called numID)
	string name;		// A single string field (called name)
	node * next;		// A pointer to the next node in the list
};

void print(node * first);
void prepend(int userNum, string userName, node * & first);
void append(int userNum, string userName, node * & first);
void remove(int userNum, node * & first);
void swap(node * & one, node * & two);	
void sort(node * first);			

int main() {
// Variable definitions
	node * first;				// Pointer to the first node in the list
	node * last;				// Pointer to the last node in the list
	int size;					// How many students are in the file
	int choice;					// Menu choice

	int inputID;
	string inputName;
//_____________________________________________________________________________________________________________________________________________________________	
//_____________________________________________________________________________________________________________________________________________________________	
//					-- Descomentar esta zona para input manualmente los student nodes. -- 
//									To manually enter data into nodes:


	char more_nodes = 'y';	// Control to know if the user wants to enter more

		// Creates the first node
		first = new node;			// Create the first node
		cout << "What's the first student ID: ";
		cin >> first -> numID;		// Put data in it
		cout << "What's the first student's NAME: ";
		cin >> first -> name;		// Put data in it
		first -> next = NULL;		// Point it to NULL (since it's the end)
		last = first;				// Point last to it (since it's the end)


	// This loop adds one new node, loads data into it, and updates pointers	
		while(more_nodes == 'y')		
		{
			last -> next = new node;	// Get a new node tacked onto the end of the list
			last = last -> next;		// Toggle last to point to this new node (since it's the new "last")
			cout << "introduce new student's ID: ";
			cin >> last -> numID;			// Put the data from the user into the new node (which is the last one in this case)
			cout << "introduce new student's NAME: ";
			cin >> last -> name;
			last -> next = NULL;		// Point the new node to NULL
			
			print(first);

			cout << "Do you have more numbers to enter?";
			cin >> more_nodes;
		}

//_____________________________________________________________________________________________________________________________________________________________	
//_____________________________________________________________________________________________________________________________________________________________	
//				Should be uncommentted when imputing the file

// Create the first node
//	first = new node;			// Create the first node
//	last = first;				// Point last to it (since it's the end) 
//_____________________________________________________________________________________________________________________________________________________________	
/*

// OPEN THE FILE AND LOAD DATA INTO THE first NODE

// LOOP THROUGH THE FILE AND LOAD THE REMAINING DATA INTO THE LIST

	// Holds the instances of ifstream.
	ifstream infile; 
    //Opens the file
	infile.open("class_list.txt");

    //grab info from file and save it in howMany(grabs first thing in the file)
    // number of students in file
    // la cosa esta ">>" reads a line from txt file
    // Read the next word from the file and store it in currentWord: (fileIn >> currentWord)
	int howMany;
	infile >> howMany;
	//grabs 2 and stores them separately each line

// we are loading data into the node recently created'first'
	while(!infile.eof()){

		node * myNode;
		myNode = new node;
		infile >> myNode->numID;
		infile >> myNode->name;

		node *myTemp = first;

		//siempre va a estar null first al principio
		if (myTemp == NULL) {
			//if  first node null se iguala a mynode
			myTemp = myNode; 
			myTemp->next = NULL;
			
		} else {

        while(myTemp->next != NULL){ 

        	myTemp = myTemp->next;
        	myTemp->next = myNode;
        }
    }
                //last node
        //myTemp->next = myNode;
       // myTemp->next->next = NULL;

}

infile.close();
*/
//_____________________________________________________________________________________________________________________________________________________________	






do {
	cout << "1. Print the list\n"
	<< "2. Prepend (add) a node to the beginning of the list\n"
	<< "3. Append (add) a node to the end of the list\n"
	<< "4. Delete a node by ID\n"
	<< "5. Sort the list by ID\n"
	<< "6. Quit\n\n"
	<< "What do you want to do: ";
	cin >> choice;
	cout << endl;

	if (choice == 1) {
		print(first);
	}
		//		PREPEND
	else if (choice == 2) {
		cout << "Please introduce student's ID to PREPEND to the list: " << endl;
		cin >> inputID;
		cout << "Please introduce student's NAME to PREPEND to the list: " << endl;
		cin >> inputName;
		prepend(inputID, inputName ,first);
	}		
		//		APPEND
	else if (choice == 3) {
		cout << "Please introduce student's ID to APPEND to the list: " << endl;
		cin >> inputID;
		cout << "Please introduce student's NAME to APPEND to the list: " << endl;
		cin >> inputName;
		append(inputID, inputName ,first);
	}		
		//		DELETE
	else if (choice == 4) {
		cout << "Please introduce student's ID to DELETE from the list: " << endl;
		cin >> inputID;
		remove(inputID, first);		
	}
		//		SORT
	else if (choice == 5) {
		sort(first);			
	}

	cout << " -- Here's your updated list: --  " << endl << endl;		
	print(first);

		//		QUIT
} while (choice != 6);

return 0;
}


void print(node * first) {
	// Print out the linked list by having a temporary pointer scroll through the entire list
	node * temp;				// Make a temporary (dummy) pointer
	temp = first;				// Point it to the first node in the list

	while(temp != NULL)			// Continue until temp reaches NULL (the end)
	{
		cout << " --- ID: " << temp -> numID << " Name: " << temp -> name << endl;		// PRINT OUT THE NAME AND ID
		temp = temp -> next;				// Move temp to the next node
	}
	cout << endl;
}

/**
 * Allows user to enter a new student name and ID to a node at the START of the list.
 *
 * @param userNum		The ID of the student node that will be created and added to list.
 * @param userName 		The name of the student node that will be created and added to list.
 * @param first 		The current first node of list.
 
 */
void prepend(int userNum, string userName, node * & first) {
	//creates new node with user input
	node * nodeToAdd;
	nodeToAdd = new node;
	nodeToAdd -> numID = userNum;
	nodeToAdd -> name = userName;
	nodeToAdd -> next = NULL;

	// if list is empty
	if (first == NULL) { 
		first = nodeToAdd;
	}
  	//if list if NOT empty
	else {
		nodeToAdd->next = first;
		first = nodeToAdd;
	}

}

/**
 * Allows user to enter a new student name and ID to a node at the END of the list.
 *
 * @param userNum		The ID of the student node that will be created and added to list.
 * @param userName 		The name of the student node that will be created and added to list.
 * @param first		 	The current first node of list.
 
 */
void append(int userNum, string userName, node * & first) {
	//creates new node with user input
	node * nodeToAdd;
	nodeToAdd = new node;
	nodeToAdd -> numID = userNum;
	nodeToAdd -> name = userName;
	nodeToAdd -> next = NULL;

	
	// if list is empty
	if (first == NULL) { 
		first = nodeToAdd;
	}
  	//if list if NOT empty
	else {
		// crezate temp to scroll through list to find last node
		node * temp;
		temp = first;

		while (temp->next != NULL) {
			temp = temp->next;
		}
        temp->next = nodeToAdd;		// add nodeToAdd at the end
    }

    print(first);



}

/**
 * Allows the user to enter any student numID, and deletes that student's node from list.
 * Adjust pointers if node is deleted.
 * If not found, print message.
 *
 * @param userNum		The ID of the student node that will be deleted from list.
 * @param first		 	The current first node of list.
 
 */

void remove(int userNum, node * & first) {
	// create temp to scroll through list
	node * temp;
	temp = first;
	// Previous node to the one to delete
	node * prev;
	prev = first;

	// if list only has one mode, and that mode is the desired one, cout message. (weird case, raro raro por si acaso)
	if (temp->next == NULL && temp->numID == userNum)
	{
		cout << endl << "ERROR. Student ID: "<< userNum <<" found but cannot be deleted as it is the only element on " << endl; 
		cout << "the list and it cannot be made empty." << endl << endl;
		return;
	}
	
	// check if ID is in FIRST node (while list has more than 1 elem)
	if (temp != NULL && temp->numID == userNum)
	{
    	//update first pointer to point to correct node (el segundo en este caso se convierte en primero)
		first = temp->next;   
        delete(temp);   //deletes de ndoe recyclin the memory            
        return;
    }

    // loop rest of list

    // prev = temp;     not sure if before or inside while
    // si no es el numero avanzamos en la loop
    while (temp != NULL && temp->numID != userNum) {
    	prev = temp;
    	temp = temp->next;
    }

    //makingsure the ID is actually in the list
    if (temp == NULL) {
    	cout << endl << "404 ERROR. Student ID: "<< userNum << " not found." << endl << endl;
    	return;
    } 

    // update pointers so that prev jumps over the node to delete
    prev->next = temp->next;
 	//delete temp once the rerouting was done
    delete(temp);  

    
}

/**
 * Swaps the two given nodes.
 *
 * @param one A node to sawap.
 * @param two A node to swap.
 
 */
void swap(node * & one, node * & two){

	int tempID = one->numID;
	string tempName = one->name;

	one->numID = two->numID;
	one->name = two->name;
	two->numID = tempID;
	two->name = tempName;

}

/**
 * Sorts linked list by numID with the Bubble Sort Algorithm.
 *
 * @param first The first node of the list to sort.
 
 */
void sort(node * first) {
	int swapping = 0;
	node * temp;
	//temp = first;
	node * otherTemp;


	//check to see if list is empty
	// (doesnt happen cause list cannot be made empty (delete methd))
	if (temp == NULL) {
		cout << "The list is empty, cannot be sorted." << endl;
		return;
	}
	do {
        swapping = 0;	// reseteamos el valor cada vez que entramos en el loop
        temp = first;	// para que la lista se sortee del todo y no un elemento  por vez que loop runs

        while (temp->next != NULL) {
        	if (temp->numID > temp->next->numID) { 
        		swap(temp, temp->next);
                swapping++;			// se incrementa solo si se ha realizado un swap
            }
            temp = temp->next;	// advance in list
        }
        otherTemp = temp;	//veamos si lo necesito, not sure
    }
    while (swapping);


}
