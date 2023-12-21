#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

// 字符串直接作为栈
class Solution {
public:
    string removeDuplicates(string S) {
        string result;
        for (char s : S) {
            if (result.empty() || result.back() != s) {
                result.push_back(s);
            } else {
                result.pop_back();
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s = "abbaca";

    string s_removeDuplicates = solution.removeDuplicates(s);
    cout << s_removeDuplicates << endl;
    cin.get();
    return 0;
}