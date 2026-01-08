#include <iostream>
#include <vector>
using namespace std;

void printSpiral(int mat[][4], int n, int m) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int dirRow[] = {0, 1, 0, -1};
    int dirCol[] = {1, 0, -1, 0};

    int row = 0, col = 0, dir = 0;

    for (int count = 0; count < n * m; count++) {
        cout << mat[row][col] << " ";
        visited[row][col] = true;

        int nextRow = row + dirRow[dir];
        int nextCol = col + dirCol[dir];

        if (nextRow < 0 || nextRow >= n ||
            nextCol < 0 || nextCol >= m ||
            visited[nextRow][nextCol]) {
            dir = (dir + 1) % 4;
        }

        row += dirRow[dir];
        col += dirCol[dir];
    }
}
