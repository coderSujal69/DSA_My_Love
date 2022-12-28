#include<iostream>
using namespace std;

struct node
{
    int data,pn;
    node *link;
};
class plistq{
    node *front ,*rear;
    public : 
    plistq(){  front =rear = NULL; }
    void append(int num,int pr);
    void del();
    void display();
};
void plistq ::append(int num , int pr){
    node *temp = new node;
    temp->data = num;
    temp->pn = pr;
    if ( front ==NULL )
    {
        temp->link = NULL;
        rear =temp;
        front = temp;
        return ;
    }
    if ( temp->pn < front->pn)
    {
        temp->link = temp;
        front = temp;
        return;
    }
    node*t,*old;
    while (t != rear)
    {
       old =t;
       t= t->link;
       if (temp->pn < t->pn)
       {
          old->link =temp;
          temp->link = t;
          return;
       }
       
    }
    if (t==rear)
    {
         t->link = temp;
         temp->link = NULL;
         rear = temp;
    }
    
}
void plistq ::del(){
    if (front == NULL )
    {
        cout<<"\nQueue is Empty"<<endl;
        return;
    }
    else
    {
        node*temp = front;
        cout<<"Deleted Element is "<<temp->data<<endl;
        front = front->link;
        delete(temp);
    }
    
}
void plistq ::display(){
     if (front == NULL )
    {
        cout<<"\nQueue is Empty"<<endl; 
    }
    node*t = front;
        while (t != NULL)
        {
             cout<<"\n"<<t->data;
             t= t->link;
        }
}
int main()
{
     int ch,n,p;
     plistq q;
     cout<<"\nENter a number and priority to append in linked list :";
     cin>>n>>p;
     q.append(n,p);
     cout<<"\nENter a number and priority to append in linked list :";
     cin>>n>>p;
     q.append(n,p);
   
        // cout<<"\nElements of linked list are :";
        // q.display();
        // q.del();
        cout<<"\nElements of linked list are :";
        q.display();
     return 0;
}