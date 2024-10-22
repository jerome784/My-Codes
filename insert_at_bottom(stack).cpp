#include<iostream>
#include<stack>
using namespace std;
void insert_at_bottom(stack<int> &st,int x){
    stack<int> temp;
    while(!st.empty()){
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

void insert_at_bottom_recur(stack<int> &st,int y){
    if(st.empty()){
        st.push(y);
        return;
    }
    int curr=st.top();
    st.pop();
    insert_at_bottom_recur(st,y);
    st.push(curr);
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
    //insert_at_bottom(st,x);
    insert_at_bottom_recur(st,x);
    while(!st.empty()){
        int i=st.top();
        cout<<i<<" ";
        st.pop();
    }
    
    
    
    return 0;
}