#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *node;
node head=NULL,temp,temp1,newnode;

node insert(node head,FILE *fp1)
{

    newnode=(node)malloc(sizeof(struct node));
    fscanf(fp1,"%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        head=newnode;
        newnode->next=temp;
    }
    return head;
}

void display(node head,FILE *fp2)
{
    temp=head;
    while(temp!=NULL)
    {
        fprintf(fp2," %d\n",temp->data);
        temp=temp->next;
    }
}

node sort(node head)
{
    int x;
    temp1=head;
    while(temp1->next!=NULL)
    {
        temp=head;
        while(temp->next!=NULL)
        {
            if(temp->data > temp->next->data)
            {
                x=temp->data;
                temp->data=temp->next->data;
                temp->next->data=x;

            }
            temp=temp->next;
        }
        temp1=temp1->next;
    }
    return head;
}

void main()
{
    int n;
    FILE *fp1,*fp2;
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");
    printf("Enter the value of n\n: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        head=insert(head,fp1);
    }
    display(head,fp2);
    head=sort(head);
    fprintf(fp2,"After sorting\n");
    display(head,fp2);
    fclose(fp1);
    fclose(fp2);
}
