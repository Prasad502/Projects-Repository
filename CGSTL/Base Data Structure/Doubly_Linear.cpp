#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int Val;
    Node *Next;
    Node *Prev;
};

class DoublyLinearList
{
    Node *head;
    Node *temp;
    Node *temp1;
    Node *Tail;
    int count;

public:
    DoublyLinearList()
    {
        head = NULL;
        temp = NULL;
        count = 0;
    }

    void InsertFirst(int Value)
    {
        Node *new_node = new Node;
        new_node->Val = Value;
        new_node->Next = NULL;
        new_node->Prev = NULL;
        Tail = new_node;
        count++;

        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            head->Prev = new_node;
            new_node->Next = head;
            head = new_node;
        }
    }

    void InsertLast(int Value)
    {
        Node *new_node = new Node;
        new_node->Val = Value;
        new_node->Next = NULL;
        new_node->Prev = NULL;
        Tail = new_node;
        count++;

        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            temp = head;
            while (temp->Next != NULL)
            {
                temp = temp->Next;
            }
            temp->Next = new_node;
            new_node->Prev = temp;
        }
    }

    void InsertatPOS(int value, int index)
    {
        temp = head;
        Node *new_node = new Node;
        new_node->Val = value;
        new_node->Next = NULL;
        int i = 0;

        if (index == 0)
        {
            InsertFirst(value);
            return;
        }

        while (i < index - 1)
        {
            if (temp->Next != NULL)
            {
                temp = temp->Next;
                i++;
            }
            else
            {
                cout << "Index out of Bound !!\n";
                return;
            }
        }

        new_node->Next = temp->Next;
        temp->Next = new_node;
    }

    void DeleteFirst()
    {
        if (head == NULL)
        {
            cout << "Linked List already Empty...\n";
            return;
        }
        else if (head->Next == NULL)
        {
            delete (head);
            return;
        }
        else
        {
            temp = head;
            head = head->Next;
            delete (temp);
        }
    }

    void DeleteLast()
    {
        if (head == NULL)
        {
            cout << "Linked List already Empty...\n";
            return;
        }
        else if (head->Next == NULL)
        {
            delete (head);
            return;
        }
        else
        {
            temp = head;
            while (temp->Next->Next != NULL)
            {
                temp = temp->Next;
            }
            delete (temp->Next);
            temp->Next = NULL;
        }
    }

    void DeletefromPOS(int index)
    {
        temp = head;

        if (index == 0)
        {
            temp->Next = head;
            delete (temp);
            return;
        }

        int i = 0;

        while (index > 0 && i < index - 1)
        {
            temp = temp->Next;
            i++;
        }

        temp1 = temp->Next;
        temp->Next = temp->Next->Next;
        delete (temp1);
    }

    void Display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << "| " << temp->Val << " | "
                 << " -> ";
            temp = temp->Next;
        }

        cout << " NULL\n";
    }

    int get_Count()
    {
        return count;
    }
};

int main()
{
    DoublyLinearList DL;

    DL.InsertFirst(10);
    DL.InsertFirst(20);
    DL.InsertFirst(30);
    DL.InsertFirst(40);
    DL.InsertFirst(50);

    DL.Display();

    DL.InsertLast(60);
    DL.Display();

    DL.InsertatPOS(70, 2);
    DL.InsertatPOS(80, 3);

    DL.Display();

    DL.DeleteFirst();
    DL.Display();

    DL.DeleteLast();
    DL.Display();

    DL.DeletefromPOS(3);
    DL.Display();

    return 0;
}