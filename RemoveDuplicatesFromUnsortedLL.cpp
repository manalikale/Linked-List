

/*
 Remove duplicates from an unsorted linkedlist.
 
 Algo:
 
 Use an unordered set. Insert the first element of the linked list in the set. Traverse the linked list till there exists a next element after the start of the linked list.
 For every element that is a duplicate,
 
 node *temp=head->next->next;
 delete(head->next);
 head->next=temp;
 
 Otherwise for every element that is unique:
 head=head->next;
 unordered_set.insert(head->data);
 
 Time: O(n) where O(1) is the average insert time in an unordered_set and there are N elements in the linked list
 
 
 */

//Buffer(use of set allowed)


#include<iostream>
#include<unordered_set>

using namespace std;

struct node{
    
    int data;
    struct node *next;
};

void removeDuplicates(struct node *start)
{
    node *temp;
    unordered_set<int>un;
    un.insert(start->data);
    while(start->next)
    {
        //If duplicate
        if(un.find(start->next->data)!=un.end())
        {
            temp=start->next->next;
            delete(start->next);
            start->next=temp;
        }
        //If not duplicate
        else
        {
            start=start->next;
            un.insert(start->data);
        }
    }
}

//Inserting backwards, last inserted element is the first element
void push(struct node **start,int new_data)
{
    node *new_node=new node();
    new_node->data=new_data;
    new_node->next=*start;
    *start=new_node;
}

void printlist(struct node *node)
{
    while(node!=NULL)
    {
        cout<<node->data;
        node=node->next;
    }
}
int main()
{
    struct node *start = NULL;
    
    /* The constructed linked list is:
     10->12->11->11->12->11->10*/
    push(&start, 1);
    push(&start, 1);
    push(&start, 2);
    push(&start, 4);
    push(&start, 1);
    push(&start, 2);
    push(&start, 5);
    
    cout<<"Linked list before removing duplicates:";
    printlist(start);
    
    removeDuplicates(start);
    
    cout<<"\n Linked list after removing duplicates:";
    printlist(start);
    cout<<endl;
    return 0;
}




/*
 Remove duplicates from an unsorted linkedlist.
 
 Algo:
 
 
 Time: O(n^2)
 
 
 */

//Buffer usage is not allowed. Hence use two pointers one to traverse through the linked list and the other to select the duplicate elements


#include<iostream>
#include<unordered_set>

using namespace std;

struct node{
    
    int data;
    struct node *next;
};

void removeDuplicates(struct node *start)
{
    struct node *ptr1;
    struct node *ptr2;
    struct node *dup;
    
    ptr1=start;
    
    //Pick elements one by one
    while(ptr1!=NULL && ptr1->next!=NULL)
    {
        ptr2=ptr1;
        
        //Compare the picked element with the rest of the element
        while(ptr2->next!=NULL)
        {
            if(ptr1->data==ptr2->next->data)
            {
                dup=ptr2->next;
                ptr2->next=ptr2->next->next;
                free(dup);
            }
            else
            {
                ptr2=ptr2->next;
            }
        }
        ptr1=ptr1->next;
    }
    
}

//Inserting backwards, last inserted element is the first element
void push(struct node **start,int new_data)
{
    node *new_node=new node();
    new_node->data=new_data;
    new_node->next=*start;
    *start=new_node;
}

void printlist(struct node *node)
{
    while(node!=NULL)
    {
        cout<<node->data;
        node=node->next;
    }
}
int main()
{
    struct node *start = NULL;
    
    /* The constructed linked list is:
     10->12->11->11->12->11->10*/
    push(&start, 1);
    push(&start, 1);
    push(&start, 2);
    push(&start, 4);
    push(&start, 1);
    push(&start, 2);
    push(&start, 5);
    
    cout<<"Linked list before removing duplicates:";
    printlist(start);
    
    removeDuplicates(start);
    
    cout<<"\n Linked list after removing duplicates:";
    printlist(start);
    cout<<endl;
    return 0;
}
