#include <iostream>
#include <vector>

#include "PreOrderTraversal.h"
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) return t2;
        if (t2 == NULL) return t1;
        // 重新定义新的节点，不修改原有两个树的结构
        TreeNode* root = new TreeNode(0);
        root->val = t1->val + t2->val;
        root->left = mergeTrees(t1->left, t2->left);
        root->right = mergeTrees(t1->right, t2->right);
        return root;
    }
};

int main() {
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(3);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(5);

    TreeNode* t2 = new TreeNode(2);
    t2->left = new TreeNode(1);
    t2->right = new TreeNode(3);
    t1->left->right = new TreeNode(4);
    t1->right->right = new TreeNode(7);

    Solution solution;

    TreeNode* mergedTree = solution.mergeTrees(t1, t2);

    // 前序遍历
    vector<int> result = preorderTraversal(mergedTree);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    cin.get();
    return 0;
}
