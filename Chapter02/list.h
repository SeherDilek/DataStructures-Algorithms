class List
{
private:
    int m_count;
    int *m_items;

public:
    List() {}
    ~List() {}
    int Get(int index);
    void Insert(int index, int val);
    int Search(int val);

    void Remove(int index);
    int Count();
};