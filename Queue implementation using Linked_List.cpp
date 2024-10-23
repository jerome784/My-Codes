#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int val){
        data=val;
        next=nullptr;
    }
};
class Queue{
  Node* head;
  Node* tail;
  int size;
  public:
  Queue(){
      Node* head=nullptr;
      Node* tail=nullptr;
      size=0;
      
  }
  void enqueue(int value){
      Node* new_node=new Node(value);
      if(head==nullptr){
          head=new_node;
          tail=new_node;
      }
      else{
          tail->next=new_node;
          tail=new_node;
      }
      size++;
  }
  void dequeue(){
      if(head==nullptr){
          return;
      }
      else{
          Node* temp=head;
          Node* new_head=head->next;
          free(temp);
          head=new_head;
          size--;
          
      }
  }
  
  bool is_empty(){
      return head==nullptr;
  }
  int front(){
      return head->data;
  }
  
};
int main(){
    Queue q;
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(45);
    q.enqueue(12);
    while(!q.is_empty()){
        int curr=q.front();
        q.dequeue();
        cout<<curr<<" ";
    }
    
    
    return 0;
}