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
    ~DoublyNode() { cout << "node is deleted." << endl; }
};

template <typename T>
class DoublyLinkedList
{
private:
    int m_count = 0;

public:
    // Constructor
    DoublyLinkedList() {};
    ~DoublyLinkedList() { cout << "bittim gozun aydin bittim helal olsun" << endl;};

    DoublyNode<T>* Head = NULL;
    DoublyNode<T>* Tail = NULL;

    DoublyNode<T>* Get(int index);

    void InsertHead(T val);
    void InsertTail(T val);
    void Insert(int index, T val);

    int Search(T val);

    void RemoveHead();
    void RemoveTail();
    void Remove(int index);

    int Count() {return m_count;};
    void PrintList();

    void PrintListBackward();
};

template<typename T>
void DoublyLinkedList<T>::RemoveTail()
{
    if (m_count == 0)
        return;

    if (m_count == 1)
    {
        RemoveHead();
        return;
    }

    DoublyNode<T>* node = Tail;
    Tail = Tail->Previous;
    Tail->Next = NULL;

    delete node;

    m_count--;
} 

template<typename T>
void DoublyLinkedList<T>::RemoveHead()
{
    if (m_count == 0)
        return;

    DoublyNode<T>* node = Head;
    Head = Head->Next;

    delete node;

    if (Head != NULL)
        Head->Previous = NULL;

    m_count--;
}

template<typename T>
void DoublyLinkedList<T>::Remove(int index)
{
    // Do nothing if list is empty
    if(m_count == 0)
        return;
    // Do nothing if index is out of bound
    if(index < 0 || index >= m_count)
        return;
    // If removing the current Head
    if(index == 0)
    {
        RemoveHead();
        return;
    }
    // If removing the current Tail
    else if(index == m_count - 1)
    {
        RemoveTail();
        return;
    }
    
    auto prevNode = Head;
    for (int i = 0; i < index - 1; i++)
        prevNode = prevNode->Next;

    auto node = prevNode->Next;
    auto nextNode = node->Next;

    prevNode->Next = nextNode;
    nextNode->Previous = prevNode;

    delete node;

    m_count--;
}

template<typename T>
void DoublyLinkedList<T>::InsertHead(T val)
{
    DoublyNode<T>* node = new DoublyNode(val);
    node->Next = Head;

    if (Head != NULL)
        Head->Previous = node;
    
    Head = node;

    if (m_count == 0)
        Tail = node;

    m_count++;
}

template<typename T>
void DoublyLinkedList<T>::InsertTail(T val)
{
    if (m_count == 0)
    {
        InsertHead(val);
        return;
    }
    DoublyNode<T>* node =  new DoublyNode<T>(val);
    Tail->Next = node;
    node->Previous = Tail;
    Tail = node;
    m_count++;
}

template<typename T>
void DoublyLinkedList<T>::Insert(int index, T val)
{
    if (index < 0 || index > m_count)
        return;

    if (index == 0)
    {
        InsertHead(val);
        return;
    }
    else if (index == m_count)
    {
        InsertTail(val);
        return;
    }

    auto prevNode = Head;
    for (int i = 0; i < index - 1; i++)
        prevNode = prevNode->Next;
    
    DoublyNode<T>* node = new DoublyNode(val);
    auto nextNode = prevNode->Next;
    
    prevNode->Next = node;
    node->Previous = prevNode;

    node->Next = nextNode;
    nextNode->Previous = node;

    m_count++;
}


template <typename T>
void DoublyLinkedList<T>::PrintListBackward()
{
    auto node = Tail;
    while(node != NULL)
    {
        std::cout << node->Value << " -> ";
        node = node->Previous;
    }
    std::cout << "NULL" << std::endl;
}

int main()
{
    // NULL
    DoublyLinkedList<int> linkedList = DoublyLinkedList<int>();
    // it will be printed backwardly
    // 43->NULL
    linkedList.InsertHead(43);
    // 43->76->NULL
    linkedList.InsertHead(76);
    // 15->43->76->NULL
    linkedList.InsertTail(15);
    // 44->15->43->76->NULL
    linkedList.InsertTail(44);
    // Print the list element
    cout << "First Printed:" << endl;
    linkedList.PrintListBackward();
    cout << endl;
    // 100->44->15->43->76->NULL
    linkedList.Insert(4, 100);
    // 100->44->48->15->43->76->NULL
    linkedList.Insert(3, 48);
    // 100->44->48->15->43->76->22->NULL
    linkedList.Insert(0, 22);
    // Print the list element
    cout << "Second Printed:" << endl;
    linkedList.PrintListBackward();
    cout << endl;

    linkedList.RemoveHead();
    return 0;
}