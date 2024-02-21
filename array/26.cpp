#include <iostream>
#include <vector>
using namespace std;

// 删除有序数组中的重复项
// 双指针法
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow + 1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int result = solution.removeDuplicates(nums);
    cout << result << endl;

    cin.get();
    return 0;
}