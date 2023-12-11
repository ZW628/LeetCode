#include <iostream>
#include <stack>
#include <unordered_map>
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
    vector<int> rightSideView(TreeNode *root) {
        unordered_map<int, int> rightViewValue;
        int maxDepth = -1;

        stack<TreeNode *> nodeStack;
        stack<int> depthStack;
        nodeStack.push(root);
        depthStack.push(0);

        while (!nodeStack.empty()) {
            TreeNode *node = nodeStack.top();
            nodeStack.pop();
            int depth = depthStack.top();
            depthStack.pop();

            if (node != nullptr) {
                maxDepth = max(maxDepth, depth);

                if (rightViewValue.find(depth) == rightViewValue.end()) {
                    rightViewValue[depth] = node->val;
                }

                nodeStack.push(node->left);
                nodeStack.push(node->right);
                depthStack.push(depth + 1);
                depthStack.push(depth + 1);
            }
        }

        vector<int> rightViewNode;
        for (int depth = 0; depth <= maxDepth; depth++) {
            rightViewNode.push_back(rightViewValue[depth]);
        }
        return rightViewNode;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution solution;
    vector<int> rightNode = solution.rightSideView(root);
    // cout << boolalpha;
    for (int num : rightNode) {
        cout << "rightNode: " << endl;
        cout << num << endl;
    }

    cin.get();
    return 0;
}
