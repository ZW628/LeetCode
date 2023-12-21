#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};

int main() {
    Solution solution;

    // 输入字符串
    string s = "abcdefg"; // 修改为字符串初始化
    int k = 2;

    // 输出原始字符串
    cout << "Original String: " << s << endl;

    // 调用反转函数
    string reversedStr = solution.reverseStr(s, k);

    // 输出反转后的字符串
    cout << "Reversed String: " << reversedStr << endl;

    cin.get();
    return 0;
}