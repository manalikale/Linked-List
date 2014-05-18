/*
 Detect a loop in the linked list and remove it
 
 Algo:
 
 This method is also dependent on Floyd’s Cycle detection algorithm.  1) Detect Loop using Floyd’s Cycle detection algo and get the pointer to a loop node.  2) Count the number of nodes in loop. Let the count be k.  3) Fix one pointer to the head and another to kth node from head.  4) Move both pointers at the same pace, they will meet at loop starting node.  5) Get pointer to the last node of loop and make next of it as NULL.
 
 
 */



#include<iostream>


using namespace std;

struct node{
    
    int data;
    node *next;
};

void push(struct node **head, int new_data)
{
    node *new_node=new node();
    new_node->data=new_data;
    new_node->next=*head;
    *head=new_node;
}

void printList(struct node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
}

void removeLoop(struct node *loopnode, struct node *head)
{
    //Initialize both the pointers to point to the startin poin of the loop
    node *p1=loopnode;
    node *p2=loopnode;
    
    unsigned int count=1;
    int i=0;
    
    //Count the number of nodes in the loop
    
    while(p1->next!=p2)
    {
        p1=p1->next;
        count++;
    }
    //Initialize one pointer to the starting of the linked list
    p1=head;
    //Initialize the second pointer also to the starting of the linked list but move it k no of nodes ahead from the head
    p2=head;
    
    for(int i=0;i<count;i++)
    {
        p2=p2->next;
    }
    
    //Find the starting point of the loop
    while(p1!=p2)
    {
        p1=p1->next;
        p2=p2->next;
        
    }
    //Iterat in the loop till you reach the end of the loop i.e the next element after the end of the loop is the start of the loop
    p2=p2->next;
    while(p2->next!=p1)
    {
        p2=p2->next;
    }
    
    //Make the end of the loop as NULL
    p2->next=NULL;

}

int detectLoop(struct node *head)
{
    node *slow=head;
    node *fast=head;
    
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    
        if(slow==fast)
        {
            removeLoop(slow,head);
            return 1;
        }
    }
    return 0;
}

int main()
{
    struct node* head = NULL;
    
    push(&head, 10);
    push(&head, 4);
    push(&head, 15);
    push(&head, 20);
    push(&head, 50);
    
 /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
    detectLoop(head);
    
   cout<<"Linked List after removing loop \n"<<endl;
    printList(head);
    return 0;
}
