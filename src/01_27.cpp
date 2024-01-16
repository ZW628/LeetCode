#include <iostream>
#include <vector>
using namespace std;

//  暴力解法
//  时间复杂度：O(n^2)
//  空间复杂度：O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) { // 发现需要移除的元素，就将数组集体向前移动一位
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                i--;    // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
                size--; // 此时数组的大小-1
            }
        }
        return size;
    }
};

int main() {
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    Solution solution;
    int newSize = solution.removeElement(nums, val);

    // 输出修改后的 nums 数组
    cout << "Modified nums array: ";
    for (int i = 0; i < newSize; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    // 输出修改后的数组大小
    cout << "New size of nums: " << newSize << endl;

    cin.get();
    return 0;
}