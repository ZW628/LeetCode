#include <queue>
#include <vector>

#include "TreeNode.h"

using namespace std;

// 二叉树的直径
class Solution {
    int maxDiameter = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maxDiameter;
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);

        int myDiameter = leftMax + rightMax;
        maxDiameter = max(maxDiameter, myDiameter);

        return 1 + max(leftMax, rightMax);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    int res = solution.diameterOfBinaryTree(root);

    cout << res;
    cin.get();
    return 0;
}