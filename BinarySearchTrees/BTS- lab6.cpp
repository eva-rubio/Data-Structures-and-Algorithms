//============================================================================
// File name    : BTS.cpp
// Author       : Eva Rubio
// Description  : LAB #6 - Binary Search Trees
// This program implements a BST
//============================================================================


#include <iostream>
using namespace std;

struct node{
	int num;
	node * parent;
	node * left;
	node * right;
};

void print(node * temp);
void insert(node * & root, node * temp, int value);
void search(node * temp, int value);
void remove(node * temp, int value);

int main()
{
	node * root = NULL;
	int choice;
	int value;
	
	do
	{
		cout << "\n1. Print the tree\n"
		 	 << "2. Insert into the tree\n"
			 << "3. Search for a value in the tree\n"
			 << "4. Delete from the tree\n"
		     << "5. Quit\n\n"
		     << "What do you want to do: ";
		cin >> choice;

		if (choice == 1)
		{
			print(root);
		}
		else if (choice == 2)
		{
			cout << "\nWhat number do you want to insert: ";
			cin >> value;
	    	insert(root, root, value);
			print(root);
		}
		else if (choice == 3)
		{
			print(root);
			cout << "\nWhat number do you want to search for: ";
			cin >> value;
			search(root, value);
		}
		else if (choice == 4)
		{
			cout << "What number do you want to remove: ";
			cin >> value;
			remove(root, value);
			print(root);
		}
	} while (choice != 5);
	
return 0;
}


void insert(node * & root, node * temp, int value)
{
	if(temp == NULL)
	{
		temp = new node;
		temp -> num = value;
		temp -> parent = NULL;
		temp -> left = NULL;
		temp -> right = NULL;
		root = temp;
	}
	else
	{
		if(value <= temp -> num)
		{
			if(temp -> left == NULL)
			{
				temp -> left = new node;
				temp -> left -> num = value;
				temp -> left -> left = NULL;
				temp -> left -> right = NULL;
				temp -> left -> parent = temp;
			}
			else
			{
				temp = temp -> left;
				insert(root, temp, value);
			}
		}

		else if(value > temp -> num)
		{
			if(temp -> right == NULL)
			{
				temp -> right = new node;
				temp -> right -> num = value;
				temp -> right -> left = NULL;
				temp -> right -> right = NULL;
				temp -> right -> parent = temp;
			}
			else
			{
				temp = temp -> right;
				insert(root, temp, value);
			}

		}
	}
		
}			

void search(node * temp, int value)
{
	if(temp == NULL)
	{
		cout << "\nYour number isn't in the tree\n";
	}
	else if(temp -> num == value)
	{
		cout << "\nYou found the number in the tree\n";
	}
	else if(value < temp -> num)
	{
		temp = temp -> left;
		search(temp, value);
	}
	else if(value > temp -> num)
	{
		temp = temp -> right;
		search(temp, value);
	}

}

/**
 * Searches the table to find the node to delete, if found, rearanges pointers and deletes such node.
 *
 * @param temp 			The node to delete 
 * @param value 		 
*/
void remove(node * temp, int value){
	
	//When encontrado o I'm at Null
	while (temp != NULL) {
		if (temp -> num == value) {
			//encontradooooooo!

			
			if (temp -> left == NULL && temp -> right == NULL) {	// when at the boottom, nadie debajo
				if (temp -> parent -> right == temp) {
					temp -> parent -> right = NULL;
					delete temp;
				}
				if (temp -> parent -> left == temp) {
					temp -> parent -> left = NULL;
					delete temp;
				}
			}

			else if (temp -> left == NULL && temp -> right != NULL) { // solamente UNICO hijo
				temp -> num = temp -> right -> num;
				temp -> right = NULL;
				delete temp -> right;
			}
			else if (temp -> right == NULL && temp -> left != NULL) {
				temp -> num = temp -> left -> num;
				temp -> left = NULL;
				delete temp -> left;
			}

			else if (temp -> left != NULL && temp -> right != NULL) { // cuando tiene DOS hijos--

				node * otherTemp = new node;
				otherTemp = temp -> left;

				if (otherTemp -> right == NULL) {
					temp -> num = otherTemp -> num;
					temp -> left = otherTemp->left;
					delete otherTemp;
					break;
				}

				while (otherTemp -> right != NULL) {
					otherTemp = otherTemp -> right;
				}
				
				cout << temp -> num;
				cout << otherTemp -> num;
				temp -> num = otherTemp -> num;

				if (otherTemp -> left == NULL) {
					otherTemp -> parent -> right = NULL;
					delete otherTemp;
				}
				if (otherTemp -> left != NULL) {
					otherTemp -> parent -> left = otherTemp -> left;
					delete otherTemp;
				}	
			}
			break;
		}

		else if (value < temp -> num) {	// si debo seguir buscando, esto es recursivo
			temp = temp -> left;
		}
		else if (value > temp -> num) {
			temp = temp -> right;
		}
	}




}

void print(node * temp)
{
	cout << endl << endl;	

	for(int j = 0; j < 5; j++)
	{	
		cout << '\t';
	}
	cout << temp -> num << endl << endl;
	
	for(int j = 1; j < 5; j++)
	{	
		cout << '\t';
	}
	
	if(temp -> left != NULL)
		cout << temp -> left -> num  << "                  ";
	else
		cout << "                        ";
	if(temp -> right != NULL)
		cout << temp -> right -> num;
 	
	
	cout << endl << endl;

	cout << "                            ";

	node * templ = NULL;
	node * tempr = NULL;
	node * templl = NULL;
	node * templr = NULL;
	node * temprl = NULL;
	node * temprr = NULL;
	
	if (temp -> left != NULL)
	{
		templ = temp -> left;
		if(templ -> left != NULL)
		{
			cout << templ -> left -> num  << "      ";
			templl = templ -> left;
		}
		else
			cout << "       ";
		if(templ -> right != NULL)
		{
			cout << templ -> right -> num  << "          ";
 			templr = templ -> right;
		}	
		else
			cout << "         ";
	}	
	if (temp -> right != NULL)
	{
		tempr = temp -> right;
		if(tempr -> left != NULL)
		{
			cout << tempr -> left -> num  << "      ";
			temprl = tempr -> left;
		}
		else
			cout << "          ";
		if(tempr -> right != NULL)
		{
			cout << tempr -> right -> num  << "      ";
 			temprr = tempr -> right;
		}	
		else
			cout << "        ";
	}	

	cout << endl << endl;

	cout << "                        ";

if (temp -> left != NULL)
{
	if (templl != NULL)
	{
		if (templl -> left != NULL)
			cout << templl -> left -> num << "    ";
		else
			cout << "     ";
		if (templl -> right != NULL)
			cout << templl -> right -> num << "    ";
		else
			cout << "     ";
	}
	else
		cout << "           ";

	if (templr != NULL)
	{
		if (templr -> left != NULL)
			cout << templr -> left -> num << "   ";
		else
			cout << "    ";
		if (templr -> right != NULL)
			cout << templr -> right -> num << "   ";
		else
			cout << "     ";		
	}
	else
		cout << "          ";
}
else
	cout << "             ";

if (temp -> right != NULL)
{
	if (temprl != NULL)
	{
		if (temprl -> left != NULL)
			cout << temprl -> left -> num << "   ";
		else
			cout << "     ";
		if (temprl -> right != NULL)
			cout << temprl -> right -> num << "   ";
		else
			cout << "    ";
	}
	else
		cout << "        ";

	if (temprr != NULL)
	{
		if (temprr -> left != NULL)
			cout << temprr -> left -> num << "   ";
		else
			cout << "    ";
		if (temprr -> right != NULL)
			cout << temprr -> right -> num << "   ";
		else
			cout << "     ";		
	}
	else
		cout << "        ";
}
else
	cout << "           ";

} 