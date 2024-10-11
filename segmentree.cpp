#include<iostream>
#include<stdio.h>   
#include<set>
#include<map>

    using namespace std;  
    const int maxn = 8e5 + 5;
    long long ans, n, k;
    long long S[maxn + 5];
    long long F[maxn / 4 + 5], a[maxn / 4 + 5];
    long long zero = 0;

void update(long long id, long long l, long long r, long long u, long long v, long long value){
    if(l > v or r < u)  return;
    if(l >= u and r <= v){
        S[id] += value;
        return;
    }
    long long m = (l + r) / 2;
    update(2 * id, l, m, u, v, value);
    update(2 * id + 1, m + 1, r, u, v, value);
    S[id] = max(S[2 * id], S[2 * id + 1]);
}
long long find(long long id, long long l, long long r, long long u, long long v){
    if(l > v or r < u)  return -1e9;
    if(l >= u and r <= v){
        return S[id];
    }
    long long m = (l + r) / 2;
    return max(find(2 * id, l, m, u, v), find(2 * id + 1, m + 1, r, u, v));
}
    //phap test feature 1

    signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL); 
    freopen("text.inp", "r", stdin);
    freopen("text.out", "w", stdout);
    cin >> n >> k;
    for(long i = 1; i <=  n; i++)   cin >> a[i];

    for(long i = 1; i <= n; i++){
        long long x = find(1, 1, n, max(zero, i - k), i-1);
        x = max(x,zero);
        F[i] = max(F[i], x + a[i]);
        ans = max(ans, F[i]);
        update(1, 1, n, i, i, F[i]);
        // cout << F[i] << " ";
    }
    cout << ans << endl;
    //phap test feature 1
}