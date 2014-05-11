/*
 Count the number of nodes in a loop in a Linked list
 
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


int countNodes(node *loopnode,node *head)
{
    node *p1=loopnode;
    node *p2=loopnode;
    unsigned int count=1;
    while(p1->next!=p2)
    {
        p1=p1->next;
        count++;
    }
    return count;
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
            node *p1=slow;
            node *p2=slow;
            unsigned int count=1;
            while(p1->next!=p2)
            {
                p1=p1->next;
                count++;
            }
            return count;
            
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
    return detectLoop(head);

   
}
