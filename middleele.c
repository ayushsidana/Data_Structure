#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* start=NULL;
struct node* createnode()
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
    return n;
}
void insertnode()
{
    struct node *temp,*t;
    temp=createnode();
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        t=start;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=temp;
    }
}
void deletefirst()
{
    struct node *temp;
    temp=start;
    start=start->next;
    free(temp);
}
void print()
{
    struct node *temp;
    temp=start;
    printf("%d\n",start);
    while(temp!=NULL)
    {
        printf("%d %d\n",temp->data,temp->next);
        temp=temp->next;
    }
}
void middle()
{
    struct node *a=NULL,*b=NULL;
    a=start;
    b=start;
    while(b!=NULL && b->next!=NULL)
    {
        a=a->next;
        b=b->next->next;
    }
    printf("%d",a->data);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
    insertnode();
    }

    middle();
    return 0;
}

