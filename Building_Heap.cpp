/*Tao is working on a data processing application that analyzes a list of integers. He wants to implement a feature that processes the data in the following manner:



Build a min-heap from a given list of integers.
Calculate the average of the integers in the list.
Filter out the integers that are less than the calculated average and maintain the min-heap property for the remaining integers.
Input format :
The first line contains an integer n, representing the number of integers in the list.

The second line contains n space-separated integers, representing the values.

Output format :
The first line displays "Average: " representing a double representing the average of the integers, rounded to two decimal places.

The second line displays the remaining integers in the modified min-heap, space-separated.



Refer to the sample output for the exact format.

Code constraints :
the test cases will fall under the following constraints:

1 ≤ n ≤ 10

1 ≤ values ≤ 100*/
#include <iostream>
#include <iomanip> 

using namespace std;
// You are using GCC
void swap(int *x, int *y) {
    int temp=*x;
    *x=*y;
    *y=temp;
    
}

void minHeapify(int arr[], int n, int i) {
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    
    if(left<n && arr[left]<arr[smallest]){
        smallest =left;
    }
    if(right<n && arr[right]<arr[smallest]){
        smallest=right;
    }
    if(smallest!=i){
        swap(arr[i],arr[smallest]);
        minHeapify(arr,n,smallest);
    }
    
}

void buildMinHeap(int arr[], int n) {
    for(int i=n/2-1;i>=0;i--){
        minHeapify(arr,n,i);
    }
    
}

int filterElements(int arr[], int *n, double avg) {
    int i=0;
    while(i<*n){
        if(arr[i]<avg){
            arr[i]=arr[*n-1];
            (*n)--;
            minHeapify(arr,*n,i);
        }
        else{
            i++;
        }
    }
    return *n;
    
}

double calculateAverage(int arr[], int n) {
    
    double sum=0.0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum/n;
    
}
int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    buildMinHeap(arr, n);

    double avg = calculateAverage(arr, n);

    n = filterElements(arr, &n, avg);

    cout << "Average: " << fixed << setprecision(2) << avg << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}