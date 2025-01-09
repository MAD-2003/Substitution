#include <iostream>
#include <cctype>

using namespace std;


bool is_valid_key(const string &key) {
    if (key.length() != 26) {
        return false;
    }

    bool seen[26] = {false}; 

    for (char c : key) {
        if (!isalpha(c)) {
            return false;  
        }

        int index = toupper(c) - 'A';
        if (seen[index]) {
            return false; 
        }

        seen[index] = true;
    }

    return true;
}

char encrypt_char(char plain_char, const string &key) {
    if (isalpha(plain_char)) {
        int index = toupper(plain_char) - 'A'; 
        char encrypted_char = key[index];      
        return islower(plain_char) ? tolower(encrypted_char) : encrypted_char;
    }
    return plain_char;  
}

int main() {
    string key;


    cout << "Enter a 26-character key: ";
    cin >> key;


    if (!is_valid_key(key)) {
        cout << "Invalid key. Key must contain 26 unique alphabetic characters." << endl;
        return 1;
    }

    string plaintext;
    cout << "plaintext: ";
    cin.ignore(); 
    getline(cin, plaintext);

  
    cout << "ciphertext: ";
    for (char c : plaintext) {
        cout << encrypt_char(c, key);
    }
    cout << endl;

    return 0;
}
