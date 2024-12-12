#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int v)
    {
        this->value = v;
        this->next = NULL;
    }
};

class Queue
{
private:
    Node *head;
    Node *tail;

public:

    Queue() : head(NULL), tail(NULL){   }

    bool isEmpty()
    {
        return (head == NULL && tail == NULL);
    }

    void enqueue(int data)
    {
        Node *newNode = new Node(data);

        if(this->isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int dequeue(int &data)
    {
        if(this->isEmpty())
        {
            return 0;
        }
        else
        {
            data = head->value;
            Node *tempPtr = head;
            if(head == tail)
            {
                tail = tail->next;
            }
            head = head->next;
            delete tempPtr;
            return 1;
        }
    }

    int getFront(int &data)
    {
        if(this->isEmpty())
        {
            return 0;
        }
        else
        {
            data = head->value;
            return 1;
        }
    }

    int getRear(int &data)
    {
        if(this->isEmpty())
        {
            return 0;
        }
        else
        {
            data = tail->value;
            return 1;
        }
    }

    void print()
    {
        Node *tempPtr = this->head;
        cout << "\n[ ";
        while (tempPtr != NULL)
        {
            cout << tempPtr->value << " ";
            tempPtr = tempPtr->next;
        }
        cout << "]\n";
    }
};

int main()
{
    int data = 0;
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    q.print();

    cout << "\n********************************************************************************************\n";

    q.getFront(data)? cout << "\nFront element: " << data : cout << "\nQueue is already empty !!!\n";
    q.getRear(data)? cout << "\nRear element: " << data : cout << "\nQueue is already empty !!!\n";

    cout << "\n\n********************************************************************************************\n";

    q.dequeue(data)? cout << data << " is dequeued !!!\n" : cout << "\nQueue is already empty !!!\n";
    q.dequeue(data)? cout << data << " is dequeued !!!\n" : cout << "\nQueue is already empty !!!\n";
    q.dequeue(data)? cout << data << " is dequeued !!!\n" : cout << "\nQueue is already empty !!!\n";
    q.dequeue(data)? cout << data << " is dequeued !!!\n" : cout << "\nQueue is already empty !!!\n";
    q.dequeue(data)? cout << data << " is dequeued !!!\n" : cout << "\nQueue is already empty !!!\n";
    q.dequeue(data)? cout << data << " is dequeued !!!\n" : cout << "\nQueue is already empty !!!\n";
    q.dequeue(data)? cout << data << " is dequeued !!!\n" : cout << "\nQueue is already empty !!!\n";

    cout << "\n********************************************************************************************\n";

    q.getFront(data)? cout << "\nFront element: " << data : cout << "\nQueue is already empty !!!\n";
    q.getRear(data)? cout << "\nRear element: " << data : cout << "\nQueue is already empty !!!\n";

    cout << "\n********************************************************************************************\n";

    q.print();


    return 0;
}
