#include<iostream>
#include<vector>
using namespace std;
class Queue{
    vector<int> q;
    int front;
    int back;
    int size;
    public:
    Queue(){
        front=-1;
        back=-1;
        size=0;
    }
    void enqueue(int value){
        if(front==-1 && back==-1){
            q.push_back(value);
            front++;
            back++;
            size++;
            return;
        }
        q.push_back(value);
        size++;
        back++;
        
    }
    void dequeue(){
        if(front==back){
            front=-1;
            back=-1;
            size--;
            return;
        }
        front++;
        size--;
    }
    int Size(){
        return size;
    }
    bool is_Empty(){
        return front==-1;
    }
    
    int getfront(){
        return q[front];
    }
    
};
int main(){
    Queue qu;
    qu.enqueue(20);
    qu.enqueue(35);
    qu.enqueue(12);
    qu.enqueue(10);
    qu.enqueue(1);
    while(!qu.is_Empty()){
        int curr=qu.getfront();
        qu.dequeue();
        cout<<curr<<" ";
    }
    cout<<qu.Size()<<endl;
}