/*Emma is a mathematics enthusiast who wants to analyze prime numbers for her research. She collects several integers and aims to create a max heap that only includes the prime numbers from her collection.



After inserting the prime numbers into the max heap, she wants to visualize the max heap structure to understand the hierarchy of these numbers.



Note

A prime number is a natural number greater than one that has no positive divisors other than one and itself.

Input format :
The first line contains an integer n, representing the number of integers Emma collected.

The second line consists of n space-separated integers, which are the values Emma wants to analyze.

Output format :
The output consists of two parts:

If any prime numbers were inserted into the max heap, display them as integers separated by a space.
If a number is not prime, print a message in the format: "<value> is not a prime number".


Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n ≤ 10

1 ≤ values ≤ 100

Sample test cases :
Input 1 :
5
1 3 2 4 5
Output 1 :
1 is not a prime number
4 is not a prime number
Max Heap: 5 2 3 
Input 2 :
6
17 7 5 11 13 19
Output 2 :
Max Heap: 19 13 17 7 11 5 */
// You are using GCC
#include <stdio.h>
#include<iostream>
using namespace std;


void maxHeapify(int arr[], int n, int i) 
{
   int largest=i;
   int left=2*i+1;
   int right=2*i+2;
   if(left<n && arr[left]>arr[largest]){
       largest=left;
   }
   if(right<n && arr[right]>arr[largest]){
       largest=right;
   }
   if(largest!=i){
       swap(arr[i],arr[largest]);
       maxHeapify(arr,n,largest);
   }
}


void insertIntoMaxHeap(int arr[], int *n, int value) 
{
    
    int index=*n;
    arr[index]=value;
    (*n)++;
    while(index>0){
        int parent=(index-1)/2;
        if(arr[parent]<arr[index]){
            swap(arr[parent],arr[index]);
            index=parent;
        }else{
            break;
        }
        
    }
}

bool isPrime(int num) 
{
    if(num<=1){
        return false;
        
    }
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

void printMaxHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
   int n;
   cin>>n;
   int arr[n];
   int size=0;
   for(int i=0;i<n;i++){
       int value;
       cin>>value;
       if(isPrime(value)){
           insertIntoMaxHeap(arr,&size,value);
       }
       else{
           cout<<value<<" is not a prime number"<<endl;
       }
   }
  
   cout<<"Max Heap: ";
   printMaxHeap(arr,size);
   
}