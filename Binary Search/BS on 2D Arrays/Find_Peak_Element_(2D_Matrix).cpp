//Optimal
#include <bits/stdc++.h>
using namespace std;

pair<int,int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    int low = 0, high = m - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        int maxRow = 0;
        for(int row = 0; row < n; row++) {
            if(mat[row][mid] > mat[maxRow][mid]) {
                maxRow = row;
            }
        }

        int left  = (mid > 0)     ? mat[maxRow][mid - 1] : -1;
        int right = (mid < m - 1) ? mat[maxRow][mid + 1] : -1;

        if(mat[maxRow][mid] > left && mat[maxRow][mid] > right) {
            return {maxRow, mid};
        }
        else if(mat[maxRow][mid] < left) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return {-1, -1};
}
