#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
const int maxn = 1005;
bool Visit[maxn];
long n, g[maxn][maxn], ms[maxn];
long ans = 1e9 + 7;

bool dfs(long u, long lim)
{
    for (long i = 1; i <= n; i++)
    {
        if (!Visit[i] and g[u][i] <= lim)
        {
            Visit[i] = true;
            if (ms[i] == -1 || dfs(ms[i], lim))
                return ms[i] = u, true;
        }
    }
    return false;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("test.inp","r",stdin);
    // freopen("test.out","w",stdout);
    cin >> n;
    long l = 0, r;
    for (long i = 1; i <= n; i++)
        for (long j = 1; j <= n; j++)
        {
            cin >> g[i][j];
            r = max(r, g[i][j]);
        }
    while (l <= r)
    {
        long m = (l + r) / 2;
        bool ok = true;
        memset(ms, -1, sizeof(ms));
        for (long i = 1; i <= n; i++)
        {
            memset(Visit, false, sizeof(Visit));
            ok = ok & dfs(i, m);
            if (ok == false)
                break;
        }
        if (ok)
        {
            r = m - 1;
            ans = min(ans, m);
        }
        else
            l = m + 1;
    }
    cout << ans;
}