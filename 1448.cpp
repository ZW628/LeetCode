#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int dfs(TreeNode *root, int path_max) {
        if (root == nullptr) {
            return 0;
        }
        int good_notes = 0;
        if (root->val >= path_max) {
            path_max = root->val;
            good_notes++;
        }
        good_notes += dfs(root->left, path_max) + dfs(root->right, path_max);
        return good_notes;
    }
    int goodNodes(TreeNode *root) { return dfs(root, INT_MIN); }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    Solution solution;
    int num = solution.goodNodes(root);
    cout << "goodNodes: " << num << endl;

    cin.get();
    return 0;
}
