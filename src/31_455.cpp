#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 分发饼干
// 版本一
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1; // 饼干数组的下标
        int result = 0;
        for (int i = g.size() - 1; i >= 0; i--) { // 遍历胃口
            if (index >= 0 && s[index] >= g[i]) { // 遍历饼干
                result++;
                index--;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> g = {1, 2, 3}, s = {1, 1};
    int result = solution.findContentChildren(g, s);

    cout << result << endl;

    cin.get();
    return 0;
}