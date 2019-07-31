#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node* next;
};
struct Stack
{
    struct node* top;
};
bool IsEmpty(struct Stack* st)
{
    if(st->top==NULL)
        return true;
    else
        return false;
}
struct node* Top(struct Stack* st)
{
    return (st->top);
}
struct Stack* Push(struct Stack* st,int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(st->top==NULL)
    {
        st->top=temp;
        return st;
    }
    temp->next=st->top;
    st->top=temp;
    return st;
}
struct Stack* Pop(struct Stack* st)
{
    struct node* temp=st->top;
    if(IsEmpty(st))
    {
        printf("Error : No Elements to POP");
        return st;
    }
    st->top=temp->next;
    free(temp);
    return st;
}
void Print(struct node* top)
{
    if(top==NULL)return;
    printf("%d ",top->data);
    Print(top->next);
}
int main()
{
    struct Stack* st=(struct Stack*)malloc(sizeof(struct Stack));
    struct node* top;
    st->top=NULL;
    st=Push(st,1);
    st=Push(st,2);
    st=Push(st,3);
    st=Push(st,4);
    printf("\n");
    Print(st->top);
    st=Pop(st);
    printf("\n");
    Print(st->top);
    top=Top(st);
    printf("\nTop of the Stack : %d\n",top->data);
    return 0;
}
