#include <iostream>
#include <vector>
using namespace std;

// 最长递增子序列
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1); // 初始化：dp[i]=1
        int result = 0;
        // 循环遍历所有i之前的j
        for (int i = 1; i < nums.size(); i++) {
            // cout << "i:" << i << endl;   //debug
            for (int j = 0; j < i; j++) {
                // cout << "  j:" << j << endl;
                //  位置i的最长升序子序列等于j从0到i-1各个位置的最长升序子序列 + 1 的最大值
                //  dp[i]表示以nums[i]结尾的最长递增子序列的长度
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
                // cout << "   dp[" << i << "]:" << dp[i] << endl;
            }
            if (dp[i] > result) result = dp[i];
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};

    int result = solution.lengthOfLIS(nums);
    cout << result << endl;

    cin.get();
    return 0;
}