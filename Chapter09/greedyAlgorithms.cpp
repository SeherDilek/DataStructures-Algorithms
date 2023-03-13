#include <iostream>
#include <vector>

using namespace std;

void MinimalChangeCoin(double changingNominal)
{
    double denom[] = { 0.01, 0.05, 0.10, 0.25, 1, 2, 5, 10, 20, 50, 100 };

    int totalDenom = sizeof(denom) / sizeof(denom[0]);
    vector<double> result;

    for (int i = totalDenom - 1; i >= 0; i--)
    {
        while (changingNominal >= denom[i])
        {
            changingNominal -= denom[i];
            result.push_back(denom[i]);
        }
        
        if (changingNominal < denom[0])
            break;
    }

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
}

// Huffman coding


int main()
{
    cout << "Coin Change Problem" << endl;

    // Initialize the change nominal
    float change = 17.61;
    // Getting the minimal
    cout << "Minimal number of change for ";
    cout << change << " is " << endl;
    MinimalChangeCoin(change);

    return 0;

}