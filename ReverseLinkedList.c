#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* Insert(struct node* Head,int data,int pos)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    int i;
    temp->data=data;
    temp->next=NULL;
    if(pos==1)
    {
        temp->next=Head;
        Head=temp;
        return Head;
    }
    struct node* temp2=(struct node*)malloc(sizeof(struct node));
    temp2=Head;
    for(i=0;i<pos-2;i++)
        temp2=temp2->next;
    temp->next=temp2->next;
    temp2->next=temp;
    return Head;

}
struct node* Delete(struct node* head,int pos)
{
    struct node*temp=head;
    struct node*temp2=(struct node*)malloc(sizeof(struct node));
    int i;
    if(pos==1)
    {
        head=head->next;
        free(temp);
        return head;
    }
    for(i=0;i<pos-2;i++)
    {
        temp=temp->next;
    }
    temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
    return head;


}
struct node* ReverseList(struct node* Head)
{
    struct node *next,*current,*prev;
    prev=NULL;
    current=Head;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    Head=prev;
    return Head;
}
void Print(struct node* Head)
{
   printf("\nList is.... [");
   while(Head!=NULL)
   {
       printf("%d ",Head->data);
       Head=Head->next;
   }
   printf("]\n");
}
int main()
{
    struct node* Head=(struct node*)malloc(sizeof(struct node));
    Head=NULL;
    Head=Insert(Head,101,1);
    Head=Insert(Head,104,2);
    Head=Insert(Head,108,3);
    Head=Insert(Head,112,4);
    printf("\n-----------------------");
    Print(Head);
    Head=ReverseList(Head);
    printf("\n-----------------------");
    Print(Head);
    return 0;
}

