#include <iostream>
using namespace std;

template <typename T>
class DoublyNode
{
public:
    T Value;
    DoublyNode<T> *Next = NULL;
    DoublyNode<T> *Previous = NULL;

    DoublyNode(T value) : Value(value), Next(NULL), Previous(NULL) {}
    ~DoublyNode() {  };
};

template <typename T>
class Deque
{
private:
    int m_count = 0;
    DoublyNode<T>* m_front = NULL;
    DoublyNode<T>* m_back = NULL;

public:
    Deque() {};
    ~Deque() {};

    bool IsEmpty();
    T Front();
    T Back();
    void EnqueueFront(T val);
    void EnqueueBack(T val);
    void DequeueFront();
    void DequeueBack();
};

template<typename T>
bool Deque<T>::IsEmpty()
{
    return m_count <= 0;
}

template<typename T>
T Deque<T>::Front()
{
    return m_front->Value;
}

template<typename T>
T Deque<T>::Back()
{
    return m_back->Value;
}

template<typename T>
void Deque<T>::EnqueueFront(T val)
{
    DoublyNode<T>* node = new DoublyNode(val);
    node->Next = m_front;
    if (m_front != NULL)
        m_front->Previous = node;
    
    m_front = node;

    if (m_count == 0)
        m_back = node;


    m_count++;
}

template<typename T>
void Deque<T>::EnqueueBack(T val)
{
    if (m_count == 0)
    {
        EnqueueFront(val);
        return;
    }

    DoublyNode<T>* node = new DoublyNode(val);

    node->Previous = m_back;
    m_back->Next = node;
    m_back = node;

    m_count++;
}

template<typename T>
void Deque<T>::DequeueFront()
{
    if (m_count == 0)
        return;

    DoublyNode<T>* node = m_front;

    m_front = m_front->Next;
    delete node;

    if (m_front != NULL)
        m_front->Previous = NULL;

    m_count--;
}

template<typename T>
void Deque<T>::DequeueBack()
{
    if (m_count == 0)
        return;
    else if (m_count == 1)
    {
        DequeueFront();
        return;
    }
    DoublyNode<T>* node = m_back;

    m_back = m_back->Previous;

    m_back->Next = NULL;

    delete node;

    m_count--;
}

int main()
{
    // NULL
    Deque<int> deque = Deque<int>();
    // Enqueue several numbers to the deque
    // 26
    deque.EnqueueFront(26);
    // 26 - 78
    deque.EnqueueBack(78);
    // 26 - 78 - 44
    deque.EnqueueBack(44);
    // 91 - 26 - 78 - 44
    deque.EnqueueFront(91);
    // 35 - 91 - 26 - 78 - 44
    deque.EnqueueFront(35);
    // 35 - 91 - 26 - 78 - 44 - 12
    deque.EnqueueBack(12);
    // list the element of queue
    while(!deque.IsEmpty())
    {
    // Get the front element
    cout << deque.Back() << " - ";
    // Remove the front element
    deque.DequeueBack();
    }
    cout << "END" << endl;
    return 0;
}