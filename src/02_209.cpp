#include <iostream>
#include <vector>
using namespace std;

// 暴力解法
class Solution {
public:
    int minSubArrayLen(vector<int> &nums, int val) {
        int result = INT32_MAX;
        int sum = 0;
        int subLength = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum >= val) {
                    subLength = j - i + 1;
                    result = result < subLength ? result : subLength;
                    break;
                }
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int val = 7;
    Solution solution;
    int result = solution.minSubArrayLen(nums, val);

    cout << result << endl;

    cin.get();
    return 0;
}
