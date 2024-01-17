#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 有序数组的平方
// 双指针法
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int k = A.size() - 1;
        vector<int> result(A.size(), 0);
        for (int i = 0, j = A.size() - 1; i <= j;) {
            if (A[i] * A[i] < A[j] * A[j]) {
                result[k--] = A[j] * A[j];
                j--;
            } else {
                result[k--] = A[i] * A[i];
                i++;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};

    Solution solution;
    vector<int> new_nums = solution.sortedSquares(nums);
    // 输出修改后的 nums 数组
    cout << "Modified nums array: ";
    for (int i = 0; i < new_nums.size(); i++) {
        cout << new_nums[i] << " ";
    }
    cout << endl;

    cin.get();
    return 0;
}
