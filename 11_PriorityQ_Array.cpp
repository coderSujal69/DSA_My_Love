#include <iostream>
using namespace std;

struct data
{
    int p, d;
};
const int mx = 10;
class pque
{
    struct data d[mx];
    int front, rear;
public:
    pque();
    void add( struct data dt);
    struct data rearone();
    void sort();
};
pque ::pque()
{

    front = rear = -1;
}
void pque ::add(struct data dt)
{
    if (rear = mx - 1)
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        rear++;
        d[rear] = dt;
        if (front == -1)
        {
            front = 0;
        }
        sort();
    }
}
void pque ::sort()
{

    struct  data temp;
    for (int i = front; i <= rear; i++)
    {
        for (int j = i + 1; j <= rear; j++)
        {
            if (d[i].p <= d[j].p)
            {
                temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }
}
struct data pque ::rearone()
{
    struct data t;
    t.p = 0;
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
        return t;
    }
    struct data temp;
    temp = d[front];
    d[front] = t;
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }

    return temp;
}
int main()
{
    pque q;
    struct  data dt;
    int j =0;
    cout<<"Enter data with Priority"<<endl;
    struct data dd;
    cin>>dd.d>>dd.p;
    q.add(dd);
    cout<<"Enter data with Priority"<<endl;  
    cin>>dd.d>>dd.p;
    q.add(dd);
    dt=q.rearone();


    return 0;
}