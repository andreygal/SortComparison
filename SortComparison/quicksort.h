#pragma once
#include <cstdlib>
#include <vector>
//array functions
template <typename T>
void Quicksort(T* arr, int begin, int end);

template <typename T>
int Partition(T* arr, int begin, int end);

template <typename T>
int RandPartition(T* arr, int begin, int end);

//overloaded versions for vectors
template <typename T>
void Quicksort(std::vector<T>& arr, int begin, int end);

template <typename T>
int Partition(std::vector<T>& arr, int begin, int end);

template <typename T>
int RandPartition(std::vector<T>& arr, int begin, int end);

template <typename T>
void Quicksort(T* arr, int begin, int end) {
	if (begin < end) {
		int pivotIndex = RandPartition(arr, begin, end);
		Quicksort(arr, begin, pivotIndex - 1);
		Quicksort(arr, pivotIndex + 1, end);
	}
}

template <typename T>
int Partition(T* arr, int begin, int end) {
	T pivot = arr[end];
	T temp; 
	int index = begin - 1; 
	for (int j = begin; j < end; j++) {
		if (arr[j] <= pivot) {
			//move to the next index
			index++; 
			//exchange the current element with the indexed element 
			temp = arr[j];
			arr[j] = arr[index];
			arr[index] = temp; 
		}
	}
	temp = arr[index + 1];
	arr[index + 1] = arr[end]; 
	arr[end] = temp; 
	return (index + 1);
}

template <typename T>
int RandPartition(T* arr, int begin, int end) {
	//choose a random pivot
	int pivotIndex = begin + (rand() % (end - begin + 1));
	//swap last element with the pivot
	T temp = arr[pivotIndex];
	arr[pivotIndex] = arr[end];
	arr[end] = temp;
	//call Partition on the resultant array 
	return Partition(arr, begin, end); 
}

template <typename T>
void Quicksort(std::vector<T>& arr, int begin, int end) {
	if (begin < end) {
		int pivotIndex = RandPartition(arr, begin, end);
		Quicksort(arr, begin, pivotIndex - 1);
		Quicksort(arr, pivotIndex + 1, end);
	}
}

template <typename T>
int Partition(std::vector<T>& arr, int begin, int end) {
	T pivot = arr[end];
	T temp;
	int index = begin - 1;
	for (int j = begin; j < end; j++) {
		if (arr[j] <= pivot) {
			//move to the next index
			index++;
			//exchange the current element with the indexed element 
			temp = arr[j];
			arr[j] = arr[index];
			arr[index] = temp;
		}
	}
	temp = arr[index + 1];
	arr[index + 1] = arr[end];
	arr[end] = temp;
	return (index + 1);
}

template <typename T>
int RandPartition(std::vector<T>& arr, int begin, int end) {
	//choose a random pivot
	int pivotIndex = begin + (rand() % (end - begin + 1));
	//swap last element with the pivot
	T temp = arr[pivotIndex];
	arr[pivotIndex] = arr[end];
	arr[end] = temp;
	//call Partition on the resultant array 
	return Partition(arr, begin, end);
}