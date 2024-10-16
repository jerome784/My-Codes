#include <iostream>
using namespace std;
struct node
{
int data;
node *next;
node(int value){
data=value;
next=NULL;
}
};
node *insertElements(int arr[],int size)
{
if (size==0)
return NULL;
node *head=new node(arr[0]);
node *current=head;
for(int i=1;i<size;i++)
{
current->next=new node(arr[i]);
current=current->next;
}
return head;
}
void printList(node *head){
node *current=head;
while(current!=NULL){
cout<<current->data;
current=current->next;
}
}
int main()
{
int arr[]={1,2,3,4,5};
int size=sizeof(arr)/sizeof(arr[0]);
node *head=insertElements(arr,size);
printList(head);

return 0;
}