#include <iostream>
#include <vector>

using namespace std;

// 组合
class Solution {
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path;           // 用来存放符合条件结果

    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
        }
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i);         // 处理节点
            backtracking(n, k, i + 1); // 递归
            path.pop_back();           // 回溯，撤销处理的节点
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        result.clear(); // 可以不写
        path.clear();   // 可以不写
        backtracking(n, k, 1);
        return result;
    }
};

int main() {
    Solution solution;
    int n = 4, k = 2;
    vector<vector<int>> result = solution.combine(n, k);

    // 输出结果
    cout << "[";
    for (auto it = result.begin(); it != result.end(); ++it) {
        vector<int>& level = *it;
        cout << "[";
        for (int i = 0; i < level.size(); i++) {
            cout << level[i];
            if (i < level.size() - 1) {
                cout << ",";
            }
        }
        cout << "]";

        // 使用迭代器判断是否为最后一个元素
        if (it + 1 != result.end()) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    cin.get();
    return 0;
}