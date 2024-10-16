#include<iostream>
using namespace std;
int binary(int arr[],int n,int target){
 
   int start=0;int end=n;
   while(start<end){
       int mid=(end+start)/2;
       if(arr[mid]==target){
           return mid;
       }
       else if(arr[mid]<target){
           start=mid+1;
       }
       else{
           end=mid-1;
       }
   }
   return -1;
}
int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<binary(arr,n,target);
    
    return 0;
}