#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            // j的结束条件是 j < i - 1 ，其实 j < i 也是可以的，不过可以节省一步
            // j 遍历，只需要遍历到 n/2 就可以，后面就没有必要遍历了，一定不是最大值
            for (int j = 1; j <= i / 2; j++) {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    int n = 10;
    int result = solution.integerBreak(n);

    cout << result << endl;

    cin.get();
    return 0;
}
