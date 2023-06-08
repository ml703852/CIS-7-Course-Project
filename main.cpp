// CIS 7 Course Project
// Author: Mehak Lohchan
// Published: June 7th, 2023

#include <iostream>
#include <string>

using namespace std;

// function to encrypt the plaintext
string encrypt(string plaintext, string keyword) {
    string ciphertext = "";
    int keyLen = keyword.length();
    int plainLen = plaintext.length();

    for (int i = 0; i < plainLen; i++) {
        char plainChar = plaintext[i];
        char keyChar = keyword[i % keyLen];

        // convert characters to uppercase
        plainChar = toupper(plainChar);
        keyChar = toupper(keyChar);

        // check if the character is a letter
        if (isalpha(plainChar)) {
            // encryption formula: Ei = (Pi + Ki) mod 26
            char cipherChar = ((plainChar - 'A') + (keyChar - 'A')) % 26 + 'A';
            ciphertext += cipherChar;
        } else {
            // preserve non-letter characters as is
            ciphertext += plainChar;
        }
    }

    return ciphertext;
}

// function to decrypt the ciphertext
string decrypt(string ciphertext, string keyword) {
    string plaintext = "";
    int keyLen = keyword.length();
    int cipherLen = ciphertext.length();

    for (int i = 0; i < cipherLen; i++) {
        char cipherChar = ciphertext[i];
        char keyChar = keyword[i % keyLen];

        // convert characters to uppercase
        cipherChar = toupper(cipherChar);
        keyChar = toupper(keyChar);

        // check if the character is a letter
        if (isalpha(cipherChar)) {
            // decryption formula: Di = (Ei - Ki + 26) mod 26
            char plainChar = ((cipherChar - 'A') - (keyChar - 'A') + 26) % 26 + 'A';
            plaintext += plainChar;
        } else {
            // preserve non-letter characters as is
            plaintext += cipherChar;
        }
    }

    return plaintext;
}

// main to call the functions and prompt the user for input
int main() {
    string plaintext;
    string keyword;
    string choice;

    cout << "Enter 'e' to encrypt or 'd' to decrypt a message: ";
    cin >> choice;
    cin.ignore();

    cout << "Enter the message: ";
    getline(cin, plaintext);

    cout << "Enter the keyword: ";
    getline(cin, keyword);

  // ask the user if they want to encrypt or decrypt a message
    string result;
    if (choice == "e") {
        result = encrypt(plaintext, keyword);
        cout << "Encrypted message: " << result << endl;
    } else if (choice == "d") {
        result = decrypt(plaintext, keyword);
        cout << "Decrypted message: " << result << endl;
    } 

    return 0;
}
