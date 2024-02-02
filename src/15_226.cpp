#include <iostream>
#include <vector>

#include "LevelOrder.h"
#include "TreeNode.h"
using namespace std;

// 翻转二叉树
// 递归法
class Solution {
public:
    TreeNode* exchangeNode(TreeNode* root) {
        if (root == NULL) return root;
        TreeNode* node = root;
        swap(node->left, node->right);
        exchangeNode(node->left);
        exchangeNode(node->right);
        return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution solution;
    TreeNode* result = solution.exchangeNode(root);

    vector<vector<int>> level_result = levelOrder(result);

    for (const auto& level : level_result) {
        cout << "[";
        for (int i = 0; i < level.size(); i++) {
            cout << level[i];
            if (i < level.size() - 1) cout << ",";
        }
        cout << "]";
        if (&level != &level_result.back()) cout << ",";
    }

    cin.get();
    return 0;
}
