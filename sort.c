#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct NODE
{
    int data;
    struct NODE *next;
};
typedef struct NODE *node;
node head=NULL,temp,temp2;

node insert_node(FILE *fptr,int n)
{
    int d;
    for(int i=0;i<n;i++)
    {
        fscanf(fptr,"%d",&d);
        node newnode=(node)malloc(sizeof(struct NODE));
        newnode->data=d;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            temp=head;
            head=newnode;
            head->next=temp;
        }
    }
}

void sort()
{
    int x;
    temp2=head;
    while(temp2->next!=NULL)
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
        temp2=temp2->next;
    }
}

void rad(FILE *fptr,int n)
{
    for(int i=0;i<n;i++)
    {
        fprintf(fptr,"%d\t",rand()%100);
    }
}

void display(node head,FILE *fptr)
{
    temp=head;
    while(temp!=NULL)
    {
        fprintf(fptr,"%d ",temp->data);
        temp=temp->next;
    }
}

void main()
{
    int n;
    FILE *fptr;
    double start,stop;
    printf("Enter no. of numbers: ");
    scanf("%d",&n);
    fptr=fopen("input.txt","w");
    rad(fptr,n);
    fclose(fptr);
    fopen("input.txt","r");
    insert_node(fptr,n);
    start=clock();
    sort();
    stop=clock();
    fclose(fptr);
    fptr=fopen("output.txt","w");
    display(head,fptr);
    fprintf(fptr,"\nTime: %lf",(stop-start)/CLOCKS_PER_SEC);
    fclose(fptr);
}
