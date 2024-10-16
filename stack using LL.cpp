#include <iostream>
using namespace std;
class Node{
    public:
  int data;
  Node* next;
  Node(int d){
      data=d;
      next=NULL;
      
  }
  
};
class Stack{
    int capacity;
    Node* head;
    int currentsize;
    public:
    Stack(int c){
        capacity=c;
        currentsize=0;
        head=NULL;
    }
    bool isEmpty(){
        return head==NULL;
    }
    bool isFull(){
        return currentsize==capacity;
    }
    void push(int x){
        if(isFull()){
            cout<<"Stack overflow"<<endl;
            return;
        }
        Node* new_node=new Node(x);
        new_node->next=head;
        head=new_node;
        currentsize++;
    }
    int  pop(){
        if(isEmpty()){
            cout<<"Underflow"<<endl;
            return -1;
        }
        Node* new_head=head->next;
        int element=head->data;
        delete head;
        head=new_head;
        return element;
        currentsize--;
        
    }
    int getTop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return head->data;
    }
    
    int size(){
        return currentsize+1;
    }
    
    
};

int main(){
    Stack st=Stack(5);
    st.push(4);
    st.push(3);
    st.push(1);
    st.push(6);
    st.push(8);
    st.push(9);st.push(12);
    cout<<st.getTop()<<endl;
    st.pop();
    cout<<st.getTop()<<endl;
    cout<<st.size()<<endl;
    
}