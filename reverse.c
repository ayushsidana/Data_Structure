#include<stdlib.h>
#include<stdio.h>
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
    while(n!=-1)
    {
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
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
    scanf("%d",&n);
    }
    return head;
    }
    void reverse(struct node** start)
{
    struct node *curr=*start,*nextt=NULL,*prev=NULL;
    while(curr!=NULL)
    {
        nextt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextt;
    }
    *start=prev;
}
int main()
{
    struct node* head=NULL;
   head=takeinput();
   reverse(&head);
   print(head);
   return 0;
}
