/*Meet Alex, who is interested in managing a dynamic array of integers using a Min Heap structure.



Alex needs to implement a program that allows for the insertion of elements, construction of a Min Heap, and the deletion of elements that are powers of two from the heap.

Input format :
The first line contains an integer n representing the number of elements to be inserted into the Min Heap.

The second line consists of n space-separated integers value that represents the value to be inserted into the heap.

Output format :
The first line should display "Initial Min Heap: " followed by integers the initial Min Heap after all elements have been inserted.

The second line should display "Updated Min Heap: " followed by integers the updated Min Heap after all powers of two have been removed.



Refer to the sample output for the exact format.

Code constraints :
the test cases will fall under the following constraints:

1 ≤ n ≤ 10

1 ≤ values ≤ 100

Sample test cases :
Input 1 :
5
4 3 2 5 6
Output 1 :
Initial MinHeap: 2 4 3 5 6 
Updated Min Heap: 3 5 6 */
#include <iostream>
#include <cmath>

using namespace std;
// You are using GCC
void swap(int *x, int *y) {
    int temp=*x;
    *x=*y;
    *y=temp;
    
}

void minHeapify(int heap[], int size, int i) {
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    
    if(left<size && heap[left]<heap[smallest]){
        smallest=left;
    }
    if(right<size && heap[right]<heap[smallest]){
        smallest=right;
    }
    if(smallest!=i){
        swap(heap[i],heap[smallest]);
        minHeapify(heap,size,smallest);
    }
    
}

void buildMinHeap(int heap[], int size) {
    for(int i=size/2-1;i>=0;i--){
        minHeapify(heap,size,i);
    }
    
    
}

void insertElement(int heap[], int &size, int value) {
    size++;
    int index=size-1;
    heap[index]=value;
    while(index>0){
        int parent=(index-1)/2;
        if(heap[parent]>heap[index]){
            swap(&heap[parent],&heap[index]);
            index=parent;
        }else{
            break;
        }
    }
    
    
}

void displayMinHeap(int heap[], int size) {
    for(int i=0;i<size;i++){
        cout<<heap[i]<<" ";
    }cout<<endl;
    
}

bool isPowerOfTwo(int n) {
    return (n>0) && (n & (n-1))==0;
    
}

void deletePowersOfTwo(int heap[], int &size) {
    int i=0;
    while(i<size){
        if(isPowerOfTwo(heap[i])){
            heap[i]=heap[size-1];
            size--;
            minHeapify(heap,size,i);
            
        }else{
            i++;
        }
    }
    
    
} 
int main() {
    int n;
    cin >> n;

    // Allocate dynamic memory for the heap
    int* heap = new int[n];
    int size = 0;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertElement(heap, size, value);
    }

    buildMinHeap(heap, size);
    
    cout << "Initial MinHeap: ";
    displayMinHeap(heap, size);

    deletePowersOfTwo(heap, size);

    cout << "Updated Min Heap: ";
    displayMinHeap(heap, size);

    delete[] heap;

    return 0;
}