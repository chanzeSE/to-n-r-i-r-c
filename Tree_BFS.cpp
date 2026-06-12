#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;

void Tree_BFS(int root) {
    queue<int> q;

    q.push(root);
    visited[root] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : adj[v]) { // u theo thứ tự từ nhỏ đến lớn
            if (!visited[u]) {
                visited[u] = 1;
                q.push(u);

                cout << "(" << v << "," << u << ")" << '\n';
            }
        }
    }
}

int main() {
    int n, m, root;
    cin >> n >> m >> root;

    adj.resize(n + 1);
    visited.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // bỏ dòng này nếu là đồ thị có hướng
    }

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    Tree_BFS(root);

    return 0;
}