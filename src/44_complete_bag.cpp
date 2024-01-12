#include <iostream>
#include <vector>
using namespace std;

// 完全背包，即物品可以取多次
// 先遍历物品，在遍历背包
void test_CompletePack() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    vector<int> dp(bagWeight + 1, 0);
    for (int i = 0; i < weight.size(); i++) { // 遍历物品
        // cout << "i: " << i << endl; //debug
        for (int j = weight[i]; j <= bagWeight; j++) { // 遍历背包容量
            // cout << "  j: " << j << endl;
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            // cout << "    dp[" << j << "]: " << dp[j] << endl;
        }
    }
    cout << dp[bagWeight] << endl;
    cin.get();
}
int main() { test_CompletePack(); }