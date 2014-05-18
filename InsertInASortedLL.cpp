/*
 Insert in a sorted linked list */

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

void sortedInsert(node **head, node *new_node)
{
    node *current;
    //Base case: When the list is empty or when the data of the new node is less than or equal to the head node value
    if(*head==NULL || (*head)->data>=new_node->data)
    {
        new_node->next=*head;
        *head=new_node;
    }
    else
    {
        current=*head;
        //Find the node just after which the new node is to be inserted
        while(current->next!=NULL && current->next->data < new_node->data)
        {
            current=current->next;
        }
        new_node->next=current->next;
        current->next=new_node;
    }
}

// A utility function to print a linked list
void printList(struct node *node)
{
    while(node != NULL)
    {
        cout<<node->data<<"->";
        node = node->next;
    }
    cout<<"\n";
}

/* Drier program to test above function */
int main(void)
{
    node *head=NULL;
    node *new_node=newNode(5);
    push(&head,8);
    push(&head,7);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    sortedInsert(&head, new_node);
    printList(head);
    return 0;
}
