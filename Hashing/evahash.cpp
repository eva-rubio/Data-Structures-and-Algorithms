//============================================================================
// File name    : hash.cpp
// Author       : Eva Rubio
// Description  : Prog #3 - Hashing
// This program implements a class for a hash table 
//============================================================================


#include <iostream>
using namespace std;

const int SIZE = 10;

struct node{
	string name;
	int IDnum;
	node * next;		// the next node in each row of the table
};

class hash_table
{
public:
	node * table[SIZE];		// an array of pointers, one for each row
	int length[SIZE];		// an array to hold the length of each row
	node * temp; 			// to tell me whre i am in the list
	int row;				// to differenciate between regular null or last null

//  Constructor
	hash_table() {
		int i;
		for(i = 0; i < SIZE; i++) {
			table[i] = NULL;
			length[i] = 0;
		}
		row = 0;
		temp = table[row];
	}

//  Methods
	
/**
 * function which associates a hash value to each data element (based on its key value)
 *
 * @param key_ID    The key from the data element
 * @return   		The designated location (hash value) for that data element in the table
 */
	int hashing(int key_ID) {
		return key_ID % SIZE;
	}

	void rowLengths() {
		cout << "Here are the lengths of each row:\n";
		for (int i = 0; i < SIZE; i++)
		{
			cout << '|' << i << "| " << length[i] << endl;
		}
	}
/**
 * Prints the table
 *
 * @param temp Temporary node to go through table
 * @param row  To keep track of where in the table we are
 */
	void print(node * temp, int row) {
		// last row of array: SIZE-1
		// always stopping case goes first. if it is the lAST NULL:
		if(temp == NULL && row == SIZE-1) {
			cout << "\n\nPrinting Complete\n";

		//if its a REGULAR NULL - go to the next row	
		} else if(temp == NULL) {
			cout << endl;
			row++;
			temp = table[row];
			print(temp, row);

		//if its a regular NUMBER - print and continue.
		} else {
			cout << temp -> name << " : " << temp -> IDnum << '\t';
			temp = temp -> next;
			print(temp, row);
		}

	}
/**
 * Inserts a node in the hash table using the id num as key 
 */
	void addNode() {

		int idNew;
		string nameNew;
		node * newNode = new node;

		node * myTemp = new node; // que es una fila en realidad

		cout << "Enter a new name to be inserted: ";
		cin >> nameNew;
		cout << "Enter its ID number:  ";
		cin >> idNew;
		// to know where it goes
		row = hashing(idNew);
		//el row(array) en el que vamos a store el new node
		myTemp = table[row];
		newNode -> name = nameNew;
		newNode -> IDnum = idNew;
		//points the newNode next to point to the corresponding array(row) in the table
		// hace que el next point to el array que esta en la fila correspondiente
		newNode -> next = myTemp;

		//Point the slot i table pointer to this newnode
		table[row] = newNode;
		length[row]++;

	}
/**
 * Searches the table to find if the 'ID' given is in it or not.
 *
 * @param temp 			The appropiate table pointer 
 * @param key_ID 		The ID to be found in the table
*/
	void buscar(node * temp, int key_ID){
		int theCorrectRow = hashing(key_ID); //to search faster and only in the row it should be in
		if (temp == NULL){
			cout << "The ID number: " << key_ID << " is NOT in the chart.\n";

		} else if (temp != NULL && temp -> IDnum != key_ID){
			buscar(temp->next, key_ID);

		}else {
			cout << endl;
			cout << "ID number " << key_ID  << " found! Corresponding Name: " << temp->name << endl;
		}

	}
/*
 * Searches through table to see if given 'name' is in it or not. 
 *
 * @param temp 		The a temp pointer (pointing to row 0's first node) 
 * @param key_name 	The name to be found in the table
 * @return 			true or false
 */
	bool nameLookup(node * temp, int row, string key_name) {
		// end of table
		if(temp == NULL && row == SIZE-1) {
			return false;
			//avanzar a la siguente row y preguntar otra vez
		} else if(temp == NULL && row != SIZE-1) {
			row++;
			temp = table[row];
			return nameLookup(temp, row, key_name);

		} else if(temp != NULL && temp->name != key_name){	// dentro de la misma fila pero no es el primer valor
			return nameLookup(temp->next, row ,key_name);

		} else {
			return true;
		}
	}
};


int main()
{
	int choice, key_ID;
	node * temp;
	string key_name;
	hash_table chart;		// Declares a hash table called chart

	do
	{
		cout << "\n0. Print the row lengths\n"
			 << "1. Print the entire table\n"
			 << "2. Add a node\n"
			 << "3. Look up a node in the table by ID number\n"
			 << "4. Look up a node in the table by name\n"
		     << "5. Quit\n\n"
		     << "What do you want to do: ";
		cin >> choice;

		if (choice == 0)
		{
			chart.rowLengths();
		}
		else if (choice == 1)
		{
			chart.print(chart.temp, 0);
		}
		else if (choice == 2)
		{
	    	chart.addNode();
		}
		else if (choice == 3)
		{
			cout << "What ID number do you want to search for: ";
			cout << endl;
			cin >> key_ID;
			temp = chart.table[chart.hashing(key_ID)];
			//chart.IDLookup(temp, key_ID);
			chart.buscar(temp, key_ID);
		}
		else if (choice == 4)
		{
			cout << "What name do you want to search for: ";
			cin >> key_name;
			temp = chart.table[0];
			if(chart.nameLookup(temp,0,key_name) == true)
			{
				cout << key_name << " is in your chart!\n";
			}
			else
			{
				cout << key_name << " is NOT in the chart\n";
			}
		}
		
	} while (choice != 5);
		
	return 0;
}


