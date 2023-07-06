#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int Val;
    Node *Next;
};

class SinglyLinearList
{
    Node *head;
    Node *temp;
    Node *temp1;
    int Count;

public:
    SinglyLinearList()
    {
        head = NULL;
        temp = NULL;
        Count = 0;
    }

    void InsertFirst(int value)
    {
        Node *new_node = new Node;
        new_node->Val = value;
        new_node->Next = NULL;
        Count++;

        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            new_node->Next = head;
            head = new_node;
        }
    }

    void InsertLast(int value)
    {
        Node *new_node = new Node;
        new_node->Val = value;
        new_node->Next = NULL;
        Count++;

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
            cout << "Linked List Empty !!\n";
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
            cout << "Linked List Empty !!\n";
        }
        if (head != NULL && head->Next == NULL)
        {
            head = NULL;
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

        cout << temp->Val << endl;

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
        return Count;
    }
};

int main()
{
    SinglyLinearList L;

    L.InsertFirst(10);
    L.InsertLast(30);
    L.InsertFirst(20);

    L.Display();

    L.DeleteFirst();

    L.Display();

    L.DeleteLast();

    L.Display();

    L.InsertatPOS(20, 1);
    L.InsertatPOS(100, 0);
    L.InsertatPOS(200, 2);
    L.InsertatPOS(300, 6);

    cout << L.get_Count() << endl;

    L.Display();

    L.DeletefromPOS(2);

    L.Display();
}