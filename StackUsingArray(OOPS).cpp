#include<iostream>
#define max_size 100
using namespace std;
class STACK
{
    int a[max_size];
    int top;
public:
    STACK()
    {
        top=-1;
    }
    void push(int);
    void pop();
    int Top();
    void Print();
    bool IsEmpty();
};
bool STACK :: IsEmpty()
{
    if(top==-1)
        return true;
    else
        return false;
}
void STACK :: push(int x)
{
    if(top==max_size-1)
    {
            cout<<"Stack OverFlow\n";
            return;
    }
    a[++top]=x;
}
void STACK ::pop()
{
    if(IsEmpty())
    {
        cout<<"Error : No Elements to remove\n";//Stack Underflow
        return;
    }
    top--;
}
int STACK :: Top()
{
    return a[top];
}
void STACK :: Print()
{
    cout<<"Stack : ";
    for(int i=0;i<=top;i++)
       cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{
    STACK st;
    st.push(2);st.Print();
    st.push(3);st.Print();
    st.push(4);st.Print();
    st.push(5);st.Print();
    st.pop();st.Print();
    cout<<"Top Of the Stack : "<<st.Top()<<endl;
    return 0;
}
