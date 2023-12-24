#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path;           // 用来存放符合条件结果
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
        }
        for (int i = startIndex; i <= n; i++) {
            cout << "startIndex: " << startIndex << endl; // debug
            cout << "i: " << i << endl;
            path.push_back(i); // 处理节点

            cout << "path.push_back: "; // debug
            for (int i = 0; i < path.size(); i++) {
                cout << path[i];
            }
            cout << endl;

            backtracking(n, k, i + 1); // 递归
            path.pop_back();           // 回溯，撤销处理的节点

            cout << "path.pop_back: "; // debug
            for (int i = 0; i < path.size(); i++) {
                cout << path[i];
            }
            cout << endl;
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
    for (vector<int> level : result) {
        cout << "[";
        for (int i = 0; i < level.size(); i++) {
            cout << level[i];
            if (i < level.size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (&level != &result.back()) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    cin.get();
    return 0;
}