#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {
// public:
//     TreeNode *searchBST(TreeNode *root, int val) {
//         if (root == nullptr) {
//             return nullptr;
//         }
//         if (val == root->val) {
//             cout << "root: " << root->val << endl;
//             return root;
//         }
//         return searchBST(val < root->val ? root->left : root->right, val);
//     }
// };
class Solution {
public:
    TreeNode *searchBST(TreeNode *root, int val) {
        while (root) {
            if (val == root->val) {
                return root;
            }
            root = val < root->val ? root->left : root->right;
        }
        return nullptr;
    }
};

int main() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution solution;
    TreeNode *node = solution.searchBST(root, 2);
    if (node) {
        cout << "BST Node value: " << node->val << endl;
    } else {
        cout << "Node not found." << endl;
    }

    cin.get();
    return 0;
}