#include <iostream>
#include <list>

using namespace std;

// Seperate chaining
#define TABLE_SIZE 7

class HashTable
{
private:
    std::list<std::pair<int, string>> tableList[TABLE_SIZE];

    int HashFunction(int key);

public:
    HashTable() {};

    void Insert(int key, string value);
    string Search(int key);
    void Remove(int key);
    bool IsEmpty();
};

int HashTable::HashFunction(int key)
{
    return key % TABLE_SIZE;
}

void HashTable::Insert(int key, string value)
{
    bool isKeyFound = false;

    int hashKey = HashFunction(key);

    for (auto& keyValue : tableList[hashKey])
    {
        if (keyValue.first == key)
        {
            isKeyFound = true;
            keyValue.second = value;
        }
    }
    
    if (!isKeyFound)
        tableList[hashKey].emplace_back(key, value);
}

string HashTable::Search(int key)
{
    int hashKey = HashFunction(key);

    for (auto& keyValue : tableList[hashKey])
    {
        if (keyValue.first == key)
            return keyValue.second;
    }

    return "";
}

void HashTable::Remove(int key)
{
    int hashKey = HashFunction(key);

    auto& cell = tableList[hashKey];
    for (auto it = cell.begin(); it != cell.end(); it++)
    {
        if (it->first == key)
        {
            cell.erase(it);
            break;
        }
    }
}

bool HashTable::IsEmpty()
{
    int totalElement = 0;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        totalElement += (int)tableList[i].size();

        if (totalElement > 0)
            return false;
    }
    return true;
}

int main()
{
    HashTable* hashTable = new HashTable();

    if (hashTable->IsEmpty())
        cout << "Hash table is empty";
    else
        cout << "Hash table is not empty";

    cout << endl;
    
    // check if hash table is empty
    cout << "Adding a data" << endl;
    hashTable->Insert(434, "Dylan");
    
    if(hashTable->IsEmpty())
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
    hashTable->Remove(key);name = hashTable->Search(key);
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
}