#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int iVal;
    Node *Right;
    Node *Left;
} *Root;

class Binary_Search_Tree
{

    int iRet = 0;
    int Side = 0;
    Node *Parent = Root;

public:
    Binary_Search_Tree()
    {
        Root = NULL;
    }

public:
    bool Insert_Node(int iTemp, Node *temp)
    {
        if (Root == NULL)
        {
            Root = new Node;
            Root->iVal = iTemp;
            Root->Left = NULL;
            Root->Right = NULL;
            return true;
        }
        else
        {
            if (temp->iVal == iTemp)
            {
                return false;
            }
            if (iTemp > temp->iVal)
            {
                if (temp->Right != NULL)
                {
                    Insert_Node(iTemp, temp->Right);
                }
                else
                {
                    Node *new_node = new Node;
                    new_node->iVal = iTemp;
                    new_node->Left = NULL;
                    new_node->Right = NULL;
                    temp->Right = new_node;
                    return true;
                }
            }
            else if (iTemp < temp->iVal)
            {
                if (temp->Left != NULL)
                {
                    Insert_Node(iTemp, temp->Left);
                }
                else
                {
                    Node *new_node = new Node;
                    new_node->iVal = iTemp;
                    new_node->Left = NULL;
                    new_node->Right = NULL;
                    temp->Left = new_node;
                    return true;
                }
            }
        }
    }

    void Preorder_Traversal(Node *temp)
    {
        if (Root == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (temp != NULL)
        {
            cout << temp->iVal << "  ";
            Preorder_Traversal(temp->Left);
            Preorder_Traversal(temp->Right);
        }
    }

    void Inorder_Traversal(Node *temp)
    {
        if (Root == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (temp != NULL)
        {
            Inorder_Traversal(temp->Left);
            cout << temp->iVal << "  ";
            Inorder_Traversal(temp->Right);
        }
    }

    void Postorder_Traversal(Node *temp)
    {
        if (Root == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (temp != NULL)
        {
            Postorder_Traversal(temp->Left);
            Postorder_Traversal(temp->Right);
            cout << temp->iVal << "  ";
        }
    }

    void Display(Node *ptr, int level)
    {
        int i;
        if (ptr != NULL)
        {
            Display(ptr->Right, level + 1);
            cout << endl;
            if (ptr == Root)
                cout << "Root->:  ";
            else
            {
                for (i = 0; i < level; i++)
                    cout << "       ";
            }
            cout << ptr->iVal;
            Display(ptr->Left, level + 1);
        }
    }

    bool Find_Element(Node *temp, int iTemp)
    {
        if (temp->iVal == iTemp && temp->Left == NULL && temp->Right == NULL)
        {
            return true;
        }
        else
        {
            if (iTemp > temp->iVal)
            {
                if (Find_Element(temp->Right, iTemp))
                {
                    return true;
                }
                else if (Find_Element(temp->Left, iTemp))
                {
                    return true;
                }
            }
            return false;
        }
    }

    // bool Del(int iTemp, Node *temp)
    // {
    //     cout << "At Node : " << temp->iVal << endl;
    //     if (temp->iVal > iTemp)
    //     {
    //         Del(iTemp, temp->Left);
    //     }
    //     if (temp->iVal < iTemp)
    //     {
    //         Del(iTemp, temp->Right);
    //     }
    //     if (temp->iVal == iTemp)
    //     {
    //         if (temp->Left == NULL && temp->Right == NULL)
    //         {
    //             delete (temp);
    //             return true;
    //         }
    //     }
    // }

    int Max_Sub_Tree(Node *temp, Node *Parent1)
    {
        cout << Parent1->iVal << " " << temp->iVal << endl;
        if (temp->Right == NULL)
        {
            int Max = temp->iVal;
            if (temp->Left != NULL)
            {
                if (Side)
                {
                    Parent1->Right = temp->Left;
                }
                else
                {
                    Parent1->Left = temp->Left;
                }
            }

            cout << Parent1->iVal << " " << temp->iVal << endl;
            cout << Parent1->Left->iVal << endl;
            cout << Max << " " << temp->iVal;
            delete (temp);
            return Max;
        }
        else
        {
            Parent1 = temp;
            Side = 1;
            Max_Sub_Tree(temp->Right, Parent1);
        }
    }

    void Delete_Node(int iTemp, Node *temp)
    {
        if (temp->iVal == iTemp)
        {
            if (temp->Left == NULL && temp->Right == NULL)
            {
                if (Side)
                {
                    Parent->Right = NULL;
                }
                else
                {
                    Parent->Left = NULL;
                }
                delete (temp);
                cout << "Element Deleted Successfully.\n";
            }
            else if (temp->Left != NULL && temp->Right == NULL)
            {
                Parent = temp;
                cout << Parent->iVal << " " << temp->iVal << endl;
                Side = 0;
                int Max = Max_Sub_Tree(temp->Left, Parent);
                Parent->iVal = Max;
                cout << "Element Deleted Successfully.\n";
            }
        }
        else if (temp->iVal > iTemp)
        {
            Parent = temp;
            Side = 0;
            Delete_Node(iTemp, temp->Left);
        }
        else if (temp->iVal < iTemp)
        {
            Parent = temp;
            Side = 1;
            Delete_Node(iTemp, temp->Right);
        }
        else
        {
            cout << "Element Not Found.\n";
        }
    }
};

int main()
{
    Binary_Search_Tree BST;
    Node *temp;
    int iChoice, iTemp;

    while (1)
    {
        cout << "1. Insert Element \n2. Delete Element \n3. Inorder Traversal \n4. Preorder Traversal \n5. Postorder Traversal \n6. Display \n7. Exit";
        cout << "\nEnter your choice : ";
        cin >> iChoice;
        switch (iChoice)
        {
        case 1:
            bool iFlag;
            cout << "Enter the element to be inserted : ";
            cin >> iTemp;
            temp = Root;
            iFlag = BST.Insert_Node(iTemp, temp);
            if (iFlag)
            {
                cout << "Element Inserted.\n";
            }
            else
            {
                cout << "Element already present in the tree.\n";
            }
            break;
        case 2:
            if (Root == NULL)
            {
                cout << "Tree is empty, nothing to delete\n";
            }
            else
            {
                bool iFlag;
                cout << "Enter the number to be deleted : ";
                cin >> iTemp;
                temp = Root;
                // iFlag =
                BST.Delete_Node(iTemp, temp);
                // if (iFlag)
                // {
                //     cout << "Element found and deleted successfully.\n";
                // }
                // else
                // {
                //     cout << "Element not found in the tree.\n";
                // }
            }
            break;
        case 3:
            cout << "Inorder Traversal :" << endl;
            BST.Inorder_Traversal(Root);
            cout << endl;
            break;
        case 4:
            cout << "Preorder Traversal :" << endl;
            BST.Preorder_Traversal(Root);
            cout << endl;
            break;
        case 5:
            cout << "Postorder Traversal :" << endl;
            BST.Postorder_Traversal(Root);
            cout << endl;
            break;
        case 6:
            cout << "Display BST:" << endl;
            BST.Display(Root, 1);
            cout << endl;
            break;
        case 7:
            exit(1);
        default:
            cout << "Wrong choice" << endl;
        }
    }
}