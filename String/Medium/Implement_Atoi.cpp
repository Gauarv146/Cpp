//Optimal
#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int i = 0, n = s.size();
    
    // 1. Skip leading spaces
    while (i < n && s[i] == ' ') i++;

    // 2. Handle sign
    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // 3. Convert digits with tight overflow control
    int num = 0;
    while (i < n && isdigit(s[i])) {
        int digit = s[i] - '0';

        // Core overflow guard (sign-aware)
        if (num > (INT_MAX - digit) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        num = num * 10 + digit;
        i++;
    }

    return num * sign;
}
