#include <iostream>
#include <vector>
using namespace std;

// 打家劫舍2
class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        // 情况二：考虑包含首元素，不包含尾元素
        int result1 = robRang(nums, 0, nums.size() - 2);
        // 情况三：考虑包含尾元素，不包含首元素
        int result2 = robRang(nums, 1, nums.size() - 1);
        return max(result1, result2);
    }

private:
    int robRang(vector<int> &nums, int start, int end) {
        if (end == start) return nums[start];
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i < end; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 3, 2};
    int result = solution.rob(nums);
    cout << result << endl;

    cin.get();
    return 0;
}