#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Queue {
private:
    int Front;  //first begin
    int Rear;   //last begin
    int SIZE;
    int capacity;
    T* elements;
    bool isFull() {
        return (SIZE == capacity);
    }
public:
    Queue(int Capacity = 10)
    {
        Front = Rear = -1;
        SIZE = 0;
        capacity = Capacity;
        elements = new T[capacity];
    }

    ~Queue()
    {
        delete[] elements;
    }

    void enqueue(T element)
    {
        if (isFull())
        {
            cout << "Full Queue.\n";
            return;
        }
        if (isEmpty())
        {
            Front = Rear = 0;
        }
        else
        {
            Rear = (Rear + 1) % capacity;
        }
        elements[Rear] = element;
        SIZE++;
    }

    T dequeue()
    {
        if (isEmpty()){
            cout << "Empty Queue.\n";
            return T();
        }
        T element = elements[Front];
        if (Front == Rear) {
            Front = Rear = -1;
        }
        else {
            Front = (Front + 1) % capacity;
        }
        SIZE--;
        return element;
    }

    T first()
    {
        return elements[Front];
    }

    bool isEmpty()
    {
        return (Front == -1 && Rear == -1);
    }

    int queueSize()
    {
        return SIZE;
    }

    void clear()
    {
        Front = Rear = -1;
        SIZE = 0;
        delete[] elements;
        elements = new T[capacity];
    }

    void print()
    {
        cout << "[";
        if (isEmpty()){
            cout << "]\n";
            return;
        }
            for (int i = Front; i <= Rear; i++) {
                cout << elements[i] << " ";
            }
        cout << "]\n";
    }

};
