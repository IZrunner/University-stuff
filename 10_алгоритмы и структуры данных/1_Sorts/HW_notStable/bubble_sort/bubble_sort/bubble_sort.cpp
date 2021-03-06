// bubble_sort.cpp: определяет точку входа для консольного приложения.
//
//#include "pch.h"
#include "stdafx.h"
#include <iostream>
#include "cstdlib"
#include "ctime"
#include<fstream>
using namespace std;
int n, m; // кол-во эл. массива

//void print(int *a);
//int control();

void exch(int &a, int &b);
//void sort_bubble(int *array);
//void insert_sort(int *a, int n);
//void select_sort(int *a, int n);
//void merge(int *a, int low, int mid, int high);
//void merge_sort(int *a, int low, int high);
void quicksort(int* a, int first, int last);



int main()
{
	///////////////////созд. масс.////////////////////////
	//n = control();
	cout << "Input the number :";
	cin >> n;
	int *a = new int[n];

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
		//tmpr = a[i]; //sorted by decrease by default

		a[i] = rand() % 2001 - 1000; //random fill
	
		
		//if (a[i] > a[i - 1])
		//{
		//	a[i] = a[i - 1]; a[i - 1] = tmpr; //sorted by decrease by default
		//}
		

		//a[i] = some_val;	//fill with equal values	
	}
	//a[rand_first_pos] = a[rand_second_pos]; // 2 equal random numbers in random order


	
	////////////////sort////////////////////////
	unsigned int start_time = clock(); //current time
	//sort_bubble(a);
	//insert_sort(a, n);
	//select_sort(a, n);
	//merge_sort(a, 0, n);
	quicksort(a, 0, n);


	unsigned int end_time = clock(); // end time
	unsigned int search_time = end_time - start_time; //searching time
	cout << "\n" << "Programms' executing tome : " << search_time << " ms\n";
	fout << search_time << "\n";
	//fout << "MESSAGE";
	fout.close();


	system("pause");
	return 0;
}


//outprint the array

//void print(int *a)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << a[i] << "\t";
//	}
//}



//input control
//int control()
//{
//	while (true)
//	{
//		cout << "Input the number :";
//		cin >> n;
//		if (cin.get() == '\n' && n > 0) break;
//		else
//		{
//			cout << "A real number awaited!";
//			cin.clear(); // сбрасываются флаги ошибок
//			cin.sync(); // извл. все симв. сплоть до '\n'
//		}
//	}
//	return n;
//}

//ADD STEP 1000 TO ALL ALGORYTHMS

//////////////////////////////////BUBBLE SORT

// swap
void exch(int &a, int &b)
{
	int tmp = a; a = b; b = tmp;
}

////bubble sort
//void sort_bubble(int *array)
//{
//	for (int i = n - 1; i >= 0; i-=1000)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (array[j] > array[j + 1]) exch(array[j], array[j + 1]);
//		}
//	}
//}

//////////////////////////////////BUBBLE SORT


//////////////////////////////////INSERTION SORT

//void insert_sort(int *a, int n)
//{
//	int i, j, value;
//
//	for (i = 1; i < n; i+=1000)
//	{
//		value = a[i];
//		for (j = i - 1; j >= 0 && a[j] > value; j--)
//		{
//			a[j + 1] = a[j];
//		}
//		a[j + 1] = value;
//	}
//}

///////////////////////////////////INSERTION SORT


//////////////////////////////////SELECTION SORT

//void select_sort(int *a, int n) {
//	for (int i = 0; i < n - 1; i+=1000) {
//		/* устанавливаем начальное значение минимального индекса */
//		int min_i = i;
//		/* находим индекс минимального элемента */
//		for (int j = i + 1; j < n; j++) {
//			if (a[j] < a[min_i]) {
//				min_i = j;
//			}
//		}
//		/* меняем значения местами */
//		int temp = a[i];
//		a[i] = a[min_i];
//		a[min_i] = temp;
//	}
//}

//////////////////////////////////SELECTION SORT


//////////////////////////////////MERGE SORT

//void merge(int *a, int low, int mid, int high)
//{
//	// Variables declaration. 
//	int *b = new int[high + 1 - low];
//	int h, i, j, k;
//	h = low;
//	i = 0;
//	j = mid + 1;
//	// Merges the two array's into b[] until the first one is finish
//	while ((h <= mid) && (j <= high))
//	{
//		if (a[h] <= a[j])
//		{
//			b[i] = a[h];
//			h++;
//		}
//		else
//		{
//			b[i] = a[j];
//			j++;
//		}
//		i++;
//	}
//	// Completes the array filling in it the missing values
//	if (h>mid)
//	{
//		for (k = j; k <= high; k++)
//		{
//			b[i] = a[k];
//			i++;
//		}
//	}
//	else
//	{
//		for (k = h; k <= mid; k++)
//		{
//			b[i] = a[k];
//			i++;
//		}
//	}
//	// Prints into the original array
//	for (k = 0; k <= high - low; k++)
//	{
//		a[k + low] = b[k];
//	}
//	delete[] b;
//}
//
//void merge_sort(int *a, int low, int high)
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

void quicksort(int* a, int first, int last)
{
	int i = first, j = last, x = a[(first + last) / 2];
	do {
		while (a[i] < x) i++;
		while (a[j] > x) j--;

		if (i <= j) {
			if (i < j) exch(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (i < last)
		quicksort(a, i, last);
	if (first < j)
		quicksort(a, first, j);
}

//////////////////////////////////QUICKSORT