#include <iostream>
#include <vector>
using namespace std;

// 时间复杂度：O(n)
// 空间复杂度：O(1)
// 双指针方法
// 快指针：遍历旧数组，指向新数组需要的元素，慢指针：指向新数组的下标
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

int main() {
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    Solution solution;
    int newSize = solution.removeElement(nums, val);

    // 输出修改后的数组大小
    cout << "New size of nums: " << newSize << endl;

    // 输出修改后的 nums 数组
    cout << "Modified nums array: ";
    for (int i = 0; i < newSize; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cin.get();
    return 0;
}