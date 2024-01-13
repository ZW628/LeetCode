#include <iostream>
#include <vector>
using namespace std;

// 零钱兑换2
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) { // 遍历物品
            // cout << "i: " << i << endl; //debug
            for (int j = coins[i]; j <= amount; j++) { // 遍历背包
                // cout << "  j: " << j << endl;
                dp[j] += dp[j - coins[i]];
                // cout << "    dp[" << j << "]: " << dp[j] << endl;
            }
        }
        return dp[amount];
    }
};

int main() {
    Solution solution;
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    int result = solution.change(amount, coins);

    cin.get();
    return 0;
}
