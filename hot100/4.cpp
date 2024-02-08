#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 寻找两个正序数组的中位数
class Solution {
public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
        int n = nums1.size() + nums2.size();
        vector<int> a(n, 0);
        int i = 0, j = 0, k = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j])
                a[k++] = nums1[i++];
            else
                a[k++] = nums2[j++];
        }
        while (i < nums1.size()) a[k++] = nums1[i++];
        while (j < nums2.size()) a[k++] = nums2[j++];
        if (n % 2) return a[n / 2];
        return (a[n / 2] + a[n / 2 - 1]) * 0.5;
    }
};
