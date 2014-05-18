/*
 Function that counts the number of times an integer occurs in a linked list
 
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

int count(node *head, int search_for)
{
    node *current=head;
    int count=0;
    while(current!=NULL)
    {
        if(current->data==search_for)
            count++;
        current=current->next;
    }
    return count;
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
    cout<<count(head,6)<<endl;
    return 0;
}
