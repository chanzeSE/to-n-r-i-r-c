#include <iostream>
using namespace std;

const int INF = 1000000000;

int n;
int w[105][105];
int d[105];
int truoc[105];
bool visited[105];

void Dijkstra(int s)
{
    
    for(int v = 1; v <= n; v++)
    {
        d[v] = w[s][v];
        truoc[v] = s;
        visited[v] = false;
    }

    d[s] = 0;
    visited[s] = true;

    while(true)
    {
        int u = -1;
        int Min = INF;

        for(int v = 1; v <= n; v++)
        {
            if(!visited[v] && d[v] < Min)
            {
                Min = d[v];
                u = v;
            }
        }

        if(u == -1) break;

        visited[u] = true;

        for(int v = 1; v <= n; v++)
        {
            if(!visited[v] &&
               w[u][v] != INF &&
               d[v] > d[u] + w[u][v])
            {
                d[v] = d[u] + w[u][v];
                truoc[v] = u;
            }
        }
    }
}

int main()
{
    cin >> n;

    // Nhập ma trận trọng số
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> w[i][j];

            if(i != j && w[i][j] == 0)
                w[i][j] = INF;
        }
    }

    int s;
    cin >> s;

    Dijkstra(s);

    cout << "Khoang cach ngan nhat:\n";

    for(int i = 1; i <= n; i++)
        cout << "d[" << i << "] = " << d[i] << '\n';

    return 0;
}