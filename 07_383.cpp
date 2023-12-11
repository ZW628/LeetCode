#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 暴力解法
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (int i = 0; i < magazine.length(); i++) {
            for (int j = 0; j < ransomNote.length(); j++) {
                // 在ransomNote中找到和magazine相同的字符
                if (magazine[i] == ransomNote[j]) {
                    ransomNote.erase(ransomNote.begin() + j); // ransomNote删除这个字符
                    break;
                }
            }
        }
        // 如果ransomNote为空，则说明magazine的字符可以组成ransomNote
        if (ransomNote.length() == 0) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution solution;

    string ransomNote = "aa";
    string magazine = "ab";

    bool output = solution.canConstruct(ransomNote, magazine);
    cout << "output : ";

    cout << boolalpha << output << endl;

    cin.get();
    return 0;
}
