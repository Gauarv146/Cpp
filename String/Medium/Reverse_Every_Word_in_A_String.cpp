//Optimal
#include <iostream>
using namespace std;

void reverseRange(string &s, int left, int right) {
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

string reverseWords(string s) {
    int n = s.length();
    int start = 0;

    for (int end = 0; end <= n; end++) {

        // End of word or end of string
        if (end == n || s[end] == ' ') {

            // Reverse current word
            reverseRange(s, start, end - 1);

            // Move to next word
            start = end + 1;
        }
    }

    return s;
}

int main() {
    string s = "Reverse Every Word";
    cout << reverseWords(s);
    return 0;
}
