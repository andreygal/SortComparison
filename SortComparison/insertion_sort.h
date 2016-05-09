#pragma once
#include <vector>

template <typename T, typename Compare>
void InsertionSort(std::vector<T>& input_vector, Compare comp) {
	int i, j, n = input_vector.size();
	T key;

	for (i = 1; i < n; i++) {
		key = input_vector[i];
		j = i - 1;
		while ((j >= 0) && comp(key, input_vector[j])) {
			input_vector[j + 1] = input_vector[j];
			j--;
		}
		input_vector[j + 1] = key;
	}
}
