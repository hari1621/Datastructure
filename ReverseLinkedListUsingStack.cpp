#include<iostream>
#include<stack>
using namespace std;
struct node
{
    int data;
    node *next;
};
struct LinkedList
{
    node *head,*tail;
};
LinkedList* Reverse(LinkedList* Node)
{
    stack<struct node*> S;
    struct node* temp=Node->head;
    while(temp!=NULL)
    {
        S.push(temp);
        temp=temp->next;
    }
    temp=S.top();
    Node->head=temp;
    S.pop();
    while(!S.empty())
    {
        temp->next=S.top();
        temp=temp->next;
        S.pop();
    }
    temp->next=NULL;
    return Node;
}
LinkedList* InsertAtFirst(struct LinkedList* Node,int data)
{
    node* temp= new node();
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
LinkedList* InsertAtPos(struct LinkedList* Node,int data,int pos)
{
    node* temp=new node();
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
LinkedList* InsertAtEnd(struct LinkedList* Node,int data)
{
    node* temp=new node();
    temp->data=data;
    temp->next=NULL;
    Node->tail->next=temp;
    Node->tail=temp;
    return Node;
}
LinkedList* DeleteAtFirst(struct LinkedList *Node)
{
    struct node* temp;
    temp=Node->head;
    Node->head=Node->head->next;
    delete temp;
    return Node;
}
LinkedList* DeleteAtEnd(struct LinkedList *Node)
{
    struct node *temp=Node->head;
    while(temp->next->next!=NULL)//find Second last node
        temp=temp->next;
    delete Node->tail;
    Node->tail=temp;
    Node->tail->next=NULL;
    return Node;
}
LinkedList* DeleteAtPos(struct LinkedList* Node,int pos)
{
    struct node* temp=Node->head;
    int i;
    for(i=0;i<pos-2;i++)
       temp=temp->next;
    struct node* temp2;
    temp2=temp->next;
    temp->next=temp2->next;
    delete temp2;
    return Node;

}
void Print(struct node* head)
{
    if(head==NULL)return;
    cout<<head->data<<" ";
    Print(head->next);
}
int main()
{
    LinkedList* Node= new LinkedList();
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
    Print(Node->head);// 4 112 113 23 114 115 116 98
    cout<<endl;
    Node=Reverse(Node);
    Print(Node->head);
    return 0;


}


