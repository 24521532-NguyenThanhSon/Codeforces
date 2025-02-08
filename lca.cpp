#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int N = 1000 + 3;
int n, q;
struct Edge
{
    int v, w;
    Edge(int v = 0, int w = 0) : v(v), w(w) {}
};
vector<Edge> g[N];

int h[N], f[N], up[N][10];

void dfs(int u)
{
    for (Edge &e : g[u])
    {
        int v = e.v, w = e.w;
        if (v == up[u][0])
            continue;

        h[v] = h[u] + 1;
        f[v] = f[u] + w;

        up[v][0] = u;
        for (int j = 1; j < 10; ++j)
            up[v][j] = up[up[v][j - 1]][j - 1];

        dfs(v);
    }
}

int lca(int u, int v)
{
    if (h[u] != h[v])
    {
        if (h[u] < h[v])
            swap(u, v);

        int k = h[u] - h[v];
        for (int j = 0; (1 << j) <= k; ++j)
            if (k >> j & 1)
                u = up[u][j];
    }
    if (u == v)
        return u;

    int k = __lg(h[u]);
    for (int j = k; j >= 0; --j)
        if (up[u][j] != up[v][j])
            u = up[u][j], v = up[v][j];
    return up[u][0];
}

int dist(int u, int v)
{
    int p = lca(u, v);
    return f[u] + f[v] - 2 * f[p];
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1, u, v, c; i < n; ++i)
    {
        cin >> u >> v >> c;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }

    dfs(1);
    int u, v;
    while (q--)
    {
        cin >> u >> v;
        cout << dist(u, v) << '\n';
    }
}
