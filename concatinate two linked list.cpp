node *concatenate(node *head1,node *head2)
{
node *ptr=new node;
ptr=head1;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=head2;
return head1;
}


//connect the head of two linked