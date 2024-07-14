#include <iostream>
#include <vector>
#include <random>
#include "searchSortAlgorithms.h"

// Function to generate a random integer within a given range [min, max]
int getRandomNumber(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int main() {
    const int ARRAY_SIZE = 5000;
    std::vector<int> list1(ARRAY_SIZE);
    std::vector<int> list2(ARRAY_SIZE);
    std::vector<int> list3(ARRAY_SIZE);

    // Initialize the three lists with random values
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        list1[i] = getRandomNumber(1, ARRAY_SIZE); // Filling list1 with random values from 1 to ARRAY_SIZE
        list2[i] = list1[i]; // Copying the same random values to list2
        list3[i] = list1[i]; // Copying the same random values to list3
    }

    int comparisons, itemAssignments;

    // Bubble Sort
    comparisons = 0;
    itemAssignments = 0;
    std::vector<int> list1_copy = list1; // Copy list1 to a new vector for sorting
    bubbleSort(list1_copy, comparisons, itemAssignments);

    std::cout << "Bubble sort" << std::endl;
    std::cout << "Comparisons: " << comparisons << std::endl;
    std::cout << "Item assignments: " << itemAssignments << std::endl;

    // Selection Sort
    comparisons = 0;
    itemAssignments = 0;
    std::vector<int> list2_copy = list2; // Copy list2 to a new vector for sorting
    selectionSort(list2_copy, comparisons, itemAssignments);

    std::cout << "\nSelection sort" << std::endl;
    std::cout << "Comparisons: " << comparisons << std::endl;
    std::cout << "Item assignments: " << itemAssignments << std::endl;

    // Insertion Sort
    comparisons = 0;
    itemAssignments = 0;
    std::vector<int> list3_copy = list3; // Copy list3 to a new vector for sorting
    insertionSort(list3_copy, comparisons, itemAssignments);

    std::cout << "\nInsertion sort" << std::endl;
    std::cout << "Comparisons: " << comparisons << std::endl;
    std::cout << "Item assignments: " << itemAssignments << std::endl;

    return 0;
}
