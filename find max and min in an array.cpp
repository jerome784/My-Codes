#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n; 
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max_no=INT_MIN;
    int min_no=INT_MAX;
    for(int i=0;i<n;i++){
     if(max_no<arr[i]){
         max_no=arr[i];
     }   
     if(min_no>arr[i]){
         min_no=arr[i];
     }
    }
    cout<<"maximum "<<max_no<<" ";
    cout<<"minimum "<<min_no<<" ";
    return 0;
}