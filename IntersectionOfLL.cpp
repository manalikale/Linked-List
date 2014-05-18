/*
 
 Find intersection point of two linked lists
 
 Algo:
 1) Get count of the nodes in first list, let count be c1.
 2) Get count of the nodes in second list, let count be c2.
 3) Get the difference of counts d = abs(c1 – c2)
 4) Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes.
 5) Then we can traverse both the lists in parallel till we come across a common node. (Note that getting a common node is done by comparing the address of the nodes)
 
 Time Complexity: O(m+n) 
 Space:O(1)
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

int getCount(node *head)
{
    node *current=head;
    int count=0;
    while(current!=NULL)
    {
        count++;
        current=current->next;
    }
    return count;
}

int getIntersectionNodeHelper(int d, node *head1, node *head2);
int getIntersectionNode(node *head1, node *head2)
{
    int c1=getCount(head1);
    int c2=getCount(head2);
    int d;
    if(c1>c2)
    {
        d=c1-c2;
        return getIntersectionNodeHelper(d, head1, head2);
    }
    if(c1<c2)
    {
        d=c2-c1;
        return getIntersectionNodeHelper(d, head2, head1);
    }
    return -1;
}


int getIntersectionNodeHelper(int d, node *head1, node *head2)
{
    node *current1=head1;
    node *current2=head2;
    
    for(int i=0;i<d;i++)
    {
        if(current1==NULL)
        {
            return -1;
        }
        //Move the bigger list d nodes ahead
        current1=current1->next;
    }
    //Move bothe the smaller and the bigger lists together while comparing their data nodes
    while(current1!=NULL && current2!=NULL)
    {
        if(current1==current2)
        {
            return current1->data;
        }
        current1=current1->next;
        current2=current2->next;
    }
    return -1;
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
    struct node* newNode;
    struct node* head1 =
    (struct node*) malloc(sizeof(struct node));
    head1->data  = 10;
    
    struct node* head2 =
    (struct node*) malloc(sizeof(struct node));
    head2->data  = 3;
    
    newNode = (struct node*) malloc (sizeof(struct node));
    newNode->data = 6;
    head2->next = newNode;
    
    newNode = (struct node*) malloc (sizeof(struct node));
    newNode->data = 9;
    head2->next->next = newNode;
    
    newNode = (struct node*) malloc (sizeof(struct node));
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next  = newNode;
    
    newNode = (struct node*) malloc (sizeof(struct node));
    newNode->data = 30;
    head1->next->next= newNode;
    
    head1->next->next->next = NULL;
    
    cout <<getIntersectionNode(head1, head2)<<endl;
    
        return 0;
}
