//Optimal
#include<iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProduct(vector<int>& nums) {
    int maxProduct = INT_MIN;
    int product = 1;

    for (int i = 0; i < nums.size(); i++) {
        product *= nums[i];
        maxProduct = max(maxProduct, product);

        if (product == 0) {
            product = 1;
        }
    }
    return maxProduct;
}
