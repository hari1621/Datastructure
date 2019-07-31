#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* Insert(struct node* tail,int data)
{
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        if(tail==NULL)
        {
            tail=temp;
            temp->next=tail;
            return tail;
        }
        temp->next=tail->next;
        tail->next=temp;
        tail=temp;
        return tail;
}
struct node* InsertAtPos(struct node* tail,int data,int pos)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    struct node* temp2;
    temp2=tail->next;
    int i;
    for(i=0;i<pos-2;i++)
    {
        temp2=temp2->next;
    }
    temp->next=temp2->next;
    temp2->next=temp;
    return tail;
}
struct node* InsertAtBegin(struct node* tail,int data)
{
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        if(tail==NULL)
        {
            tail=temp;
            temp->next=tail;
            return tail;
        }
        temp->next=tail->next;
        tail->next=temp;
        return tail;
}
void display(struct node* tail)
{
    struct node* temp=tail;
    do
    {
        printf("%d ",temp->next->data);
        temp=temp->next;

    }while(temp!=tail);
}
int main()
{
    struct node* tail=(struct node*)malloc(sizeof(struct node));
    tail=NULL;
    tail=InsertAtBegin(tail,12);
    tail=Insert(tail,13);
    tail=InsertAtPos(tail,14,2);
    tail=InsertAtBegin(tail,15);
    display(tail);
    return 0;
}
