#include <iostream>
#include <vector>
#include <queue>


using namespace std;

class MinHeapNode
{
public:
    char Data;
    unsigned Frequency;

    MinHeapNode* LeftChild;
    MinHeapNode* RightChild;

    MinHeapNode(char data, unsigned freq)
    {
        LeftChild = NULL;
        RightChild = NULL;

        this->Data = data;
        this->Frequency = freq;
    }
};

class compare
{
public:
    bool operator()(MinHeapNode* left, MinHeapNode* right)
    {
        return (left->Frequency > right->Frequency);
    }
};

void HuffmanCodes(char data[], int freq[], int dataSize)
{
    MinHeapNode* left, *right, *top;

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for(int i = 0; i < dataSize; i++)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with
        // frequency equal to the sum of the
        // two nodes frequencies. Make the
        // two extracted node as left and right children
        // of this new node. Add this node
        // to the min heap '$' is a special value
        // for internal nodes, not used
        top = new MinHeapNode('$', left->Frequency + right->Frequency);   

        top->LeftChild = left;
        top->RightChild = right;

        minHeap.push(top);
    }

    PrintCodes(minHeap.top(), "");
}

void PrintCodes(MinHeapNode* root, string str)
{
    if (!root)
        return;

    if (root->Data != '$')
    {
        cout << root->Data << ": ";
        cout << str << endl;
    }

    PrintCodes(root->LeftChild, str + "0");
    PrintCodes(root->RightChild, str + "1");
}