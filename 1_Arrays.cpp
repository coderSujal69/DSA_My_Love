#include <iostream>
using namespace std;

class array
{
    int size;
    int data;
    int *p = new int[size];

public:
    void getdata()
    {
        cout << "Enter Size" << endl;
        cin >> size;
        cout << "Enter elements" << endl;
        for (int i = 0; i < size; i++) 
        {
            cin >> p[i];
        }
    }
    void printdata()
    {
        cout << "Elements are" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << p[i] << endl;
        }
    }
    void sort()
    {
        int temp;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size-1-i; j++)
            {

                if (p[j] > p[j + 1])
                {
                    temp = p[j];
                    p[j] = p[j + 1];
                    p[j + 1] = temp;
                }
            }
        }

        cout << "Elements in Ascending order is " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << p[i] << endl;
        }
    }
    void SearchElement()
    {
        int key, i;
        bool flag = false;
        cout << "Enter element to Search" << endl;
        cin >> key;
        for (i = 0; i < size; i++)
        {
            if (key == p[i])
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            cout << "Elemnent " << key << " Found on " << i + 1 << " position" << endl;
        }
        else
        {
            cout << "Elemnet is Not Present in the Array" << endl;
        }
    } 
void reverseArray( int start, int end)
{
    while (start < end)
    {
        int temp = p[start];
        p[start] = p[end];
        p[end] = temp;
        start++;
        end--;
    }

    }
  
    ~array()
    {
        cout << "Destructer called" << endl;
        delete p;
    }
};
int main()
{
    array a1;
    a1.getdata();
    // a1.sort();
    // a1.SearchElement();
    // array a2 = a1;
    // a2.printdata();
    // a1.reverseArray(0,4);
    a1.printdata();
    return 0;
}