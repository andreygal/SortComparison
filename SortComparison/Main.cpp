#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "quicksort.h"			// vector sorting algorithms
#include "merge_sort.h"
#include "insert_ascending.h"
#include "insertion_sort.h" 
#include "sort_timer.h"			// timer class
using namespace std;

// outputs the first 5 and last 5 items in the vector
void outputFirst_Last(const vector<int>& v);

// types of sorts we will test
enum sortType {
	MERGESORT, QUICKSORT, INSERTIONSORT
};

// apply the specified sort to v and time it.
// output the result using sortName as a descriptive
// label
void timeSort(vector<int>& v, sortType sort,
	const string& sortName);

int main()
{
	const int VECTORSIZE = 100000;
	vector<int> v1, v2, v3, v4;
	unsigned int rndNum, i;
	unsigned seed = time(0);
	srand(seed);

	// load the vectors with the same sequence of 100000
	// random numbers in the range 0 to 999999
	for (i = 0; i < VECTORSIZE; i++)
	{
		rndNum = rand() % VECTORSIZE;
		v1.push_back(rndNum);
		v2.push_back(rndNum);
		v3.push_back(rndNum);
	}

	// repeat process for the merge sort
	cout << "Random input for merge sort" << endl;
	timeSort(v1, MERGESORT, "MergeSort");
	cout << "Sorted input for merge sort" << endl;
	timeSort(v1, MERGESORT, "MergeSort");
	cout << "Reverse sorted input for merge sort" << endl; 
	reverse(v1.begin(), v1.end());
	timeSort(v1, MERGESORT, "MergeSort");
	

	// repeat process for the quick sort
	cout << "Random input for quicksort" << endl;
	timeSort(v2, QUICKSORT, "Quicksort");
	cout << "Sorted input for quicksort" << endl;
	timeSort(v2, QUICKSORT, "Quicksort");
	cout << "Reverse sorted input for quicksort" << endl;
	reverse(v2.begin(), v2.end());
	timeSort(v2, QUICKSORT, "Quicksort");


	// repeat process for the insertion sort
	cout << "Random input for insertion sort" << endl;
	timeSort(v3, INSERTIONSORT, "Insertion Sort");
	cout << "Sorted input for Insertion Sort" << endl;
	timeSort(v3, INSERTIONSORT, "Insertion Sort");
	cout << "Reverse sorted input for Insertion Sort" << endl;
	reverse(v3.begin(), v3.end());
	timeSort(v3, INSERTIONSORT, "Insertion Sort");


	system("pause");
	return 0;
}

void outputFirst_Last(const vector<int>& v)
{
	// capture vector size in n
	int i, n = v.size(), m = 5;

	// if the vector size is 10 or less, just
	// output the whole vector
	if (n <= 10)
		m = n;

	// output m elements
	for (i = 0; i < m; i++)
		cout << v[i] << "  ";

	// for n > 10, output "..." and the last 5 elements
	if (n > 10)
	{
		cout << ". . .  ";
		for (i = n - 5; i < n; i++)
			cout << v[i] << "  ";
	}
	cout << endl;
}

void timeSort(vector<int>& v, sortType sort,
	const string& sortName)
{
	timer t;

	// start timing and then sort vector arr
	t.start();

	switch (sort)
	{
	case MERGESORT:		MergeSort(v, 0, v.size());
		break;
	case QUICKSORT:		Quicksort(v, 0, v.size() - 1);
		break;
	case INSERTIONSORT:	InsertionSort(v, InsertAscending<int>());
		break;
	}
	t.stop();

	// output the first 5 and last 5 elements of sorted vector
	outputFirst_Last(v);

	cout << sortName << " time is " << t.time() << endl << endl;
}

