#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;

void Tree_DFS(int v)
{
    visited[v] = 1;  // ChuaXet[v] = 0

    for (int u : adj[v]) // u theo thứ tự từ nhỏ đến lớn
    {
        if (!visited[u]) // ChuaXet[u]
        {
            cout << "(" << v << "," << u << ")" << '\n';
            Tree_DFS(u);
        }
    }
}

int main()
{
    int n, m, root;
    cin >> n >> m >> root;

    adj.resize(n + 1);
    visited.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // bỏ nếu là đồ thị có hướng
    }

    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    Tree_DFS(root);

    return 0;
}