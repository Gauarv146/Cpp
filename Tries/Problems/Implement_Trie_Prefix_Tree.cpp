//Optimal
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    unordered_map<string, TrieNode*> children;
    bool isEnd;

    TrieNode() {
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* current = root;

        while (!word.empty()) {
            bool matched = false;

            for (auto& it : current->children) {
                string edge = it.first;
                TrieNode* child = it.second;

                int i = 0;
                while (i < edge.size() && i < word.size() && edge[i] == word[i]) {
                    i++;
                }

                if (i == 0) continue;

                matched = true;

                if (i == edge.size()) {
                    // Full edge matched
                    word = word.substr(i);
                    current = child;
                } else {
                    // Partial match — split edge
                    string common = edge.substr(0, i);
                    string oldSuffix = edge.substr(i);
                    string newSuffix = word.substr(i);

                    TrieNode* splitNode = new TrieNode();

                    splitNode->children[oldSuffix] = child;
                    current->children.erase(edge);
                    current->children[common] = splitNode;

                    if (!newSuffix.empty()) {
                        splitNode->children[newSuffix] = new TrieNode();
                        splitNode->children[newSuffix]->isEnd = true;
                    } else {
                        splitNode->isEnd = true;
                    }

                    return;
                }
                break;
            }

            if (!matched) {
                current->children[word] = new TrieNode();
                current->children[word]->isEnd = true;
                return;
            }
        }

        current->isEnd = true;
    }

    bool search(string word) {
        TrieNode* current = root;

        while (!word.empty()) {
            bool matched = false;

            for (auto& it : current->children) {
                string edge = it.first;
                TrieNode* child = it.second;

                if (word.find(edge) == 0) {
                    word = word.substr(edge.size());
                    current = child;
                    matched = true;
                    break;
                }
            }

            if (!matched) return false;
        }

        return current->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* current = root;

        while (!prefix.empty()) {
            bool matched = false;

            for (auto& it : current->children) {
                string edge = it.first;
                TrieNode* child = it.second;

                if (edge.find(prefix) == 0 || prefix.find(edge) == 0) {
                    prefix = prefix.size() > edge.size()
                            ? prefix.substr(edge.size())
: "";
                    current = child;
                    matched = true;
                    break;
                }
            }

            if (!matched) return false;
        }

        return true;
    }
};
