//Optimal
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* left;   // bit 0
    TrieNode* right;  // bit 1

    TrieNode() {
        left = right = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int bit = 31; bit >= 0; bit--) {
            int currBit = (num >> bit) & 1;

            if (currBit == 0) {
                if (!node->left)
                    node->left = new TrieNode();
                node = node->left;
            } else {
                if (!node->right)
                    node->right = new TrieNode();
                node = node->right;
            }
        }
    }

    int getMaxXOR(int x) {
        TrieNode* node = root;
        int maxXor = 0;

        for (int bit = 31; bit >= 0; bit--) {
            int currBit = (x >> bit) & 1;

            if (currBit == 0) {
                if (node->right) {
                    maxXor |= (1 << bit);
                    node = node->right;
                } else {
                    node = node->left;
                }
            } else {
                if (node->left) {
                    maxXor |= (1 << bit);
                    node = node->left;
                } else {
                    node = node->right;
                }
            }
        }
        return maxXor;
    }
};

int maximumXOR(vector<int>& nums, int x) {
    Trie trie;

    for (int num : nums)
        trie.insert(num);

    return trie.getMaxXOR(x);
}

int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    int x = 5;
    cout << maximumXOR(nums, x);
    return 0;
}
