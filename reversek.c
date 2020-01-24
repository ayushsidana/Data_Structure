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
/*node* kReverse(node*head,int n)
{
    //write your code here
    node *curr=head,*nextt=NULL,*temp=NULL,*start=NULL,*prev=NULL; int k=0,c=0;
    while(curr!=NULL)
    {
        k=0; prev=NULL; start=curr;
        while(curr!=NULL && k<n)
        {
            k++;
            nextt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextt;
        }
        if(c==0)
        {
            temp=prev;
        }
        else
        {
        head->next=prev;
        }
        head=start;
        c++;
    }
    return temp;
}*/

void reversek(struct node **head)
{
        int c=0,k,t=0;
    scanf("%d",&k);
    struct node *start1=NULL,*curr=*head,*nextt=NULL,*prev=NULL;
   // printf("%d %d\n",curr,curr->next);
while(curr)
{
    start1=curr;
    prev=NULL;
    while(curr!=NULL && c<k)
    {
        c++;
        nextt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextt;
    }
    c=0;
    *head=prev;
    head=&(start1->next);
   // printf("%d %d %d %d %d\n",start1,&head,*head,start1->next,&(start1->next));
}
}
int main()
{
    struct node* head=NULL,*start=NULL;
   head=takeinput();
   print(head);
   reversek(&head);
   print(head);
   return 0;
}
