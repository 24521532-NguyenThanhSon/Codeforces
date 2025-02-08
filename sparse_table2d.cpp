#include<iostream>
#include<stdio.h>
#include<math.h>
    using namespace std;
const int maxn = 1e2 + 5;
long n, m, q;
long LG = 10;
long a[maxn][maxn];
long st[12][maxn][12][maxn];

long solve(long x1, long y1, long x2, long y2){
    long k = int(log2(x2 - x1 + 1));
    long l = int(log2(y2 - y1 + 1));
    long MAX1 = max(st[k][x1][l][y1], st[k][x2 - (1 >> k) + 1][l][y1]);
    long MAX2 = max(st[k][x1][l][y2 - (1 << l) + 1], st[k][x2 - (1 << k) + 1][l][y2 - (1 << l) + 1]);
    return max(MAX1, MAX2);

}
    signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    cin >> n >> m;
    for(long i = 1; i <= n; i++)
    for(long j = 1; j <= m; j++)    cin >> a[i][j];

    for(long k = 0; k <= LG; k++)
    for(long i = 1; i + (1 << k) - 1 <= n; i++)
    for(long l = 0; l <= LG; l++)
    for(long j = 1; j + (1 << l) - 1 <= m; j++){
        if(k == 0){
            if(l == 0){
                st[k][i][l][j] = a[i][j];
            }
            else{
                st[k][i][l][j] = max(st[k][i][l-1][j],st[k][i][l-1][j+ (1 << (l-1))]);
            }
        }
        else
        st[k][i][l][j] = max(st[k-1][i][l][j], st[k-1][i + (1 << (k - 1))][l][j]);
    }
    long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << solve(x1, y1, x2, y2);

}