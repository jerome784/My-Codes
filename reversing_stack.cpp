#include<iostream>
#include<stack>
using namespace std;
void reverse_stack(stack<int> &st){
    stack<int> t1,t2;
    while(!st.empty()){
        int curr=st.top();
        st.pop();
        t1.push(curr);
    }
    while(!t1.empty()){
        int curr=t1.top();
        t1.pop();
        t2.push(curr);
    }
    while(!t2.empty()){
        int curr=t2.top();
        t2.pop();
        st.push(curr);
    }
    
}
void insert_at_bottom(stack<int> &st,int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int curr=st.top();
    st.pop();
    insert_at_bottom(st,x);
    st.push(curr);
    
}
void reverse_recursion(stack<int> &st){
    if(st.empty()) return;
    int value=st.top();
    st.pop();
    reverse_recursion(st);
    insert_at_bottom(st,value);
}
int main(){
    int n;
    cin>>n;
    stack<int> st;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        st.push(num);
    }
    reverse_recursion(st);
    while(!st.empty()){
        int val=st.top();
        st.pop();
        cout<<val<<" ";
    }
    
    
}