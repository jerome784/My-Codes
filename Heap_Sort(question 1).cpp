/*Problem Statement



David is a data analyst who often needs to analyze numbers by extracting their digits and sorting them in descending order. This will help him visualize the frequency of each digit and understand patterns within large numerical datasets.



Write a program that takes a number as input, extracts its digits, sorts them, and displays the sorted digits as a single number using the heap sort algorithm.

Input format :
The input consists of an integer n, representing a single number.

Output format :
The output displays the digits of the number sorted in descending order as a single integer without any spaces.



Refer to the sample output for the formatting specifications.

Code constraints :
The test cases will fall under the following constraints:

2 ≤ n ≤ 109

Sample test cases :
Input 1 :
123
Output 1 :
321
Input 2 :
31524
Output 2 :
54321
Input 3 :
1001
Output 3 :
1100*/
#include <iostream>
#include <cmath> 
using namespace std;
// You are using GCC
void swap(int* a, int* b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int arr[], int size, int root) {
    int smallest=root;
    int left=2*root+1;
    int right=2*root+2;
    if(left<size && arr[left]<arr[smallest]){
        smallest=left;
    }
    if(right<size && arr[right]<arr[smallest]){
        smallest=right;
    }
    if(smallest!=root){
        swap(arr[root],arr[smallest]);
        heapify(arr,size,smallest);
    }
}

void heapSort(int arr[], int size) {
    for(int i=size/2-1;i>=0;i--){
        heapify(arr,size,i);
    }
    for(int i=size-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

void extractDigits(int num, int*& digits, int& digitCount) {
    digitCount=0;
    int temp=num;
    while(temp>0){
        digitCount++;
        temp/=10;
    }
    digits=new int[digitCount];
    for(int i=0;i<digitCount;i++){
        digits[i]=num%10;
        num/=10;
    }
}

void printSortedDigits(int digits[], int digitCount) {
    for(int i=0;i<digitCount;i++){
        cout<<digits[i];
    }
    cout<<endl;
} 
int main() {
    int num;
    cin >> num;
    int* digits = nullptr;
    int digitCount = 0;
    extractDigits(num, digits, digitCount);
    heapSort(digits, digitCount);
    printSortedDigits(digits, digitCount);
    delete[] digits; 
    return 0;
}