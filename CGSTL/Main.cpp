/////////////////////////////////////////////////
//
// Sample Code For Demonstrating Header File Use.
//
/////////////////////////////////////////////////

#include <iostream>

// Include User Defined Header File.

#include "CGSTL.h"

using namespace std;

int main()
{
     int ch = 0;
     while (true)
     {
          cout << endl
               << "-----------------------------------" << endl;
          cout << "1. Singly Linear Linked List" << endl
               << "2. Singly Circular Linked List" << endl
               << "3. Doubly Linear Linked List" << endl
               << "4. Doubly Circular Linked List" << endl
               << "5. Stack " << endl
               << "6. Queue " << endl
               << "7. Doubly Ended Queue" << endl
               << "8. Exit " << endl;
          cout << "-----------------------------------" << endl;
          cout << "Enter your choice : ";
          cin >> ch;

          switch (ch)
          {
          case 1:
          {
               SinglyLinearList<int> s1;
               s1.InsertFirst(1);
               s1.InsertFirst(2);
               s1.InsertFirst(3);
               cout << endl
                    << "Singly Linked List after Inserting Element at First Position : ";
               s1.Display();
               s1.InsertLast(9);
               s1.InsertLast(8);
               cout << endl
                    << "Singly Linked List after Inserting Element at Last Position : ";
               s1.Display();
               s1.InsertatPOS(4, 2);
               cout << endl
                    << "Singly Linked List after Inserting Element at Specified Position : ";
               s1.Display();
               s1.DeleteFirst();
               cout << endl
                    << "Singly Linked List after Deleting Element at First Position : ";
               s1.Display();
               s1.DeleteLast();
               cout << endl
                    << "Singly Linked List after Deleting Element at Last Position : ";
               s1.Display();
               s1.DeletefromPOS(2);
               cout << endl
                    << "Singly Linked List after Deleting Element at Specified Position : ";
               s1.Display();
               break;
          }
          case 2:
          {
               SinglyCircularList<float> s1;
               s1.InsertFirst(1.01);
               s1.InsertFirst(2.02);
               s1.InsertFirst(3.03);
               cout << endl
                    << "S Circular Linked List after Inserting Element at First Position : ";
               s1.Display();
               s1.InsertLast(9.09);
               cout << endl
                    << "S Circular Linked List after Inserting Element at Last Position : ";
               s1.Display();
               s1.InsertatPOS(3, 10.010);
               cout << endl
                    << "S Circular Linked List after Inserting Element at Specified Position : ";
               s1.Display();
               s1.DeleteFirst();
               cout << endl
                    << "S Circular Linked List after Deleting Element at First Position : ";
               s1.Display();
               s1.DeleteLast();
               cout << endl
                    << "S Circular Linked List after Deleting Element at Last Position : ";
               s1.Display();
               s1.DeletefromPOS(4);
               cout << endl
                    << "S Circular Linked List after Deleting Element at Specified Position : ";
               break;
          }
          case 3:
          {
               DoublyLinearList<string> s1;
               s1.InsertFirst("Manish");
               s1.InsertFirst("Prasad");
               s1.InsertFirst("Pratiksha");
               cout << endl
                    << "Doubly Linked List after Inserting Element at First Position : ";
               s1.Display();
               s1.InsertLast("Shrutika");
               s1.InsertLast("ADS");
               cout << endl
                    << "Doubly Linked List after Inserting Element at Last Position : ";
               s1.Display();
               s1.InsertatPOS(3, "VIIT");
               cout << endl
                    << "Doubly Linked List after Inserting Element at Specified Position : ";
               s1.Display();
               s1.DeleteFirst();
               cout << endl
                    << "Doubly Linked List after Deleting Element at First Position : ";
               s1.Display();
               s1.DeleteLast();
               cout << endl
                    << "Doubly Linked List after Deleting Element at Last Position : ";
               s1.Display();
               s1.DeletefromPOS(4);
               cout << endl
                    << "Doubly Linked List after Deleting Element at Specified Position : ";
               s1.Display();
               break;
          }
          case 4:
          {
               DoublyCircularList<char> s1;
               s1.InsertFirst('A');
               s1.InsertFirst('B');
               s1.InsertFirst('C');
               cout << endl
                    << "D Circular Linked List after Inserting Element at First Position : ";
               s1.Display();
               s1.InsertLast('E');
               s1.InsertLast('F');
               cout << endl
                    << "D Circular Linked List after Inserting Element at Last Position : ";
               s1.Display();
               s1.InsertatPOS('Z', 3);
               cout << endl
                    << "D Circular Linked List after Inserting Element at Specified Position : ";
               s1.Display();
               s1.DeleteFirst();
               cout << endl
                    << "D Circular Linked List after Deleting Element at First Position : ";
               s1.Display();
               s1.DeleteLast();
               cout << endl
                    << "D Circular Linked List after Deleting Element at Last Position : ";
               s1.Display();
               s1.DeletefromPOS(4);
               cout << endl
                    << "D Circular Linked List after Deleting Element at Specified Position : ";
               break;
          }
          case 5:
          {
               Stack<int> s1;
               s1.Push(11);
               cout << endl
                    << "Stack after Pushing One Element : ";
               s1.Display();
               s1.Push(22);
               s1.Push(33);
               cout << endl
                    << "Stack after Pushing Multiple Elements : ";
               s1.Display();
               int temp = s1.get_Size();
               cout << endl
                    << "Number of Elements in the Stack : " << temp;
               s1.Pop();
               cout << endl
                    << endl
                    << "Stack after Poping One Element : ";
               s1.Display();
               s1.Pop();
               s1.Pop();
               cout << endl
                    << "Stack after Poping All Elements : ";
               s1.Display();
               break;
          }
          case 6:
          {
               Queue<char> s1;
               s1.Enqueue('A');
               cout << endl
                    << "Queue After Pushing One Element : ";
               s1.Display();
               s1.Enqueue('B');
               s1.Enqueue('C');
               cout << endl
                    << "Queue After Pushing Multiple Elements : ";
               s1.Display();
               int temp = s1.get_Count();
               cout << endl
                    << "Number of Elements in the Queue : " << temp;
               s1.Dequeue();
               cout << endl
                    << endl
                    << "Queue After Poping One Element : ";
               s1.Display();
               s1.Dequeue();
               s1.Dequeue();
               cout << endl
                    << "Queue After Poping All Elements : ";
               s1.Display();
               break;
          }
          case 7:
          {
               Doubly_Ended_Queue<char> s1;
               s1.Insert_Front('A');
               cout << endl
                    << "Queue After Pushing One Element : ";
               s1.Display();
               s1.Insert_Rear('B');
               s1.Insert_Front('C');
               cout << endl
                    << "Queue After Pushing Multiple Elements : ";
               s1.Display();
               int temp = s1.get_Count();
               cout << endl
                    << "Number of Elements in the Queue : " << temp;
               s1.Delete_Front();
               cout << endl
                    << endl
                    << "Queue After Poping One Element : ";
               s1.Display();
               s1.Delete_Rear();
               cout << endl
                    << "Queue After Poping All Elements : ";
               s1.Display();
               break;
          }
          case 8:
          {
               exit(0);
          }
          default:
               cout << endl
                    << "Enter a valid choice !!" << endl;
               break;
          }
     }
     return 0;
}