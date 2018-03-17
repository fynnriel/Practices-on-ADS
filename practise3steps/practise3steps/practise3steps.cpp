// practise3steps.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <clocale>
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

void radix(int *ar, int *br, int sizeAB, int sizeC)
{
	int i, k, n;
	k = sizeC;
	n = sizeAB;
	int* cr = new int[n];
	for (i = 0; i < n; i++)
		br[i] = 0;
	for (i = 0; i <= k; i++)
		cr[i] = 0;
	for (i = 0; i < n; i++)
		cr[ar[i]] += 1;
	for (i = 1; i < k + 1; i++)
		cr[i] += cr[i - 1];
	for (i = n - 1; i >= 0; i--)
	{
		br[cr[ar[i]] - 1] = ar[i];
		cr[ar[i]] -= 1;
	}
	delete[] cr;
}


int main()
{
	int i, n = 1000, k = 999, id;
	int* a = new int[n];
	int* b = new int[n];
	cout << " Choose the sorting algorithm:\n";
	cout << "1 - selection\n2 - radix\n";
	cin >> id;
	for (i = 0; i<n; i++)
	{
		a[i] = int(rand() % 10000);
		cout << a[i] << endl;
	}

	cout << " Choose the sorting algorithm:\n";
	cout << "1 - selection\n2 - radix\n";
	cin >> id;

	switch (id)
	{
	case 1:
	{

		clock_t start = clock();
		selection(a, n);
		clock_t end = clock();

		cout << "\nSorted:\n";
		for (i = 0; i<n; i++)
		{
			cout << a[i] << endl;
		}
		cout << "\nSorting time for selection: " << end - start;
		break;
	}

	case 2:
	{

		clock_t start = clock();
		radix(a, b, n, k);
		clock_t end = clock();

		cout << "\nSorted:\n";
		for (i = 0; i<n; i++)
		{
			cout << b[i] << "  ";
		}
		cout << "\nSorting time for radix: " << end - start;
		break;
	}
	}

	cout << endl;
	delete[] a;
	system("pause");
	return 0;
}
