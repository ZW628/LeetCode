#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// 无重复字符的最长子串
// 滑动窗口 + 哈希表
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dic;
        int i = -1, res = 0, len = s.size();
        for (int j = 0; j < len; j++) {
            if (dic.find(s[j]) != dic.end()) {
                i = max(i, dic.find(s[j])->second); // 更新左指针
            }
            dic[s[j]] = j;         // 哈希表记录
            res = max(res, j - i); // 更新结果
        }
        return res;
    }
};

int main() {
    Solution solution;
    string s = "abcabcbb";
    int result = solution.lengthOfLongestSubstring(s);
    cout << result << endl;

    cin.get();
    return 0;
}