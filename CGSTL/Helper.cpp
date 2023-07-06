#include <iostream>
#include "CGSTL.h"
//-----------------------------------------------------------------------
// Function Defination of Singly Linear Linked List
//-----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////
//
// Constructor name:  SinglyLinearList
// Input:          Initialization of variables.
// Output:         Variable initialized.
// Description:    Used to initialize variables.
//
///////////////////////////////////////////////////////////////////////

template <class T>
SinglyLinearList<T>::SinglyLinearList()
{
    head = NULL;
    temp = NULL;
    Count = 0;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  Display
// Input:            -
// Output:         Display linked list.
// Description:    Used to display linked list.
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLinearList<T>::Display()
{
    Node<T> *temp = head;

    while (temp != NULL)
    {
        cout << "| " << temp->ival << " | "
             << " -> ";
        temp = temp->Next;
    }

    cout << " NULL\n";
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  Count
// Input:            -
// Output:         Return linked list element count.
// Description:    Used to return linked list element count.
//
///////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLinearList<T>::get_Count()
{
    return Count;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  InsertFirst
// Input:          Generic datatype element
// Output:         Insert element at position first in linked list.
// Description:    Used to insert element at position first in linked list
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLinearList<T>::InsertFirst(T value)
{
    Node<T> *new_node = new Node<T>;
    new_node->ival = value;
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

///////////////////////////////////////////////////////////////////////
//
// Function name:  InsertLast
// Input:          Generic datatype element
// Output:         Insert element at position last in linked list.
// Description:    Used to insert element at position last in linked list
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLinearList<T>::InsertLast(T value)
{
    Node<T> *new_node = new Node<T>;
    new_node->ival = value;
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

/////////////////////////////////////////////////////////////////////////////
//
// Function name:  InsertAtPos
// Input:          Generic datatype element, Integer
// Output:         Insert element at position first in linked list.
// Description:    Used to insert element at position first in linked list
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLinearList<T>::InsertatPOS(T value, int index)
{
    temp = head;
    Node<T> *new_node = new Node<T>;
    new_node->ival = value;
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

///////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteFirst
// Input:               -
// Output:         Delete element from first position in linked list.
// Description:    Used to delete element from first position in linked list
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLinearList<T>::DeleteFirst()
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

////////////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteLast
// Input:               -
// Output:         Delete element from last position in linked list.
// Description:    Used to delete element from last position in linked list
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLinearList<T>::DeleteLast()
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

////////////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteAtPos
// Input:          Integer
// Output:         Delete element from desire position in linked list.
// Description:    Used to delete element from desire position in linked list
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLinearList<T>::DeletefromPOS(int index)
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

    cout << temp->ival << endl;

    temp1 = temp->Next;
    temp->Next = temp->Next->Next;
    delete (temp1);
}

//-----------------------------------------------------------------------
// Function Defination of Doubly Linear Linked List
//-----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////
//
// Constructor name:  DoublyLinearList
// Input:          Initialization of variables.
// Output:         Variable initialized.
// Description:    Used to initialize variables.
//
///////////////////////////////////////////////////////////////////////

template <class T>
DoublyLinearList<T>::DoublyLinearList()
{
    head = NULL;
    temp = NULL;
    count = 0;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  Display
// Input:            -
// Output:         Display linked list.
// Description:    Used to display linked list.
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLinearList<T>::Display()
{
    Node<T> *temp = head;

    while (temp != NULL)
    {
        cout << "| " << temp->ival << " | "
             << " -> ";
        temp = temp->Next;
    }

    cout << " NULL\n";
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  Count
// Input:            -
// Output:         Return linked list element count.
// Description:    Used to return linked list element count.
//
///////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLinearList<T>::get_Count()
{
    return count;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  InsertFirst
// Input:          Generic datatype element
// Output:         Insert element at position first in linked list.
// Description:    Used to insert element at position first in linked list
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLinearList<T>::InsertFirst(T Value)
{
    Node<T> *new_node = new Node<T>;
    new_node->ival = Value;
    new_node->Next = NULL;
    new_node->Prev = NULL;

    if (head == NULL)
    {
        head = new_node;
        count++;
    }
    else
    {
        head->Prev = new_node;
        new_node->Next = head;
        head = new_node;
        count++;
    }
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  InsertLast
// Input:          Generic datatype element
// Output:         Insert element at position last in linked list.
// Description:    Used to insert element at position last in linked list
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLinearList<T>::InsertLast(T Value)
{
    Node<T> *new_node = new Node<T>;
    new_node->ival = Value;
    new_node->Next = NULL;
    new_node->Prev = NULL;

    if (head == NULL)
    {
        head = new_node;
        count++;
    }
    else
    {
        temp = head;
        int i = 0;
        while (temp->Next != NULL)
        {
            if (i < count)
            {
                temp = temp->Next;
                i++;
            }
            else
            {
                break;
            }
        }
        temp->Next = new_node;
        new_node->Prev = temp;
        count++;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
// Function name:  InsertAtPos
// Input:          Generic datatype element, Integer
// Output:         Insert element at position first in linked list.
// Description:    Used to insert element at position first in linked list
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLinearList<T>::InsertatPOS(int index, T value)
{
    temp = head;
    Node<T> *new_node = new Node<T>;
    new_node->ival = value;
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
    count++;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteFirst
// Input:               -
// Output:         Delete element from first position in linked list.
// Description:    Used to delete element from first position in linked list
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLinearList<T>::DeleteFirst()
{
    if (head == NULL)
    {
        cout << "Linked List already Empty...\n";
        return;
    }
    else if (head->Next == NULL)
    {
        delete (head);
        count--;
        return;
    }
    else
    {
        temp = head;
        head = head->Next;
        delete (temp);
        count--;
    }
}

////////////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteLast
// Input:               -
// Output:         Delete element from last position in linked list.
// Description:    Used to delete element from last position in linked list
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLinearList<T>::DeleteLast()
{
    if (head == NULL)
    {
        cout << "Linked List already Empty...\n";
        return;
    }
    else if (head->Next == NULL)
    {
        delete (head);
        count--;
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
        count--;
        temp->Next = NULL;
    }
}

////////////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteAtPos
// Input:          Integer
// Output:         Delete element from desire position in linked list.
// Description:    Used to delete element from desire position in linked list
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLinearList<T>::DeletefromPOS(int index)
{
    temp = head;

    if (index >= count)
    {
        cout << "Index out of Bounds.\n";
        return;
    }

    if (index == 0)
    {
        head->Next = head;
        delete (temp);
        count--;
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
    count--;
}

//-----------------------------------------------------------------------
// Function Defination of Singly Circular Linked List
//-----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////
//
// Constructor name:  SinglyCircularList
// Input:          Initialization of variables.
// Output:         Variable initialized.
// Description:    Used to initialize variables.
//
///////////////////////////////////////////////////////////////////////

template <class T>
SinglyCircularList<T>::SinglyCircularList()
{
    head = NULL;
    temp = NULL;
    Count = 0;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  Display
// Input:            -
// Output:         Display linked list.
// Description:    Used to display linked list.
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCircularList<T>::Display()
{
    Node<T> *temp = head;
    int i = 0;

    while (temp != NULL)
    {
        if (i < Count)
        {
            cout << "| " << temp->ival << " | "
                 << " -> ";
            temp = temp->Next;
            i++;
        }
        else
        {
            break;
        }
    }

    cout << " NULL\n";
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  Count
// Input:            -
// Output:         Return linked list element count.
// Description:    Used to return linked list element count.
//
///////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCircularList<T>::get_Count()
{
    return Count;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  InsertFirst
// Input:          Generic datatype element
// Output:         Insert element at position first in linked list.
// Description:    Used to insert element at position first in linked list
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCircularList<T>::InsertFirst(T value)
{
    Node<T> *new_node = new Node<T>;
    new_node->ival = value;
    new_node->Next = NULL;

    if (head == NULL)
    {
        head = new_node;
        head->Next = head;
        Count++;
    }
    else
    {
        new_node->Next = head;
        head = new_node;
        Count++;
    }
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  InsertLast
// Input:          Generic datatype element
// Output:         Insert element at position last in linked list.
// Description:    Used to insert element at position last in linked list
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCircularList<T>::InsertLast(T value)
{
    Node<T> *new_node = new Node<T>;
    new_node->ival = value;
    new_node->Next = NULL;

    if (head == NULL)
    {
        head = new_node;
        head->Next = head;
        Count++;
    }
    else
    {
        temp = head;
        int i = 0;
        while (temp->Next != NULL)
        {
            if (i < Count)
            {
                temp = temp->Next;
                i++;
            }
            else
            {
                break;
            }
        }
        temp->Next = new_node;
        new_node->Next = head;
        cout << endl
             << head->ival << " " << temp->ival << endl;
        Count++;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
// Function name:  InsertAtPos
// Input:          Generic datatype element, Integer
// Output:         Insert element at position first in linked list.
// Description:    Used to insert element at position first in linked list
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCircularList<T>::InsertatPOS(int index, T value)
{
    if (Count < index + 1)
    {
        cout << "Index out of bounds!.\n";
        return;
    }

    temp = head;
    Node<T> *new_node = new Node<T>;
    new_node->ival = value;
    new_node->Next = NULL;
    int i = 0;

    if (index == 0)
    {
        InsertFirst(value);
        return;
    }

    while (i < index - 1)
    {
        if (i < Count - 1)
        {
            temp = temp->Next;
            i++;
        }
        else
        {
            break;
        }
    }
    new_node->Next = temp->Next;
    temp->Next = new_node;
    Count++;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteFirst
// Input:               -
// Output:         Delete element from first position in linked list.
// Description:    Used to delete element from first position in linked list
//
///////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCircularList<T>::DeleteFirst()
{
    if (head == NULL)
    {
        cout << "Linked List Empty !!\n";
    }
    else
    {
        temp = head;
        head = head->Next;
        Count--;
        delete (temp);
    }
}

////////////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteLast
// Input:               -
// Output:         Delete element from last position in linked list.
// Description:    Used to delete element from last position in linked list
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCircularList<T>::DeleteLast()
{
    if (head == NULL)
    {
        cout << "Linked List Empty !!\n";
    }
    else if (head != NULL && head->Next == NULL)
    {
        head = NULL;
    }
    else
    {
        temp = head;
        int i = 0;
        while (temp->Next->Next != NULL)
        {
            if (i < Count)
            {
                temp = temp->Next;
                i++;
            }
            else
            {
                break;
            }
        }
        Count--;
        delete (temp->Next);
        temp->Next = head;
    }
}

////////////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteAtPos
// Input:          Integer
// Output:         Delete element from desire position in linked list.
// Description:    Used to delete element from desire position in linked list
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCircularList<T>::DeletefromPOS(int index)
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
    Count--;
    delete (temp1);
}

//-----------------------------------------------------------------------
// Function Defination of Doubly Circuler Linked List
//-----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////
//
// Constructor name:  DoublyCircularList
// Input:          Initialization of variables.
// Output:         Variable initialized.
// Description:    Used to initialize variables.
//
///////////////////////////////////////////////////////////////////////

template <class T>
DoublyCircularList<T>::DoublyCircularList()
{
    head = NULL;
    temp = NULL;
    Count = 0;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  Display
// Input:            -
// Output:         Display linked list.
// Description:    Used to display linked list.
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCircularList<T>::Display()
{
    Node<T> *temp = head;
    int i = 0;

    while (temp != NULL)
    {
        if (i < Count)
        {
            cout << "| " << temp->ival << " | "
                 << " -> ";
            temp = temp->Next;
            i++;
        }
        else
        {
            break;
        }
    }

    cout << " Back to First Node\n";
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  Count
// Input:            -
// Output:         Return linked list element count.
// Description:    Used to return linked list element count.
//
///////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCircularList<T>::get_Count()
{
    return Count;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  InsertFirst
// Input:          Generic datatype element
// Output:         Insert element at position first in linked list.
// Description:    Used to insert element at position first in linked list
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCircularList<T>::InsertFirst(T value)
{
    Node<T> *new_node = new Node<T>;
    new_node->ival = value;
    new_node->Next = NULL;
    new_node->Prev = NULL;

    if (head == NULL)
    {
        head = new_node;
        Count++;
    }
    else
    {
        new_node->Next = head;
        head = new_node;
        Count++;
    }
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  InsertLast
// Input:          Generic datatype element
// Output:         Insert element at position last in linked list.
// Description:    Used to insert element at position last in linked list
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCircularList<T>::InsertLast(T value)
{
    Node<T> *new_node = new Node<T>;
    new_node->ival = value;
    new_node->Next = NULL;
    new_node->Prev = NULL;

    if (head == NULL)
    {
        head = new_node;
        Count++;
    }
    else
    {
        temp = head;
        int i = 0;
        while (temp->Next != NULL)
        {
            if (i < Count)
            {
                temp = temp->Next;
                i++;
            }
            else
            {
                break;
            }
        }
        temp->Next = new_node;
        new_node->Next = head;
        new_node->Prev = temp;
        Count++;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
// Function name:  InsertAtPos
// Input:          Generic datatype element, Integer
// Output:         Insert element at position first in linked list.
// Description:    Used to insert element at position first in linked list
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCircularList<T>::InsertatPOS(T value, int index)
{
    if (Count < index + 1)
    {
        cout << "Index out of bounds!.\n";
        return;
    }

    temp = head;
    Node<T> *new_node = new Node<T>;
    new_node->ival = value;
    new_node->Next = NULL;
    new_node->Prev = NULL;
    int i = 0;

    if (index == 0)
    {
        InsertFirst(value);
        return;
    }

    while (i < index - 1)
    {
        if (i < Count - 1)
        {
            temp = temp->Next;
            i++;
        }
        else
        {
            break;
        }
    }
    new_node->Next = temp->Next;
    temp->Next = new_node;
    new_node->Prev = temp;
    Count++;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteFirst
// Input:               -
// Output:         Delete element from first position in linked list.
// Description:    Used to delete element from first position in linked list
//
///////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCircularList<T>::DeleteFirst()
{
    if (head == NULL)
    {
        cout << "Linked List Empty !!\n";
    }
    else
    {
        temp = head;
        head = head->Next;
        Count--;
        delete (temp);
    }
}

////////////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteLast
// Input:               -
// Output:         Delete element from last position in linked list.
// Description:    Used to delete element from last position in linked list
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCircularList<T>::DeleteLast()
{
    if (head == NULL)
    {
        cout << "Linked List Empty !!\n";
    }
    else if (head != NULL && head->Next == NULL)
    {
        head = NULL;
    }
    else
    {
        temp = head;
        int i = 0;
        while (temp->Next->Next != NULL)
        {
            if (i < Count)
            {
                temp = temp->Next;
                i++;
            }
            else
            {
                break;
            }
        }
        Count--;
        delete (temp->Next);
        temp->Next = head;
    }
}

////////////////////////////////////////////////////////////////////////////
//
// Function name:  DeleteAtPos
// Input:          Integer
// Output:         Delete element from desire position in linked list.
// Description:    Used to delete element from desire position in linked list
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCircularList<T>::DeletefromPOS(int index)
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
    Count--;
    delete (temp1);
}

//-----------------------------------------------------------------------
// Function Defination Prototype of Stack using Linked List
//-----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////
//
// Constructor name:  Stack
// Input:          Initialization of variables.
// Output:         Variable initialized.
// Description:    Used to initialize variables.
//
///////////////////////////////////////////////////////////////////////

template <class T>
Stack<T>::Stack()
{
    head = NULL;
    temp = NULL;
    iCnt = 0;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  Display
// Input:            -
// Output:         Used to display stack elements.
// Description:    Display stack elements.
//
///////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T>::Display()
{
    temp = head;
    while (temp != NULL)
    {
        cout << "| " << temp->ival << " | "
             << " -> ";
        temp = temp->Next;
    }
    cout << " NULL\n";
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  Count
// Input:            -
// Output:         Used to return stack element count.
// Description:    Return stack element count.
//
///////////////////////////////////////////////////////////////////////

template <class T>
int Stack<T>::get_Size()
{
    return iCnt;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  push
// Input:          Generic datatype element
// Output:         Used to insert element in stack.
// Description:    Insert element in stack.
//
///////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T>::Push(T iVal)
{
    Node<T> *new_node = new Node<T>;
    if (head == NULL)
    {
        new_node->Next = NULL;
        head = new_node;
        new_node->ival = iVal;
        iCnt++;
    }
    else
    {
        new_node->Next = head;
        new_node->ival = iVal;
        head = new_node;
        iCnt++;
    }
}

////////////////////////////////////////////////////////////////////////////
//
// Function name:  pop
// Input:               -
// Output:         Delete element from stack.
// Description:    Used to delete element from stack.
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T>::Pop()
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

////////////////////////////////////////////////////////////////////////////
//
// Function name:  isEmpty
// Input:               -
// Output:         Stack Empty / Stack not Empty.
// Description:    Check if Stack is Empty.
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T>::isEmpty()
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

//-----------------------------------------------------------------------
// Function Defination Prototype of Queue using Linked List
//-----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////
//
// Constructor name:  Queue
// Input:          Initialization of variables.
// Output:         Variable initialized.
// Description:    Used to initialize variables.
//
///////////////////////////////////////////////////////////////////////

template <class T>
Queue<T>::Queue()
{
    Front = NULL;
    Rear = NULL;
    iCnt = 0;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  Queue
// Input:            -
// Output:         Used to display queue elements.
// Description:    Display queue elements.
//
///////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T>::Display()
{
    if (Rear == NULL)
    {
        cout << "Queue is empty.\n";
        return;
    }
    Node<T> *temp = Rear;
    while (temp != NULL)
    {
        cout << "| " << temp->ival << " | "
             << " -> ";
        temp = temp->Next;
    }
    cout << " NULL\n";
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  Count
// Input:            -
// Output:         Used to return queue element count.
// Description:    Return queue element count.
//
///////////////////////////////////////////////////////////////////////

template <class T>
int Queue<T>::get_Count()
{
    return iCnt;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  Enqueue
// Input:          Generic datatype element
// Output:         Used to insert element in queue.
// Description:    Insert element in queue.
//
///////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T>::Enqueue(T iVal)
{
    Node<T> *new_node = new Node<T>;
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

////////////////////////////////////////////////////////////////////////////
//
// Function name:  Dequeue
// Input:               -
// Output:         Delete element from queue.
// Description:    Used to delete element from queue.
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T>::Dequeue()
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

//-------------------------------------------------------------------------
// Function Defination Prototype of Doubly Ended Queue using Linked List
//-------------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////
//
// Constructor name:  Doubly_Ended_Queue
// Input:          Initialization of variables.
// Output:         Variable initialized.
// Description:    Used to initialize variables.
//
///////////////////////////////////////////////////////////////////////

template <class T>
Doubly_Ended_Queue<T>::Doubly_Ended_Queue()
{
    Front = NULL;
    Rear = NULL;
    iCnt = 0;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  Insert_Front
// Input:            -
// Output:         Used to insert queue elements at front.
// Description:    Insert queue elements at front.
//
///////////////////////////////////////////////////////////////////////

template <class T>
void Doubly_Ended_Queue<T>::Insert_Front(T iVal)
{
    Node<T> *new_node = new Node<T>;
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

///////////////////////////////////////////////////////////////////////
//
// Function name:  Insert_Rear
// Input:            -
// Output:         Used to insert queue elements at rear.
// Description:    Insert queue elements at rear.
//
///////////////////////////////////////////////////////////////////////

template <class T>
void Doubly_Ended_Queue<T>::Insert_Rear(T iVal)
{
    Node<T> *new_node = new Node<T>;
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

///////////////////////////////////////////////////////////////////////
//
// Function name:  Delete_Front
// Input:            -
// Output:         Used to Delete queue elements at front.
// Description:    Delete queue elements at front.
//
///////////////////////////////////////////////////////////////////////

template <class T>
void Doubly_Ended_Queue<T>::Delete_Front()
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

///////////////////////////////////////////////////////////////////////
//
// Function name:  Delete_Rear
// Input:            -
// Output:         Used to delete queue elements at rear.
// Description:    Delete queue elements at rear.
//
///////////////////////////////////////////////////////////////////////

template <class T>
void Doubly_Ended_Queue<T>::Delete_Rear()
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

///////////////////////////////////////////////////////////////////////
//
// Function name:  get_Count
// Input:            -
// Output:         Used to display queue element count.
// Description:    Display queue element count.
//
///////////////////////////////////////////////////////////////////////

template <class T>
int Doubly_Ended_Queue<T>::get_Count()
{
    return iCnt;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:  Display
// Input:            -
// Output:         Used to display queue elements.
// Description:    Display queue elements.
//
///////////////////////////////////////////////////////////////////////

template <class T>
void Doubly_Ended_Queue<T>::Display()
{
    if (Rear == NULL)
    {
        cout << "Queue is empty.\n";
        return;
    }
    Node<T> *temp = Rear;
    while (temp != NULL)
    {
        cout << "| " << temp->ival << " | "
             << " -> ";
        temp = temp->Next;
    }
    cout << " NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////////
template class SinglyLinearList<int>;
template class SinglyLinearList<double>;
template class SinglyLinearList<float>;
template class SinglyLinearList<char>;
template class SinglyLinearList<std ::string>;

template class DoublyLinearList<int>;
template class DoublyLinearList<double>;
template class DoublyLinearList<float>;
template class DoublyLinearList<char>;
template class DoublyLinearList<std ::string>;

template class SinglyCircularList<int>;
template class SinglyCircularList<double>;
template class SinglyCircularList<float>;
template class SinglyCircularList<char>;
template class SinglyCircularList<std ::string>;

template class DoublyCircularList<int>;
template class DoublyCircularList<double>;
template class DoublyCircularList<float>;
template class DoublyCircularList<char>;
template class DoublyCircularList<std ::string>;

template class Stack<int>;
template class Stack<double>;
template class Stack<float>;
template class Stack<char>;
template class Stack<std ::string>;

template class Queue<int>;
template class Queue<double>;
template class Queue<float>;
template class Queue<char>;
template class Queue<std ::string>;

template class Doubly_Ended_Queue<int>;
template class Doubly_Ended_Queue<double>;
template class Doubly_Ended_Queue<float>;
template class Doubly_Ended_Queue<char>;
template class Doubly_Ended_Queue<std ::string>;

//////////////////////////////////////////////////////////////////////////////