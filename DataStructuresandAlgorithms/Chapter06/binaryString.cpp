#include <iostream>
#include <math.h>

using namespace std;


string DecimalToBinaryString(int decimalNumber)
{
    string binaryString = "0";

    if (decimalNumber > 0)
    {
        binaryString = "";
        div_t dv{};
        dv.quot = decimalNumber;

        do
        {
            dv = div(dv.quot, 2);
            binaryString += to_string(dv.rem);
        }
        while (dv.quot);
    }

    return binaryString;
}

int BinaryStringToDecimal(string str)
{
    int decimalNumber = 0;

    int n;

    string::reverse_iterator it;
    for (it = str.rbegin(), n = 0; it != str.rend(); it++, n++)
    {
        char c = *it;
        if (c == '1')
            decimalNumber += pow(2, n);
    }

    return decimalNumber;
}

int main()
{
    cout << "1 for Decimal To Binary String and 2 for Binary String To Decimal";
    string selection;
    getline(cin, selection);
    if (selection == "1")
    {
        // Input a decimal number
        int decNum;
        cout << "Input a decimal number -> ";
        cin >> decNum;
        // Convert to binary string
        string binaryString = DecimalToBinaryString(decNum);
        // Show the result to user
        cout << "Binary string of " << decNum;
        cout << " is '" << binaryString;
        cout << "'" << endl;
    }
    else if (selection == "2")
    {
        cout << "Binary String To Decimal" << endl;
        // Input binary string
        string binaryString;
        cout << "Input binary string -> ";
        getline(cin, binaryString);
        // Convert to decimal
        int decNumber = BinaryStringToDecimal(
        binaryString);
        // Show the result to user
        cout << "Decimal of '" << binaryString;
        cout << "' is " << decNumber << endl;
    }
    else
    {
        cout << "Enter a valid option" << endl;
    }
    return 0;
}