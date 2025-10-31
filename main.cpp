#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to generate random password
void generatePassword(int length, bool useUpper, bool useLower, bool useDigits, bool useSymbols)
{
    // Character arrays (data structures)
    char lowerCase[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char upperCase[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char symbols[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '='};

    // Array of pointers to hold chosen character sets
    char *selectedSets[4];
    int sizeOfSets[4];
    int totalSets = 0;

    // Add selected character sets based on user input
    if (useLower)
    {
        selectedSets[totalSets] = lowerCase;
        sizeOfSets[totalSets] = 26;
        totalSets++;
    }
    if (useUpper)
    {
        selectedSets[totalSets] = upperCase;
        sizeOfSets[totalSets] = 26;
        totalSets++;
    }
    if (useDigits)
    {
        selectedSets[totalSets] = digits;
        sizeOfSets[totalSets] = 10;
        totalSets++;
    }
    if (useSymbols)
    {
        selectedSets[totalSets] = symbols;
        sizeOfSets[totalSets] = 14;
        totalSets++;
    }

    if (totalSets == 0)
    {
        cout << "Error: No character type selected! Please enable at least one option.\n";
        return;
    }

    char password[100]; // To store the generated password

    for (int i = 0; i < length; i++)
    {
        int setChoice = rand() % totalSets;           // Choose a random character set
        int index = rand() % sizeOfSets[setChoice];   // Choose a random character from that set
        password[i] = selectedSets[setChoice][index];
    }

    password[length] = '\0'; // Null terminate string

    cout << "\nGenerated Password: " << password << endl;
}

int main()
{
    srand(time(0)); // Seed random number generator

    int choice, length = 0;
    bool useUpper = false, useLower = false, useDigits = false, useSymbols = false;
    bool running = true;

    while (running)
    {
        cout << "\n========== RANDOM PASSWORD GENERATOR ==========\n";
        cout << "1. Set Password Length\n";
        cout << "2. Toggle Uppercase Letters\n";
        cout << "3. Toggle Lowercase Letters\n";
        cout << "4. Toggle Digits\n";
        cout << "5. Toggle Special Characters\n";
        cout << "6. Generate Password\n";
        cout << "7. Exit\n";
        cout << "----------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter desired password length (1-99): ";
            cin >> length;
            if (length <= 0 || length > 99)
            {
                cout << "Invalid length! Please enter between 1 and 99.\n";
                length = 0;
            }
            else
            {
                cout << "Password length set to " << length << ".\n";
            }
            break;

        case 2:
            if (useUpper == false)
            {
                useUpper = true;
                cout << "Uppercase letters ENABLED.\n";
            }
            else
            {
                useUpper = false;
                cout << "Uppercase letters DISABLED.\n";
            }
            break;

        case 3:
            if (useLower == false)
            {
                useLower = true;
                cout << "Lowercase letters ENABLED.\n";
            }
            else
            {
                useLower = false;
                cout << "Lowercase letters DISABLED.\n";
            }
            break;

        case 4:
            if (useDigits == false)
            {
                useDigits = true;
                cout << "Digits ENABLED.\n";
            }
            else
            {
                useDigits = false;
                cout << "Digits DISABLED.\n";
            }
            break;

        case 5:
            if (useSymbols == false)
            {
                useSymbols = true;
                cout << "Special characters ENABLED.\n";
            }
            else
            {
                useSymbols = false;
                cout << "Special characters DISABLED.\n";
            }
            break;

        case 6:
            if (length <= 0)
            {
                cout << "Please set a valid password length first!\n";
            }
            else
            {
                generatePassword(length, useUpper, useLower, useDigits, useSymbols);
            }
            break;

        case 7:
            cout << "Exiting... Thank you for using the Password Generator!\n";
            running = false;
            break;

        default:
            cout << "Invalid choice! Please select a valid menu option.\n";
            break;
        }
    }

    return 0;
}