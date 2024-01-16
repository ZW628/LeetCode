#include <iostream>
#include <vector>
using namespace std;

// 买卖股票的最佳时机
// 贪心解法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX;
        int result = 0;
        for (int i = 0; i < prices.size(); i++) {
            // cout << "i: " << i << endl; //debug
            low = min(low, prices[i]); // 取最左最小价格
            // cout << "  low: " << low << endl;
            result = max(result, prices[i] - low); // 直接取最大区间利润
            // cout << "  result: " << result << endl;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {7, 1, 5, 3, 6, 0};
    int result = solution.maxProfit(nums);

    cout << result << endl;

    cin.get();
    return 0;
}