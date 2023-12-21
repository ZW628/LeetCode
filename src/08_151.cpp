#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void reverse(string& s, int start, int end) { // 翻转，区间写法：左闭右闭 []
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    // 去除多余空格，保证单词之间之只有一个空格，且字符串首尾没空格。
    // 双指针法
    void removeExtraSpaces(string& s) {
        int slow = 0;
        for (int i = 0; i < s.size(); ++i) {
            cout << "i: " << i << endl;
            if (s[i] != ' ') {
                cout << "slow: " << slow << endl;
                if (slow != 0) {
                    s[slow++] = ' ';
                }
                while (i < s.size() && s[i] != ' ') {
                    cout << "slow: " << slow << endl;
                    cout << "s[slow]: " << s[slow] << endl;
                    s[slow++] = s[i++]; // 先赋值然后再递增
                }
            }
        }
        s.resize(slow); // slow的大小即为去除多余空格后的大小。
    }

    string reverseWords(string s) {
        removeExtraSpaces(s);
        cout << s << endl;
        reverse(s, 0, s.size() - 1); // 将整个字符串反转
        cout << s << endl;
        // 将每个单词反转
        int start = 0; // removeExtraSpaces后保证第一个单词的开始下标一定是0。
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { // 到达空格或者串尾，说明一个单词结束。进行翻转。
                reverse(s, start, i - 1);       // 翻转，注意是左闭右闭[]的翻转。
                start = i + 1;                  // 更新下一个单词的开始下标start
            }
        }
        return s;
    }
};

int main() {
    Solution solution;

    // 输入字符串
    string s = "the sky  is";

    // 输出原始字符串
    cout << "Original String: \"" << s << "\"" << endl;

    // 调用反转函数
    string reversedStr = solution.reverseWords(s);

    // 输出反转后的字符串
    cout << "Reversed Words: \"" << reversedStr << "\"" << endl;

    cin.get();
    return 0;
}
