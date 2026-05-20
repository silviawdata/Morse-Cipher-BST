/*
 * Name: Silvia Williams
 * Description: This program implements a Morse Code
 * translation using Binary Search Tree to encrypt
 * and decrypt .txt files.
 * Input: letters file, text files and choice E or D.
 * Output: Morse code with a path of "L"s and/or "R"s
 * and/or "S";
 * or the original text of the lore of Resident Evil 3
 * and why it is better than the 2020 remake.
 */

// including header file and libraries
#include "bst.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // object for letters.txt/maps characters
    // to their Morse code Paths
    bst<char, string> MorseCode;

    // object for morse code to the original
    // used for reversing the mapping
    bst<string, char> ReverseCodes;

    // initializing string and char variables
    // used for input of the file names and choice
    string lettersFile = "";
    string textFile = "";
    char crypt = ' ';

    // initializing file straem
    ifstream inFile;

    // input from the console/terminal
    cin >> lettersFile >> textFile >> crypt;

    // edge case for choice/crypt
    if (crypt != 'E' && crypt != 'e' && crypt != 'D' && crypt != 'd')
    {
        cout << "Invalid crypt chosen" << endl;
        return 0;
    }

    // for parsing each character from letters file
    char ch;
    // opens first letters.txt file
    inFile.open(lettersFile);

    // edge case if letters file does not open
    if (!inFile)
    {
        cout << "Error for Letters.txt: Cannot Open FILE!" << lettersFile << endl;
        return 0;
    }

    inFile.get(ch); // gets the first character

    // reads through letters and inserts
    //  each character into BST.
    while (!inFile.eof())
    {
        // inserting a char with empty string so we can
        // build it in the setup first and then update paths later
        MorseCode.insert(ch, "");

        inFile.get(ch);

        inFile.get(ch);
    }

    inFile.close(); // closes file

    // https://cplusplus.com/reference/ios/ios/clear/
    // it is like the same a cin.clear where it clears
    // former conditions used with the first open file.
    // so we parse again.
    inFile.clear();

    // insert new line character with empty string place holder
    MorseCode.insert('\n', "");

    // Update upper case letters - range ASCII
    for (char c = 'A'; c <= 'Z'; c++)
    {
        // from char c getting the path directions "L",
        // "R" or "S" and saving it as a string called
        // path. Then updating it with the proper function
        // using the parameters (char, string path)
        string path = MorseCode.getPath(c);
        MorseCode.update(c, path);
    }
    // similar logic just lowercase
    for (char c = 'a'; c <= 'z'; c++)
    {
        string path = MorseCode.getPath(c);
        MorseCode.update(c, path);
    }
    // similar logic just using digit characters.
    for (char c = '0'; c <= '9'; c++)
    {
        string path = MorseCode.getPath(c);
        MorseCode.update(c, path);
    }

    // handles special cases for punctuation //
    // same logic (char, string)
    string coma = MorseCode.getPath(',');
    MorseCode.update(',', coma);

    string period = MorseCode.getPath('.');
    MorseCode.update('.', period);

    string space = MorseCode.getPath(' ');
    MorseCode.update(' ', space);

    string newline = MorseCode.getPath('\n');
    MorseCode.update('\n', newline);

    // This is reverse mapping from Morse Code path to individual
    // characters.
    // Similar logic to update just in reverse
    // getting path/string from the first BST, then insert as
    // a key/char.
    for (char c = 'A'; c <= 'Z'; c++)
    {
        string path = MorseCode.getValue(c);
        ReverseCodes.insert(path, c);
    }
    // similar logic for lower case
    for (char c = 'a'; c <= 'z'; c++)
    {
        string path = MorseCode.getValue(c);
        ReverseCodes.insert(path, c);
    }
    // similar logic for digit characters
    for (char c = '0'; c <= '9'; c++)
    {
        string path = MorseCode.getValue(c);
        ReverseCodes.insert(path, c);
    }

    // handles special cases for punctuation //
    // same logic (string, char)
    string coma1 = MorseCode.getValue(',');
    ReverseCodes.insert(coma1, ',');

    string period1 = MorseCode.getValue('.');
    ReverseCodes.insert(period1, '.');

    string space1 = MorseCode.getValue(' ');
    ReverseCodes.insert(space1, ' ');

    string newline1 = MorseCode.getValue('\n');
    ReverseCodes.insert(newline1, '\n');

    // char for to read in each character from file
    char carrot;

    // string to bulid the Morse code path during
    // decryption
    string morseLine = "";

    // opens next file //
    inFile.open(textFile);

    // edge case for opening file
    if (!inFile)
    {
        cout << "Error for re3Encrypted.txt: Cannot Open FILE!" << textFile << endl;
        return 0;
    }
    // Encryption to convert plain text to Morse Code
    if (crypt == 'E' || crypt == 'e')
    {
        while (inFile.get(carrot))
        {
            // outputs string with # as a divider
            cout << MorseCode.getValue(carrot) << '#';
        }
    }
    // Decryption to convert Morse Code to plain text
    else if (crypt == 'D' || crypt == 'd')
    {
        morseLine = ""; // resets

        while (inFile.get(carrot))
        {
            // while there is no divider, build the string
            //  for interpretation
            if (carrot != '#')
            {
                // builds string character by character
                morseLine = morseLine + carrot;
            }
            else
            {
                // decodes and outputs original plain text
                cout << ReverseCodes.getValue(morseLine);
                morseLine = "";
            }
        }
    }
    inFile.close(); // close file
    return 0;
}
