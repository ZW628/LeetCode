#include <iostream>
#include <vector>
using namespace std;

// 不同的二叉搜索数
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    int n = 3;
    int result = solution.numTrees(n);

    cout << result << endl;

    cin.get();
    return 0;
}
