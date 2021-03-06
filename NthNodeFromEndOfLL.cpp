/*
 Find the Nth Node from the end of the linked list
 
 Algo:
 
 Maintain two pointers – reference pointer and main pointer.
 Initialize both reference and main pointers to head. 
 First move reference pointer to n nodes from head. 
 Now move both pointers one by one until reference pointer reaches end. 
 Now main pointer will point to nth node from the end. Return main pointer.
 
 Time Complexity: O(n) where n is the length of the list
 

 
 */

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

void printNthFromLast(node *head, int n)
{
    node *main=head;
    node *ref=head;
    
    int count=0;
    if(head!=NULL)
    {
        while(count<n)
        {
            if(ref==NULL)
            {
                cout<<"The node number is greater than the total number of nodes in the list"<<endl;
                return;
            }
            //Increment the reference pointer to reach n nodes from the start
            ref=ref->next;
            count++;
        }
        //Now start moving the main pointer from the start till the reference pointer reaches the end of the list
        //When the reference pointer reaches the end of the list, the main pointer is going to point to the nth element from the end of the list
        while(ref!=NULL)
        {
            main=main->next;
            ref=ref->next;
        }
        cout<<"Node number "<<main->data<<" is "<<n<<" nodes from the end of the list"<<endl;
    }
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
    
    printNthFromLast(head, 4);
    return 0;
}
