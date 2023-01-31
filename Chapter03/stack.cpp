#include <iostream>
#include <cstring>
using namespace std;


template <typename T>
class Node
{
public:
    T Value;
    Node<T> *Next;

    Node(T value) : Value(value), Next(NULL) {}
};

template <typename T>
class Stack
{
private: 
    int m_count = 0;
    Node<T>* m_top = NULL;

public:
    Stack() {};
    ~Stack() {};
    bool IsEmpty();
    T Top();
    void Push(T val);
    void Pop();
};

template<typename T>
bool Stack<T>::IsEmpty()
{
    return m_count <= 0;
}

template<typename T>
T Stack<T>::Top()
{
    return m_top->Value;
}

template <typename T>
void Stack<T>::Push(T val)
{
    Node<T>* node = new Node(val); 
    node->Next = m_top;
    m_top = node;

    m_count++;
}

template <typename T>
void Stack<T>::Pop()
{
    if (IsEmpty())
        return;
    
    Node<T>* node = m_top;

    m_top = m_top->Next;

    delete node;

    m_count--;
}

bool IsValid(char expression[])
{
    int n = strlen(expression);
    Stack<char> stackChar = Stack<char>();

    for (int i = 0; i < n; i++)
    {
        if (expression[i] == '{')
            stackChar.Push('{');
        else if (expression[i] == '[')
            stackChar.Push('[');
        else if (expression[i] == '(')
            stackChar.Push('(');
        else if (expression[i] == '}' ||
            expression[i] == ']' ||
            expression[i] == ')')
        {
            if (expression[i] == '}' && 
                (stackChar.IsEmpty() || stackChar.Top() != '{'))
                return false;
            else if (expression[i] == ']' &&
                (stackChar.IsEmpty() || stackChar.Top() != '['))
                return false;
            else if(expression[i] == ')' &&
                (stackChar.IsEmpty() || stackChar.Top() != '('))
                return false;
            // VALID
            else
                stackChar.Pop();
        }
    }
    // If the stack is empty,
    // the expression is valid
    // otherwise it's invalid
    if (stackChar.IsEmpty())
        return true;
    else
        return false;
}

int main()
{
    Stack<int> stackInt = Stack<int>();

    // Store several numbers to the stack
    stackInt.Push(32);
    stackInt.Push(47);
    stackInt.Push(18);
    stackInt.Push(59);
    stackInt.Push(88);
    stackInt.Push(91);
    // list the element of stack
    while(!stackInt.IsEmpty())
    {
        // Get the top element
        cout << stackInt.Top() << " - ";
        // Remove the top element
        stackInt.Pop();
    }
    cout << "END" << endl;

    // Prepare array for storing
    // the expression
    char expr[1000];
    expr[0] = '(';
    expr[1] = '{';

    // Check the validity
    bool bo = IsValid(expr);
    // Notify the user
    cout << endl;
    cout << "The " << expr << " expression is ";
    if(bo)
    cout << "valid";
    else
    cout << "invalid";
    cout << endl;
    return 0;

    return 0;
}
