//Optimal
#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.length() != t.length())
        return false;

    int mapST[256] = {0};
    int mapTS[256] = {0};

    for (int i = 0; i < s.length(); i++) {
        char c1 = s[i];
        char c2 = t[i];

        if (mapST[c1] != mapTS[c2])
            return false;

        mapST[c1] = i + 1;
        mapTS[c2] = i + 1;
    }

    return true;
}

int main() {
    string s = "foo";
    string t = "bar";

    if (isIsomorphic(s, t))
        cout << "Isomorphic\n";
    else
        cout << "Not Isomorphic\n";

    return 0;
}
