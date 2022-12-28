#include <iostream>
using namespace std;
struct node
{
    int data;
    node *link;
};
class Q_Linked
{
    node *front, *rear;

public:
    Q_Linked() { front = rear = NULL; }
    void add(int);
    int delq();
    void print();
    ~Q_Linked();
};
void Q_Linked ::add(int item)
{
    node *temp = new node;
    temp->data = item;
    temp->link = NULL;
    if (rear == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    }
}
int Q_Linked ::delq()
{
    if (front == NULL)
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    else
    {
        int num = front->data;
        node *temp = front;
        if (front->link = NULL)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->link;
            delete temp;
        }

        return num;
    }
}
void Q_Linked ::print()
{

    node *temp = front;
    if (temp == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    do
    {
        cout << " " << temp->data;
        temp = temp->link;
    } while (temp != NULL);
}
Q_Linked ::~Q_Linked()
{
    node *temp;
    while (front != NULL)
    {
        temp = front;
        front = front->link;
        delete temp;
    }
}
int main()
{
    Q_Linked q1;
    int ch, num;
    do
    {
        cout << "\n Choose an Option "
             << "\n 1 . Add an element"
             << "\n 2.  Delete an Element "
             << "\n 3.  Print Elements "
             << "\n 4.  Exit  " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter element to be added " << endl;
            cin >> num;
            q1.add(num);
            break;
        case 2:
            cout << "Element deleted is  " << endl;

            num = q1.delq();
            cout << num;
            break;
        case 3:
            cout << "Elements are " << endl;
            q1.print();
            break;

     
        }
    } while (ch != 4);

    return 0;
}