#include<iostream>
using namespace std;
void mergesort(int arr1[],int arr2[],int arr3[],int n1,int n2){
    int i=0,j=0,k=0;
    arr3[n1+n2];
    while(i<=n1 && j<=n2){
        if(arr1[i]>arr2[j]){
            arr3[k++]=arr2[j++];
        }
        else{
            arr3[k++]=arr1[i++];
        }
    }
    while(i<=n1){
        arr3[k++]=arr1[i++];
    }
    while(j<=n2){
        arr3[k++]=arr2[j++];
    }
    for(int i=0;i<n1+n2;i++){
        cout<<arr3[i]<<" ";
        
    }
    
}
int main(){
    int n1;
    cin>>n1;
    int arr1[n1];
    for(int i=0;i<n1;i++){
    cin>>arr1[i];
    }
    int n2;
    cin>>n2;
    int arr2[n2];
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    int arr3[n1+n2];
    mergesort(arr1,arr2,arr3,n1,n2);
    
}