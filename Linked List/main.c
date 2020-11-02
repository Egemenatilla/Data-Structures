#include <stdio.h>
#include <stdlib.h>

struct node //create a basic link list with data and next
{
    int data;
    struct node *next;
};

struct node* createNode(int data)   //create a node which include one data and one next
{
   struct node *a;
   a = (struct node*)malloc(sizeof(struct node));
   a->data = data;
   a->next = NULL;
   return a;
};
//insert node the beginning of the linked list.
// a(new node)
 //  ---------     ----------
 // |data|next-|> |data|next-|>NULL
 //  ---------     ----------
 //head
void insertNode(int data,struct node **head)
{
    struct node *a = createNode(data);
    a->next = *head;
    *head = a;
}
//insert node the end of the linked list
// x                            (new node)
//  ---------     ----------    ----------
// |data|next-|> |data|next-|> |data|next-|>NULL
//  ---------     ----------    ----------
// head
//if the linked list has no elements, create one and then add.
void append(int data,struct node **head)
{
    struct node *a = createNode(data);
    if(*head == NULL)
    {
        a->next = *head;
        *head = a;
    }
    else
    {
        struct node *x = *head;
        while(x->next!=NULL)
            x = x->next;
        x->next = a;
    }

}
void insertAfter(int data,struct node *prev)
{
    if(prev == NULL)
        return;
    struct node *a=(struct node*)malloc(sizeof(struct node));
    a->data = data;
    a->next = prev->next;
    prev->next = a;
}

void writeList(struct node *head)
{
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
}

void deleteNode(int deleting, struct node **head) //deleting the node whose content is known
{
    struct node *temp = *head;
    struct node *prev;
    while(temp!=NULL && temp->data!=deleting)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp==*head)
        *head=(*head)->next;
    else
        prev->next=temp->next;
    free(temp);

}

int main()
{
    struct node *list1=NULL;

     insertNode(20,&list1);
     insertNode(30,&list1);
     insertNode(200,&list1);
     insertNode(40,&list1);
     append(1,&list1);
     append(400,&list1);
     insertNode(80,&list1);
     deleteNode(400,&list1);
     writeList(list1);

     printf("\n");
    return 0;
}
