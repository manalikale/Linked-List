/*
 Reverse a linked list in groups of given size
 
 Algorithm: reverse(head, k)
 1) Reverse the first sub-list of size k. While reversing keep track of the next node and previous node. Let the pointer to the next node be next and pointer to the previous node be prev. See this post for reversing a linked list.
 2) head->next = reverse(next, k) /* Recursively call for rest of the list and link the two sub-lists
3) return prev //prev becomes the new head of the list
 
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

node *reverseInGroupsOfN(node *head, int n)
{
    node *current=head;
    node *prev=NULL;
    node *next;
    int count=0;
    while(current!=NULL && count<n)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        count++;
    }
    if(next!=NULL)
    {
        head->next=reverseInGroupsOfN(next,n);
    }
    return prev;
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
    node *r=reverseInGroupsOfN(head, 3);
    cout<<"\nList after rotation:"<<endl;
    printList(r);
    cout<<endl;
    
    return 0;
}
