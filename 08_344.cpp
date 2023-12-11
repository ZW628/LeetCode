#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};

int main() {
    Solution solution;

    // 输入字符串
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    // 输出原始字符串
    cout << "Original String: ";
    for (char ch : s) {
        cout << ch << " ";
    }
    cout << endl;

    // 调用反转函数
    solution.reverseString(s);

    // 输出反转后的字符串
    cout << "Reversed String: ";
    for (char ch : s) {
        cout << ch << " ";
    }
    cout << endl;

    cin.get();
    return 0;
}
