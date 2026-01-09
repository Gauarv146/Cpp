//Optimal
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();        // number of rows
    int m = matrix[0].size();     // number of columns

    int row = 0;          // start from first row
    int col = m - 1;      // start from last column

    // Traverse until indices are valid
    while (row < n && col >= 0) {

        // If target found
        if (matrix[row][col] == target) {
            return true;
        }

        // Current element is too large
        else if (matrix[row][col] > target) {
            col--;        // move left
        }

        // Current element is too small
        else {
            row++;        // move down
        }
    }

    // Target not found
    return false;
}
