//#include "stdafx.h"
#include "pch.h"
#include <iostream>
#include "cstdlib"
#include "ctime"
#include<fstream>
#include <algorithm>

using namespace std;

int n, m; // amount of array elements
int columnToBeSorted;

//void printTwoD(int **);
//void sort_bubble(int **, int, int);
//void insert_sort(int **, int, int);
void selection_sort(int **, int, int);
//void merge(int **, int, int, int);
//void merge_sort(int **, int, int);
//void quicksort(int**, int, int, int);


int main()
{
	///////////////////create array////////////////////////
	cout << "Input the first dimension :";
	cin >> n;
	cout << "Input the second dimension :";
	cin >> m;
	cout << "Column to be sorted: ";
	cin >> columnToBeSorted;
	int **a = new int*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}
	ofstream fout;
	fout.open("report.txt", ios::app);
	if (!fout.is_open())
	{
		cout << "file is closed\n";
	}


	//int tmpr; // sort by decrease
	//int rand_first_pos, rand_second_pos; // 2 equal random numbers in random order
	//cout << "Enter 1-st position to be equaled to the 2-nd : \n";
	//cin >> rand_first_pos;
	//cout << "Enter 2-nd position to be equaled to the 1-st : \n";
	//cin >> rand_second_pos;

	/*int some_val;
	cout << "Enter the value array to be filled by : \n";
	cin >> some_val;*/


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//tmpr = a[i][j]; //sorted by decrease by default

			a[i][j] = rand() % 2001 - 1000; //random fill

			//if (a[i] > a[i - 1])
			//{
			//	a[i] = a[i - 1]; a[i - 1] = tmpr; //sorted by decrease by default
			//}

			//a[i][j] = some_val;	//fill with equal values	
		}
	}
	//a[rand_first_pos] = a[rand_second_pos]; // 2 equal random numbers in random order


	////////////////sorts////////////////////////
	unsigned int start_time = clock(); //current time
	//printTwoD(a); cout << "\n";
	//sort_bubble(a, n, columnToBeSorted);
	//insert_sort(a, n, columnToBeSorted);
	selection_sort(a, n, columnToBeSorted);
	//merge_sort(a, 0, n - 1);
	//quicksort(a, 0, n -1, columnToBeSorted);
	//printTwoD(a);


	unsigned int end_time = clock(); // end time
	unsigned int search_time = end_time - start_time; //searching time
	cout << "\n" << "Programms' executing time : " << search_time << " ms\n";
	fout << search_time << "\n";	
	fout.close();

	for (int i = 0; i < n; ++i) // free space 
	{ 
		delete[] a[i];		
	}
	delete[] a;

	system("pause");
	return 0;
}


//print out the array
//void printTwoD(int **aTD)
//{
//	for (int i = 0; i < n; ++i)
//	{ 
//		for (int j = 0; j < m; ++j)
//		{
//			cout << aTD[i][j] << "\t";
//		}
//		cout << "\n";
//	}			
//}


//ADD STEP 1000 TO ALL ALGORYTHMS

//////////////////////////////////BUBBLE SORT
//void sort_bubble(int **array, int n, int columnToBeSorted)
//{
//	for (int i = n - 1; i < n; i++) // change on -=1000
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (array[j][columnToBeSorted] > array[j+1][columnToBeSorted])
//				swap(array[j], array[j+1]);
//		}
//	}
//}
//////////////////////////////////BUBBLE SORT


//////////////////////////////////INSERTION SORT
//void insert_sort(int **a, int n, int columnToBeSorted)
//{
//	int i, j, value;
//	int* targetRowValue;
//
//	for (i = 1; i < n; i++) // change on +=1000
//	{
//		value = a[i][columnToBeSorted];
//		targetRowValue = a[i];
//		for (j = i - 1; j >= 0 && *a[j] > value; j--)
//		{
//			a[j + 1] = a[j];
//		}
//		a[j + 1] = targetRowValue;
//	}
//}
///////////////////////////////////INSERTION SORT


//////////////////////////////////SELECTION SORT
void selection_sort(int **a, int n, int columnToBeSorted) {
	for (int i = 0; i < n - 1; i++) { // change on +=1000
		//set the initial value of the minimal index 
		int min_i = i;
		//find index of the least element
		for (int j = i + 1; j < n; j++) {
			if (a[j][columnToBeSorted] < a[min_i][columnToBeSorted]) {
				min_i = j;
			}
		}
		//swap values
		swap(a[i], a[min_i]);
	}
}
//////////////////////////////////SELECTION SORT


//////////////////////////////////MERGE SORT
//void merge(int **a, int low, int mid, int high)
//{
//	// variables declaration. 
//	int **b = new int*[high + 1 - low];
//	int positionOne, positionTwo, positionThree,  k;
//	positionOne = low;
//	positionTwo = mid + 1;
//	positionThree = 0;
//	
//	// merges the two array's into b[] until the first one is finish
//	while (positionOne <= mid && positionTwo <= high)
//	{
//		if (a[positionOne][1] <= a[positionTwo][1])
//		{
//			b[positionThree++] = a[positionOne++];
//		}
//		else
//		{
//			b[positionThree++] = a[positionTwo++];
//		}		
//	}
//	
//	while (positionTwo <= high)
//		b[positionThree++] = a[positionTwo++];
//	while (positionOne <= mid)
//		b[positionThree++] = a[positionOne++];
//	
//
//	// prints into the original array
//	for (positionThree = 0; positionThree < high - low + 1; positionThree++)
//	{
//		a[positionThree + low] = b[positionThree];
//	}
//	delete[] b;
//}
//
//void merge_sort(int **a, int low, int high)
//{// Recursive sort ...
//	int mid;
//	if (low<high)
//	{
//		mid = (low + high) / 2;
//		merge_sort(a, low, mid);
//		merge_sort(a, mid + 1, high);
//		merge(a, low, mid, high);
//	}
//}
//////////////////////////////////MERGE SORT


//////////////////////////////////QUICKSORT
//void quicksort(int** a, int first, int last, int columnToBeSorted)
//{
//	int i = first, j = last, x = a[(first + last) / 2][columnToBeSorted];
//	do {
//		while (a[i][columnToBeSorted] < x) i++; // change on +=1000
//		while (a[j][columnToBeSorted] > x) j--; // change on -=1000
//
//		if (i <= j) {
//			if (i < j) swap(a[i], a[j]);
//			i++;
//			j--;
//		}
//	} 
//	while (i <= j);
//	if (i < last)
//	{
//		quicksort(a, i, last, columnToBeSorted);
//	}		
//	if (first < j)
//	{
//		quicksort(a, first, j, columnToBeSorted);
//	}		
//}
//////////////////////////////////QUICKSORT