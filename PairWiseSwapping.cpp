/*
 Pairwise swapping
 This program swaps the nodes of linked list rather than swapping the
 field from the nodes.
 Imagine a case where a node contains many fields, there will be plenty
 of unnecessary swap calls. */

#include<iostream>

using namespace std;
/* Linked list node */
struct node
{
    int data;
    struct node* next;
};

/* Function to create a new node with given data */
node *newNode(int data)
{
    node *new_node = new node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Function to insert a node at the beginning of the Doubly Linked List */
void push(struct node** head_ref, int new_data)
{
    node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

struct node *pairWiseSwap(struct node* head)
{
    // Base Case: The list is empty or has only one node
    if (head == NULL || head->next == NULL)
        return head;
    
    // Store head of list after two nodes
    node* remaining = head->next->next;
    
    // Change head
    node* newhead = head->next;
    
    // Change next of second node
    head->next->next = head;
    
    // Recur for remaining list and change next of head
    head->next = pairWiseSwap(remaining);
    
    // Return new head of modified list
    return newhead;
}

// A utility function to print a linked list
void printList(struct node *node)
{
    while(node != NULL)
    {
        cout<<node->data<<"->";
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function */
int main(void)
{
    node *start=NULL;
    push(&start,7);
    push(&start,6);
    push(&start,5);
    push(&start,4);
    push(&start,3);
    cout<<"Linked List before swapping"<<endl;
    printList(start);
    start=pairWiseSwap(start);
    cout<<"LinkedList after swapping"<<endl;
    printList(start);
    return 0;
}
