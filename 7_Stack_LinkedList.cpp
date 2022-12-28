#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
};
class Stack
{
    node *tos;

public:
    Stack()
    {
        tos = NULL;
    }
    void push(int);
    int pop();
    void displayData();
    ~Stack();
};

void Stack ::push(int num)
{

    node *temp = new node;
    if (temp == NULL)
    {
        cout << "Stack is Full" << endl;
    }
    else
    {

        temp->data = num;
        temp->link = tos;
        tos = temp;
        cout << "Pushed " << num << " in the stack ."<< endl;
    }
}

int Stack ::pop()
{
    if (tos == NULL)
    {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    else
    {
        int item = tos->data;
        node *temp = tos;
        tos = tos->link;
        delete temp;
        return item;
    }
}
void Stack ::displayData(){
    if (tos == NULL)
    {
        cout << "Stack is Empty" << endl;
        return ;
    }
    else
    {
          cout << "Elements in Stack are \n";
     node * temp = tos;
     while (temp != NULL  )
     {
         cout<< " "<<temp->data;
         temp = temp->link;
     }
     
    }

}
Stack ::~Stack()
{
    node *temp;
    while (tos != NULL)
    {
        temp = tos;
        tos = tos->link;
        delete temp;
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
             << "\n 3.  Exit  " << endl;
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

        default:
            cout << "Please choose a valid option " << endl;
            break;
        }
    } while (ch != 4);
    return 0;
}
