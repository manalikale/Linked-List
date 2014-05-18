/*
 Delete a linked list
 
 Time Complexity: O(n)
 Auxiliary Space: O(1)
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

void deleteList(node **head)
{
    node *current=*head;
    node *next;
    
    while(current!=NULL)
    {
        next=current->next;
        free(current);
        current=next;
    }
    *head=NULL;
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
    struct node *head=NULL;
    push(&head,1);
    push(&head,1);
    push(&head,2);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    push(&head,6);
    push(&head,6);
    deleteList(&head);
    cout<<"List after deletion"<<endl;
    printList(head);
    return 0;
}
