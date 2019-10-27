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

//function to test value under test whether it is unique or not;
bool isUnique(int val, int myData[], int size);
void arrayDisplay(int myData[], int arrSize, int collNumber);

const int COLLUMN_NUMBER = 4;

int main() 
{
	
	const int collSize = 20;
	int myData[collSize] = {0};	// unique collection of int values;
	int input;
	int count = 0;
	int counter = 1;

	int index = 0; // index of myData[] collection;
		
	while (count != collSize)
	{
		cout << "Enter # " << counter << ": ";
		cin >> input;

		if (input < 10 || input > 100) 
		{
			cout << "The number entered is not in the valid range of 10 to 100" << endl;
			continue; 
		}

		// function call to return info whether a new value in Tests is a unique value or not;
		if (!isUnique(input, myData, collSize))  
		{
			count++;
			counter++;
			continue;
		}

		//Throw confirmation message to the user and store val to myData array;
		cout << "This number:  " << input << " is unique." << endl;
		counter++;
		// store unique value under test into myData array
		myData[count++] = input;
	}

	//Display collection of unique int stored in myData;
	cout << "The uniqe numbers are: " << endl;
	arrayDisplay(myData, collSize,  COLLUMN_NUMBER);

	
	
	return 0;
}

//returns informaiton whether passed in val is a unique number within the given array;
//takes: val : value to test, myData : reference to array with existing values, size: site of the array;
//returns: true: val is unique, false: value already exists in the given array;
bool isUnique(int val, int myData[], int size)
{
	bool unique = true; // setting initial value of local unique variable;

	for (int index = 0; index < size; index++)
	{
		if (myData[index] == val)
		{
			unique = false;
		} // found a duplicate, assigns false to unique variable;
	}
	return unique;
}

void arrayDisplay(int myData[], int collSize, int collNumber) 
{
	int myColumns = collNumber;
	for (int i = 0; i < collSize; i++)
	{
		if (myData[i] > 0)			// display only unique, populated values (exclude default)
		{
			if (myColumns < 1)	// check for formatting only;
			{
				cout << endl;
				myColumns = collNumber;
			}
			cout << setw(4) << myData[i];
			myColumns--;
		}
	}
}
