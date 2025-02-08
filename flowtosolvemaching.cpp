#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
    using namespace std;
const int maxn = 405;  
long MaxFlow = 0, ans = 1e9 + 7;
long s, t;
long n, g[maxn][maxn];
long trace[maxn];   
long f[maxn][maxn];
long c[maxn][maxn];
vector<int> adj[maxn];
void bfs(long lim){
    memset(trace, 0, sizeof(trace));
    queue<int> Q;
    Q.push(0);
    trace[0] = -1;
    while(!Q.empty()){
        long u = Q.front();
        Q.pop();
        for(long j = 0; j < adj[u].size(); j++){
            long v = adj[u][j];
            if(trace[v])    continue;
            if(f[u][v] == c[u][v])  continue;
            if(max(g[u][v], g[v][u]) > lim) continue;
            trace[v] = u;
            Q.push(v);
        }
    }
}
void inFlow(){
    long delta = 1e9 + 7;
    long v = t;
    while(v != s){
        long u = trace[v];
        delta = min(delta, c[u][v] - f[u][v]);
        v = u;
    }
    v = t;
    while(v != s){
        long u = trace[v];
        f[u][v] += delta;
        f[v][u] -= delta;
        v = u;
    }
    MaxFlow += delta;
}
    signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    // freopen("test.inp","r",stdin);
    // freopen("test.out","w",stdout);
    cin >> n;
    long l = 0, r = 0;
    for(long i = 1; i <= n; i++){
        for(long j = 1; j <= n; j++){
            cin >> g[i][j+ n];
            r = max(r, g[i][j + n]);
            c[i][j+n] = 1;
            adj[i].push_back(j + n);
            adj[j+n].push_back(i);
        }
    }
    for(long i = 1; i <= n; i++){
        c[0][i] = 1;
        adj[0].push_back(i);
        adj[i].push_back(0);
        adj[i+n].push_back(2*n + 1);
        adj[2*n + 1].push_back(i+n);
        c[i+n][2*n+1] = 1;
    }
    s = 0, t = 2 * n + 1;
    while(l <= r){
        long m = (l + r) / 2;
        MaxFlow = 0;
        memset(f, 0, sizeof(f));
        do{
            bfs(m);
            if(trace[t]){
                inFlow();
            }
        }while(trace[t]);
        if(MaxFlow == n){
            r = m - 1;
            ans = min(ans, m);
        }
        else{
            l = m + 1;
        }
    }
    cout << ans;
}