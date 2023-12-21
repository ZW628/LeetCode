#include <iostream>
#include <vector>

#include "LevelOrder.h"
#include "TreeNode.h"

using namespace std;

// 二叉搜索树中的搜索
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || root->val == val) return root;
        TreeNode* result = NULL;
        if (root->val > val) result = searchBST(root->left, val);
        if (root->val < val) result = searchBST(root->right, val);
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->left->right->right = new TreeNode(6);

    Solution solution;
    int val = 2;

    TreeNode* result = solution.searchBST(root, val);

    // 层序遍历
    vector<vector<int>> orderResult = levelOrder(result);

    // 输出结果
    for (vector<int> level : orderResult) {
        for (int i = 0; i < level.size(); i++) {
            cout << level[i] << " ";
        }
    }

    cin.get();
    return 0;
}
