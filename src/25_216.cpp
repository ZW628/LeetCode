#include <iostream>
#include <vector>

using namespace std;

// 组合总和III
class Solution {
private:
    vector<vector<int>> result; // 存放结果集
    vector<int> path;           // 符合条件的结果
    // targetSum：目标和，也就是题目中的n。
    // k：题目中要求k个数的集合。
    // sum：已经收集的元素的总和，也就是path里元素的总和。
    // startIndex：下一层for循环搜索的起始位置。
    void backtracking(int targetSum, int k, int sum, int startIndex) {
        if (path.size() == k) {
            if (sum == targetSum) result.push_back(path);
            return; // 如果path.size() == k 但sum != targetSum 直接返回
        }
        for (int i = startIndex; i <= 9; i++) {
            sum += i;                               // 处理
            path.push_back(i);                      // 处理
            backtracking(targetSum, k, sum, i + 1); // 注意i+1调整startIndex
            sum -= i;                               // 回溯
            path.pop_back();                        // 回溯
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear(); // 可以不加
        path.clear();   // 可以不加
        backtracking(n, k, 0, 1);
        return result;
    }
};

int main() {
    Solution solution;
    int n = 9, k = 3;
    vector<vector<int>> result = solution.combinationSum3(k, n);

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
    }
    cout << "]" << endl;

    cin.get();
    return 0;
}