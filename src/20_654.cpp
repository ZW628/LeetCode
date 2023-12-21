#include <queue>
#include <vector>

#include "LevelOrder.h"
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* node = new TreeNode(0);
        if (nums.size() == 1) {
            node->val = nums[0];
            return node;
        }
        // 找到数组中最大的值和对应的下标
        int maxValue = 0;
        int maxValueIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                maxValueIndex = i;
            }
        }
        node->val = maxValue;

        //  最大值所在的下标左区间 构造左子树
        if (maxValueIndex > 0) {
            vector<int> newVec(nums.begin(), nums.begin() + maxValueIndex);
            node->left = constructMaximumBinaryTree(newVec);
        }
        // 最大值所在的下标右区间 构造右子树
        if (maxValueIndex < (nums.size() - 1)) {
            vector<int> newVec(nums.begin() + maxValueIndex + 1, nums.end());
            node->right = constructMaximumBinaryTree(newVec);
        }

        return node;
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 6, 0, 5};
    Solution solution;
    TreeNode* root = solution.constructMaximumBinaryTree(nums);

    // 层序遍历
    vector<vector<int>> result = levelOrder(root);

    // 输出结果
    for (vector<int> level : result) {
        for (int i = 0; i < level.size(); i++) {
            cout << level[i] << " ";
        }
    }

    cin.get();
    return 0;
}
