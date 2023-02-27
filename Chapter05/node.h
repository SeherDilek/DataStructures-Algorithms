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