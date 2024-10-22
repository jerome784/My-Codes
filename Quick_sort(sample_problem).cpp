/*Ravi is spending quality time with his children, teaching them about ascending order through a fun game. To make it more interactive, Ravi has decided to create a simple program that takes a list of characters and demonstrates how to arrange them in ascending order. 



Guide Ravi by implementing this program using quick sort.*/
// You are using GCC
#include <iostream>
#include <string>

using namespace std;

int partition(char arr[], int low, int high) {
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    while(i<=j){
        while(i<=high && arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot && j>=low){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
    
}

void quickSort(char arr[], int low, int high) {
    if(low<high){
        int partIndex=partition(arr,low,high);
        quickSort(arr,low,partIndex-1);
        quickSort(arr,partIndex+1,high);
    }
    
}

int main() {
    int n;
    cin >> n;

    char characters[n];

    for (int i = 0; i < n; ++i) {
        cin >> characters[i];
    }

    quickSort(characters, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        cout << characters[i] << " ";
    }

    return 0;
}