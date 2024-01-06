#include <iostream>
#include <vector>
using namespace std;

// 不同路径
class Solution {
public:
    int uniquePaths(int m, int n) {
        // 创建一个大小为 m x n 的二维整数数组,并将所有元素初始化为0
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution solution;
    int m = 7, n = 3;
    int result = solution.uniquePaths(m, n);

    cout << result << endl;

    cin.get();
    return 0;
}
