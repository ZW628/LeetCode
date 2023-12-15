#include <queue>
#include <vector>

#include "TreeNode.h"

using namespace std;

class Solution {
private:
    int getNodesNum(TreeNode* cur) {
        if (cur == NULL) return 0;
        int leftNum = getNodesNum(cur->left);   // 左
        int rightNum = getNodesNum(cur->right); // 右
        int treeNum = leftNum + rightNum + 1;   // 中
        return treeNum;
    }

public:
    int countNodes(TreeNode* root) { return getNodesNum(root); }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution solution;

    int depth = solution.countNodes(root);

    cout << "cout: " << depth << endl;

    cin.get();
    return 0;
}