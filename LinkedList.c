#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct LinkedList
{
    struct node *head,*tail;
};
struct LinkedList* InsertAtFirst(struct LinkedList* Node,int data)
{
    struct node* temp=(struct node*)malloc((sizeof(struct node)));
    temp->data=data;
    temp->next=NULL;
    if(Node->head==NULL)
    {
        Node->head=temp;
        Node->tail=temp;
        return Node;
    }
    temp->next=Node->head;
    Node->head=temp;
    return Node;

}
struct LinkedList* InsertAtPos(struct LinkedList* Node,int data,int pos)
{
    struct node* temp=(struct node*)malloc((sizeof(struct node)));
    temp->data=data;
    temp->next=NULL;
    int i;
    struct node* temp2=Node->head;
    for(i=0;i<pos-2;i++)
    {
        temp2=temp2->next;
    }
    temp->next=temp2->next;
    temp2->next=temp;
    return Node;
}
struct LinkedList* InsertAtEnd(struct LinkedList* Node,int data)
{
    struct node* temp=(struct node*)malloc((sizeof(struct node)));
    temp->data=data;
    temp->next=NULL;
    Node->tail->next=temp;
    Node->tail=temp;
    return Node;
}
struct LinkedList* DeleteAtFirst(struct LinkedList *Node)
{
    struct node* temp;
    temp=Node->head;
    Node->head=Node->head->next;
    free(temp);
    return Node;
}
struct LinkedList* DeleteAtEnd(struct LinkedList *Node)
{
    struct node *temp=Node->head;
    while(temp->next->next!=NULL)//find Second last node
        temp=temp->next;
    free(Node->tail);
    Node->tail=temp;
    Node->tail->next=NULL;
    return Node;
}
struct LinkedList* DeleteAtPos(struct LinkedList* Node,int pos)
{
    struct node* temp=Node->head;
    int i;
    for(i=0;i<pos-2;i++)
       temp=temp->next;
    struct node* temp2;
    temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
    return Node;

}
void Print(struct node* head)
{
    if(head==NULL)return;
    printf("%d ",head->data);
    Print(head->next);
}
int main()
{
    struct LinkedList* Node=(struct LinkedList*)malloc(sizeof(struct LinkedList));
    Node->head=NULL;
    Node->tail=NULL;
    Node=InsertAtFirst(Node,112);
    Node=InsertAtEnd(Node,113);
    Node=InsertAtEnd(Node,114);
    Node=InsertAtEnd(Node,115);
    Node=InsertAtEnd(Node,116);
    Node=InsertAtPos(Node,23,3);
    Node=InsertAtFirst(Node,4);
    Node=InsertAtEnd(Node,98);
    Print(Node->head);
    printf("\n"); // 4 112 113 23 114 115 116 98
    Node=DeleteAtEnd(Node);
    Node=DeleteAtPos(Node,4);
    Node=DeleteAtFirst(Node);
    Print(Node->head);// 112 113 114 115 116
    return 0;


}

