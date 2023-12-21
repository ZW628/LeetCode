#include <queue>
#include <vector>

#include "TreeNode.h"

using namespace std;

// 迭代法_层序遍历
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        int result = 0;
        while (!que.empty()) {
            int size = que.size();
            // cout << "size: " << size << endl;
            for (int i = 0; i < size; i++) {
                // cout << "i: " << i << endl;
                TreeNode* node = que.front();
                // cout << "node->val: " << node->val << endl;
                que.pop();
                if (i == 0) result = node->val; // 记录最后一行第一个元素
                // cout << "result: " << result << endl;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);

    Solution solution;

    int result = solution.findBottomLeftValue(root);

    cout << "result: " << boolalpha << result << endl;

    cin.get();
    return 0;
}
