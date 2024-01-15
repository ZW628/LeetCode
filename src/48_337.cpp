#include <iostream>
#include <vector>

#include "TreeNode.h"

using namespace std;

// 打家劫舍III
// 暴力解法
class Solution {
public:
    int rob(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return root->val;
        // 偷父节点
        int money1 = root->val;
        if (root->left) money1 += rob(root->left->left) + rob(root->left->right);
        if (root->right) money1 += rob(root->right->left) + rob(root->right->right);
        // 不偷父节点
        int money2 = rob(root->left) + rob(root->right);
        return max(money1, money2);
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