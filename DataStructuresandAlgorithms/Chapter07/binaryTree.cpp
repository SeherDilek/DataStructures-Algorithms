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
        int Height = 0;

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

// Balanced tree is invented by Adelson-Velskii and Landis
// and named as AVL after them.
class AVL : public BST
{
private:
    BSTNode* root;

    int GetHeight(BSTNode* node);
    BSTNode* RotateLeft(BSTNode* node0);
    BSTNode* RotateRight(BSTNode* node0);
    BSTNode* Insert(BSTNode* node, int key);
    BSTNode* Remove(BSTNode* node, int key);
    int CalculateHeight(BSTNode* node);
    BSTNode* RotateIfNeeded(BSTNode* insertedNode);
public:
    AVL() { };

    void Insert(int key);
    void Remove(int key);
    void PrintTreeInOrder();
};

int AVL::GetHeight(BSTNode* node)
{
    return node == NULL ? -1 : node->Height;
}

BSTNode* AVL::RotateLeft(BSTNode* node)
{
    BSTNode* balancedNode = node->Right;
    balancedNode->Parent = node->Parent;

    node->Parent = balancedNode;

    node->Right = balancedNode->Left;
    
    if (balancedNode->Left != NULL)
        balancedNode->Left->Parent = node;

    balancedNode->Left = node;

    node->Height = CalculateHeight(node);
    balancedNode->Height = CalculateHeight(balancedNode);
    
    return balancedNode;
}
BSTNode* AVL::RotateRight(BSTNode* node)
{
    BSTNode* balancedNode = node->Left;
    balancedNode->Parent = node->Parent;

    node->Parent = balancedNode;

    node->Left = balancedNode->Right;

    if (balancedNode->Right != NULL)
        balancedNode->Right->Parent = node;

    balancedNode->Right = node;

    node->Height = CalculateHeight(node);
    balancedNode->Height = CalculateHeight(balancedNode);
    return balancedNode;
}

BSTNode* AVL::Insert(BSTNode* node, int key)
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

    return RotateIfNeeded(node);
}

BSTNode* AVL::Remove(BSTNode* node, int key)
{
    auto node1 = BST::Remove(node, key);

    if (node1 == NULL)
        return node1;

    return RotateIfNeeded(node1);
}

BSTNode* AVL::RotateIfNeeded(BSTNode* node)
{
    auto leftH = GetHeight(node->Left);
    auto rightH = GetHeight(node->Right);
    int balance = GetHeight(node->Left) - GetHeight(node->Right);
    // left heavy
    if (balance == 2)
    {
        // Left subtree's height
        int balance2 = GetHeight(node->Left->Left) - 
                        GetHeight(node->Left->Right);

        if (balance2 == 1)
            node = RotateRight(node);
        else
        {
            node->Left = RotateLeft(node->Left);
            node = RotateRight(node);
        }
    }
    else if (balance == -2)
    {
        int balance2 = GetHeight(node->Right->Left) - 
                        GetHeight(node->Right->Right);

        if (balance2 == -1)
            node = RotateLeft(node);
        else
        {
            node = RotateRight(node);
            node = RotateLeft(node);
        }
    }

    node->Height = CalculateHeight(node);

    return node;
}

int AVL::CalculateHeight(BSTNode* node)
{
    return max(GetHeight(node->Left), GetHeight(node->Right)) + 1;
}

void AVL::Remove(int key)
{
    AVL::Remove(root, key);
}

void AVL::Insert(int key)
{
    root = AVL::Insert(root, key);
}

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

void AVL::PrintTreeInOrder()
{
    BST::PrintTreeInOrder(root);
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
    // BST* tree = new BST();
    // // Define key value to be inserted to BST
    // int keys[] = {23, 12, 31, 3, 15, 7, 29, 88, 53};
    // // Inserting keys
    // for(const int& key : keys)
    //     tree->Insert(key);

    // tree->PrintTreeInOrder();
    
    // cout << "Search key 31: ";
    // if (tree->Search(31))
    //     cout << "found";
    // else
    //     cout << "NOT found";

    // cout << endl;

    // cout << "Min. Key : " << tree->FindMin();
    // cout << endl;
    // cout << "Max. Key : " << tree->FindMax();
    // cout << endl;

    // // Finding successor
    // // Successor(31) should be 53
    // // Successor(15) should be 23
    // // Successor(88) should be -1 or NULL
    // cout << "Successor(31) = ";
    // cout << tree->Successor(31) << endl;
    // cout << "Successor(15) = ";
    // cout << tree->Successor(15) << endl;
    // cout << "Successor(88) = ";
    // cout << tree->Successor(88) << endl;
    // // Finding predecessor
    // // Predecessor(12) should be 7
    // // Predecessor(29) should be 23
    // // Predecessor(3) should be -1 or NULL
    // cout << "Predecessor(12) = ";
    // cout << tree->Predecessor(12) << endl;
    // cout << "Predecessor(29) = ";
    // cout << tree->Predecessor(29) << endl;
    // cout << "Predecessor(3) = ";
    // cout << tree->Predecessor(3) << endl;

    // // Removing a key
    // cout << "Removing key 15" << endl;
    // tree->Remove(15);
    // cout << "Removing key 53" << endl;
    // tree->Remove(53);
    // // Printing all keys again
    // // Key 15 and 53 should be disappeared
    // cout << "Tree keys: ";
    // tree->PrintTreeInOrder();
    // cout << endl;

    AVL* avlTree = new AVL();
    int keys2[] = {69, 62, 46, 32, 24, 13 };
    // Inserting keys
    for(const int& key : keys2)
    {
        cout << "Inserting key " << endl;
        avlTree->Insert(key);
        avlTree->PrintTreeInOrder();
    }

    cout << "Tree keys: ";
    avlTree->PrintTreeInOrder();

    return 0;
}