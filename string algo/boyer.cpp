#include <iostream>
using namespace std;

#define SIZE 256   // ASCII size

// ---------------- BAD MATCH TABLE FUNCTION ----------------
void buildBadMatchTable(string pattern, int badMatch[]) {
    int m = pattern.length();

    // Step 1: Initialize all entries = m  (default '*')
    for(int i = 0; i < SIZE; i++)
        badMatch[i] = m;

    // Step 2: Fill values for pattern characters (except last one)
    for(int i = 0; i < m - 1; i++)
        badMatch[(int)pattern[i]] = max(1,m - 1 - i);
}

// ---------------- BOYER-MOORE SEARCH FUNCTION ----------------
void boyerMooreSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int badMatch[SIZE];

    buildBadMatchTable(pattern, badMatch);

    int shift = 0;
    bool found = false;

    while(shift <= n - m) {
        int j = m - 1;

        // Compare from right side
        while(j >= 0 && pattern[j] == text[shift + j])
            j--;

        if(j < 0) {  // match found
            cout << "Pattern found at index: " << shift << endl;
            found = true;

            // Move pattern forward
            shift += badMatch[(int)text[shift + m]];
        }
        else {
            // Shift using Bad Match Table
            shift += badMatch[(int)text[shift + j]];
        }
    }

    if(!found)
        cout << "Pattern not found!" << endl;
}


int main() {
    string text, pattern;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter pattern: ";
    getline(cin, pattern);

    boyerMooreSearch(text, pattern);

    return 0;
}