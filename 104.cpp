#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        queue<TreeNode *> Q;
        Q.push(root);
        int depth = 0;
        while (!Q.empty()) {
            int sz = Q.size();
            while (sz != 0) {
                TreeNode *node = Q.front();
                Q.pop();
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
                sz -= 1;
            }
            depth += 1;
        }
        return depth;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    int dep = solution.maxDepth(root);
    cout << "depth of Tree: " << dep << endl;

    cin.get();
    return 0;
}