#include <iostream>
using namespace std;

// Function for Naive Pattern Searching
void naiveSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    bool found = false;

    for (int i = 0; i <= n - m; i++) {

        int j;
        // Check pattern match
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) 
                break;
        }

        if (j == m) {
            cout << "Pattern found at index: " << i << endl;
            found = true;
        }
    }

    if (!found) { 
        cout << "Pattern not found in text." << endl;
    }
}

int main() {
    string text, pattern;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter pattern to search: ";
    getline(cin, pattern);

    naiveSearch(text, pattern);

    return 0;
}
