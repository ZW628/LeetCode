#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 暴力排序
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            A[i] *= A[i];
        }
        sort(A.begin(), A.end()); // 快速排序
        return A;
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
