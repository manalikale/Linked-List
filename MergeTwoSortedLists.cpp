/*
 
 Merge two sorted lists
 
 Space:Proportional to size of the 2 lists
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

node* SortedMerge(struct node* a, struct node* b)
{
    node* result = NULL;
    
    /* Base cases */
    if (a == NULL)
        return(b);
    else if (b==NULL)
        return(a);
    
    /* Pick either a or b, and recur */
    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return(result);
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
    node* res = NULL;
    node* a = NULL;
    node* b = NULL;
    
    /* Let us create two sorted linked lists to test the functions
     Created lists shall be a: 5->10->15,  b: 2->3->20 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    
    push(&b, 20);
    push(&b, 3);
    push(&b, 2);
    
    /* Remove duplicates from linked list */
    res = SortedMerge(a, b);
    printf("\n Merged Linked List is: \n");
    printList(res);
    cout <<SortedMerge(a, b)<<endl;
    return 0;
}
