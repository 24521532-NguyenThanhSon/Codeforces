#include<iostream>
#include<stdio.h>
    using namespace std;
    long long n, PRE[300005], PREPRE[300005], dp[300005], a[300005], q, l, r, t, sum[300005], f[300005];
long long solve(long long lv){
    long long l = 0, r = n, pos = 0;
    while(l <= r){
        long long m = (l + r) / 2;
        if((n * m) - (m-1) * m / 2 <= lv){
            pos = m;
            l = m + 1;
        }
        else    
            r = m - 1;
    }
    long long id = (n * pos) - (pos - 1) * pos / 2 + 1;

    return PREPRE[pos] + PRE[pos + 1] - sum[pos] - (dp[n] - dp[pos-1]) * (n - pos + 1 - (lv - id + 1));
}
void inp(){
    cin >> n;
    PRE[n + 1] = 0;
    for(long i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = dp[i-1]  + a[i];
        f[i] = a[i] * (n - i + 1);
        sum[i] = sum[i] + f[i];
    }
    PRE[n] = a[n];
    for(long i = n - 1; i >= 1; i--){
        PRE[i] = PRE[i+1] + f[i];
    }
    for(long i = 1; i <= n; i++){
        PREPRE[i] = (PREPRE[i-1] + PRE[i] - sum[i-1]);
    }
    cin >> q;
    while(q--){
        cin >> l >> r;
        cout << solve(r) - solve(l) << endl;
    }
}
    signed main(){
    t = 1;
    while(t--){
        inp();
    }
}