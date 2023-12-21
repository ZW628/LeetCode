#ifndef LECELORDER_H
#define LECELORDER_H

#include <queue>
#include <vector>

#include "TreeNode.h"

using namespace std;

// 层序遍历
vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != NULL) que.push(root); // 将根节点加入队列
    vector<vector<int>> result;
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop(); // 删除根节点
            vec.push_back(node->val);
            if (node->left) que.push(node->left); // 加入叶子节点
            if (node->right) que.push(node->right);
        }
        result.push_back(vec);
    }
    return result;
}

#endif