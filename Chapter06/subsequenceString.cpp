#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<string> GenerateSubsequences(string str)
{
    vector<string> subsequences;

    int strLength = str.length();
    int bitCounter = pow(2, strLength);

    for (int i = 0; i < bitCounter; i++)
    {
        // temporary variable to store current
        // subsequence
        string subsequence = "";
        for (int j = 0; j < strLength; j++)
        {
            // Check if j-th bit in the bitCounter is set
            // If so, pick j-th character from str
            if (i & (1 << j))
            {
                subsequence += str[j];
            }
        }
        subsequences.push_back(subsequence);
    }

    return subsequences;
}

bool IsSubsequence(string str1, string str2, int x, int y)
{
    if (x = 0)
        return true;

    if (y == 0)
        return false;

    if (str1[x - 1] == str2[y - 1])
        return IsSubsequence(str1, str2, x - 1, y - 1);
    else
        return IsSubsequence(str1, str2, x, y - 1);
}

int main()
{
    cout << "Subsequence Generator" << endl;
    // Input string
    string str;
    cout << "Input string -> ";
    getline(cin, str);
    // Generate subsequences
    vector<string> myvector = GenerateSubsequences(
    str);
    // Show the result to user
    cout << "All subsequences of '" << str;
    cout << "':" << endl;
    for (
    vector<string>::iterator it = myvector.begin();
    it != myvector.end();
    ++it)
    {
    cout << *it << " ";
    }
    cout << endl;
    return 0;
}