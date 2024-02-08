#include <string>
using namespace std;

// 最长回文子串
// 暴力解法
class Solution {
public:
    string longestPalindrome(string s) {
        string longest = ""; // 初始化最长回文子串
        int maxLen = 0;      // 记录最长回文子串的长度
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j <= s.length(); j++) {
                string tempS = s.substr(i, j - i);
                // 如果是回文串，并且长度比上一个回文串长，就更新
                if (isPalindrome(tempS) && tempS.length() > maxLen) {
                    longest = tempS;
                    maxLen = longest.length();
                }
            }
        }
        return longest;
    }

    // 判断s是否为回文串
    bool isPalindrome(string s) {
        for (int i = 0; i < s.length() / 2; i++) {
            // 逐个对比字符串首尾对称位置上的字符
            if (s[i] != s[s.length() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};

// 时间复杂度：O(n^3) = 两个for循环(O(n^2)) * 判断回文串(O(n))
// 空间复杂度：O(1)
