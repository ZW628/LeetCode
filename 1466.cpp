#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int minReorder(int n, vector<vector<int>>& connections) {
    // 创建一个二维整数向量 conn_idx，用于存储连接信息
    vector<vector<int>> conn_idx(n, vector<int>());

    //  遍历连接数组，将连接信息添加到 conn_idx 中
    for (int i = 0; i < connections.size(); i++) {
        // 输出当前连接的信息
        cout << "Connection " << i << ": " << connections[i][0] << " -> " << connections[i][1] << endl;

        // 将连接索引 i 添加到连接的两个节点所对应的行中
        conn_idx[connections[i][0]].push_back(i);
        conn_idx[connections[i][1]].push_back(i);
    }

    // 输出 conn_idx 的内容
    cout << "conn_idx:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " connected to connections:";
        for (auto idx : conn_idx[i]) {
            cout << " " << idx;
        }
        cout << endl;
    }

    // 创建一个布尔向量 vi，用于标记连接是否已经被访问过
    vector<bool> vi(connections.size(), false);

    // 初始化 ans 为 0，用于记录需要重新排序的边的数量
    int ans = 0;

    // 创建一个队列 que，用于广度优先搜索
    queue<int> que;
    que.push(0); // 将起始节点 0 推入队列

    // 进入循环，直到队列为空
    while (!que.empty()) {
        // 从队列中取出队首元素并存储在 q 中
        auto q = que.front();
        que.pop(); // 从队列中移除队首元素

        // 遍历与节点 q 相关的连接索引
        for (auto idx : conn_idx[q]) {
            // 如果连接已经被访问过，则跳过
            if (vi[idx]) continue;

            // 标记连接为已访问
            vi[idx] = true;

            // 获取连接的两个节点 a 和 b
            int a = connections[idx][0];
            int b = connections[idx][1];

            // 如果节点 a 与当前节点 q 相等（表示连接是从 a 指向 q 的）
            // 则增加 ans，表示需要修改这条连接
            ans += (a == q);

            // 计算 a 的新值，如果原来是 a 则改为 b，反之亦然
            a = (a == q) ? b : a;

            // 将新的节点 a 推入队列，以便继续广度优先搜索
            que.push(a);
        }
    }

    // 返回 ans，表示需要重新排序的边的数量
    return ans;
}

int main() {
    int n = 6;
    vector<vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};

    int result = minReorder(n, connections);
    cout << "Minimum Reorder Count: " << result << endl;

    cin.get();
    return 0;
}