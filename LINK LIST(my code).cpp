#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
        
    }
};

void insertAtHead(Node* &head,int val){
    Node* new_node=new Node(val);
    new_node->next=head;
    head=new_node;
}
void inserAtTail(Node* &head,int val){
    Node* new_node=new Node(val);
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
}
void insertAtpos(Node* &head,int val,int pos){
    Node* new_node=new Node(val);
    int current_pos=0;
    Node*temp=head;
    while(current_pos!=pos-1){
        temp=temp->next;
        current_pos++;
    }
    new_node->next=temp->next;
    temp->next=new_node;
    
}
void update(Node* &head,int val,int k){
    Node* temp=head;
    int cur_pos=0;
    while(cur_pos!=k){
        temp=temp->next;
        cur_pos++;
    }
    temp->data=val;
    
    
}
 void deleteAthead(Node* &head){
    Node*temp=head;
    head=head->next;
    free(temp);
}

void deleteAtTail(Node*head){
    Node* second_last=head;
    while(second_last->next->next){
        second_last=second_last->next;
    }
    Node*temp=second_last->next;
    second_last->next=NULL;
    free(temp);
}
void deleteAtPos(Node* &head,int pos){
    int current_pos=0;
        Node* position=head;
        while(current_pos!=pos-1){
            position=position->next;
            current_pos++;
        }
    Node *temp=position->next;
    position->next=position->next->next;
    free(temp);
}
void display(Node* &head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}



int main(){
    Node *head=new Node(24);
    insertAtHead(head,35);
    inserAtTail(head,67);
    display(head);
    insertAtpos(head,67,1);
    display(head);
    update(head,56,1);
    display(head);
    deleteAthead(head);
    display(head);
    deleteAtTail(head);
    insertAtHead(head,23);
    insertAtHead(head,12);
    display(head);
    deleteAtPos(head,1);
    display(head);
    
    
}