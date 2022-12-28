#include <iostream>
using namespace std;
class Stack
{
    int size, top;
    int *ptr;

public:
    Stack()
    {
        cout << "Enter size of Stack" << endl;
        cin >> size;
        ptr = new int[size];
        top = -1;
    }
    void push(int);
    int pop();
    void Top();
    void empty();
    void displayData();
};

void Stack ::push(int x)
{
    if (top == size - 1)
    {
        cout << "Stack Overflow ! cannot Push element " << x << " in the stack " << endl;
    }
    else
    {
        ptr[++top] = x;
        cout << "Pushed " << x << " on index " << top << " of Stack ." << endl;
    }
}

void Stack ::displayData()
{

    cout << "Elements in Stack are \n";
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << " ";
    }
}
int Stack ::pop()
{
    int p;
    if (top == -1)
    {
        cout << "Stack Underflow ! cannot Pop element" << endl;
    }
    else
    {
        p = ptr[top--];
        cout << "Poped " << p << " from index  " << top + 1 << " of Stack ." << endl;
    }

    return p;
}
void Stack ::Top()
{
    if (top == -1)
    {
        cout << "No element in the Stack " << endl;
    }
    else
    {
        cout << "Top of Stack is " << ptr[top];
    }
}
void Stack ::empty()
{
    if (top == -1)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << " Stack is not Empty ";
    }
}
int main()
{
    Stack st;
    int ch, num;
    do
    {
        cout << "\n Choose an Option "
             << "\n 1 . Push an element"
             << "\n 2.  Pop an Element "
             << "\n 3.  Print Elements "
             << "\n 4.  Print Top of stack "
             << "\n 5.  Check Stack is empty Or Not"
             << "\n 6.  Exit  " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter element to be pushed" << endl;
            cin >> num;
            st.push(num);
            break;
        case 2:
            cout << "Element Poped is  " << endl;
            num = st.pop();
            cout << num;
            break;
        case 3:
            cout << "Elements are " << endl;
            st.displayData();
            break;
        case 4:

            st.Top();
            break;
            break;
        case 5:

            st.empty();
            break;

        default:
            cout << "Please choose a valid option " << endl;
            break;
        }
    } while (ch != 6);

    return 0;
}