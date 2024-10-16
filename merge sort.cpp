#include<iostream>
using namespace std;
void merge(int *arr,int low,int mid,int high){
    int left=low;
    int right=mid+1;
    int temp[high-low+1];
    int k=0;
    
    while(left<=mid && right<=high){
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
    while(left<=mid){
        temp[k]=arr[left];
        left++;
        k++;
    }
    while(right<=high){
        temp[k]=arr[right];
        right++;
        k++;
    }
    for(int i=0;i<k;i++){
        arr[low+i]=temp[i];
    }
}
void merge_sort(int *arr,int low,int high){
    if(low>=high) return;
    int mid=(low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        
    }
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}