/*
Assignment 5 Arrays
Krzysztof Szczurowski 
A01013054
October 23rd 2019
*/
#include<iostream>
#include<array>
#include <iomanip>


using namespace std;

int main() 
{
	const int arraySize = 5;
	int myData[arraySize] = {0,0,0,0,0};
	int input, insert;
	int count = 0;

	int index = 0; // index into data[]

	cout << "Enter 5 unique numbers between 10 and 100: ";

	while (count != arraySize) 
	{
		cin >> input;

		if (input < 10 || input > 100) {
			cout << "Invalid input. Try again." << endl;
			continue;  // looping until user inputs valid number
		}

		for (index = 0; index < arraySize; index++) {
			if (myData[index] == input)
				break; // found duplicate, complain
		}

		if (index != arraySize) {
			cout << "Duplicate value. Try again" << endl;
			continue;  // looping until user inputs valid number
		}

		myData[count++] = input; // copy unique valid number to array
	}

	//Display Unsorted Array 
	cout << "Unsorted array:" << endl;

	for (int i = 0; i < arraySize; i++)
	{
		cout << setw(4) << myData[i];
	}

	cout << endl;

	//insertion sort 
	for (int next = 1; next < arraySize; next++)
	{
		insert = myData[next];

		int moveItem = next;

		while ((moveItem > 0) && (myData[moveItem - 1] < insert))
		{
			myData[moveItem] = myData[moveItem - 1];
			moveItem--;
		}
		myData[moveItem] = insert;
	}
	cout << endl << "Sorted Array: " << endl;

	for (int i = 0; i < arraySize; i++)
		cout << setw(4) << myData[i];

	cout << endl;

	return 0;
}