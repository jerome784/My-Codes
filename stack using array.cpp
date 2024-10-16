#include<iostream>
using namespace std;
class Stack{
  private:
  int capacity;
  int *arr;
  int top;
  public:
  Stack(int c){
      capacity=c;
      arr=new int[capacity];
      top=-1;
  }
  
  void push(int x){
      if(isFull()){
          cout<<"Stack overflow"<<endl;
          return;
      }
      top++;
      arr[top]=x;
  }
  
  void pop(){
      if(isempty()){
          cout<<"Stack underflow"<<endl;
          return ;
      }
      top--;
      
      
  }
  
  int Top(){
      return arr[top];
  }
  int sizee(){
      return top+1;
  }
  
  bool isempty(){
      if(top==-1){
          return true;
      }
      return false;
  }
  
  bool isFull(){
      if(top==capacity-1){
          return true;
      }
      return false;
  }
  
};
int main(){
    Stack st=Stack(56);
    st.push(34);
    st.push(13);
    st.push(56);
    st.push(11);
    st.push(67);
    st.Top();
    st.push(45);
    st.push(1);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.Top();
    
    
}