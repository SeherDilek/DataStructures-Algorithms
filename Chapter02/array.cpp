#include <iostream>
using namespace std;

int main()
{
    int *ptr = new int[5] {21, 47, 87, 35, 92};
    
    // Display each element value
    // by incrementing the pointer (ptr++)
    cout << "Using pointer increment" << endl;
    cout << "Value\tAddress" << endl;
    while(*ptr)
    {
        cout << *ptr << "\t";
        cout << ptr << endl;
        ptr++;
    }

    ptr = ptr - 5;
    // Display each element value
    // by accessing pointer index (ptr[])
    cout << "Using pointer index" << endl;
    cout << "Value\tAddress" << endl;
    for(int i = 0; i < 5; ++i)
    {
        cout << ptr[i] << "\t";
        cout << &ptr[i] << endl;
    }
    return 0;
}