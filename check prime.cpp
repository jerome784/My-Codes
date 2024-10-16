#include<iostream>
using namespace std;
int checkprime(int n){
    int count=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            count++;
            if((n/i)!=i){
                count++;
            }
        }
        
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    int check=checkprime(n);
    if(check==2){
        cout<<"prime number";
    }
    else{
        cout<<"not a prime number";
;   }
    
    return 0;
}