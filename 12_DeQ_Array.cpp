#include <iostream>
using namespace std;
const int mx = 10;
class dq
{

    int arr[mx], front, rear;

public:
    dq() { front = rear = -1; }
    void addAtFront(int);
    void addAtRear(int);
    int delFromFront();
    int delFromEnd();
};
void dq ::addAtFront(int item)
{
    if (front == 0)
    {
        cout << "No space at front" << endl;
    }
    else if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        front--;
        arr[front] = item;
    }
}
void dq ::addAtRear(int item)
{
    if (rear = mx - 1)
    {
        cout << "Queue is full !" << endl;
    }
    else
    {
        rear++;
        arr[rear] = item;
        if (front == -1)
        {
            front++;
        }
    }
}
int dq ::delFromFront()
{
    int data;
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    else
    {
        data = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
            return data;
        }
    }
}
int dq ::delFromEnd()
{
    int data;
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    data = arr[rear];

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear--;
        return data;
    }
}
int main()
{

    return 0;
}
