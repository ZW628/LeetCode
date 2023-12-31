#include <iostream>
#include <vector>
using namespace std;

// 买卖股票的最佳时机II
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            result += max(prices[i] - prices[i - 1], 0);
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    int result = solution.maxProfit(nums);

    cout << result << endl;

    cin.get();
    return 0;
}