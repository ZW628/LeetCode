#include <iostream>
#include <vector>
using namespace std;

// 摆动序列
// 版本二
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int curDiff = 0; // 当前一对差值
        int preDiff = 0; // 前一对差值
        int result = 1;  // 记录峰值个数，序列默认序列最右边有一个峰值
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            // 出现峰值
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
                result++;
                preDiff = curDiff; // 注意这里，只在摆动变化的时候更新prediff
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    int result = solution.wiggleMaxLength(nums);

    cout << result << endl;

    cin.get();
    return 0;
}
