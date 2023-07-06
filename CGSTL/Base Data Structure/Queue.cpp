#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int ival;
    Node *Next;
    Node *Prev;
};

class Queue
{
    Node *head;
    Node *Front;
    Node *Rear;
    Node *temp;
    int iCnt;

public:
    Queue()
    {
        Front = NULL;
        Rear = NULL;
        iCnt = 0;
    }

public:
    void Enqueue(int iVal)
    {
        Node *new_node = new Node;
        new_node->Next = NULL;
        new_node->Prev = NULL;
        if (Rear == NULL)
        {
            new_node->ival = iVal;
            Front = new_node;
            Rear = new_node;
            iCnt++;
        }
        else
        {
            new_node->Next = Rear;
            Rear->Prev = new_node;
            new_node->ival = iVal;
            Rear = new_node;
            iCnt++;
        }
    }

public:
    void Dequeue()
    {
        temp = Front;
        if (temp->Prev == NULL)
        {
            Front = NULL;
            Rear = NULL;
            delete (temp);
        }
        else
        {
            Front = temp->Prev;
            Front->Next = NULL;
            delete (temp);
        }
    }

public:
    int get_Front()
    {
        if (Front != NULL)
        {
            return Front->ival;
        }
        else
        {
            return 1;
        }
    }

public:
    int get_Rear()
    {
        if (Rear != NULL)
        {
            return Rear->ival;
        }
        else
        {
            return 1;
        }
    }

public:
    int get_Count()
    {
        return iCnt;
    }

public:
    void Display()
    {
        if (Rear == NULL)
        {
            cout << "Queue is empty.\n";
            return;
        }
        Node *temp = Rear;
        while (temp != NULL)
        {
            cout << "| " << temp->ival << " | "
                 << " -> ";
            temp = temp->Next;
        }
        cout << " NULL\n";
    }
};

int main()
{
    Queue Q1;

    Q1.Enqueue(1);
    Q1.Enqueue(2);
    Q1.Enqueue(3);
    Q1.Enqueue(4);

    Q1.Display();

    Q1.Enqueue(5);
    Q1.Enqueue(6);

    Q1.Display();

    cout << Q1.get_Front() << endl
         << Q1.get_Rear() << endl
         << Q1.get_Count() << endl;

    Q1.Dequeue();
    Q1.Dequeue();
    Q1.Dequeue();

    Q1.Display();

    Q1.Dequeue();
    Q1.Dequeue();

    Q1.Display();

    Q1.Dequeue();

    return 0;
}