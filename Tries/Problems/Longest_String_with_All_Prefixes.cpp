//Optimal
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool hasAllPrefixes(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            node = node->children[idx];
            if (!node || !node->isEnd)
                return false;
        }
        return true;
    }
};

string longestString(vector<string>& words) {
    Trie trie;

    for (string& w : words)
        trie.insert(w);

    sort(words.begin(), words.end());

    string ans = "";

    for (string& w : words) {
        if (trie.hasAllPrefixes(w)) {
            if (w.length() > ans.length())
                ans = w;
        }
    }

    return ans;
}
