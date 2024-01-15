#include <iostream>
#include <vector>

#include "TreeNode.h"

using namespace std;

// 打家劫舍III
// DP解法
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> result = robTree(root);
        return max(result[0], result[1]);
    }

    vector<int> robTree(TreeNode* cur) {
        if (cur == NULL) return vector<int>{0, 0};
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        // 偷cur，不偷左右节点
        int money1 = cur->val + left[0] + right[0];

        // 不偷cur，左右节点可偷可不偷
        // 需要考虑是否偷窃父节点的同时，也要知道在不偷窃子节点的情况下能获得的最大收益
        int money2 = max(left[0], left[1]) + max(right[0], right[1]);

        return {money2, money1};
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    Solution solution;
    int result = solution.rob(root);

    cout << result << endl;

    cin.get();
    return 0;
}