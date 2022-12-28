#include <iostream>
using namespace std;

const int m = 5;
class Queue
{
    int arr[m], front, rear;

public:
    Queue() { front = rear = -1; }
    void addq(int);
    int delq();
    void Display();
};
void Queue ::addq(int item)
{
    if (rear == m - 1)
    {
        cout << "Queue is Full." << endl;
    }
    else
    {
        rear++;
        arr[rear] = item;
        if (front == -1)
            front = 0;
    }
}
int Queue ::delq()
{
    int data;
    if (front == -1 || front>rear)
    {
        cout << "Queue is Empty." << endl;
        return -1;
    }
    data = arr[front];
    arr[front] = 0;
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
        return data;
}
void   Queue ::Display()
{
   if (front == -1)
      cout << "\nQueue is empty" << endl;
   else
   {
      cout << "\nQueue elements are : ";
      for (int i = front; i <= rear; i++)
         cout << arr[i] << " ";
      cout << endl;
   }
}
int main()
{
       Queue q1;
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
            q1.addq(num);
            break;
        case 2:
            cout << "Element deleted is  " << endl;

            num = q1.delq();
            cout << num;
            break;
        case 3:
            cout << "Elements are " << endl;
            q1.Display();
            break;

        default:
            cout << "Please choose a valid option " << endl;
            break;
        }
    } while (ch != 4);

    return 0;
}