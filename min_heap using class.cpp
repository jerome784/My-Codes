/*Benjamin is conducting a survey to understand the age distribution of participants in a community event. He collects the ages and wants to identify how many participants are younger than a specified age threshold.



To organize the data efficiently, Benjamin uses a Min-Heap to sort the ages. After inputting the ages and the threshold age, he builds the Min-Heap and counts the number of participants younger than the specified age. Finally, Benjamin prints both the sorted ages and the count of younger participants for analysis.
*/


#include<iostream>
using namespace std;

class Minheap{
  int *arr;
  int capacity;
  int size;
  public:
  Minheap(int cap){
      capacity=cap;
      arr=new int[capacity+1];
      size=0;
  }
  void insert(int val){
      size++;
      int index=size;
      arr[index]=val;
      while(index>1){
          int parent=index/2;
          if(arr[index]<arr[parent]){
              swap(arr[index],arr[parent]);
              index=parent;
          }
          else{
              break;
          }
      }
  }
  
  void print(){
      for(int i=1;i<=size;i++){
          cout<<arr[i]<<" ";
      }
      cout<<endl;
  }
  int countAge(int threshold){
      int count=0;
      for(int i=1;i<=size;i++){
          if(arr[i]<threshold){
              count++;
          }
      }
      return count;
  }
};
int main(){
    int num;
    cin>>num;
    Minheap heap(num);
    for(int i=0;i<num;i++){
        int n;
        cin>>n;
        heap.insert(n);
    }
    int threshold;
    cin>>threshold;
    heap.print();
    cout<<heap.countAge(threshold);
    
}