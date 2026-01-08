#include <bits/stdc++.h>
using namespace std;

int nextGap(int gap) {
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

int main() {
    int arr1[] = {1, 4, 7, 8, 10};
    int arr2[] = {2, 3, 9};

    int n = 5, m = 3;
    int gap = nextGap(n + m);

    while (gap > 0) {
        int i = 0;
        int j = gap;

        while (j < n + m) {
            // Case 1: both pointers in arr1
            if (i < n && j < n) {
                if (arr1[i] > arr1[j])
                    swap(arr1[i], arr1[j]);
            }
            // Case 2: i in arr1, j in arr2
            else if (i < n && j >= n) {
                if (arr1[i] > arr2[j - n])
                    swap(arr1[i], arr2[j - n]);
            }
            // Case 3: both pointers in arr2
            else {
                if (arr2[i - n] > arr2[j - n])
                    swap(arr2[i - n], arr2[j - n]);
            }

            i++;
            j++;
        }

        gap = nextGap(gap);
    }

    // Print result
    for (int i = 0; i < n; i++)
        cout << arr1[i] << " ";
    cout << endl;

    for (int i = 0; i < m; i++)
        cout << arr2[i] << " ";
}
