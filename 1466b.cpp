#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int minReorder(int n, vector<vector<int>>& connections) {
    unordered_map<int, vector<pair<int, int>>> graphs;
    for (auto& path : connections) {
        graphs[path[0]].push_back(make_pair(path[1], 1));
        graphs[path[1]].push_back(make_pair(path[0], 0));
    }

    queue<int> q;
    unordered_set<int> visited;
    q.push(0);
    visited.insert(0);
    int res = 0;

    while (!q.empty()) {
        int source = q.front();
        q.pop();
        for (auto m : graphs[source]) {
            cout << "Visited Node: " << m.first << ", Edge Direction: " << m.second << endl;
            if (visited.count(m.first)) {
                continue;
            }
            q.push(m.first);
            visited.insert(m.first);
            res += m.second;
        }
    }
    return res;
}

int main() {
    int n = 6;
    vector<vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};

    int result = minReorder(n, connections);
    cout << "Minimum Reorder Count: " << result << endl;

    cin.get();
    return 0;
}
