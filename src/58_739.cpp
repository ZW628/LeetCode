#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 每日温度
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        // 递增栈
        stack<int> st;
        vector<int> result(T.size(), 0);
        st.push(0);
        for (int i = 1; i < T.size(); i++) {
            if (T[i] < T[st.top()]) { // 情况一
                st.push(i);
            } else if (T[i] == T[st.top()]) { // 情况二
                st.push(i);
            } else {
                while (!st.empty() && T[i] > T[st.top()]) { // 情况三
                    result[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = solution.dailyTemperatures(temperatures);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i < result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]";

    cin.get();
    return 0;
}