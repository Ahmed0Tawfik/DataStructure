#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;
};

class Stack
{
    Node * top;
    public:
    Stack()
    {
        top = NULL;

    }

    bool isEmpty()
    {
        return (top == NULL);
    }

    void Push(int value)
    {
        Node * newnode = new Node();
        newnode->data = value;
        if(isEmpty())
        {
            newnode->next = NULL;
        }
        else
        {
            newnode->next = top;
        }
        top = newnode;
    }

    int Pop()
    {
        Node * delptr = top;
        int value = top->data;
        top = top->next;
        delete delptr;
        return value;
    }

    void Display()
    {
        Node * temp = top;
        while( temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    int Peek()
    {
        return top->data;
    }

    int Count()
    {
        int count = 0;
        Node * temp = top;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    bool isFound(int value)
    {
        int index = 1;
        bool found = false;
        Node * temp = top;
        while(temp != NULL)
        {
            if(temp->data == value)
            {
                cout << "is Found At Index : " << index << endl;
                return true;
            }
            temp = temp->next;
            index++;
        }
        return false;
    }

    bool isFull()
    {
        Node * ptr = new Node();
        return (ptr == NULL);
    }
};


int main()
{

Stack s1;

s1.Push(10);
s1.Push(20);
s1.Push(30);
s1.isFound(20);
cout << s1.Count() << endl;
s1.Display();
cout << "LAST ENTERED VALUE : " << s1.Pop() << endl;
s1.Display();

               

}