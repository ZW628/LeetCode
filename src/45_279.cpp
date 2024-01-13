#include <iostream>
#include <vector>
using namespace std;

// 完全平方数
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; i++) { // 遍历背包
            // cout << "i: " << i << endl;  //debug
            for (int j = 1; j * j <= i; j++) { // 遍历物品
                // cout << "  j: " << j << endl;
                dp[i] = min(dp[i - j * j] + 1, dp[i]);
                // cout << "    dp[" << i << "]: " << dp[i] << endl;
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    int n = 5;
    int result = solution.numSquares(n);

    cout << result << endl;

    cin.get();
    return 0;
}