/*Iterative reversal of a linked list
 
 Time comlexity:O(n) where n is th enumber of elements in the linked list
 
 eg: 1-2-3-4-5->NULL
 
 current=1
 next=current->next i.e. next=2
 current->next=prev i.e. current->next=NULL;
 prev=current i.e. prev=1
 current=next i.e. current=2
 
 Lastly after all the elements are reversed change the head element to prev.
 
 */

#include<iostream>

using namespace std;
/* Link list node */
struct node
{
    int data;
    struct node* next;
};

/* The function removes duplicates from a sorted list */
void reverse(struct node **head)
{
    node *prev=NULL;
    node *current=*head;
    node *next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;


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
    reverse(&head);
    
    printf("Linked list after reversal ");
    printList(head);
    cout<<endl;

}
