#include <iostream>

using namespace std;

class Node
{
public:
    int Value;
    Node *Next;

    Node(int value) : Value(value), Next(NULL) {}
};

bool CompareAllMatchedElements(Node* ptr1, Node* ptr2)
{
    if (ptr1 != NULL && ptr2 == NULL)
        return false;
    
    if (ptr1 == NULL)
        return true;

    if (ptr1->Value == ptr2->Value)
        return CompareAllMatchedElements(ptr1->Next, ptr2->Next);
    else
        return false;
}

bool SublistSearch(Node* firstList, Node* secondList)
{
    if (firstList == NULL && secondList == NULL)
        return true;

    if (firstList == NULL && secondList != NULL
        || firstList != NULL && secondList == NULL)
        return false;
    
    if (firstList->Value == secondList->Value)
    {
        if (CompareAllMatchedElements(firstList, secondList))
            return true;
    }

    return SublistSearch(firstList, secondList->Next);
}

int main()
{
    cout << "Sublist Search" << endl;
    // Initialize first list
    // 23 -> 30 -> 41
    Node * node1_c = new Node(41);
    Node * node1_b = new Node(30);
    node1_b->Next = node1_c;
    Node * node1_a = new Node(23);
    node1_a->Next = node1_b;
    // Initialize second list
    // 10 -> 15 -> 23 -> 30 -> 41 -> 49
    Node * node2_f = new Node(49);
    Node * node2_e = new Node(41);
    node2_e->Next = node2_f;
    Node * node2_d = new Node(30);
    node2_d->Next = node2_e;
    Node * node2_c = new Node(23);
    node2_c->Next = node2_d;
    Node * node2_b = new Node(15);
    node2_b->Next = node2_c;
    Node * node2_a = new Node(10);
    node2_a->Next = node2_b;
    // Notify user the result
    // if the return is true
    // the searched value is found
    cout << "Result: second list is ";
    if(SublistSearch(node1_a, node2_a))
    {
        cout << "found";
    }
    else
    {
        cout << "not found";
    }
        cout << " in first list." << endl;
    return 0;
}