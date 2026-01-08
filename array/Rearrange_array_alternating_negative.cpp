// Optimal
#include <iostream>
using namespace std;

void rightRotate(int arr[], int outOfPlace, int cur) {
    int temp = arr[cur];
    for (int i = cur; i > outOfPlace; i--) {
        arr[i] = arr[i - 1];
    }
    arr[outOfPlace] = temp;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int outOfPlace = -1;

    for (int index = 0; index < n; index++) {

        if (outOfPlace >= 0) {
            if ((arr[index] >= 0 && arr[outOfPlace] < 0) ||
                (arr[index] < 0 && arr[outOfPlace] >= 0)) {

                rightRotate(arr, outOfPlace, index);

                if (index - outOfPlace >= 2)
                    outOfPlace += 2;
                else
                    outOfPlace = -1; 
            }
        }

        if (outOfPlace == -1) {
            if ((arr[index] >= 0 && index % 2 == 1) ||
                (arr[index] < 0 && index % 2 == 0)) {
                outOfPlace = index;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
