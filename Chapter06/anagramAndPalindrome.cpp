#include <iostream>
#include <algorithm>

using namespace std;

bool IsAnagram(string str1, string str2)
{
    // transform all characters to uppercase
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

    str1.erase(remove(str1.begin(), str1.end(), ' '), str1.end());
    str2.erase(remove(str2.begin(), str2.end(), ' '), str2.end());

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    return str1 == str2;    
}

bool IsPalindrome(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    str.erase(remove(str.begin(), str.end(), ' '), str.end());

    int left = 0;
    int right = str.length() - 1;

    while (left < right)
    {
        if (str[left++] != str[right--])
            return false;
    }
    return true;
}

int main()
{
    cout << "A for Anagram, P for Palindrome" << endl;
    
    string choice;
    getline(cin, choice);

    if (choice == "A" || choice == "a")
    {
        cout << "Anagram" << endl;
        // Input string1
        string string1;
        cout << "Input string 1 -> ";
        getline(cin, string1);
        // Input string2
        string string2;
        cout << "Input string 2 -> ";
        getline(cin, string2);
        // Check if they are anagram
        cout << "'" << string1 << "' and '";
        cout << string2 << "' are ";
        if(IsAnagram(string1, string2))
        {
        cout << "anagram";
        }
        else
        {
        cout << "NOT anagram";
        }
        cout << endl;
    }
    else if (choice == "P" || choice == "p")
    {
        cout << "Palindrome" << endl;
        // Input string
        string str;
        cout << "Input string -> ";
        getline(cin, str);
        // Check if it is palindrome
        cout << "'" << str << "' is ";
        if(IsPalindrome(str))
        {
        cout << "a palindrome";
        }
        else
        {
        cout << "NOT a palindrome";
        }
        cout << endl;
    }
    else
    {
        cout << "The input can not be categorized." << endl;
    }
    return 0;
}