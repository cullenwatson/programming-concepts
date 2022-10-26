/*
 * Cullen Watson
 * 03/01/2020
 * Program 2
 * Encrypts and decrypts a message based on the Caesar Cipher
 */

#include <iostream>
#include <sstream>

using namespace std;

// Three prototypes
int menu();

void decrypt(string &cipher);

void encrypt(string passcode);

int main() {

    // Welcome message
    cout << "Starting up your cipher!" << endl << endl;

    // Run menu
    int choice;
    do {
        choice = menu();

        if (choice == 1) {
            string passcode;

            // Get encryption passcode
            bool invalid = true;
            int j = 0;
            do {
                j = 0;
                cout << "Enter your passcode: " << flush;
                cin >> passcode;

                for(int i=0; i<passcode.length(); i++) {
                    if((passcode[i] < 65) || ((passcode[i] > 90) && (passcode[i] <97)) || (passcode[i] > 122)) {
                        j++;
                    }
                }
                if(j==0)
                    invalid = false;

            } while(invalid);

            cin.ignore();
            encrypt(passcode);
        } else if (choice == 2) {
            string cipher;

            // Get encrypted message
            cout << "Enter the message to be decrypted: " << flush;
            cin.ignore();
            getline(cin, cipher);

            decrypt(cipher);
        } else if (choice != 3) {
            cout << "Please enter a valid option.\n" << endl;
        }

    } while (choice != 3);

    // Output goodbye message
    cout << "Goodbye!" << endl;

    return 0;
}

int menu() {

    // Display menu of options
    cout << "Please select an option:" << endl;
    cout << "   1. Encrypt Message" << endl;
    cout << "   2. Decrypt Message" << endl;
    cout << "   3. Quit" << endl;
    cout << "Enter: " << flush;

    // Get input from user
    int input;
    cin >> input;
    cout << endl;

    // Return input
    return input;
}

void encrypt(string passcode) {

    string message;

    // Get decrypted message
    cout << "Enter the message to be encrypted: " << flush;
    getline(cin, message);


    // Convert string to uppercase
    string messageInCaps;
    for (int i = 0; i < message.length(); i++) {
        messageInCaps += toupper(message[i]);

    }

    stringstream ss;

    for (int i = 0, j = 0; i < messageInCaps.length(); i++) {

        // exclude characters that are not in the alphabet
        if (messageInCaps[i] < 65 || messageInCaps[i] > 90) {
            ss << messageInCaps[i];

        } else {
            // Shift characters by it's ASCII minus A's starting value 65
            int shift = passcode[j % passcode.length()] - 65;

            // apply the shift
            char letter = messageInCaps[i] + shift;

            // make sure the letter is in range
            if (letter > 90) {
                letter -= 26;
                ss << letter;
                j++;
            } else {
                ss << letter;
                j++;
            }
        }

    }

    cout << "\nEncrypting your message..." << endl << endl;

    // Output results
    cout << "Passcode: " << passcode << endl;
    cout << "Plaintext Message: " << messageInCaps << endl;
    cout << "Ciphertext Message: " << ss.str() << endl << endl;

}

void decrypt(string &cipher) {

    // declare cipher and passcode variables
    string passcode;

// Get encryption passcode
    bool invalid = true;
    int j = 0;
    do {
        j = 0;
        cout << "Enter your passcode: " << flush;
        cin >> passcode;

        for(int i=0; i<passcode.length(); i++) {
            if((passcode[i] < 65) || ((passcode[i] > 90) && (passcode[i] <97)) || (passcode[i] > 122)) {
                j++;
            }
        }
        if(j==0)
            invalid = false;

    } while(invalid);

    // create string stream
    stringstream ss;

    for (int i = 0, j = 0; i < cipher.length(); i++) {

        // exclude characters that are not in the alphabet
        if (cipher[i] < 65 || cipher[i] > 90) {
            ss << cipher[i];

        } else {
            // turn passcode letter into an integer amount
            int shift = passcode[j % passcode.length()] - 65;

            // undo the letter shift
            char letter = cipher[i] - shift;

            // make sure the letter is in range
            if (letter < 65) {
                letter += 26;
                ss << letter;
                j++;
            } else {
                ss << letter;
                j++;
            }
        }

    }

    // output results
    cout << "\nDecrypting your message...\n" << endl;
    cout << "Ciphertext Message: " << cipher << endl;
    cout << "Plaintext Message: " << ss.str() << endl << endl;
}