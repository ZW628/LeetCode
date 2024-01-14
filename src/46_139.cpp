#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// 单词拆分
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {     // 遍历背包
            for (int j = 0; j < i; j++) {         // 遍历物品
                string word = s.substr(j, i - j); // substr(起始位置，截取的个数)
                if (wordSet.find(word) != wordSet.end() && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};

int main() {
    Solution solution;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    bool result = solution.wordBreak(s, wordDict);

    cout << boolalpha << result << endl;

    cin.get();
    return 0;
}