#include <iostream>
using namespace std;

template <typename T>
struct node
{
    T value;
    node<T> *next;
    node(T val)
    {
        next = nullptr;
        value = val;
    }
};

template <typename T>
class Stack
{
private:
    node<T> *head;
    int Size;

public:
    Stack()
    {
        head = nullptr;
        Size = 0;
    }

    void push(T val)
    {
        node<T> *temb = new node<T>(val);
        temb->next = head;
        head = temb;
        Size++;
    }

    T pop()
    {
        node<T> *old_head = head;
        T value = old_head->value;
        head = head->next;
        delete old_head;
        Size--;
        return value;
    }

    void print()
    {
        node<T> *current = head;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
    }

    bool is_empty()
    {
        return (head == nullptr);
    }

    T top()
    {
        return head->value;
    }

    void clear()
    {
        while (head != nullptr)
        {
            node<T> *old_head = head;
            head = head->next;
            delete old_head;
        }
        Size = 0;
    }

    int stackSize()
    {
        return Size;
    }
};
int get_precedence(char op);
string infixToPostfix(string infix);

int longestValidParentheses(string s);

int main()
{
    // test the implmentiont of stack
    // Stack<int> m;
    // m.push(1);
    // m.push(2);
    // m.push(3);
    // m.push(0);
    // m.push(3);
    // m.print();
    // cout<< endl;
    // // m.pop();
    // cout << m.pop() << endl;
    // m.print();
    // m.clear();
    // // cout << m.is_empty() << endl;

    // test the longestValidParentheses
    // string s = "(()";
    // cout << longestValidParentheses(s) << endl;

    // test to infixToPostfix
    // string infix = "10+2*5-3";
    // string postfix = infixToPostfix(infix);
    // cout << postfix << endl;
}
int get_precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return -1;
    }
}
string infixToPostfix(string infix)
{
    Stack<char> stack;
    string postfix = "";
    char c = ' ';
    for (int i = 0; i < infix.length(); i++)
    {
        c = infix[i];
        if (isdigit(c))
        {
            string num;
            while (i < infix.length() && isdigit(infix[i]))
            {
                num += infix[i];
                i++;
            }
            i--;
            postfix += num;
            postfix += " ";
        }
        else
        {
            while (!stack.is_empty() && get_precedence(c) <= get_precedence(stack.top()))
            {
                postfix += stack.pop();
            }
            stack.push(c);
        }
    }
    while (!stack.is_empty())
    {
        postfix += stack.pop();
    }

    return postfix;
}
int longestValidParentheses(string s)
{
    int n = s.size(), longest = 0;
    Stack<int> stk;
    stk.push(-1);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            stk.push(i);
        }
        else
        {
            stk.pop();
            if (stk.is_empty())
            {
                stk.push(i);
            }
            else
            {
                longest = max(longest, i - stk.top());
            }
        }
    }
    return longest;
}