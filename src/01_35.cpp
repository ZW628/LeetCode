#include <iostream>
#include <vector>
using namespace std;

// 搜索插入位置
// 暴力解法
class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= target) {
                return i;
            }
        }
        return nums.size();
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    Solution solution;
    cout << solution.searchInsert(nums, target) << endl;

    cin.get();
    return 0;
}