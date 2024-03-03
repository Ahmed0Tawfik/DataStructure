#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;
};

class Queue
{
    Node * front;
    Node * rear;
    
    public:
    Queue()
    {
        front = rear = NULL;
    }

    void enQueue(int value)
    {
        Node * newnode = new Node();
        newnode->data = value;
        if(isEmpty())
        {
            front = rear = newnode;
            newnode->next = NULL;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }

    }

    int deQueue()
    {
        if(isEmpty())
        {
            cout << "Nothing to Dequeue !!" << endl;
        }
        else if( front == rear)
        {
            int value = front->data;
            front = rear = NULL;
            return value;
        }
        else
        {
            int value = front->data;
            Node *delptr = front;
            front = front->next;
            delete delptr;
            return value;
        }
    }

    bool isEmpty()
    {
        return (front == NULL);
    }

    void Display()
    {
        Node * temp = front;
        while(temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    bool isFound(int key)
    {
        Node * temp = front;
        while(temp->next != NULL)
        {
            int index = 1;
            if(temp->data == key)
            {
                cout << "is Found at Index : " << index << endl;
                return true;
            }
            else
            {
                temp = temp->next;
                index++;
            }
        }
        cout << "NOT FOUND" << endl;
        return false;
    }

    int getFront()
    {
        return front->data;
    }

    int getRear()
    {
        return rear->data;
    }

    void Clear()
    {
        while(!isEmpty())
        {
            deQueue();
        }
    }
};

int main()
{
    Queue q1;
    cout << q1.isEmpty() << endl;
    q1.enQueue(10);
    q1.enQueue(20);
    q1.enQueue(30);
    cout << "Front " << q1.getFront() << endl;
    cout << "Rear " << q1.getRear() << endl;
    q1.Display();
    cout << "First to go: " << q1.deQueue() << endl;
    q1.isFound(10);
    q1.isFound(20);
    q1.Display();
    q1.Clear();
    q1.Display();


}