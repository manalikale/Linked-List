/*
 Delete alternate nodes of a linked list
 
 Algo:
 Keep track of previous of the node to be deleted. 
 First change the next link of previous node and then free the memory allocated for the node.
 
 Time Complexity: O(n) where n is the number of nodes in the given list.
 */

#include<iostream>

using namespace std;
/* Linked list node */
struct node
{
    int data;
    struct node* next;
};

/* Function to insert a node at the beginning of the Doubly Linked List */
void push(struct node** head_ref, int new_data)
{
    node* new_node = new node();
    new_node->data=new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

void deleteAlternateNodes(node *head)
{
    if(head==NULL)
    {
        return;
    }
    
    node *prev=head;
    node *current=head->next;
    while(prev!=NULL && current!=NULL)
    {
        prev->next=current->next;
        free(current);
    
        prev=prev->next;
        if(prev!=NULL)
        {
            current=prev->next;
        }
    }
    
}

void printList(struct node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
}
/* Drier program to test above function */
int main(void)
{
    
    node *head=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    push(&head,6);
    push(&head,7);
    push(&head,8);
    cout<<"Original list :"<<endl;
    printList(head);
    deleteAlternateNodes(head);
    cout<<"\nList after deletion:"<<endl;
    printList(head);
    cout<<endl;
    
    return 0;
}
