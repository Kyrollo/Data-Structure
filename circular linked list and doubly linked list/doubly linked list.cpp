#include<iostream>

using namespace std;

class Node
{
    public:
        int value;
        Node* next;
        Node* previous;

};

class doubly_linked_list
{
    private:
        Node* head;
        Node* tail;
    public:
        doubly_linked_list() 
        {
            head = nullptr;
            tail = nullptr;
        }
        void insertAtHead(int e)
        {
            if (head == nullptr && tail == nullptr)
            {
                Node* n;
                n = new Node();
                n->value = e;
                n->next = nullptr;
                n->previous = nullptr;
                head = n;
                tail = n;
            }
            else
            {
                Node* n;
                n = new Node();
                n->value = e;
                n->next = head;
                n->previous = nullptr;
                head = n;
            }
        }
        void print() 
        {
            Node* current = head;
            cout << "[ ";
            while (current != nullptr) {
                cout << current->value << " , ";
                current = current->next;
            }
            cout << "]" << endl;
        }
        void insertAtTail(int e)
        {
            if(head == nullptr)
            {
                insertAtHead(e);
                return;
            }
            Node* n = new Node();
            n->value = e;
            n->previous = tail;
            n->next = nullptr;
            tail->next = n;
            tail = n;
        }
        void insertAt(int e, int index)
        {
            Node* n = new Node();
            n->value = e;
            Node* current = head;
            for(int i = 0; i < index; i++)
            {
                current = current->next;
            }
            if (current != nullptr)
            {
                n->next = current->next;
                n->previous = current;
                current->next = n;
            }
            else
            {
                cout << "Index out of range ;(" << endl;
                return;
            }  
        }
        void insertAfter (Node* prev_node, int data)
        {
            if (prev_node == nullptr)
            {
                cout << "The given previous node cannot be NULL";
                return;
            }
            Node* new_node = new Node();
            new_node->value = data;
            new_node->next = prev_node->next;
            prev_node->next = new_node;
            new_node->previous = prev_node;
            if (new_node->next != nullptr)
            {
                new_node->next->previous = new_node;
            }
        }
        void insert(Node* n)
        {
            if (head == nullptr)
            {
                head = n;
                tail = n;
                return;
            }
            tail->next = n;
            n->previous = tail;
            tail = n;
        }
        void removeAtHead()
        {
            if (head == nullptr)
            {
                cout << "List is empty" << endl;
                return;
            }
            if (head->next != nullptr)
            {
                head->next->previous = nullptr;
            }
            head = head->next;
        }
        void removeAtTail()
        {
            if (head == nullptr)
            {
                cout << "List is empty" << endl;
                return;
            }
            tail = tail->previous;
            tail->next = nullptr;
        }
        void removeAt(int index)
        {
            index = index - 1;
            Node* current = new Node();
            current = head;
            Node* next = new Node();
            Node* prev = new Node();
            for(int i = 0; i < index; i++)
            {
                current = current->next;
            }
            if (current != nullptr)
            {
                next = current->next;
                prev = current->previous;
                prev->next = next;
                next->previous = prev;
            }
            else
            {
                cout << "Index out of range ;(" << endl;
                return;
            }
        }
        int retrieveAt (int index)
        {
            index = index - 1;
            Node* current = new Node();
            current = head;
            for(int i = 0; i < index; i++)
            {
                current = current->next;
            }
            if (current != nullptr)
            {
                return current->value;
            }
            else
            {
                cout << "Index out of range ;(" << endl;
                return 0;
            }
        }
        void replaceAt(int newElement, int idex)
        {
            idex = idex - 1;
            Node* current = new Node();
            current = head;
            for(int i = 0; i < idex; i++)
            {
                current = current->next;
            }
            if (current != nullptr)
            {
                current->value = newElement;
            }
            else
            {
                cout << "Index out of range ;(" << endl;
                return;
            }
        }
        bool isExist(int e)
        {
            Node* current = new Node();
            current = head;
            while(current != nullptr)
            {
                if (current->value == e)
                {
                    return true;
                }
                current = current->next;
            }
            return false;
        }
        bool isItemAtEqual(int e, int index)
        {
            Node* current = head;
            for(int i = 0; i < index; i++)
            {
                current = current->next;
            }
            if (current != nullptr)
            {
                return (current->value == e);
            }
            else
            {
                cout << "Index out of range ;(" << endl;
                return false;
            }
        }
        void swap (int firstItemIdx, int secondItemIdx) 
        {
            firstItemIdx = firstItemIdx - 1;
            secondItemIdx = secondItemIdx - 1;
            Node* firstItem = new Node();
            Node* secondItem = new Node();
            firstItem = head;
            secondItem = head;
            for(int i = 0; i < firstItemIdx; i++)
            {
                firstItem = firstItem->next;
            }
            for(int i = 0; i < secondItemIdx; i++)
            {
                secondItem = secondItem->next;
            }
            if (firstItem != nullptr && secondItem != nullptr)
            {
                Node* temp = new Node();
                temp->value = firstItem->value;
                firstItem->value = secondItem->value;
                secondItem->value = temp->value;
            }
            else
            {
                cout << "Index out of range ;(" << endl;
                return;
            }
        }
        void reverse() 
        {
            if (head == nullptr || tail == nullptr) 
            {
                return;
            }

            Node* current = head;
            while (current != nullptr) {
                Node* temp = current->previous;
                current->previous = current->next;
                current->next = temp;
                current = current->previous;
            }
            Node* temp = head;
            head = tail;
            tail = temp;
        }
        bool isEmpty()
        {
            return head == nullptr;
        }
        int size()
        {
            int count = 0;
            Node* current = new Node();
            current = head;
            while(current != nullptr)
            {
                count++;
                current = current->next;
            }
            return count;
        }
        void clear()
        {
            head = nullptr;
            tail = nullptr;
        }
        void backwardTraversal ()
        {
            Node* current = new Node();
            current = tail;
            cout << "[ ";
            while(current != nullptr)
            {
                cout << current->value << " ,";
                current = current->previous;
            }
            cout<< "]" << endl;
        }


};

int main()
{
    Node* n = new Node();
    n->value = 1;
    n->next = nullptr;
    n->previous = nullptr;

    doubly_linked_list l1;
    l1.print();
    l1.insert(n);
    l1.print();
    l1.insertAtHead(5);
    l1.print();
    l1.insertAtHead(1);
    l1.insertAtHead(2);
    l1.insertAtHead(3);
    l1.print();
    l1.insertAtTail(0);
    l1.insertAtTail(-1);
    l1.insertAtHead(4);
    l1.print();
    l1.insertAfter(n,55);
    l1.print();
    l1.removeAtHead();
    l1.print();
    l1.removeAtTail();
    l1.print();
    l1.replaceAt(23,1);
    l1.print();
    cout << "5 : " << l1.isExist(5) << endl;
    cout << "55 : " << l1.isExist(55) << endl;
    cout << "1 : " << l1.isItemAtEqual(1,1) << endl;
    cout << "2 : " << l1.isItemAtEqual(2,2) << endl;
    l1.swap(1,4);
    l1.print();
    cout << "Size : " << l1.size() << endl;
    cout << "Empty : " << l1.isEmpty() << endl;
    cout << "Retrieve : " << l1.retrieveAt(1) << endl;
    l1.reverse();
    l1.backwardTraversal();
    l1.clear();
    l1.print();
}