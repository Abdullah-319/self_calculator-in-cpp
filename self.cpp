#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to remove common characters and return the count of remaining characters
int removeCommonCharacters(string &name1, string &name2)
{
    for (char &c : name1)
    {
        size_t pos = name2.find(c);
        if (pos != string::npos)
        {
            // Cancel common character
            name2.erase(pos, 1);
            c = '*'; // Mark as removed
        }
    }

    // Count remaining characters
    int count1 = count_if(name1.begin(), name1.end(), [](char c)
                          { return c != '*'; });
    int count2 = name2.length();
    return count1 + count2;
}

// Function to calculate the result based on the remaining count
string calculateSELF(int remainingCount)
{
    string outcomes = "SELF";
    while (outcomes.length() > 1)
    {
        int removeIndex = (remainingCount % outcomes.length()) - 1;
        if (removeIndex < 0)
        {
            removeIndex += outcomes.length();
        }
        outcomes.erase(removeIndex, 1);
    }
    return outcomes;
}

int main()
{
    cout << "Hello baby" << endl;
    cout << "Welcome to this imaginary love world" << endl;
    cout << "Here we go!" << endl;

    string name1, name2;

    // Get user input
    cout << "Enter first name: " << endl;
    cin >> name1;
    cout << "Enter second name: " << endl;
    cin >> name2;

    // Find common alphabets and display
    cout << "Common alphabets: ";
    for (int i = 0; i < name1.length(); ++i)
    {
        for (int j = 0; j < name2.length(); ++j)
        {
            if (name1[i] == name2[j])
            {
                cout << name1[i] << " ";
                break;
            }
        }
    }
    cout << endl;

    // Remove common characters and calculate the remaining count
    int remainingCount = removeCommonCharacters(name1, name2);

    // Calculate the result
    string result = calculateSELF(remainingCount);

    // Display the result
    cout << "Result: " << result << endl;

    return 0;
}
