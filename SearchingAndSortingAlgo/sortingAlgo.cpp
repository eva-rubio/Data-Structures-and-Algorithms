#include <iostream>
#include <ctime>
#include <math.h>
#include <cstdlib>

// Author: Eva Rubio

using namespace std;

const int SIZE = 8;

void print2Darray(int chart[SIZE][SIZE]); // This function will print the chart
void getRowSORTED(int chart[SIZE][SIZE], int userChoice);
void getRow(int chart[SIZE][SIZE], int userChoice);
void getColumn(int chart[SIZE][SIZE], int userChoice);
void getColumnBubbleSorted(int chart[SIZE][SIZE], int userChoice);
void print1Darray(int *array, int size);
void selectionSort(int *array);
void bubbleSort(int *array);
int binarySearch(int *array, int toFind);
void binarySearchRow(int chart[SIZE][SIZE], int userChoice, int toFind);


int main(){

	int chart [SIZE][SIZE]; // This declares a 2d array of ints
	int choice;
	int selection; // For the user to select a row or colum to sort or search
	int toFind; //number to look for in binary search

    int array1[SIZE] = {6,7,8,0,1,9,3,2};
    //cout << endl << "SORTS ROW of 1d test array: " << endl;
	//selectionSort(array1);
	/**
	cout << "UNSORTED: " << endl;
	print1Darray(array1, SIZE);
	cout << endl << "SORTED: " << endl;
	bubbleSort(array1);
	int where;
	where = binarySearch(array1, 8);
	cout << "the location: " << where << endl;
*/
	// This code will load the chart with random numbers between 0-50
	int seed = time(0);
	srand(seed);
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			chart[i][j] = rand() % 50;
		}
	}
	
	//cout << "Creates NEW Chart and prints it: " << endl;
	//print2Darray(chart);
	//cout << "Gets row 2 and prints it: " << endl;
	//getRowSORTED(chart, 2);
	//cout << endl << "Gets Column 3 and prints it: " << endl;
	//getColumn(chart, 3);
	//cout << endl << "Gets column 3 and sorts it: " << endl;
	//getColumnBubbleSorted(chart, 3);
	//cout << endl << "binary search row 3, looking for 12: " << endl;
	//binarySearchRow(chart, 3, 12);

	///------- ^^^my tests^^^^

	do {
		cout << "0. Print the whole chart\n"
		<< "1. Bubble sort a COLUMN of scores\n"
		<< "2. Selection sort a ROW of scores\n"
		<< "3. Binary search a ROW\n"
		<< "4. Quit\n\n"
		<< "What do you want to do: ";
		cin >> choice;

		if (choice == 0) {
			print2Darray(chart);
			
		} else if (choice == 1){
			cout << "Please introduce the Column number to be BUBBLE sorted: " << endl;
			cin >> selection;
			getColumnBubbleSorted(chart, selection);

		} else if (choice == 2) {
			cout << "Please introduce the Row number to be sorted: " << endl;
			cin >> selection;
			getRowSORTED(chart, selection);

		} else if (choice == 3) {
			cout << "Please introduce the Row number to be searched: " << endl;
			cin >> selection;
			cout << "Please introduce value to search: " << endl;
			cin >> toFind;
			binarySearchRow(chart, selection, toFind);

		}


	} while (choice != 4);







	
	cout << "ENNNNNND " << endl;


	return 0;
}
/**
 * Prints 2D array.
 *
 * @param array An array.
 */
void print2Darray(int chart[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << chart[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}
/**
 * Prints 1D array.
 *
 * @param array An array.
 * @param size The size of the array.
 */
void print1Darray(int array[], int size)
{
	int i;
	for(i = 0; i < size; i++)
		cout << array[i] << '\t';
}
/**
 * Gets the desired Row of a 2d array and prints it.
 *
 * @param chart A 2d array.
 * @param userChoice The Row to get.
 */
void getRow(int chart[SIZE][SIZE], int userChoice){
	int temp[SIZE];
	for (int i = 0; i < SIZE; i++) {
		temp[i] = chart[userChoice][i];
	}
	print1Darray(temp, SIZE);
}
/**
 * Gets the desired Column of a 2d array and prints it.
 *
 * @param chart A 2d array.
 * @param userChoice The Column to get.
 */
void getColumn(int chart[SIZE][SIZE], int userChoice){
	int temp[SIZE];
	for (int i = 0; i < SIZE; i++) {
		temp[i] = chart[i][userChoice];
	}
	// prints the selected column of array
	print1Darray(temp, SIZE);
}
/**
 * Gets the desired Row of a 2d array and sorts its .
 *
 * @param chart A 2d array.
 * @param userChoice The Row to get and sort.
 */
void getRowSORTED(int chart[SIZE][SIZE], int userChoice){
	int temp[SIZE];
	for (int i = 0; i < SIZE; i++) {
		temp[i] = chart[userChoice][i];
	}
	cout << "ROW " << userChoice <<" BEFORE SORTING: " << endl;
	print1Darray(temp, SIZE);
	//cout << endl << "getRowSORTED method will now call selectionSort: " << endl;
	cout << endl << " SORTED ROW 2:" << endl;
	selectionSort(temp);	
}

/**
 * Gets the desired Row of a 2d array, sorts it and searchs through the row 
 * with the Binary Search algo.
 *
 * @param chart A 2d array.
 * @param userChoice The Row to get.
 */
void binarySearchRow(int chart[SIZE][SIZE], int userChoice, int toFind){
	int temp[SIZE]; // to get one unique row in a 2d array
	int where;
	for (int i = 0; i < SIZE; i++) {
		temp[i] = chart[userChoice][i];
	}
	cout << "ROW " << userChoice <<" BEFORE SORTING: " << endl;
	print1Darray(temp, SIZE);
	cout << endl << "ROW " << userChoice <<" AFTER SORTING: " << endl;
	bubbleSort(temp);

	where = binarySearch(temp, toFind);
	if (where == -1){
		cout << endl << "Value not in chart. " << endl;
	}else{
		cout << endl << "Value at index : " << where << endl;
	}
}

/**
 * Gets the desired Column of a 2d array and sorts it with the Bubble Sort algorithm.
 *
 * @param chart A 2d array.
 * @param userChoice The Column to get.
 */
void getColumnBubbleSorted(int chart[SIZE][SIZE], int userChoice){
	int temp[SIZE];
	for (int i = 0; i < SIZE; i++) {
		temp[i] = chart[i][userChoice];
	}
	// prints the selected column of array
	cout << "COLUMN " << userChoice <<" BEFORE SORTING: " << endl;
	print1Darray(temp, SIZE);
	cout << endl << " SORTED COLUMN:" << endl;
	bubbleSort(temp);
}

/**
 * Uses Selection Sort algorythm to sort the given 1d array and keeps track of swaps and comparisons. 
 *
 * @param array The array
 */
void selectionSort(int *array) {
    int small;
    int mytemp;
    int comparisons = 0;
    int swaps = 0;
    
    
    for (int k = 0; k < SIZE; k++){
        
        int small = k;
        for (int current = k; current < SIZE; current++){
        	comparisons++;
            //checking which one is the smaller
            if (array[small] > array[current]){    
                small = current;
            }
        }

        //swaping the values, need to have mytemp to store it
        mytemp = array[k];
        array[k] = array[small];
        array[small] = mytemp;
        swaps++; 
        cout << endl << "Swaps done: " << swaps << "  Numb of comparisons: " << comparisons << endl;
        cout << endl << "My sorted array: " << endl;

        print1Darray(array, SIZE);
    }
    cout << endl;
}

/**
 * Uses Bubble Sort algorythm to sort the given 1d array and keeps track of swaps and comparisons. 
 *
 * @param array The array
 */

void bubbleSort(int *array) {
    int swaps = 0;
    int comparisons = 0;
    int mytemp;

    for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE - 1; j++){
            comparisons++;
            //only swap if bigger number
            if (array[j] > array[j + 1]){
                swaps++;
                mytemp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = mytemp;
            }
        }
        //exists early if there are no swaps done.
        if( swaps == 0 ){
            break;
        }
        print1Darray(array, SIZE);
        cout << endl;
    }

    cout << endl << "Swaps done: " << swaps << "  Numb of comparisons: " << comparisons << endl;
}


/**
 * Uses Binary Search algorythm to search the given 1d SORTED array and keeps track of swaps and comparisons. 
 *
 * @param array The SORTED array
 * @param toFind The number to be searched for in the given array
 * @return The location, index, of toFind. Returns -1 otherwise.
 */

int binarySearch(int *array, int toFind) {
	int low = 0;
	int middle = 0;
	int high = SIZE - 1;

	while(high >= low){
		middle = (high + low)/2;
		if (array[middle] < toFind){
			low = middle +1;
		}else if (array[middle] > toFind){
			high = middle -1;
		}else{
			return middle;
		}

	}
	return -1; //if not found
}

