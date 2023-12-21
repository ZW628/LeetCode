#pragma once

#include <vector>

#include "TreeNode.h"

using namespace std;

// 前序遍历
void traversal(TreeNode* cur, vector<int>& vec) {
    if (cur == NULL) return;
    vec.push_back(cur->val);    // 中
    traversal(cur->left, vec);  // 左
    traversal(cur->right, vec); // 右
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    traversal(root, result);
    return result;
}