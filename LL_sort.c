#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;
struct node *temp,*temp1,*temp2,*newnode;

void display(struct node *);
struct node* sort(struct node *);
struct node* insert_at_beg(struct node *);

main()
{
    int ch;
    head=NULL;
    while(1)
    {
      printf("1--insert at beginning\n");
      printf("2--sort list\n");
     printf("3--display linked list\n");
     printf("4--exit\n");

     printf("enter your choice\n");
     scanf("%d",&ch);
     switch(ch)
     {
        case 1:newnode=(struct node*)malloc(sizeof(struct node));
             printf("enter data\n");
             scanf("%d",&newnode->data);
             head=insert_at_beg(newnode);
             break;
        case 2: head=sort(head);
        case 3: display(head);
            break;
        case 4: exit(0);
             break;
    default: printf("Invalid choice\n");
     }
    }
}

struct node* insert_at_beg(struct node *newnode)
{
   if(head==NULL)
   {
     head=newnode;
     head->next=NULL;
     return(head);
   }
   else
   {
     newnode->next=head;
     head=newnode;
     return(head);
   }
}

void display(struct node *head)
{
   if(head==NULL)
   {
     printf("the linked list is empty\n");
   }
   else
   {
      temp=head;
      while(temp!=NULL)
      {
         printf("%d->",temp->data);
         temp=temp->next;
      }
      printf("\n");
   }
}

struct node* sort(struct node *head)
{
    int i;
    temp1=head;
    while(temp1->next!=NULL)
    {
        temp=head;
        while(temp->next!=NULL)
        {
            if(temp->data > temp->next->data)
            {
                i=temp->data;
                temp->data=temp->next->data;
                temp->next->data=i;
            }
             temp=temp->next;
        }

        temp1=temp1->next;
    }
    return (head);
}
