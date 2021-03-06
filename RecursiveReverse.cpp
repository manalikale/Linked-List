/*Recursive reversal of a linked list
 
 Time comlexity:O(n) where n is th enumber of elements in the linked list
 
Problem: Will not work with a loop in the linked list
 
 */

#include<iostream>

using namespace std;
/* Link list node */
struct node
{
    int data;
    struct node* next;
};


void recursiveReverse(struct node** head_ref)
{
    struct node* first;
    struct node* rest;
    
    /* empty list */
    if (*head_ref == NULL)
        return;
    
    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = *head_ref;
    rest  = first->next;
    
    /* List has only one node */
    if (rest == NULL)
        return;
    
    /* reverse the rest list and put the first element at the end */
    recursiveReverse(&rest);
    first->next->next  = first;
    
    /* tricky step -- see the diagram */
    first->next  = NULL;
    
    /* fix the head pointer */
    *head_ref = rest;
}

/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginging of the linked list */
void push(struct node ** head_ref, int new_data)
{
    /* allocate node */
    node* new_node = new node();
    
    /* put in the data  */
    new_node->data  = new_data;
    
    /* link the old list off the new node */
    new_node->next = (*head_ref);
    
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while(node!=NULL)
    {
        cout <<node->data;
        node = node->next;
    }
}

/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    
    /* Let us create a sorted linked list to test the functions
     Created linked list will be 11->11->11->13->13->20 */
    push(&head, 2);
    push(&head, 3);
    push(&head, 1);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    
    printf("Linked list before reversal");
    cout<<endl;
    printList(head);
    cout<<endl;
    
    /* Remove duplicates from linked list */
    recursiveReverse(&head);
    
    printf("Linked list after reversal ");
    printList(head);
    cout<<endl;

}
