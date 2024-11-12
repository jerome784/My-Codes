/*
Alex is a competitive programmer preparing for a coding competition that requires him to manage and prioritize a set of scores. He wants to maintain a max heap to ensure he can quickly access the highest scores as he adds new scores to his list. Alex plans first to input his initial set of scores and then add more scores later. After building the max heap, he wants to display the scores in priority order from highest to lowest.



Write a program that constructs a max heap from an array of initial scores entered by Alex, allows him to insert additional scores, and then displays the resulting max heap structure.

*/





#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to maintain the max-heap property
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Function to build the max heap by calling maxHeapify
void buildMaxHeap(int arr[], int n) {
    // Start from the last non-leaf node and move upwards
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Function to insert a new element into the max heap
void insertIntoMaxHeap(int arr[], int &n, int value) {
    n++;  // Increase the heap size
    arr[n - 1] = value;  // Insert the new value at the end of the heap

    int i = n - 1;
    // Percolate the new element up to its correct position
    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main() {
    int arr[100];
    int n = 0;
    int num_elements;
    cin >> num_elements;

    for (int i = 0; i < num_elements; i++) {
        int value;
        cin >> value;
        insertIntoMaxHeap(arr, n, value);
    }

    int num_new_elements;
    cin >> num_new_elements;

    for (int i = 0; i < num_new_elements; i++) {
        int new_element;
        cin >> new_element;
        insertIntoMaxHeap(arr, n, new_element);
    }

    // After inserting all elements, build the max heap
    buildMaxHeap(arr, n);

    // Print the max heap
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
