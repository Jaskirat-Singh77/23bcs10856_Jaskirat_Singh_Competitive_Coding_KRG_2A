#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert word
    void insert(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (node->children[idx] == NULL)
                node->children[idx] = new TrieNode();

            node = node->children[idx];
        }

        node->isEnd = true;
    }

    // Search word
    bool search(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (node->children[idx] == NULL)
                return false;

            node = node->children[idx];
        }

        return node->isEnd;
    }

    // Check prefix
    bool startsWith(string prefix) {
        TrieNode* node = root;

        for (char ch : prefix) {
            int idx = ch - 'a';

            if (node->children[idx] == NULL)
                return false;

            node = node->children[idx];
        }

        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");

    cout << trie.search("apple") << endl;   // 1 (true)
    cout << trie.search("app") << endl;     // 0 (false)
    cout << trie.startsWith("app") << endl; // 1 (true)

    return 0;
}