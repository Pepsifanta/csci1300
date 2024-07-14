#include "searchSortAlgorithms.h"

// Bubble Sort Algorithm
// Sorts the vector 'arr' in ascending order using the bubble sort algorithm.
void bubbleSort(std::vector<int>& arr, int& comparisons, int& itemAssignments) {
    int n = arr.size();
    bool swapped;

    // Traverse through the array
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        // Compare and swap adjacent elements to move the largest element to the correct position
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                itemAssignments += 3; // Increment item assignments for the swap (3 because we use std::swap)
                swapped = true;
            }
        }

        // If no swaps were made during the inner loop, the array is already sorted, and we can break
        if (!swapped)
            break;
    }
}

// Selection Sort Algorithm
void selectionSort(std::vector<int>& arr, int& comparisons, int& itemAssignments) {
    int n = arr.size();

    // Traverse through the array
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        // Find the minimum element in the remaining unsorted part of the array
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Swap the found minimum element with the element at position i
        if (min_index != i) {
            std::swap(arr[i], arr[min_index]);
            itemAssignments += 3; // Increment item assignments for the swap (3 because we use std::swap)
        }
    }
}

// Insertion Sort Algorithm
void insertionSort(std::vector<int>& arr, int& comparisons, int& itemAssignments) {
    int n = arr.size();

    // Traverse through the array starting from the second element
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than the key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            itemAssignments++;
            j--;
        }

        // Place the key (current element being sorted) at its correct position in the sorted sequence
        arr[j + 1] = key;
        itemAssignments++;
    }
}
