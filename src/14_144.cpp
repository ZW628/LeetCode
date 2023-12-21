#include <iostream>
#include <vector>

#include "TreeNode.h"

using namespace std;

class Solution {
public:
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
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    vector<int> traverseRoot = solution.preorderTraversal(root);

    for (int val : traverseRoot) {
        cout << val << " ";
    }
    cout << endl;

    cin.get();
    return 0;
}
