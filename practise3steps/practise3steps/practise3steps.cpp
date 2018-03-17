// practise3steps.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <time.h>

using namespace std;

void selection(int *ar, int n)
{
	int i, j, mx, nmx;
	for (i = 0; i < n - 1; i++)
	{
		mx = ar[i];
		nmx = i;
		for (j = i + 1; j < n; j++)
		{
			if (ar[j]<mx)
			{
				mx = ar[j];
				nmx = j;
			}
		}
		ar[nmx] = ar[i];
		ar[i] = mx;
	}
}


int main()
{
	int i, n = 1000;
	int* a = new int[n];
	for (i = 0; i<n; i++)
		{
			a[i] = int(rand() % 10000);
			cout << a[i] << endl;
		}

	clock_t start = clock();
	selection(a, n);
	clock_t end = clock();

	cout << "\nSorted:\n";
	for (i = 0; i<n; i++)
	{
		cout << a[i] << endl;
	}
	cout << "\nSorting time for selection: " << end - start;
		
	cout << endl;
	delete[] a;
	system("pause");
	return 0;
}

