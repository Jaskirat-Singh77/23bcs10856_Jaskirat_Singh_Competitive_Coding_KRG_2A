#include <iostream>
#include <string>
using namespace std;

long long computeHash(string s, long long p, long long m) {
    long long hash_value = 0;
    for (char c : s) {
        hash_value = (hash_value * p + c) % m;
    }
    return hash_value;
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;

    long long p = 31;
    long long m = 1e9 + 9;

    int n = text.length();
    int k = pattern.length();

    if (k > n) return 0;

    long long pattern_hash = computeHash(pattern, p, m);
    long long text_hash = computeHash(text.substr(0, k), p, m);

    // Precompute p^(k-1)
    long long power = 1;
    for (int i = 1; i < k; i++)
        power = (power * p) % m;

    for (int i = 0; i <= n - k; i++) {

        if (pattern_hash == text_hash) {
            if (text.substr(i, k) == pattern) {
                cout << "Pattern found at index: " << i << endl;
            }
        }

        if (i < n - k) {
            text_hash = (text_hash - text[i] * power % m + m) % m;
            text_hash = (text_hash * p + text[i + k]) % m;
        }
    }

    return 0;
}