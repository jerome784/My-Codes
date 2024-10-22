/*Sam needs to sort an array of integers using the divide-and-conquer method. He wants to implement the merge sort algorithm, displaying the array after each iteration to track the sorting process. 



Assist him in writing a program that divides the array, merges it back, and prints the array.*/
// You are using GCC
#include <iostream>
using namespace std;

int rec = 0;
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        
    }
    cout<<endl;
}

void conquer(int arr[], int l, int m, int r,int n) {
    int left=l;
    int right=m+1;
     int size=r-l+1;
    int temp[size];
   
    int k=0;
    
    while(left<=m && right<=r){
        if(arr[left]<arr[right]){
            temp[k]=arr[left];
            left++;
            k++;
        }
        else{
            temp[k]=arr[right];
            right++;
            k++;
        }
    }
    while(left<=m){
        temp[k]=arr[left];
        left++;
        k++;
    }
    while(right<=r){
        temp[k]=arr[right];
        right++;
        k++;
    }
    for(int i=0;i<size;i++){
        arr[l+i]=temp[i];
    }
        rec++;
        cout<<"After iteration "<<rec<<endl;
        printArray(arr,n);
}

void divide(int arr[], int l, int r,int n) {
    if(l<r){
        int mid=l+(r-l)/2;
        divide(arr,l,mid,n);
        divide(arr,mid+1,r,n);
        conquer(arr,l,mid,r,n);
    }
    
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
   cout<<"Given Array"<<endl;
   printArray(arr,n);
   
   divide(arr,0,n-1,n);
   
   cout<<"Sorted Array"<<endl;
   printArray(arr,n);
    return 0;
}