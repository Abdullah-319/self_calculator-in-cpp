#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to remove common characters and return the count of remaining characters
int removeCommonCharacters(string &name1, string &name2)
{
    string tempName2 = name2; // Copy of name2 to track modifications
    for (char &c : name1)
    {
        size_t pos = tempName2.find(c);
        if (pos != string::npos)
        {
            // Cancel common character
            tempName2.erase(pos, 1);
            c = '*'; // Mark as removed
        }
    }

    // Count remaining characters
    int count1 = count_if(name1.begin(), name1.end(), [](char c)
                          { return c != '*'; });
    int count2 = tempName2.length();
    return count1 + count2;
}

// Function to calculate the relationship status
string calculateRelationship(int remainingCount)
{
    string outcomes[] = {"Single", "Enemies", "Lovers", "Friends"};
    int index = 0;

    while (outcomes[1] != "")
    {
        int removeIndex = (remainingCount % 4) - 1;
        if (removeIndex < 0)
        {
            removeIndex += 4;
        }

        for (int i = removeIndex; i < 3; i++)
        {
            outcomes[i] = outcomes[i + 1]; // Shift elements left
        }
        outcomes[3] = ""; // Remove last element
    }

    return outcomes[0];
}

int main()
{
    cout << "🌟 Welcome to the Love Calculator! 🌟" << endl;
    cout << "--------------------------------------" << endl;

    string name1, name2;

    // Get user input
    cout << "Enter first name: ";
    cin >> name1;
    cout << "Enter second name: ";
    cin >> name2;

    // Convert names to lowercase for case-insensitivity
    transform(name1.begin(), name1.end(), name1.begin(), ::tolower);
    transform(name2.begin(), name2.end(), name2.begin(), ::tolower);

    // Find and display all occurrences of common alphabets
    cout << "Common alphabets: ";
    string commonLetters = "";
    string tempName2 = name2; // Copy to track modifications

    for (char c : name1)
    {
        size_t pos = tempName2.find(c);
        if (pos != string::npos)
        {
            commonLetters += c;
            commonLetters += " ";
            tempName2.erase(pos, 1); // Remove only the first occurrence
        }
    }

    if (commonLetters.empty())
    {
        cout << "None";
    }
    else
    {
        cout << commonLetters;
    }
    cout << endl;

    // Remove common characters and calculate the remaining count
    int remainingCount = removeCommonCharacters(name1, name2);

    // Calculate the result
    string result = calculateRelationship(remainingCount);

    // Display the result
    cout << "--------------------------------------" << endl;
    cout << "Remaining count: " << remainingCount << endl;
    cout << "Your relationship status is: " << result << endl;
    cout << "--------------------------------------" << endl;

    return 0;
}
