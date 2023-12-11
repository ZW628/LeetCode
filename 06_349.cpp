#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
        unordered_set<int> nums_set(nums1.begin(), nums1.end()); // 将nums1转化为unordered_set
        for (int num : nums2) {
            // 发现nums2的元素 在nums_set里又出现过
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};

    vector<int> nums = solution.intersection(nums1, nums2);
    cout << "intersection : ";
    for (int i; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    cin.get();
    return 0;
}
