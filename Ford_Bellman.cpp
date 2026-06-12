#include <iostream>
using namespace std;

const int INF = 1000000000;

int n;
int w[105][105];
int d[105];
int truoc[105];

void Ford_Bellman(int s)
{

    for(int v = 1; v <= n; v++)
    {
        d[v] = w[s][v];
        truoc[v] = s;
    }

    d[s] = 0;

    for(int k = 1; k <= n - 1; k++)
    {
        for(int u = 1; u <= n; u++)
        {
            for(int v = 1; v <= n; v++)
            {
                if(w[u][v] != INF &&
                   d[u] != INF &&
                   d[v] > d[u] + w[u][v])
                {
                    d[v] = d[u] + w[u][v];
                    truoc[v] = u;
                }
            }
        }
    }
}

int main()
{
    cin >> n;

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
    Ford_Bellman(s);
    cout << "Khoang cach ngan nhat:\n";

    for(int i = 1; i <= n; i++)
        cout << "d[" << i << "] = " << d[i] << '\n';

    return 0;
}