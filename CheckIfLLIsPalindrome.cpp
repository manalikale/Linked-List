/*Function to check if a singly linked list is palindrome 
 
 Time comlexity:This method takes O(n) time and O(1) extra space.
 
 Algo:
   1) Get the middle of the linked list.  2) Reverse the second half of the linked list.  3) Check if the first half and second half are identical.  4) Construct the original linked list by reversing the second half again and attaching it back to the first half
 
 */

#include<iostream>

using namespace std;
/* Link list node */
struct node
{
    char data;
    struct node* next;
};

void reverse(node **head)
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

bool compareLists(node *head1, node *head2)
{
    node *temp1=head1;
    node *temp2=head2;
    
    while (temp1 && temp2)
    {
        if(temp1 && temp2)
        {
            if(temp1->data==temp2->data)
            {
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else
            {
                return 0;
            }
        }
    }
    
    //If both lists are empty return 1
    if(temp1==NULL && temp2==NULL)
    {
        return 1;
    }
    //When one list is empty and other is not
    
    return 0;
}


bool isPalindrome(node *head)
{
    node *slow=head;
    node *fast=head;
    node *second_half=head;
    node *prevofslow=head;
    node *midnode=NULL;
    bool res=true;
    
    if(head!=NULL)
    {
        //Get the middle node. Move the fast ptr by 2 nodes and slow ptr by 1 node,
        //then slow will have the middle node
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            
            //We need prev of slow pointer for a linked list with odd elements
            prevofslow=slow;
            slow=slow->next;
        }
        
        //A fast ptr would become NULL if there are even elements in the list
        //and not NULL if the list has odd number of elements.
        //We need to skip the middle node for the odd case and store it somewhere so we can restore it
        //for the original list
        
        if(fast!=NULL)
        {
            midnode=slow;
            slow=slow->next;
        }
        
        //Now reverse the second half and compare it with the first half
        
        second_half=slow;
        prevofslow->next=NULL;//NULL terminate the first half
        reverse(&second_half);
        res=compareLists(head, second_half);
        
        reverse(&second_half);
        
        //Attach the midnode for the odd length list
        if(midnode!=NULL)
        {
            prevofslow->next=midnode;
            midnode->next=second_half;
        }
        //Attach first half with the second half
        else
        {
            prevofslow->next=second_half;
        }
    }
    return res;
}

/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginging of the linked list */
void push(struct node ** head_ref, int new_data)
{
    node* new_node = new node();
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)  = new_node;
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
    
    char str[]="aba";
    for(int i=0;str[i]!='\0';i++)
    {
        push(&head, str[i]);
    }
     printList(head);
    isPalindrome(head)? cout<<"\nIs Palindrome\n":cout<<"\nNot palindrome\n"<<endl;
}
