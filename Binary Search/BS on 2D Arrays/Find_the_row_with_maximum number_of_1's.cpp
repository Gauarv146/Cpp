//Optimal
#include <bits/stdc++.h>
using namespace std;

int rowWithMaxOnes(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    int row = 0;
    int col = m - 1;
    int maxRowIndex = -1;

    while (row < n && col >= 0) {
        if (mat[row][col] == 1) {
            maxRowIndex = row;   // update answer
            col--;               // move left
        } else {
            row++;               // move down
        }
    }

    return maxRowIndex;
}
