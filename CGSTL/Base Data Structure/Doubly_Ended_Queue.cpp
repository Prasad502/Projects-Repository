#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int ival;
    Node *Next;
    Node *Prev;
};

class Doubly_Ended_Queue
{
    Node *head;
    Node *Front;
    Node *Rear;
    Node *temp;
    int iCnt;
    int iSize;

public:
    Doubly_Ended_Queue()
    {
        Front = NULL;
        Rear = NULL;
        iCnt = 0;
    }

public:
    void Insert_Front(int iVal)
    {
        Node *new_node = new Node;
        new_node->Next = NULL;
        new_node->Prev = NULL;

        if (Front == NULL)
        {
            new_node->ival = iVal;
            Front = new_node;
            Rear = new_node;
            iCnt++;
        }
        else
        {
            Front->Next = new_node;
            new_node->Prev = Front;
            new_node->ival = iVal;
            Front = new_node;
            iCnt++;
        }
    }

public:
    void Insert_Rear(int iVal)
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
    void Delete_Front()
    {
        if (Front == NULL)
        {
            cout << "Queue UnderFlow.\n";
        }
        else
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
    }

public:
    void Delete_Rear()
    {
        if (Front == NULL)
        {
            cout << "Queue UnderFlow.\n";
        }
        else
        {
            temp = Rear;
            if (temp->Next == NULL)
            {
                Front = NULL;
                Rear = NULL;
                delete (temp);
            }
            else
            {
                Rear = temp->Next;
                Rear->Prev = NULL;
                delete (temp);
            }
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
    Doubly_Ended_Queue Q1;

    Q1.Insert_Front(1);
    Q1.Insert_Front(2);
    Q1.Insert_Front(3);
    Q1.Insert_Front(4);

    Q1.Display();

    Q1.Insert_Rear(5);
    Q1.Insert_Rear(6);
    Q1.Insert_Rear(7);

    Q1.Display();

    cout << Q1.get_Front() << endl
         << Q1.get_Rear() << endl
         << Q1.get_Count() << endl;

    Q1.Delete_Front();
    Q1.Delete_Front();
    Q1.Delete_Front();

    Q1.Display();

    Q1.Delete_Rear();
    Q1.Delete_Rear();

    Q1.Display();

    Q1.Delete_Rear();

    return 0;
}