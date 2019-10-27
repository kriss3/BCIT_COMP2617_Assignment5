/*
Assignment 5 Arrays
Krzysztof Szczurowski 
A01013054
Initial implementation using C-Style arrays;
After successfull tests, switched to C++11 arrays; 
Commented out declarations of C-Style arrays for historical purposes;
October 23rd 2019
*/
#include<iostream>
#include<array>
#include <iomanip>
using namespace std;

//function to test value under test whether it is unique or not;
//bool isUnique(int val, int myData[], int size);
template<size_t arrSize>
bool isUnique(int val, const array<int, arrSize> & myData, int size);

//function to display collection of number;
//void arrayDisplay(int myData[], int arrSize);
template<size_t arrSize>
void arrayDisplay(const array<int, arrSize> & myData, int size);

const int COLUMN_NUMBER = 5;

int main() 
{
	const size_t collSize = 20;
	//int myData[collSize] = {0};	// unique collection of int values;
	array<int, collSize> myData = {0};
	int input;
	int count = 0;
	int counter = 1;

	int index = 0; // index of myData[] collection;
		
	while (count != collSize)
	{
		cout << "Enter # " << counter << " : ";
		cin >> input;

		if (input < 10 || input > 100) 
		{
			cout << "The number entered is not in the valid range of 10 to 100\n" << endl;
			continue; 
		}

		// function call to return info whether a new value in Tests is a unique value or not;
		if (!isUnique(input, myData, collSize))  
		{
			count++;
			counter++;
			cout << endl;
			continue;
		}

		//Throw confirmation message to the user and store val to myData array;
		cout << "The number: " << input << " is unique\n" << endl;
		counter++;
		// store unique value under test into myData array
		myData[count++] = input;
	}

	//Display collection of unique int stored in myData;
	cout << "The unique numbers are:\n" << endl;
	arrayDisplay(myData, collSize);
	cout << endl;
	return 0;
}

//returns informaiton whether passed in val is a unique number within the given array;
//takes: val : value to test, myData : reference to array with existing values, size: site of the array;
//returns: true: val is unique, false: value already exists in the given array;
template<size_t arrSize>
bool isUnique(int val, const array<int, arrSize> & myData, int size)
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

//helper function to display values stored in the passed in collection;
//takes: an array and its size;
//returns: nothing;
template<size_t arrSize>
void arrayDisplay(const array<int, arrSize> & myData, int collSize) 
{
	int myColumns = COLUMN_NUMBER;
	for (int i = 0; i < collSize; i++)
	{
		if (myData[i] > 0)			// display only unique, populated values (exclude default)
		{
			if (myColumns < 1)	// check for formatting only;
			{
				cout << endl;
				myColumns = COLUMN_NUMBER;
			}
			cout << setw(6) << myData[i];
			myColumns--;
		}
	}
}
