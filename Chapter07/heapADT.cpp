#include <iostream>
#include <vector>

using namespace std;

// Used to implement priority queue
class BinaryHeap
{
private:
    int HeapSize = 0;
    vector<int> vect = vector<int>();

    int p(int i) { return i >> 1; }
    int l(int i) { return i << 1; }
    int r(int i) { return (i << 1) + i; }

    void ShiftUp(int index);
    void ShiftDown(int index);

public:
    BinaryHeap() {};

    bool IsEmpty();
    void Insert(int key);
    int ExtractMax();
    int GetMax();
    
};

bool BinaryHeap::IsEmpty()
{
    return HeapSize == 0;
}

void BinaryHeap::ShiftUp(int index)
{
    // No need to shift the root
    if (index == 1)
        return;

    auto returned = p(index);
    
    if (vect[index] > vect[p(index)])
    {
        // Swap upwards
        swap(vect[index], vect[p(index)]);

        // recurce until root
        ShiftUp(p(index));
    }
}

void BinaryHeap::Insert(int key)
{
    if (HeapSize + 1 >= int(vect.size()))
        vect.push_back(0);

    vect[++HeapSize] = key;

    ShiftUp(HeapSize);
}

int BinaryHeap::GetMax()
{
    return vect[1];
}

void BinaryHeap::ShiftDown(int index)
{
    if (index < HeapSize)
        return;

    int swapId = index;

    if (l(index) <= HeapSize && vect[swapId] < vect[r(index)])
        swapId = r(index);

    if (swapId != index)
    {
        swap(vect[index], vect[swapId]);

        ShiftDown(swapId);
    }
}

// Remove last element after extracting
int BinaryHeap::ExtractMax()
{
    // get the value
    int maxVal = vect[1];

    // swap with the last existing leaf
    swap(vect[1], vect[HeapSize - 1]);

    // fix the property downward
    ShiftDown(1);

    return maxVal;
}

int main()
{
    BinaryHeap* priorityQueue = new BinaryHeap();

    cout << "Is queue empty? ";
    if (priorityQueue->IsEmpty())
        cout << "TRUE";
    else
        cout << "FALSE";
    cout << endl;
    priorityQueue->Insert(14);
    cout << "Insert 14 to queue" << endl;

    priorityQueue->Insert(53);
    cout << "Insert 53 to queue" << endl;
    priorityQueue->Insert(8);
    cout << "Insert 8 to queue" << endl;
    priorityQueue->Insert(32);
    cout << "Insert 32 to queue" << endl;

    // Peek the maximum element
    // It should be 53
    cout << "GetMax() = ";
    cout << priorityQueue->GetMax();
    cout << endl;

    // Extract maximum element
    cout << "ExtractMax() = ";
    cout << priorityQueue->ExtractMax();
    cout << endl;
}