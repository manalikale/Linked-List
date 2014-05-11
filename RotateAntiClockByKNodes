
/*
 Rotate a linked list in an anti- clockwise manner
 
 
 Algo:
 Given a singly linked list, rotate the linked list counter-clockwise by k nodes. Where k is a given positive integer. For example, if the given linked list is 10->20->30->40->50->60 and k is 4, the list should be modified to 50->60->10->20->30->40. Assume that k is smaller than the count of nodes in linked list.
 To rotate the linked list, we need to change next of kth node to NULL, next of last node to previous head node, and finally change head to (k+1)th node. So we need to get hold of three nodes: kth node, (k+1)th node and last node.  Traverse the list from beginning and stop at kth node. Store pointer to kth node. We can get (k+1)th node using kthNode->next. Keep traversing till end and store pointer to last node also. Finally, change pointers as stated above.
 
 
 Time Complexity: O(n) where n is the number of nodes in Linked List. The code traverses the linked list only once.
 
 */



#include<stdio.h>
#include<iostream>

using namespace std;
struct node
{
	int data;
	struct node*next;
};

void rotate(struct node **head_ref, int k)
{
	if(k==0)
        return;
	
	struct node* current = *head_ref;
	
	int count=1;
	while(count<k && current !=NULL)
	{
		current=current->next;
		count++;
	}
	
	if(current==NULL)
	{
		return;
	}
	
	struct node* kNthnode=current;
	
	while(current->next!=NULL)
	{
		current=current->next;
	}
	
	current->next=*head_ref;
	*head_ref=kNthnode->next;
	kNthnode->next=NULL;
}

void push (struct node** head_ref, int new_data)
{
    node* new_node =new node;
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        cout <<node->data;
        node = node->next;
    }
}

/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    struct node* head = NULL;
    
    // create a list 10->20->30->40->50->60
    for (int i = 60; i > 0; i -= 10)
        push(&head, i);
    
    printf("Given linked list \n");
    printList(head);
    rotate(&head,0);
    
    printf("\nRotated Linked list \n");
    printList(head);
    
    return 0;
}
