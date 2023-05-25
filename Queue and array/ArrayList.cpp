#include <bits/stdc++.h>
using namespace std;

template <typename T>

class ArrayList {
private:
    int SIZE;
    int capacity;
    T* elements;
    void resize() {
        capacity *= 2;
        T* newElements = new T[capacity];
        for (int i = 0; i < SIZE; i++) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }

public:
//    ArrayList() {
//        SIZE = 0;
//        capacity = 1;
//        elements = new T[capacity];
//    }

    ArrayList(int Capacity = 1) {
        SIZE = 0;
        capacity = Capacity;
        elements = new T[capacity];
    }

    ~ArrayList() {
        delete[] elements;
    }

    void insert(T element) {
        if (isFull()){
            resize();
        }
        elements[SIZE] = element;
        SIZE++;
    }

    void insertAt(T element, int index) {
        if (isFull()){
            resize();
        }
        if (index < 0 || index > SIZE) {
            cout << "Invalid index" << "\n";
            return;
        }
        for (int i = SIZE; i > index; i--) {
            elements[i] = elements[i-1];
        }
        elements[index] = element;
        SIZE++;
    }

    T retrieveAt(int index) {
        if (index < 0 || index >= SIZE) {
            cout << "Invalid index" << "\n";
            return T();
        }
        return elements[index];
    }

    void removeAt(int index) {
        if (index < 0 || index >= SIZE) {
            cout << "Invalid index" << "\n";
            return;
        }
        for (int i = index; i < SIZE-1; i++) {
            elements[i] = elements[i+1];
        }
        SIZE--;
    }

    void replaceAt(T newElement, int index) {
        if (index < 0 || index >= SIZE) {
            cout << "Invalid index" << "\n";
            return;
        }
        elements[index] = newElement;
    }

    bool isItemAtEqual(T element, int index) {
        return (elements[index] == element);
    }

    bool isEmpty() {
        return (SIZE == 0);
    }

    bool isFull() {
        return (SIZE == capacity);
    }

    int listSize() {
        return SIZE;
    }

    int maxListSize() {
        return capacity;
    }

    void clear() {
        SIZE = 0;
        capacity = 1;
        delete[] elements;
        elements = new T[capacity];
    }

    void print() {
        cout << "[";
        for (int i = 0; i < SIZE; i++){
            cout << elements[i] << " ";
        }
        cout << "]\n";
    }
};
