#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;
};

class LinkedList
{
    public:
    Node * head;

    LinkedList()
    {
        head = NULL;
    }

    bool isEmpty()
    {
        return (head == NULL);
    }

    void insertFirst(int newitem)
    {
        Node *newNode = new Node;

        newNode->data = newitem;

        if(isEmpty())
        {
            newNode->next = NULL;
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void Display()
    {
        int counter = 0;
        Node * temp = head;
        while(temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
            counter++;
        }
        cout << "Number of items = " << counter << endl;
    }

    bool isFound(int key)
    {
        Node * temp = head;
        bool found = false;
        while(temp != NULL)
        {
            if(temp->data == key)
            {
                found == true;
            }
            temp = temp->next;
        }
        return found;
    }

    void insertBefore(int value,int beforevalue)
    {
       if(head->data == beforevalue)
       {
        insertFirst(value);
       }
       else
       {
            if(isFound(beforevalue))
            {
                Node * newnoode = new Node;
                newnoode->data = value;
                Node * temp = head;
                while(temp->next->data != beforevalue && temp != NULL && temp->data != beforevalue)
                {
                    temp = temp->next;
                }
                newnoode->next = temp->next;
                temp->next = newnoode;
        }
       }
    }

    void Append(int value)
    {
        if(!isEmpty())
        {
            Node *newitemm = new Node;
            newitemm->data = value;
            newitemm->next = NULL;
            Node *temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newitemm;
        }
        else
        {
            insertFirst(value);
        }
    }

    void DeleteFirst()
    {
        if(isEmpty())
        {
            cout << "NOTHING TO DELETE HERE" << endl;
        }
        else
        {
            Node * delptr = head;
            head = head->next;
            delete delptr;
        }
        
    }

    void DeleteValue(int value)
    {
        if(isEmpty())
        {
            cout << "LIST IS EMPTY NOTHING TO DELETE HERE" << endl;
        }
        else
        {
            Node * temp = head;
            if(temp->data == value)
            {
                DeleteFirst();
            }
            else
            {
                while(temp != NULL && temp->next->data != value)
                {
                    temp = temp->next;
                }
                Node * delptr = temp->next;
                temp->next = delptr->next;
                delete delptr;
            }
            
        }
    }

    void DeleteLast()
    {
        if(isEmpty())
        {
            cout << "NOTHING TO DELETE HERE IDIOT" << endl;
        }
        else
        {
            Node * temp = head;
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            Node * delptr = temp->next;
            temp->next = NULL;
            delete delptr;
        }
    }
};

int main()
{
    // TO TEST ONLY

    LinkedList list;

    list.DeleteFirst();
    list.DeleteLast();
    list.DeleteValue(45);

    list.Append(10);
    list.Append(20);
    list.insertFirst(30);
    list.insertBefore(35,30);
    list.Append(60);

    list.Display();

    list.DeleteFirst();
    list.DeleteLast();
    list.DeleteValue(20);

    list.Display();
}