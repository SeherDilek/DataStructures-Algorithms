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
void PrintNode(Node<T>* node)
{
    while (node != NULL)
    {
        cout << node->Value << " -> ";
        node = node->Next;
    }
    cout << "NULL" << endl;
}

template <typename T>
class LinkedList
{
private:
    int m_count = 0;

public:
    // Constructor
    LinkedList() {};
    ~LinkedList() { cout << "bittim gozun aydin bittim helal olsun" << endl;};

    Node<T>* Head;
    Node<T>* Tail;

    Node<T>* Get(int index);

    void InsertHead(T val);
    void InsertTail(T val);
    void Insert(int index, T val);

    int Search(T val);

    void RemoveHead();
    void RemoveTail();
    void Remove(int index);

    int Count() {return m_count;};
    void PrintList();
};

template <typename T>
Node<T>* LinkedList<T>::Get(int index)
{
    if (index < 0 || index > m_count)
        return NULL;

    Node<T>* node = Head;

    for (int i = 0; i < index; i++)
        node = node->Next;
    return node;
}

template <typename T>
void LinkedList<T>::InsertHead(T val)
{
    Node<T>* node = new Node<T>(val);
    node->Next = Head;
    Head = node;

    if (m_count == 0)
        Tail = Head;
    
    m_count++;
}

template <typename T>
void LinkedList<T>::InsertTail(T val)
{
    if (m_count == 0)
    {
        InsertHead(val);
        return;
    }
    Node<T>* node = new Node<T>(val);
    Tail->Next = node;
    Tail = node;

    m_count++;
}

template <typename T>
void LinkedList<T>::Insert(int index, T val)
{
    if (index == 0)
    {
        InsertHead(val);
        return;
    }
    else if (index == m_count - 1)
    {
        InsertTail(val);
        return;
    }

    auto prevNode = Head;
    for (int i = 0; i < index - 1; i++)
        prevNode = prevNode->Next;

    auto nextNode = prevNode->Next;

    Node<T>* node = new Node<T>(val);
    node->Next = nextNode;
    prevNode->Next = node;

    m_count++;
}

template <typename T>
int LinkedList<T>::Search(T val)
{
    if (m_count == 0)
        return -1;

    int index = 0;
    Node<T>* node = Head;
    while(node->Value != val)
    {
        index++;
        node = node->Next;

        if(node == NULL)
            return -1;
    }

    return index;
}

template <typename T>
void LinkedList<T>::RemoveHead()
{
    if (m_count == 0)
        return;

    auto node = Head;
    Head = Head->Next;

    delete node;

    m_count--;
}

template <typename T>
void LinkedList<T>::RemoveTail()
{
    if (m_count == 0)
        return;
    else if (m_count == 1)
    {
        RemoveHead();
        return;
    }

    auto prevNode = Head;
    auto node = prevNode->Next;
    while (node->Next != NULL)
    {
        prevNode = prevNode->Next;
        node = node->Next;
    }

    prevNode->Next = NULL;
    Tail = prevNode;

    delete node;

    m_count--;
}

template <typename T>
void LinkedList<T>::Remove(int index)
{
    if (m_count == 0)
        return;
    else if (m_count == 1)
    {
        RemoveHead();
        return;
    }
    
    if (index == 0)
    {
        RemoveHead();
        return;
    }
    else if (index == m_count - 1)
    {
        RemoveTail();
        return;
    }
    else if (index > m_count || index < 0)
        return;

    auto prevNode = Head;
    for (int i = 0; i < index - 1; i++)
    {
        prevNode = prevNode->Next;
    }

    auto node = prevNode->Next;
    auto nextNode = node->Next;

    prevNode->Next = nextNode;

    delete node;

    m_count--;
}

template <typename T>
void LinkedList<T>::PrintList()
{
    Node<T> * node = Head;
    while(node != NULL)
    {
        std::cout << node->Value << " -> ";
        node = node->Next;
    }
    std::cout << "NULL" << std::endl;
}

int main()
{
    LinkedList<int> list = LinkedList<int>();

    list.InsertHead(43);
    list.InsertHead(76);
    list.InsertTail(15);
    list.InsertTail(44);

    // Print the list element
    cout << "First Printed:" << endl;
    list.PrintList();
    cout << endl;
    // 76->43->15->44->100->NULL
    list.Insert(4, 100);
    // 76->43->15->48->44->100->NULL
    list.Insert(3, 48);
    // 22->76->43->15->48->44->100->NULL
    list.Insert(0, 22);
    // Print the list element
    cout << "Second Printed:" << endl;
    list.PrintList();
    cout << endl;

    // Get value of the second index
    // It should be 43
    cout << "Get value of the second index:" << endl;
    Node<int> * get = list.Get(2);
    if(get != NULL)
    cout << get->Value;
    else
    cout << "not found";
    cout << endl << endl;
    // Find the position of value 15
    // It must be 3
    cout << "The position of value 15:" << endl;
    int srch = list.Search(15);
    cout << srch << endl;
    // Remove first element
    cout << "Remove the first element:" << endl;
    list.Remove(0);
    // 76->43->15->48->44->100->NULL
    list.PrintList();
    cout << endl;
    // Remove fifth element
    cout << "Remove the fifth element:" << endl;
    list.Remove(4);
    // 76->43->15->48->100->NULL
    list.PrintList();
    cout << endl;
    // Remove tenth element
    cout << "Remove the tenth element:" << endl;
    list.Remove(9);
    // Nothing happen
    // 76->43->15->48->100->NULL
    list.PrintList();
    cout << endl;
    return 0;
}