// Head File Inclusion
#include <iostream>

// Defining Namespace

using namespace std;

// Creation Of Structures

template <class T>
struct Node
{
    T ival;
    struct Node *Next;
    struct Node *Prev;
};

//-----------------------------------------------------------------------
// Class Defination And Function Prototype of Singly Linear Linked List
//-----------------------------------------------------------------------

template <class T>
class SinglyLinearList
{
private:
    Node<T> *head;
    Node<T> *temp;
    Node<T> *temp1;
    int Count;

public:
    SinglyLinearList();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertatPOS(T, int);
    void DeleteFirst();
    void DeleteLast();
    void DeletefromPOS(int);
    void Display();
    int get_Count();
};

//-----------------------------------------------------------------------
// Class Defination And Function Prototype of Doubly Linear Linked List
//-----------------------------------------------------------------------

template <class T>
class DoublyLinearList
{
private:
    Node<T> *head;
    Node<T> *temp;
    Node<T> *temp1;
    Node<T> *Tail;
    int count;

public:
    DoublyLinearList();
    void Display();
    int get_Count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertatPOS(int, T);
    void DeleteFirst();
    void DeleteLast();
    void DeletefromPOS(int);
};

//-----------------------------------------------------------------------
// Class Defination And Function Prototype of Singly Circular Linked List
//-----------------------------------------------------------------------

template <class T>
class SinglyCircularList
{
private:
    Node<T> *head;
    Node<T> *temp;
    Node<T> *temp1;
    int Count;

public:
    SinglyCircularList();
    void Display();
    int get_Count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertatPOS(int, T);
    void DeleteFirst();
    void DeleteLast();
    void DeletefromPOS(int);
};

//-----------------------------------------------------------------------
// Class Defination And Function Prototype of Doubly Circular Linked List
//-----------------------------------------------------------------------

template <class T>
class DoublyCircularList
{

private:
    Node<T> *head;
    Node<T> *temp;
    Node<T> *temp1;
    int Count;

public:
    DoublyCircularList();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertatPOS(T, int);
    void DeleteFirst();
    void DeleteLast();
    void DeletefromPOS(int);
    void Display();
    int get_Count();
};

//-----------------------------------------------------------------------
// Class Defination And Function Prototype of Stack using Linked List
//-----------------------------------------------------------------------

template <class T>
class Stack
{

private:
    Node<T> *head;
    Node<T> *temp;
    int iCnt;

public:
    Stack();
    void Display();
    void Push(T);
    void isEmpty();
    int get_Size();
    void Pop();
};

//-----------------------------------------------------------------------
// Class Defination And Function Prototype of Queue using Linked List
//-----------------------------------------------------------------------

template <class T>
class Queue
{

private:
    Node<T> *head;
    Node<T> *Front;
    Node<T> *Rear;
    Node<T> *temp;
    int iCnt;

public:
    Queue();
    void Enqueue(T);
    void Dequeue();
    void Display();
    int get_Count();
    int get_Front();
    int get_Rear();
};

//----------------------------------------------------------------------------------
// Class Defination And Function Prototype of Doubly Ended Queue using Linked List
//----------------------------------------------------------------------------------

template <class T>
class Doubly_Ended_Queue
{

private:
    Node<T> *head;
    Node<T> *Front;
    Node<T> *Rear;
    Node<T> *temp;
    int iCnt;

public:
    Doubly_Ended_Queue();
    void Insert_Front(T iVal);
    void Insert_Rear(T iVal);
    void Delete_Front();
    void Delete_Rear();
    int get_Count();
    void Display();
};

//////////////////////////////////////////////////////////////////////////////////