/*Tao is developing a program to manage a min-heap data structure for a small application. The program should enable Tao to insert elements, remove the root node, find the maximum value in the heap, and calculate the sum and average of all nodes in the heap.



The program must ensure that the min-heap property is maintained throughout these operations.

Input format :
The first line contains an integer n, representing the number of elements to be inserted into the min-heap.

The second line consists of n space-separated integers, representing which are the values to be inserted into the heap.

Output format :
The output displays the following format:

Print the elements of the min-heap in order, separated by spaces, on a single line.
Print the value of the root node after removing it.
Print the maximum value present in the heap after the removal operation.
Print the sum of all remaining nodes in the heap.
Print the average of all remaining nodes in the heap, rounded to two decimal places.


Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n ≤ 10

1 ≤ values ≤ 10

Sample test cases :
Input 1 :
5
6 4 3 7 8
Output 1 :
Min Heap: 3 6 4 7 8 
Root node: 3
Maximum value: 8
Sum of nodes: 25
Average of nodes: 6.25
Input 2 :
5
3 9 2 6 8
Output 2 :
Min Heap: 2 6 3 9 8 
Root node: 2
Maximum value: 9
Sum of nodes: 26
Average of nodes: 6.50*/
#include<iostream>
#include<iomanip>
using namespace std;
void minHeapify(int arr[],int size,int i){
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<size && arr[left]<arr[smallest]){
        smallest=left;
    }
    if(right<size && arr[right]<arr[smallest]){
        smallest=right;
    }
    if(smallest!=i){
        swap(arr[i],arr[smallest]);
        minHeapify(arr,size,smallest);
    }
}
void insertElements(int arr[],int value,int &size){
    int index=size;
    arr[index]=value;
    size++;
    while(index>0){
        int parent=(index-1)/2;
        if(arr[parent]>arr[index]){
            swap(arr[index],arr[parent]);
            index=parent;
        }else{
            break;
        }
    }
}
void buildMinHeap(int arr[],int size){
    for(int i=size/2-1;i>=0;i--){
        minHeapify(arr,size,i);
    }
}
void removeElement(int arr[],int &size){
    if(size<=0){
        return;
    }
    arr[0]=arr[size-1];
    size--;
    minHeapify(arr,size,0);
}
int findMax(int arr[],int size){
    int max=arr[0];
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
int sum_of_nodes(int arr[],int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    return sum;
}
double findAverage(int arr[],int size){
    double sum=0.0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    return sum/size;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    int size=0;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        insertElements(arr,value,size);
    }
    
    cout<<"Min Heap: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    cout<<"Root node: "<<arr[0]<<endl;
    removeElement(arr,size);
    cout<<"Maximum value: "<<findMax(arr,size)<<endl;
    cout<<"Sum of nodes: "<<sum_of_nodes(arr,size)<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"Average of nodes: "<<findAverage(arr,size)<<endl;
    
}