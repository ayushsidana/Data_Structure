#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void print(struct node* head)
    {
        while(head!=NULL)
        {
            printf("%d ",head->data);
            head=head->next;
        }
    }
struct node* takeinput()
{
    struct node *head=NULL,*tail=NULL;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=i;
    newnode->next=NULL;
    if(head==NULL)
    {
    head=newnode;
    tail=newnode;
    }
    else
    {
        tail->next=newnode;
        tail=tail->next;
    }
    }
    //tail->next=NULL;
   // tail->next=head->next;
    return head;
    }
struct node* swappair(struct node* head)
{
    struct node *first=head,*second=NULL;
    if(first)
    {
        second=first->next;
    }
    if(!first || !second)
    {
        return first;

    }
    second->next=swappair(second->next);
    first->next=second->next;
    second->next=first;
    return second;
}
int main()
{
    struct node* head=NULL,*start=NULL;
   head=takeinput();
   start=swappair(head);
   print(start);
   return 0;
}

