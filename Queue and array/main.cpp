#include "ArrayList.cpp"
#include "Queue.cpp"
using namespace std;

///Problem number 1
//Generate Binary Numbers from 1 to N
void binaryNumbers(int n)
{
    //Create a Queue to store the binary numbers in it
    Queue<string> q1;
    //Enqueue number 1 to it
    q1.enqueue("1");
    //Loop n times
    for (int i = 1; i <= n; i++)
    {
        //Enqueue 0 and 1 to it (Binary numbers sequence)
        q1.enqueue(q1.first()+"0");
        q1.enqueue(q1.first()+"1");
        //Print the front number and remove it
        cout << q1.dequeue() << " ";
    }
    cout << "\n";
}

template<typename T>
///Problem number 2
//Implement a Stack
class Stack{
private:
    Queue<T> queue1;
    Queue<T> queue2;
public:
    Stack(int Capacity = 5)
    {
        Queue<T> queue1(Capacity);
        Queue<T> queue2(Capacity);
    }
    void push (T element)
    {
        queue1.enqueue(element);
    }
    T pop()
    {
        if (queue1.isEmpty()) {
            cout << "Empty Stack.\n";
            return T();
        }
        while (queue1.queueSize() > 1) {
            queue2.enqueue(queue1.dequeue());
        }
        T element = queue1.dequeue();
        swap(queue1, queue2);
        queue2.clear();
        return element;
    }
    T top()
    {
        if (queue1.isEmpty()) {
            cout << "Empty Stack.\n";
            return T();
        }
        while (queue1.queueSize() > 1) {
            queue2.enqueue(queue1.dequeue());
        }
        T element = queue1.dequeue();
        queue2.enqueue(element);
        swap(queue1, queue2);
        queue2.clear();
        return element;
    }
    bool isEmpty ()
    {
        return queue1.isEmpty();
    }
    int stackSize ()
    {
        return queue1.queueSize();
    }
    void clear()
    {
        queue1.clear();
    }
    void print()
    {
        queue1.print();
    }
};

template <typename T>
///Problem number 3
//Sorting a Queue
void sortQueue(Queue<T>& q) {
    if (q.queueSize() <= 1){
        return;
    }
    int Size = q.queueSize();
    Queue<T> tempQueue(Size);
    // Loop through the queue n times
    for (int i = 0; i < Size; i++) {
        // Find the minimum element in the remaining unsorted elements
        T minElement = q.first();
        int minIndex = 0;
        for (int j = 0; j < Size - i; j++) {
            T currentElement = q.dequeue();
            if (currentElement < minElement) {
                minElement = currentElement;
                minIndex = j;
            }
            q.enqueue(currentElement);
        }
        // Enqueue the minimum element to the temporary queue
        tempQueue.enqueue(minElement);
        // Dequeue and enqueue the remaining unsorted elements to the original queue
        for (int j = 0; j < Size - i; j++) {
            T currentElement = q.dequeue();
            if (j != minIndex) {
                q.enqueue(currentElement);
            }
        }
    }

    // Copy the sorted elements from the temporary queue back to the original queue
    for (int i = 0; i < Size; i++) {
        q.enqueue(tempQueue.dequeue());
    }
}

int main() {
    ///Program that test Array list
    /*
    ArrayList<int> arr(5);
    arr.insert(10);
    arr.insert(20);
    arr.insert(30);
    arr.insert(40);
    arr.insert(50);
    arr.print();
    cout << "Does the array is full? " << arr.isFull() << "\n";
    arr.removeAt(1);
    arr.print();
    arr.replaceAt(60, 1);
    arr.print();
    cout << "The max size of the array: " << arr.maxListSize() << "\n";
    arr.insertAt(70, 2);
    arr.print();
    cout << "The first index item: " << arr.retrieveAt(0) << "\n";
    cout << "Does the third item equal 60? " << arr.isItemAtEqual(60, 2) << "\n";
    cout << "The size of the array: " << arr.listSize() << "\n";
    arr.clear();
    arr.print();
    cout << "Does the array is empty? " << arr.isEmpty() << "\n";
    */
    ///Program that test Queue
    /*
    Queue<int> myQueue(5);
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.print();
    cout << "The size of the Queue: " << myQueue.queueSize() << "\n";
    myQueue.dequeue();
    myQueue.print();
    cout << "Does the Queue is empty? " << myQueue.isEmpty() << "\n";
    cout << "The first index item: " << myQueue.first() << "\n";
    myQueue.clear();
    myQueue.print();
    */
    ///Program that test the problem 1
    /*
    binaryNumbers(3);
    binaryNumbers(5);
    */
    ///Program that test the problem 2
    /*
    Stack<int> stack1(5);
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.print();
    cout << "The size of stack: " << stack1.stackSize() << "\n";
    stack1.pop();
    stack1.print();
    cout << "The last index: " << stack1.top() << "\n";
    cout << "Does the stack is empty? " << stack1.isEmpty() << "\n";
    stack1.clear();
    stack1.print();
    */
    ///Program that test the problem 3
    /*
    Queue<int> q1(4);
    q1.enqueue(3);
    q1.enqueue(15);
    q1.enqueue(2);
    q1.enqueue(4);
    q1.print();
    sortQueue(q1);
    q1.print();

    q1.clear();
    q1.enqueue(9);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(1);
    q1.print();
    sortQueue(q1);
    q1.print();
    */
}
