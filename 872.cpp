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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void dfs(TreeNode *node, vector<int> &seq) {
        // if (node->left == nullptr && node->right == nullptr)
        if (!node->left && !node->right) {
            seq.push_back(node->val);
        } else {
            if (node->left) {
                dfs(node->left, seq);
            }
            if (node->right) {
                dfs(node->right, seq);
            }
        }
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> seq1;
        if (root1) {
            dfs(root1, seq1);
        }

        vector<int> seq2;
        if (root2) {
            dfs(root2, seq2);
        }

        return seq1 == seq2;
    }
};

int main() {
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);

    TreeNode *root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(7);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(2);
    root2->right->right->left = new TreeNode(9);
    root2->right->right->right = new TreeNode(8);

    Solution solution;
    bool ifSimilar = solution.leafSimilar(root1, root2);
    // cout << boolalpha;
    cout << "ifSimilar: " << boolalpha << ifSimilar << endl;

    cin.get();
    return 0;
}

// @lc code=end
