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

class Stack
{
private:
    Node *tos;

public:

    Stack() : tos(NULL){   }

    bool isEmpty()
    {
        return this->tos == NULL;
    }

    void push(int n)
    {
        Node *newNode = new Node(n);
        newNode->next = this->tos;
        this->tos = newNode;
    }

    int pop(int &data)
    {
        if(this->isEmpty())
        {
            return 0;
        }
        else
        {
            data = tos->value;
            Node *tempPtr = tos;
            tos = tos->next;
            delete tempPtr;
            return 1;
        }
    }

    int peek(int &data)
    {
        if (this->isEmpty())
        {
            return 0;
        }
        data = this->tos->value;
        return 1;
    }

    void print()
    {
        Node *tempPtr = this->tos;
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
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    s.print();

    cout << "\n********************************************************************************************\n";

    s.peek(data)? cout << "\Top element: " << data : cout << "\nStack is already empty !!!\n";

    cout << "\n********************************************************************************************\n";

    s.pop(data)? cout << data << " is poped !!!\n" : cout << "\nStack is already empty !!!\n";
    s.pop(data)? cout << data << " is poped !!!\n" : cout << "\nStack is already empty !!!\n";
    s.pop(data)? cout << data << " is poped !!!\n" : cout << "\nStack is already empty !!!\n";
    s.pop(data)? cout << data << " is poped !!!\n" : cout << "\nStack is already empty !!!\n";
    s.pop(data)? cout << data << " is poped !!!\n" : cout << "\nStack is already empty !!!\n";
    s.pop(data)? cout << data << " is poped !!!\n" : cout << "\nStack is already empty !!!\n";
    s.pop(data)? cout << data << " is poped !!!\n" : cout << "\nStack is already empty !!!\n";

    cout << "\n********************************************************************************************\n";

    s.peek(data)? cout << "\Top element: " << data : cout << "\nStack is already empty !!!\n";

    cout << "\n********************************************************************************************\n";

    s.print();


    return 0;
}
