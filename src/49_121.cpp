#include <iostream>
#include <vector>
using namespace std;

// 买卖股票的最佳时机
// 暴力解法
class Solution {
public:
    int maxMoney(vector<int> &nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                result = max(result, (nums[j] - nums[i]));
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    int result = solution.maxMoney(nums);

    cout << result << endl;

    cin.get();
    return 0;
}