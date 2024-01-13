#include <iostream>
#include <vector>
using namespace std;

// 爬楼梯，DP解法
int main() {
    int n = 3, m = 2; // n个台阶，每次至多爬m个

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {     // 遍历背包
        for (int j = 1; j <= m; j++) { // 遍历物品
            if (i - j >= 0) dp[i] += dp[i - j];
        }
    }

    cout << dp[n] << endl;
    cin.get();
}