#include "bits/stdc++.h"
using namespace std;
int32_t main(){
    int n; cin>>n;
    int target; cin>>target;
    vector<int> arr(n);
    for(auto &i :arr){
        cin>>i;
    }
    bool found=false;
    sort(arr.begin(),arr.end() );
    for(int i=0;i<n;i++){
        int low=i+1;
        int high=n-1;
        while(low<high){
            int current =arr[i]+arr[low]+arr[high];
            if(current==target){
                cout<<found;
                found=true;
                
            }
            else if(current > target){
                high--;
            }
            else{
                low++;
            }
        }
         
    }
    if(found){
        cout<<true;
    }
    else{
        cout<<false;
    }
    return 0;
}