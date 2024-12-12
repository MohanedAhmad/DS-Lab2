#include <iostream>

using namespace std;

class Stack
{
private:
    int Size, tos;
    int *stk;

public:

    Stack() : Size(10), tos(-1)
    {
        stk = new int[Size];
    }

    Stack(int s) : Size(s), tos(-1)
    {
        stk = new int[Size];
    }

    Stack(const Stack &s)
    {
        this->Size = s.Size;
        this->tos = s.tos;
        for(int i = 0 ; i <= this->tos ; i++)
        {
            this->stk[i] = s.stk[i];
        }
    }

    ~Stack()
    {
        delete [] this->stk;
    }

    bool isEmpty()
    {
        return this->tos == -1;
    }

    bool isFull()
    {
        return this->tos == (this->Size - 1);
    }

    void push(int n)
    {
        if(this->isFull())
        {
            cout << "\nStack is full !!!\n";
        }
        else
        {
            this->stk[++this->tos] = n;
            cout << "\nAdded\t" << n << "\t to the stack" << endl;
        }
    }

    int pop(int &value)
    {
        if(this->isEmpty())
        {
            return 0;
        }
        else
        {
            value = this->stk[(this->tos)--];
            return 1;
        }
    }

    int peek(int &value)
    {
        if (this->isEmpty())
        {
            return 0;
        }
        value = this->stk[this->tos];
        return 1;
    }

    void print()
    {
        cout << "\n[ ";
        for(int i = this->tos ; i > -1 ; i--)
        {
            cout << this->stk[i] << " ";
        }
        cout << "]\n";
    }
};

int main()
{
    int data=0;
    Stack s(3);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.print();

    cout << "\n********************************************************************************************\n";

    s.peek(data)? cout << "\Top element: " << data : cout << "\nStack is already empty !!!\n";

    cout << "\n********************************************************************************************\n";

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
