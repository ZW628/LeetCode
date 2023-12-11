#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> visit;
    int num;

    void dfs(vector<vector<int>> &rooms, int x) {
        visit[x] = true;
        num++;
        for (auto &it : rooms[x]) {
            if (!visit[it]) {
                dfs(rooms, it);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        int n = rooms.size();
        num = 0;
        visit.resize(n);
        dfs(rooms, 0);
        return n == num;
    }
};

int main() {
    vector<vector<int>> rooms = {{1, 3}, {3, 0, 1}, {2}, {0}};
    Solution solution;
    bool canVisit = solution.canVisitAllRooms(rooms);
    cout << "canVisitAllRooms: " << boolalpha << canVisit << endl;

    cin.get();
    return 0;
}
