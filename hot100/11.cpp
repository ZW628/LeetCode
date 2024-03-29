#include <iostream>
#include <vector>
using namespace std;

// 盛最多水的容器
class Solution {
public:
    int maxWater(vector<int> height) {
        int l = 0, r = height.size() - 1;
        int res = 0;
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            res = max(res, area);
            if (height[l] <= height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return res;
    }
};
