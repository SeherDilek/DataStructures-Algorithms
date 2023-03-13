#include <iostream>
#include <list>

using namespace std;

// Open addressing technique
#define TABLE_SIZE 7

class HashElement
{
public:
    int key;
    string value;

    HashElement(int key, string value)
    {
        this->key = key;
        this->value = value;
    }
};

class HashTable
{
private:
    int currentSize;
    HashElement* *arr;
    HashElement* deletedElement;

    int HashFunction(int key);
public:
    HashTable()
    {
        currentSize = 0;
        arr = new HashElement*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
            arr[i] = NULL;
        
        deletedElement = new HashElement(-1, "");
    };

    void Insert(int key, string value);
    string Search(int key);
    void Remove(int key);
    bool IsEmpty();
    void PrintHashTable();
};



int HashTable::HashFunction(int key)
{
    return key % TABLE_SIZE;
}

void HashTable::Insert(int key, string value)
{
    if (currentSize >= TABLE_SIZE)
        return;

    auto temp = new HashElement(key, value);

    int hashIndex = HashFunction(key);

    // int index = 0;
    while (arr[hashIndex] != NULL &&
        arr[hashIndex]->key != key &&
        arr[hashIndex]->key != -1)
    {
        // linear probing
        hashIndex++;

        // // quadratic probing
        // hashIndex += index * index;
        // index++;

        // // double hashing
        // hashIndex += index * hashIndex;
        // index++;

        hashIndex %= TABLE_SIZE;
    }

    if (arr[hashIndex] == NULL ||
        arr[hashIndex]->key == -1)
    {
        currentSize++;
        arr[hashIndex] = temp;
    }
}

string HashTable::Search(int key)
{
    int hashKey = HashFunction(key);

    while(arr[hashKey] != NULL && arr[hashKey]->key != deletedElement->key)
    {
        if (arr[hashKey]->key == key)
            return arr[hashKey]->value;

        // also keep looking for the key
        // using linear probing

        hashKey++;
        hashKey %= TABLE_SIZE;
    }

    return "";
}

void HashTable::Remove(int key)
{
    int hashKey = HashFunction(key);

    while(arr[hashKey] != NULL && arr[hashKey]->key != deletedElement->key)
    {
        if (arr[hashKey]->key == key)
        {
            arr[hashKey] = deletedElement;

            --currentSize;

            return;
        }

        // also keep looking for the key
        // using linear probing

        hashKey++;
        hashKey %= TABLE_SIZE;
    }
}

bool HashTable::IsEmpty()
{
    return currentSize == 0;
}

void HashTable::PrintHashTable()
{
    for (int i = 0; i < currentSize; i++)
    {
        if (arr[i] != NULL && arr[i]->key != -1)
        {
            cout << "Cell: " << i;
            cout << " Key: " << arr[i]->key;
            cout << " Value: " << arr[i]->value;
            cout << endl;
        }
    }
}

int main()
{
    cout << "Hash Table - Open Addressing - Linear Probe";
    cout << endl;
    HashTable * hashTable = new HashTable();
    // Check if hash table is empty
    bool b = hashTable->IsEmpty();
    if(b)
        cout << "Hash table is empty";
    else
        cout << "Hash table is not empty";
    cout << endl;
    // Adding a data then
    // check if hash table is empty
    cout << "Adding a data" << endl;
    hashTable->Insert(434, "Dylan");
    b = hashTable->IsEmpty();
    if(b)
        cout << "Hash table is empty";
    else
        cout << "Hash table is not empty";
    cout << endl;
    // Adding others data
    hashTable->Insert(391, "Dominic");
    hashTable->Insert(806, "Adam");
    hashTable->Insert(117, "Lindsey");
    hashTable->Insert(548, "Cameron");
    hashTable->Insert(669, "Terry");
    hashTable->Insert(722, "Brynn");
    hashTable->Insert(276, "Jody");
    hashTable->Insert(953, "Frankie");
    hashTable->Insert(895, "Vanessa");
    // Print the table
    hashTable->PrintHashTable();
    // Search key 669
    // it should be found
    int key = 669;
    cout << "Search value for key ";
    cout << key << endl;
    string name = hashTable->Search(key);
    if(name != "")
    {
        cout << "Value for key " << key;
        cout << " is " << name;
    }
    else
    {
        cout << "Value for key " << key;
        cout << " is not found";
    }
    cout << endl;
    // Remove key 669
    // then search the key
    // it should not be found
    cout << "Remove node of key ";
    cout << key << endl;
    hashTable->Remove(key);
    name = hashTable->Search(key);
    if(name != "")
    {
        cout << "Value for key " << key;
        cout << " is " << name;
    }
    else
    {
        cout << "Value for key " << key;
        cout << " is not found";
    }
    cout << endl;
    return 0;
}