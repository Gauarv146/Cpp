//Optimal
#include <bits/stdc++.h>
using namespace std;

struct State {
    int len;
    int link;
    int next[26];
};

vector<State> st;
int last;

void sa_init(int maxLen) {
    st.clear();
    st.reserve(2 * maxLen);
    st.push_back(State());
    st[0].len = 0;
    st[0].link = -1;
    memset(st[0].next, -1, sizeof st[0].next);
    last = 0;
}

void sa_extend(char ch) {
    int c = ch - 'a';
    int cur = st.size();

    st.push_back(State());
    st[cur].len = st[last].len + 1;
    memset(st[cur].next, -1, sizeof st[cur].next);

    int p = last;
    while (p != -1 && st[p].next[c] == -1) {
        st[p].next[c] = cur;
        p = st[p].link;
    }

    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = st.size();
            st.push_back(st[q]);
            st[clone].len = st[p].len + 1;

            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }

            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

long long countDistinctSubstrings(const string& s) {
    sa_init(s.size());

    for (char c : s)
        sa_extend(c);

    long long ans = 0;
    for (int i = 1; i < (int)st.size(); i++) {
        ans += st[i].len - st[st[i].link].len;
    }
    return ans;
}

int main() {
    string s = "ababa";
    cout << countDistinctSubstrings(s);
    return 0;
}
