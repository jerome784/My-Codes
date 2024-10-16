/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
void selectionsort(int arr[],int n){

    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
           if(arr[min]>arr[j]){
               min=j;
           }
            
        }
        if(min!=i){
            int temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionsort(arr,n);
    
  
}