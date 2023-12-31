#include <iostream>
#include <vector>
using namespace std;

// 跳跃游戏
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if (nums.size() == 1) return true; // 只有一个元素，就是能达到
        for (int i = 0; i <= cover; i++) { // 注意这里是小于等于cover
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) return true; // 说明可以覆盖到终点了
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    bool result = solution.canJump(nums);

    cout << boolalpha << result << endl;

    cin.get();
    return 0;
}