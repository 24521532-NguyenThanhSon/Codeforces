#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 5005;
vector<int> adj[maxn];
int n, m, s, t;
int c[maxn][maxn], f[maxn][maxn];
int trace[maxn];
int maxFlow = 0;
void bfs(){
    fill(trace, trace + n + 1, 0);
    trace[s] = -1;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty())
    {
        long u = Q.front();
        Q.pop();
        for (long j = 0; j < adj[u].size(); j++)
        {
            long v = adj[u][j];
            if (trace[v])
                continue;
            if (c[u][v] == f[u][v])
                continue;
            trace[v] = u;
            Q.push(v);
        }
    }
}
void inFlow()
{
    int delta = 1e9 + 7;
    int v = t;
    while (v != s)
    {
        long u = trace[v];
        delta = min(delta, c[u][v] - f[u][v]);
        v = u;
    }
    maxFlow += delta;
    v = t;
    while (v != s)
    {
        long u = trace[v];
        f[u][v] = f[u][v] + delta;
        f[v][u] = f[v][u] - delta;
        v = u;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> n;
    s = n, t = 1;
    long u ,v;
    while(cin >> u)
    {
        cin >> v;
        cin >> c[u][v];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    maxFlow = 0;
    do
    {
        bfs();
        if (trace[t])
            inFlow();
    } while (trace[t]);
    cout << maxFlow;
}