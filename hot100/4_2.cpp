#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 寻找两个正序数组的中位数
// 双指针法
class Solution {
public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
        int len = nums1.size() + nums2.size();
        int pre = 0, cur = 0;                // 记录当前处理的元素和当前元素的上一个元素
        int l = 0, r = 0;                    // 用来分别遍历两个数组
        for (int i = 0; i <= len / 2; ++i) { // 遍历len/2+1次之后，指向的元素必定是中位数（或者右中位数）
            pre = cur; // pre记录上一次循环的结果（len为偶数的时候即为记录左中位数）
            if (l < nums1.size() && (r >= nums2.size() || nums1[l] < nums2[r]))
                cur = nums1[l++];
            else
                cur = nums2[r++];
        }
        if (len % 2) return cur;
        return (pre + cur) * 0.5;
    }
};
