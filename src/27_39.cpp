#include <iostream>
#include <vector>

using namespace std;

// 组合总和
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            result.push_back(path);
            return;
        }

        //  剪枝
        //  如果 sum + candidates[i] > target 就终止遍历
        //  for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
        for (int i = startIndex; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i); // 不用i+1了，表示可以重复读取当前的数
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = solution.combinationSum(candidates, target);

    // 输出结果
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (i < result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    cin.get();
    return 0;
}
