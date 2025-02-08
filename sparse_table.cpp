#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cmath>
    using namespace std;
const int maxn = 1e5 + 5;
long n;
long LG = log2(maxn);
long a[maxn];
long st[16][maxn];
    signed main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);  cout.tie(NULL);
        freopen("test.inp","r",stdin);
        freopen("test.out","w",stdout);
        cin >> n;
        for(long i = 1; i <= n; i++)    cin >> a[i];
        for(long i = 1; i <= n; i++)    st[0][i] = a[i];
        for(long j = 1; j <= LG; j++){
            for(long i = 1; i + (1 << j) - 1 <= n; i-=-1){
                st[j][i] = max(st[j-1][i], st[j-1][i+(1<<(j-1))]);
            }
        }
        cout << st[1][2];
}   