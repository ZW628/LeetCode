#include <iostream>
#include <vector>
using namespace std;

// 判断子序列
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        if (dp[s.size()][t.size()] == s.size()) return true;
        return false;
    }
};

int main() {
    Solution solution;
    string s = "abc", t = "ahbgdc";
    bool result = solution.isSubsequence(s, t);
    cout << boolalpha << result;

    cin.get();
    return 0;
}