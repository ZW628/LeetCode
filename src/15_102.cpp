#include <queue>
#include <vector>

#include "TreeNode.h"

using namespace std;

class Solution {
public:
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
};

int main() {
    // 创建示例二叉树
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // 创建 Solution 对象
    Solution solution;

    // 调用层序遍历函数
    vector<vector<int>> result = solution.levelOrder(root);

    // 输出结果
    cout << "[";
    for (const auto& level : result) {
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

    // 释放二叉树内存（实际应用中可能不需要手动释放）
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    cin.get();
    return 0;
}