#include <iostream>

using namespace std;

class Queue
{
private:
    int head;
    int tail;
    int counter;
    int Size;
    int *ptr;

public:

    Queue(int s = 10)
    {
        Size = s;
        ptr = new int[Size];
        head = 0;
        counter = 0;
        tail = Size-1;
    }

    ~Queue()
    {
        delete [] ptr;
    }

    bool isEmpty()
    {
        return counter == 0;
    }

    bool isFull()
    {
        return counter == Size;
    }

    void enqueue(int data)
    {
        if(this->isFull())
        {
            cout << "\nQueue is already FULL !!!\n";
            return;
        }
        tail = (tail+1) % Size;
        ptr[tail] = data;
        counter++;
    }

    int dequeue(int &data)
    {
        if(this->isEmpty())
        {
            return 0;
        }
        else
        {
            data = ptr[head];
            head = (head + 1) % Size;
            counter--;
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
            data = ptr[head];
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
            data = ptr[tail];
            return 1;
        }
    }

    void print()
    {
        cout << "\n[ ";
        for(int i = head ; i != tail  ; i = (i + 1) % Size)
        {
            cout << ptr[i] << " ";
        }
        cout << ptr[tail];

        cout << "]\n";
    }
};

int main()
{
    int data = 0;
    Queue q(5);

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

    cout << "\n********************************************************************************************\n";

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
