#include <queue>
#include <vector>

#include "TreeNode.h"

using namespace std;

// 二叉树的最大深度
// 递归法_前序遍历
class Solution {
public:
    int result;
    void getdepth(TreeNode *node, int depth) {
        result = depth > result ? depth : result;

        if (node->left == NULL && node->right == NULL) return;

        if (node->left) {
            depth++;
            getdepth(node->left, depth);
            depth--;
        }

        if (node->right) {
            depth++;
            getdepth(node->right, depth);
            depth--;
        }
        return;
    }

    int maxDepth(TreeNode *root) {
        result = 0;
        if (root == NULL) return result;
        getdepth(root, 1);
        return result;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;

    int depth = solution.maxDepth(root);

    cout << "depth: " << depth << endl;

    cin.get();
    return 0;
}