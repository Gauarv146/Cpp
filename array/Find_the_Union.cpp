//Optimized Code (Two Pointers)

#include <iostream>
#include <vector>
using namespace std;

vector<int> unionTwoPointers(int arr1[], int n1, int arr2[], int n2) {
    vector<int> uni;

    int i = 0, j = 0;

    while (i < n1 && j < n2) {

        if (arr1[i] <= arr2[j]) {
            if (uni.empty() || uni.back() != arr1[i])
                uni.push_back(arr1[i]);
            i++;
        }
        else {
            if (uni.empty() || uni.back() != arr2[j])
                uni.push_back(arr2[j]);
            j++;
        }
    }

    while (i < n1) {
        if (uni.back() != arr1[i])
            uni.push_back(arr1[i]);
        i++;
    }

    while (j < n2) {
        if (uni.back() != arr2[j])
            uni.push_back(arr2[j]);
        j++;
    }

    return uni;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {2, 3, 4, 6};

    vector<int> result = unionTwoPointers(arr1, 5, arr2, 4);

    for (int x : result)
        cout << x << " ";

    return 0;
}
