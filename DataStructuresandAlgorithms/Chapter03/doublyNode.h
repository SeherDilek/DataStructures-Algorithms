

template <typename T>
class DoublyNode
{
public:
    T Value;
    DoublyNode<T> *Next = NULL;
    DoublyNode<T> *Previous = NULL;

    DoublyNode(T value) : Value(value), Next(NULL), Previous(NULL) {}
    ~DoublyNode() {  };
};