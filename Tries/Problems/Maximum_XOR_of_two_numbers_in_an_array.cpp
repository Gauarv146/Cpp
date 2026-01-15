//Optimal
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[2];
    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int bit = 31; bit >= 0; bit--) {
            int currBit = (num >> bit) & 1;
            if (!node->child[currBit]) {
                node->child[currBit] = new TrieNode();
            }
            node = node->child[currBit];
        }
    }

    int getMaxXOR(int num) {
        TrieNode* node = root;
        int maxXor = 0;

        for (int bit = 31; bit >= 0; bit--) {
            int currBit = (num >> bit) & 1;
            int desired = 1 - currBit;

            if (node->child[desired]) {
                maxXor |= (1 << bit);
                node = node->child[desired];
            } else {
                node = node->child[currBit];
            }
        }
        return maxXor;
    }
};

int findMaximumXOR(vector<int>& nums) {
    Trie trie;
    int ans = 0;

    for (int num : nums) {
        trie.insert(num);
    }

    for (int num : nums) {
        ans = max(ans, trie.getMaxXOR(num));
    }
    return ans;
}

int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << findMaximumXOR(nums);
    return 0;
}
