#include <iostream>

using namespace std;

class TreeNode
{
    public:
        TreeNode() {};
        ~TreeNode() {};

        int Key;
        TreeNode* Left = NULL;
        TreeNode* Right = NULL;

        TreeNode(int key) : Key(key) {}
};

void CreateBinaryTree()
{
    TreeNode* root = new TreeNode(1);
    root->Left = new TreeNode(2);
    root ->Right = new TreeNode(3);

    root->Left->Left = new TreeNode(4);
    root->Left->Right = new TreeNode(5);

    root->Right->Left = new TreeNode(6);
    root->Right->Right = new TreeNode(7);
}

class BSTNode
{
    public:
        BSTNode() {};
        ~BSTNode() {};
        int Key;
        BSTNode* Left = NULL;
        BSTNode* Right = NULL;
        BSTNode* Parent = NULL;

        BSTNode(int key) : Key(key) {}
};

class BST
{
private:
    BSTNode * root;

protected:
    BSTNode * Insert(BSTNode * node, int key);
    void PrintTreeInOrder(BSTNode * node);
    BSTNode * Search(BSTNode * node, int key);
    int FindMin(BSTNode * node);
    int FindMax(BSTNode * node);
    int Successor(BSTNode * node);
    int Predecessor(BSTNode * node);
    BSTNode * Remove(BSTNode * node, int key);

public:
    BST() {};
    void Insert(int key);
    void PrintTreeInOrder();
    bool Search(int key);
    int FindMin();
    int FindMax();
    int Successor(int key);
    int Predecessor(int key);
    void Remove(int v);
};

/// @brief 
/// @param node = root node
/// @return 
BSTNode* BST::Insert(BSTNode* node, int key)
{
    if (node == NULL)
        node = new BSTNode(key);
    else if (node->Key < key)
    {
        node->Right = Insert(node->Right, key);
        node->Right->Parent = node;
    }
    else
    {
        node->Left = Insert(node->Left, key);
        node->Left->Parent = node;
    }
    return node;
}

void BST::Insert(int key)
{
    root = Insert(root, key);
}

void BST::PrintTreeInOrder(BSTNode* node)
{
    if (node == NULL)
        return;
    
    PrintTreeInOrder(node->Left);

    cout << node->Key << " ";

    PrintTreeInOrder(node->Right);
}

void BST::PrintTreeInOrder()
{
    PrintTreeInOrder(root);
    cout << endl;
}

BSTNode* BST::Search(BSTNode* node, int key)
{
    if (node == NULL)
        return NULL;
    
    if (node->Key == key)
        return node;
    else if (node->Key < key)
        return Search(node->Right, key);
    else
        return Search(node->Left, key);
}

bool BST::Search(int key)
{
    BSTNode* result = Search(root, key);
    return result != NULL;
}

int BST::FindMin(BSTNode* node)
{
    if (node == NULL)
        return -1;
    else if (node->Left == NULL)
        return node->Key;
    else
        return FindMin(node->Left);
}

int BST::FindMin()
{
    return FindMin(root);
}

int BST::FindMax(BSTNode* node)
{
    if (node == NULL)
        return -1;
    else if (node->Right == NULL)
        return node->Key;
    else
        return FindMax(node->Right);
}

int BST::FindMax()
{
    return FindMax(root);
}

int BST::Successor(BSTNode* node)
{
    if (node == NULL)
        return -1;

    if (node->Right != NULL)
        return FindMin(node->Right);
    else
    {
        BSTNode* parentNode = node->Parent;
        BSTNode* currentNode = node;

        while(parentNode != NULL && currentNode == parentNode->Right)
        {
            currentNode = parentNode;
            parentNode = currentNode->Parent;
        }
        return parentNode == NULL ? -1 : parentNode->Key;
    }
}

int BST::Successor(int key)
{
    BSTNode* node = Search(root, key);
    return node == NULL ? -1 : Successor(node); 
}

int BST::Predecessor(BSTNode* node)
{
    if (node == NULL)
        return -1;
    
    if (node->Left != NULL)
        return FindMax(node->Left);
    else
    {
        BSTNode* parentNode = node->Parent;
        BSTNode* currentNode = node;

        while (parentNode != NULL && parentNode->Left == currentNode)
        {
            currentNode = parentNode;
            parentNode = currentNode->Left;
        }
        return parentNode == NULL ? -1 : parentNode->Key;
    }
}

int BST::Predecessor(int key)
{
    BSTNode* node = Search(root, key);
    return node == NULL ? -1 : Predecessor(node);
}

BSTNode* BST::Remove(BSTNode* node, int key)
{
    if (node == NULL)
        return NULL;

    if (node->Key == key)
    {
        // It is a leaf
        if (node->Left == NULL && node->Right == NULL)
            node = NULL;
        else if (node->Left == NULL && node->Right != NULL)
        {
            node->Right->Parent = node->Parent;
            node = node->Right;
        }
        else if (node->Left != NULL && node->Right == NULL)
        {
            node->Left->Parent = node->Parent;
            node = node->Left;
        }
        else
        {
            int successorKey = Successor(key);
            node->Key = successorKey;
            node->Right = Remove(node->Right, successorKey);
        }
    }
    else if (node->Key < key)
        node->Right = Remove(node->Right, key);
    else
        node->Left = Remove(node->Left, key);

    return node;
}

void BST::Remove(int key)
{
    Remove(root, key);
}

int main()
{
    BST* tree = new BST();
    // Define key value to be inserted to BST
    int keys[] = {23, 12, 31, 3, 15, 7, 29, 88, 53};
    // Inserting keys
    for(const int& key : keys)
        tree->Insert(key);

    tree->PrintTreeInOrder();
    
    cout << "Search key 31: ";
    if (tree->Search(31))
        cout << "found";
    else
        cout << "NOT found";

    cout << endl;

    cout << "Min. Key : " << tree->FindMin();
    cout << endl;
    cout << "Max. Key : " << tree->FindMax();
    cout << endl;

    // Finding successor
    // Successor(31) should be 53
    // Successor(15) should be 23
    // Successor(88) should be -1 or NULL
    cout << "Successor(31) = ";
    cout << tree->Successor(31) << endl;
    cout << "Successor(15) = ";
    cout << tree->Successor(15) << endl;
    cout << "Successor(88) = ";
    cout << tree->Successor(88) << endl;
    // Finding predecessor
    // Predecessor(12) should be 7
    // Predecessor(29) should be 23
    // Predecessor(3) should be -1 or NULL
    cout << "Predecessor(12) = ";
    cout << tree->Predecessor(12) << endl;
    cout << "Predecessor(29) = ";
    cout << tree->Predecessor(29) << endl;
    cout << "Predecessor(3) = ";
    cout << tree->Predecessor(3) << endl;

    // Removing a key
    cout << "Removing key 15" << endl;
    tree->Remove(15);
    cout << "Removing key 53" << endl;
    tree->Remove(53);
    // Printing all keys again
    // Key 15 and 53 should be disappeared
    cout << "Tree keys: ";
    tree->PrintTreeInOrder();

    return 0;
}