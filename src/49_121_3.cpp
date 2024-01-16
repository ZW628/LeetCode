#include <iostream>
#include <vector>
using namespace std;

// 买卖股票的最佳时机
// DP解法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0) return 0;
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }
        return dp[len - 1][1];
    }
};

int main() {
    Solution solution;
    vector<int> nums = {7, 1, 5, 3, 6, 0};
    int result = solution.maxProfit(nums);

    cout << result << endl;

    cin.get();
    return 0;
}