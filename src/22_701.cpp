#include <iostream>
#include <vector>

#include "LevelOrder.h"
#include "TreeNode.h"

using namespace std;

// 二叉搜索树中的插入操作
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if (root->val > val) root->left = insertIntoBST(root->left, val);
        if (root->val < val) root->right = insertIntoBST(root->right, val);
        return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution solution;
    int val = 5;
    TreeNode* insertRoot = solution.insertIntoBST(root, val);

    // 层序遍历
    vector<vector<int>> orderResult = levelOrder(insertRoot);

    // 输出结果
    for (vector<int> level : orderResult) {
        for (int i = 0; i < level.size(); i++) {
            cout << level[i] << " ";
        }
    }

    cin.get();
    return 0;
}