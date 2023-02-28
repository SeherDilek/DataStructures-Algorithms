#include <iostream>
#include <vector>

using namespace std;

vector<int> SearchPattern(string targetString, string patternString)
{
    vector<int> vecIndex;
    int strLength = targetString.size();
    int patternLength = patternString.length();

    if (patternLength > strLength)
        return vecIndex;

    for (int i = 0; i <= strLength - patternLength; i++)
    {
        int j;
        for (j = 0; j < patternLength; j++)
        {
            if (targetString[i + j] != patternString[j])
                break;
        }

        if (j == patternLength)
            vecIndex.push_back(i);
    }
    return vecIndex;
}

vector<int> NaivePatternSearch(string targetString, string patternString)
{
    vector<int> vecIndex;
    int strLength = targetString.size();
    int patternLength = patternString.length();

    if (patternLength > strLength)
        return vecIndex;

    for (int i = 0; i < strLength; i++)
    {
        int localI = i;
        for (int j = 0; j < patternLength; j++)
        {
            if (targetString[localI] != patternString[j])
                break;
            
            localI++;
        }
        if (localI - i == patternLength)
            vecIndex.push_back(i);
    }
    return vecIndex;
}

vector<int> KMPPatternSearch(string target, string pattern)
{
    vector<int> vecIndex;
    int strLength = target.size();
    int patternLength = pattern.length();

    vector<int> targetIndex;
    for (int i = 0; i < strLength; i++)
    {
        
    }
}

int main()
{
    cout << "Pattern Searching" << endl;

    string targetString;
    cout << "Input target string -> ";
    getline(cin, targetString);

    string patternString;
    cout << "Input pattern string -> ";
    getline(cin, patternString);

    vector<int> myVector = SearchPattern(targetString, patternString);
    vector<int> myVector2 = NaivePatternSearch(targetString, patternString);

    cout << "'" << patternString << "' is ";
    if (myVector.size() > 0)
    {
        cout << "found at index ";
        for (vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++)
            cout << *it << " ";
    }
    else
        cout << "NOT FOUND";

    cout << endl;

    cout << "with Naive algorithm '" << patternString << "' is ";    
    if (myVector2.size() > 0)
    {
        cout << "found at index ";
        for (vector<int>::iterator it = myVector2.begin(); it != myVector2.end(); it++)
            cout << *it << " ";
    }
    else
        cout << "NOT FOUND";


    cout << endl;

    return 0;
}