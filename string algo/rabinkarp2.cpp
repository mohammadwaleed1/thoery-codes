#include <iostream>
#include <string>
using namespace std;
void rabinKarp(const string &text, const string &pattern) {
    int fac=1;

    int n = text.length();
    int m = pattern.length();

    if (m > n) return;
    int phash=0;
    int thash=0;
    
    for(int i=m-1;i>=0;i--){
        phash+=pattern[i]*fac;
        thash+=text[i]*fac;
        fac*=256;
    }
    int h = 1; // 256^(m-1)
    for (int i = 0; i < m - 1; i++)
        h *= 256;
    int found=false;

    for (int i = 0; i <= n - m; i++) {
        if (thash == phash) {
            // Verify characters
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match){cout << "Pattern found at index " << i << endl;
                found=true;
            }
        // Update hash for next window
        if (i < n - m) {
            thash = (thash - text[i] * h) * 256 + text[i + m];
        }
    }
    
}
if(!found)cout<<"pattern not found in text";
};
int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    rabinKarp(text, pattern);
}
