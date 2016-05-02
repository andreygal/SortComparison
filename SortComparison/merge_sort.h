#pragma once
#include <vector>

template <typename T>
void MergeSort(std::vector<T>& input_vector, int first, int last);

template <typename T>
void merge(std::vector<T>& v, int first, int mid, int last);

template <typename T>
void MergeSort(std::vector<T>& input_vector, int first, int last) {
	if (first + 1 < last) {
		//compute the midpoint
		int mid = (first + last) / 2;
		//sort left side and right side; then merge the two
		MergeSort(input_vector, first, mid);
		MergeSort(input_vector, mid, last);
		merge(input_vector, first, mid, last);
	}
}

template <typename T>
void merge(std::vector<T>& v, int first, int mid, int last)
{
	// temporary vector to merge the sorted sublists
	std::vector<T> tempVector;
	int indexA, indexB, indexV;

	// set indexA to scan sublistA (index range [first,mid)
	// and indexB to scan sublistB (index range [mid, last)
	indexA = first;
	indexB = mid;

	// while both sublists are not exhausted, compare v[indexA] and
	// v[indexB]copy the smaller to vector temp using push_back()
	while (indexA < mid && indexB < last)
		if (v[indexA] < v[indexB])
		{
			tempVector.push_back(v[indexA]);	// copy element to temp
			indexA++;								// increment indexA
		}
		else
		{
			tempVector.push_back(v[indexB]);	// copy element to temp
			indexB++;								// increment indexB
		}

	// copy the tail of the sublist that is not exhausted
	while (indexA < mid)
	{
		tempVector.push_back(v[indexA]);
		indexA++;
	}

	while (indexB < last)
	{
		tempVector.push_back(v[indexB]);
		indexB++;
	}

	// copy vector tempVector using indexV to vector v using indexA
	// which is initially set to first
	indexA = first;

	// copy elements from temporary vector to original list
	for (indexV = 0; indexV < tempVector.size(); indexV++)
	{
		v[indexA] = tempVector[indexV];
		indexA++;
	}
}