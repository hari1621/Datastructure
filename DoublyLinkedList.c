//Implementation of DoublyLinkedList
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
struct DoublyLinkedList
{
    struct node *head,*tail;
};
struct DoublyLinkedList* InsertAtHead(struct DoublyLinkedList* List,int data)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    if(List->head==NULL)
    {
        List->head=newNode;
        List->tail=newNode;
        return List;
    }
    List->head->prev=newNode;
    newNode->next=List->head;
    List->head=newNode;
    return List;
}
struct DoublyLinkedList* InsertAtTail(struct DoublyLinkedList* List,int data)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    List->tail->next=newNode;
    newNode->prev=List->tail;
    List->tail=newNode;
    return List;
}
struct DoublyLinkedList* InsertAtPos(struct DoublyLinkedList* List,int data,int pos)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    struct node* temp=List->head;
    int i;
    for(i=0;i<pos-2;i++)
        temp=temp->next;
    newNode->prev=temp;
    newNode->next=temp->next;
    temp->next->prev=newNode;
    temp->next=newNode;
    return List;
}
struct DoublyLinkedList* DeleteAtHead(struct DoublyLinkedList* List)
{
    struct node* temp=List->head;
    List->head=List->head->next;
    List->head->prev=NULL;
    free(temp);
    return List;
}
struct DoublyLinkedList* DeleteAtTail(struct DoublyLinkedList* List)
{
    struct node* temp=List->tail;
    List->tail=List->tail->prev;
    List->tail->next=NULL;
    free(temp);
    return List;
}
struct DoublyLinkedList* DeleteAtPos(struct DoublyLinkedList* List,int pos)
{
    struct node* temp=List->head;
    int i;
    for(i=0;i<pos-2;i++)
        temp=temp->next;
    struct node* temp2=temp->next;
    temp->next=temp2->next;
    temp2->next->prev=temp;
    free(temp2);
    return List;
}
void PrintForward(struct node* head)
{
    if(head==NULL)return;
    printf("%d ",head->data);
    return PrintForward(head->next);
}
void PrintBackward(struct node* tail)
{
    if(tail==NULL)return;
    printf("%d ",tail->data);
    return PrintBackward(tail->prev);
}
int main()
{
    struct DoublyLinkedList* List=(struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));
    List->head=NULL;
    List->tail=NULL;
    List=InsertAtHead(List,23);
    List=InsertAtHead(List,13);
    List=InsertAtTail(List,33);
    List=InsertAtTail(List,22);
    List=InsertAtTail(List,18);
    List=InsertAtTail(List,16);
    List=InsertAtTail(List,21);
    List=InsertAtPos(List,17,4);
    List=InsertAtPos(List,15,2);
    PrintForward(List->head);
    printf("\n");
    PrintBackward(List->tail);
    List=DeleteAtTail(List);
    List=DeleteAtPos(List,3);
    List=DeleteAtHead(List);
    printf("\n");
    PrintForward(List->head);
    printf("\n");
    PrintBackward(List->tail);
    return 0;
}


