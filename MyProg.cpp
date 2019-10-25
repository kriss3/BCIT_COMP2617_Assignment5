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

bool isUnique(int val, int myData[], int size);

int main() 
{
	const int arraySize = 20;
	//TODO: initialize in a loop
	int myData[arraySize] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int input;
	int count = 0;
	int counter = 1;

	int index = 0; // index into data[]

	while (count != arraySize) 
	{
		cout << "Enter # " << counter << ": ";
		cin >> input;

		if (input < 10 || input > 100) 
		{
			cout << "The number entered is not in the valid range of 10 to 100" << endl;
			continue;  // looping until user inputs valid number
		}

		if (!isUnique(input, myData, arraySize)) 
		{
			counter++;
			continue;
		}

		cout << "This number:  " << input << " is unique." << endl;
		counter++;
		myData[count++] = input; // copy unique valid number to array
	}

	//Display myData array 
	for (int i = 0; i < arraySize; i++)
	{
		cout << setw(4) << myData[i];
	}

	return 0;
}

bool isUnique(int val, int myData[], int size)
{
	bool unique = true;

	for (int index = 0; index < size; index++)
	{
		if (myData[index] == val)
		{
			unique = false;
		} // found duplicate, break and continue collecting user input;
	}
	return unique;
}
