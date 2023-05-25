#include<iostream>

using namespace std;

class Node
{
    public:
        int value;
        Node* next;
        Node* previous;

};
class circularLinkedList
{
    private:
        Node* head;
        Node* tail;
    public:
        circularLinkedList() 
        {
            head = nullptr;
            tail = nullptr;
        }
        void insertAtHead(int e)
        {
            if (head == nullptr && tail == nullptr)
            {
                Node* n = new Node();
                n->value = e;
                n->next = n;
                n->previous = n;
                head = n;
                tail = n;
            }
            else
            {
                Node* n = new Node();
                n->value = e;
                n->next = head;
                n->previous = tail;
                head->previous = n;
                tail->next = n;
                head = n;
            }
        }
        void print() 
        {
            Node* current = head;
            cout << "[ ";
            if (current != nullptr) {
                do {
                    cout << current->value << " , ";
                    current = current->next;
                } while (current != head);
            }
            cout << "]" << endl;
        }
        void insertAtTail(int e)
        {
            if(head == nullptr)
            {
                Node* n = new Node();
                n->value = e;
                n->next = n;
                n->previous = n;
                head = n;
                tail = n;
            }
            else
            {
                Node* n = new Node();
                n->value = e;
                n->next = head;
                n->previous = tail;
                head->previous = n;
                tail->next = n;
                tail = n;
            }
        }
        void insertAt(int e, int index)
        {
            if(index == 0)
            {
                insertAtHead(e);
            }
            else
            {
                Node* current = head;
                for(int i = 0; i < index - 1; i++)
                {
                    current = current->next;
                }
                Node* n = new Node();
                n->value = e;
                n->next = current->next;
                n->previous = current;
                current->next->previous = n;
                current->next = n;
            }
        }
        void deleteAtHead()
        {
            if(head == nullptr)
            {
                cout << "List is empty" << endl;
            }
            else if(head == tail)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                head = head->next;
                head->previous = tail;
                tail->next = head;
            }
        }
        void deleteAtTail()
        {
            if(head == nullptr)
            {
                cout << "List is empty" << endl;
            }
            else if(head == tail)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                tail = tail->previous;
                tail->next = head;
                head->previous = tail;
            }
        }
        void deleteAt(int index)
        {
            if(index == 0)
            {
                deleteAtHead();
            }
            else
            {
                Node* current = head;
                for(int i = 0; i < index - 1; i++)
                {
                    current = current->next;
                }
                current->next = current->next->next;
                current->next->previous = current;
            }
        }
        bool isExist(int e)
        {
            Node* current = head;
            if(current != nullptr)
            {
                do
                {
                    if(current->value == e)
                    {
                        return true;
                    }
                    current = current->next;
                } while (current != head);
            }
            return false;
        }
        int indexOf(int e)
        {
            Node* current = head;
            int index = 0;
            if(current != nullptr)
            {
                do
                {
                    if(current->value == e)
                    {
                        return index;
                    }
                    current = current->next;
                    index++;
                } while (current != head);
            }
            return -1;
        }
        int size()
        {
            Node* current = head;
            int size = 0;
            if(current != nullptr)
            {
                do
                {
                    size++;
                    current = current->next;
                } while (current != head);
            }
            return size;
        }
        bool isItemAtEqual(int e, int index)
        {
            Node* current = head;
            int i = 0;
            if(current != nullptr)
            {
                do
                {
                    if(i == index)
                    {
                        if(current->value == e)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    current = current->next;
                    i++;
                } while (current != head);
            }
            return false;
        }
        void swap(int firstIndex,int secondIndex)
        {
            Node* current = head;
            Node* firstNode = nullptr;
            Node* secondNode = nullptr;
            int i = 0;
            if(current != nullptr)
            {
                do
                {
                    if(i == firstIndex)
                    {
                        firstNode = current;
                    }
                    if(i == secondIndex)
                    {
                        secondNode = current;
                    }
                    current = current->next;
                    i++;
                } while (current != head);
            }
            int temp = firstNode->value;
            firstNode->value = secondNode->value;
            secondNode->value = temp;
        }
        bool isEmpty()
        {
            if(head == nullptr)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        void clear()
        {
            head = nullptr;
            tail = nullptr;
        }

};

int main()
{
    circularLinkedList cll;
    cll.insertAtHead(1);
    cll.insertAtHead(2);
    cll.insertAtHead(3);
    cll.insertAtHead(4);
    cll.insertAtHead(5);
    cll.print();
    cll.insertAtTail(6);
    cll.insertAtTail(7);
    cll.insertAtTail(8);
    cll.print();
    cll.insertAt(9, 0);
    cll.insertAt(10, 3);
    cll.insertAt(11, 7);
    cll.print();
    cll.deleteAtHead();
    cll.print();
    cll.deleteAtTail();
    cll.print();
    cll.deleteAt(0);
    cll.print();
    cll.deleteAt(3);
    cll.print();
    cout << cll.isExist(5) << endl;
    cout << cll.isExist(7) << endl;
    cll.clear();
    cll.print();

}