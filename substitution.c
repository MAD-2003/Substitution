#include <iostream>
#include <cctype>

using namespace std;

bool is_valid_key(const char *key) {
    int length = 0;
    bool seen[26] = {false};
    while (key[length] != '\0') { 
        if (!isalpha(key[length])) {
            return false; 
        }

        int index = toupper(key[length]) - 'A';
        if (seen[index]) {
            return false; 
        }

        seen[index] = true;
        length++;
    }

    return (length == 26); ng
}


char encrypt_char(char plain_char, const char *key) {
    if (isalpha(plain_char)) {
        int index = toupper(plain_char) - 'A';  
        char encrypted_char = key[index];     
        return islower(plain_char) ? tolower(encrypted_char) : encrypted_char;
    }
    return plain_char; 
}

int main(int argc, char *argv[]) {
 
    if (argc != 2) {
        cout << "Usage: ./substitution <key>" << endl;
        return 1;
    }

    const char *key = argv[1];


    if (!is_valid_key(key)) {
        cout << "Invalid key. Key must contain 26 unique alphabetic characters." << endl;
        return 1;
    }


    char plain_char;
    cout << "plaintext: ";

    cout << "ciphertext: ";
    while (cin.get(plain_char)) {
        cout << encrypt_char(plain_char, key);
        if (plain_char == '\n') {
            break;  
        }
    }

    return 0;
}
