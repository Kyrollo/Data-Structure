#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <class t>
struct node
{
    node<t> *next;
    t data;
    node(t val)
    {
        this->data = val;
        next = nullptr;
    }
};
// linked list
template <class t>
class linked_list
{
private:
    node<t> *head;
    node<t> *tail;
    int size;

public:
    linked_list()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void insertAtHead(t value)
    {
        node<t> *temp;
        temp = new node<t>(value);
        if (size == 0)
        {
            head = temp;
            tail = temp;
            temp->next = nullptr;
        }
        else
        {
            temp->data = value;
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void insertAtTail(t value)
    {
        node<t> *temp;
        temp = new node<t>(value);
        if (size == 0)
        {
            head = temp;
            tail = temp;
            temp->next = nullptr;
        }
        else
        {
            tail->next = temp;
            temp->next = nullptr;
            tail = temp;
        }
        size++;
    }
    void print()
    {
        node<t> *curr;
        curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << ",";
            curr = curr->next;
        }
        cout << endl;
    }
    void clear()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    int linkedlistSize()
    {
        return size;
    }
    void removeAtHead()
    {
        head = head->next;
        size--;
    }
    void removeAtTail()
    {
        node<t> *curr;
        curr = head;
        while (curr->next->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = nullptr;
        tail = curr;
        size--;
    }
    bool isExsit(t val)
    {
        node<t> *curr;
        bool check = 0;
        curr = head;
        while (curr != nullptr)
        {
            if (curr->data == val)
            {
                check = 1;
                return check;
            }
            curr = curr->next;
        }
        return check;
    }
    void removeAt(int index)
    {
        node<t> *curr;
        curr = head;
        if (index > size)
        {
            cout << "the index is out of range/n";
        }
        if (index == 0)
        {
            removeAtHead();
            return;
        }
        for (int i = 2; i < index; i++)
        {
            if (curr->next != NULL)
            {
                curr = curr->next;
            }
        }
        curr->next = curr->next->next;
        size--;
    }
    void insertAt(t val, int index)
    {
        node<t> *curr = head;
        node<t> *newNode = new node<t>(val);
        if (isEmpty() || index == 0)
        {
            insertAtHead(val);
            return;
        }
        if (index > size)
        {
            insertAtTail(val);
            return;
        }
        for (int i = 2; i < index; i++)
        {
            if (curr->next != NULL)
            {
                curr = curr->next;
            }
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    void replactAt(t val, int index)
    {
        node<t> *curr = head;
        for (int i = 0; i < index; i++)
        {
            if (curr->next != NULL)
            {
                curr = curr->next;
            }
        }
        curr->data = val;
    }
    void swap(int index1, int index2)
    {
        node<t> *curr1 = head;
        node<t> *curr2 = head;
        for (int i = 0; i < index1; i++)
        {
            if (curr1->next != NULL)
            {
                curr1 = curr1->next;
            }
        }
        for (int i = 0; i < index2; i++)
        {
            if (curr2->next != NULL)
            {
                curr2 = curr2->next;
            }
        }
        int temp = curr1->data;
        curr1->data = curr2->data;
        curr2->data = temp;
    }
    void retirevAt(int index)
    {
        node<t> *curr = head;
        for (int i = 0; i < index; i++)
        {
            if (curr->next != NULL)
            {
                curr = curr->next;
            }
        }
        cout << curr->data << endl;
    }
    bool isItemAtEqual(int index, t val)
    {
        node<t> *curr = head;
        for (int i = 0; i < index; i++)
        {
            if (curr->next != NULL)
            {
                curr = curr->next;
            }
        }
        if (curr->data == val)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    node<t> *get_head()
    {
        return head;
    }
};
template <class t>
node<t> *Combine_Between_Zeros(node<t> *m);
template <typename t>
linked_list<t> mergeKLists(vector<linked_list<t>> &lists);
int main()
{
    // test linked list
    // linked_list<int> m;
    // m.insertAtHead(0);
    // m.insertAtHead(1);
    // m.insertAtHead(2);
    // m.insertAtHead(0);
    // m.insertAtHead(4);
    // m.insertAtHead(5);
    // m.insertAtHead(0);
    // m.print();
    // linked_list<int> g;
    // g.insertAtHead(7);
    // g.insertAtHead(8);
    // g.insertAtHead(9);
    // g.insertAtHead(10);
    // vector<linked_list<int>> v;
    // v.push_back(m);
    // v.push_back(m);
    // v.push_back(g);

    // test mergeKLists
    // linked_list<int> r  = mergeKLists(v);
    // r.print();
    // m.print();
    // s.print();

    // test Combine_Between_Zeros
    // Combine_Between_Zeros(m.get_head());
    //  m.print();
}
// make a function that merge two or more linled_list

// linked_list merge(linked_list list,...)
// {
//     linked_list result;
//     va_list lists;
//     va_start(lists,list);
//     node *temp = list.head;
//     while (temp != NULL)
//     {
//         result.insertAtTail(temp->data);
//         temp = temp->next;
//     }
//     linked_list temp_list;
//     while (temp_list.head != NULL)
//     {
//         temp = temp_list.head;
//         while (temp != NULL)
//         {
//             result.insertAtTail(temp->data);
//             temp = temp->next;
//         }
//         temp_list = va_arg(lists,linked_list);
//     }
//     va_end(lists);
//     return result;
// }
// Merge function to merge K sorted linked lists
template <typename t>
linked_list<t> mergeKLists(vector<linked_list<t>> &lists)
{
    priority_queue<t, vector<t>, greater<t>> min_heap;
    for (int i = 0; i < lists.size(); i++)
    {
        node<t> *curr = lists[i].head;
        while (curr != nullptr)
        {
            min_heap.push(curr->data);
            curr = curr->next;
        }
    }
    linked_list<t> merged_list;
    while (!min_heap.empty())
    {
        merged_list.insertAtTail(min_heap.top());
        min_heap.pop();
    }
    return merged_list;
}

template <class t>
node<t> *Combine_Between_Zeros(node<t> *head)
{
    if (head->data == 0)
    {
        head = head->next;
    }

    node<t> *locl_head = head;
    node<t> *temp = head;
    t sum = 0;
    while (temp != NULL)
    {
        if (temp->data != 0)
        {
            sum += temp->data;
            temp = temp->next;
        }
        else
        {
            locl_head->data = sum;
            locl_head->next = temp->next;
            temp = temp->next;
            locl_head = locl_head->next;
            sum = 0;
        }
    }
    return head;
}
