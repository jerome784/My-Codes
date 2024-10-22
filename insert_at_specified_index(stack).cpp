#include<iostream>
#include<stack>
using namespace std;
void insert_at_index(stack<int> &st,int x,int indx){
    int n=st.size();
    int count=0;
    stack<int> temp;
    while(count<n-indx){
        count++;
        int curr=st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(x);
    while(!temp.empty()){
        int curr=temp.top();
        temp.pop();
        st.push(curr);
    }
}
 


using namespace std;
int main(){
    stack<int> st;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        st.push(num);
    }
    int x;
    cin>>x;
    insert_at_index(st,x,2);
   
    while(!st.empty()){
        int i=st.top();
        cout<<i<<" ";
        st.pop();
    }
    
    
    
    return 0;
}