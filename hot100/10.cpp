#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) { return dp(s, 0, p, 0); }

private:
    map<string, bool> memo;

    /* 计算 p[j..] 是否匹配 s[i..] */
    bool dp(string& s, int i, string& p, int j) {
        int m = s.size(), n = p.size();
        // base case
        if (j == n) {
            return i == m;
        }
        if (i == m) {
            if ((n - j) % 2 == 1) {
                return false;
            }
            for (; j + 1 < n; j += 2) {
                if (p[j + 1] != '*') {
                    return false;
                }
            }
            return true;
        }

        // 记录状态 (i, j)，消除重叠子问题
        string key = to_string(i) + "," + to_string(j);
        if (memo.count(key)) return memo[key];

        bool res = false;

        if (s[i] == p[j] || p[j] == '.') {
            if (j < n - 1 && p[j + 1] == '*') {
                res = dp(s, i, p, j + 2) || dp(s, i + 1, p, j);
            } else {
                res = dp(s, i + 1, p, j + 1);
            }
        } else {
            if (j < n - 1 && p[j + 1] == '*') {
                res = dp(s, i, p, j + 2);
            } else {
                res = false;
            }
        }
        // 将当前结果记入备忘录
        memo[key] = res;

        return res;
    }
};

int main() {
    Solution solution;
    string s = "aa", p = "a*";
    bool result = solution.isMatch(s, p);

    cout << boolalpha << result << endl;

    cin.get();
    return 0;
}