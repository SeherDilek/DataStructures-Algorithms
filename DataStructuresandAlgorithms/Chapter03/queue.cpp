#include <iostream>
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
class Queue
{
private:
    int m_count = 0;
    Node<T>* m_front = NULL;
    Node<T>* m_back = NULL;

public:
    Queue() {};
    ~Queue() {};

    bool IsEmpty();
    T Front();
    void Enqueue(T val);
    void Dequeue();
};

template<typename T>
bool Queue<T>::IsEmpty()
{
    return m_count <= 0;
}

template <typename T>
T Queue<T>::Front()
{
    return m_front->Value;
}
template <typename T>
void Queue<T>::Enqueue(T val)
{
    Node<T>* node = new Node(val);
    if (m_count == 0)
    {
        m_front = node;
        m_back = node;
    }
    else
    {
        m_back->Next = node;
        m_back = node;
    }
    m_count++;
} 

template <typename T>
void Queue<T>::Dequeue()
{
    if (m_count == 0)
        return;

    Node<T>* node = m_front;
    m_front = m_front->Next;

    delete node;

    m_count--; 
}int main()
{
    // NULL
    Queue<int> queueInt = Queue<int>();
    // Enqueue several numbers to the queue
    queueInt.Enqueue(35);
    queueInt.Enqueue(91);
    queueInt.Enqueue(26);
    queueInt.Enqueue(78);
    queueInt.Enqueue(44);
    queueInt.Enqueue(12);
    // list the element of queue
    while(!queueInt.IsEmpty())
    {
    // Get the front element
    cout << queueInt.Front() << " - ";
    // Remove the front element
    queueInt.Dequeue();
    }
    cout << "END" << endl;
    return 0;
}