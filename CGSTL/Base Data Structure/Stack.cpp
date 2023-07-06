#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *Next;
};

class Stack
{
    Node *head;
    Node *temp;
    int iCnt;

public:
    Stack()
    {
        head = NULL;
        temp = NULL;
        iCnt = 0;
    }

public:
    void Push(int iVal)
    {
        Node *new_node = new Node;
        if (head == NULL)
        {
            new_node->Next = NULL;
            head = new_node;
            new_node->val = iVal;
            iCnt++;
        }
        else
        {
            new_node->Next = head;
            new_node->val = iVal;
            head = new_node;
            iCnt++;
        }
    }

public:
    void Pop()
    {
        if (head == NULL)
        {
            cout << "Stack UnderFlow.\n";
        }
        else
        {
            temp = head;
            head = head->Next;
            delete (temp);
            iCnt--;
        }
    }

public:
    void isEmpty()
    {
        if (head == NULL)
        {
            cout << "Stack Empty.\n";
        }
        else
        {
            cout << "Stack not empty.\n";
        }
    }

public:
    int get_Top()
    {
        return head->val;
    }

public:
    int get_Size()
    {
        return iCnt;
    }

public:
    void Display()
    {
        temp = head;
        while (temp != NULL)
        {
            cout << "| " << temp->val << " | "
                 << " -> ";
            temp = temp->Next;
        }
        cout << " NULL\n";
    }
};

int main()
{
    Stack S;

    S.Push(1);
    S.Push(2);
    S.Push(3);
    S.Push(4);
    S.Push(5);
    S.Push(6);
    S.isEmpty();
    cout << S.get_Top() << endl;
    S.Display();
    S.Pop();
    S.Pop();
    S.Pop();
    S.Display();
    S.Pop();
    S.Pop();
    S.Pop();
    S.isEmpty();

    return 0;
}