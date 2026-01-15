//Optimal
#include <bits/stdc++.h>
using namespace std;

class BitTrie {
    struct Node {
        int child[2];
        int cnt;
        Node() {
            child[0] = child[1] = -1;
            cnt = 0;
        }
    };

    vector<Node> trie;

public:
    BitTrie() {
        trie.emplace_back(); // root
    }

    void insert(int num) {
        int node = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (trie[node].child[bit] == -1) {
                trie[node].child[bit] = trie.size();
                trie.emplace_back();
            }

            node = trie[node].child[bit];
            trie[node].cnt++;
        }
    }

    int countXorLessThan(int num, int K) {
        int node = 0;
        int count = 0;

        for (int i = 31; i >= 0; i--) {
            if (node == -1) break;

            int bit = (num >> i) & 1;
            int kBit = (K >> i) & 1;

            if (kBit == 1) {
                int same = trie[node].child[bit];
                if (same != -1)
                    count += trie[same].cnt;

                node = trie[node].child[1 - bit];
            } else {
                node = trie[node].child[bit];
            }
        }
        return count;
    }
};
