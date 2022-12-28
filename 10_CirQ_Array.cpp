#include <iostream>
using namespace std;

class CirQ
{
    // Initialize front and rear
    int rear, front;

    // Circular Queue
    int size;
    int *arr;

public:
    CirQ(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    void AddQ(int value);
    int delQ();
    void displayQ();
};

/* Function to create Circular queue */
void CirQ::AddQ(int value)
{
    if ((front == 0 && rear == size - 1) ||
        (rear == (front - 1) % (size - 1)))
    {
        cout << "\nQueue is Full" << endl;
        return;
    }

    else if (front == -1) /* Insert First Element */
    {
        front = rear = 0;
        arr[rear] = value;
    }

    else if (rear == size - 1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }

    else
    {
        rear++;
        arr[rear] = value;
    }
}

// Function to delete element from Circular Queue
int CirQ::delQ()
{
    if (front == -1)
    {
        cout << "\nQueue is Empty" << endl;
        return -1;
    }

    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size - 1)
        front = 0;
    else
        front++;

    return data;
}

// Function displaying the elements of Circular Queue
void CirQ::displayQ()
{
    if (front == -1)
    {
        cout << "\nQueue is Empty" << endl;
        return;
    }
    cout << "\nElements in Circular Queue are: " << endl;
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            cout << " " << arr[i] << endl;
    }
    else
    {
        for (int i = front; i < size; i++)
            cout << " " << arr[i] << endl;

        for (int i = 0; i <= rear; i++)
            cout << " " << arr[i] << endl;
    }
}

int main()
{
    int s;
    cout << "Enter size of Circular Queue" << endl;
    cin >> s;
    CirQ q(s);

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
            q.AddQ(num);
            break;
        case 2:
            cout << "Element deleted is  " << endl;

            num = q.delQ();
            cout << num;
            break;
        case 3:
            cout << "Elements are " << endl;
            q.displayQ();
            break;
        case 4:
            exit;
            break;
        default:
            cout << "Invalid Choice";
            break;
        }
    } while (ch != 4);

    return 0;
}
