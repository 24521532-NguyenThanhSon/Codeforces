#include<iostream>
#include<stdio.h>
    using namespace std;
    const int maxn = 3e5 + 10;
    long long n, q;
    long long a[maxn], b[maxn];
    long long prefix[maxn], sum[maxn];
    long long super_prefix[maxn], super_sum[maxn];

//  s[i] * 
long long Cal(long long pos){
    if(pos == 0)   return 0;
    long long l = -1, r = n - 1, k = -1;
    while(l <= r){
        long long m = (l + r) / 2;
        if((2 * n - m) * (m + 1) <= 2 * pos){
            l = m + 1;
            k = m;
        }
        else
            r = m - 1;
    }
    // n + (n - 1) + ... + (n - k)  = (2n - k) * (k + 1) / 2    
    long long Index = (2 * n - k) * (k + 1) / 2 + 1;  

    if(Index > pos) return super_prefix[k+1];
    // new = k + 2
    //     5
    //   2 2
    // 1 1 1
    // k + 2 -> k + 2 + pos - index
    if(k == -1){
        return super_sum[k + 2 + pos - Index] - super_sum[k+1] - (sum[k + 1]) * (k + 1);
    }
        return super_prefix[k+1] + super_sum[k + 2 + pos - Index] - super_sum[k+1] - (sum[k + 1]) * (pos - Index + 1);

}
long long solve(long long l, long long r){
    return Cal(r) - Cal(l-1);
}
    signed main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);  cout.tie(NULL);
        freopen("test.inp","r",stdin);
        freopen("test.out","w",stdout);
        cin >> n;
        for(long i = 1; i <= n; i++)    cin >> a[i];
        for(long i = 1; i <= n; i++){
            b[i] = a[i] * (n - i + 1);
            prefix[1] = prefix[1] + b[i];
            sum[i] = sum[i-1] + a[i];
        }
        for(long i = 2; i <= n; i++){
            prefix[i] = prefix[i-1] - a[i-1] * (n - i + 2);
        }
        for(long i = 1; i <= n; i++)    super_sum[i] = super_sum[i-1] + sum[i];
        for(long i = 1; i <= n; i++)    super_prefix[i] = super_prefix[i-1] + prefix[i];

        cin >> q;
        for(long i = 1; i <= q; i++){
            long long l, r;
            cin >> l >> r;
            cout << solve(l, r) << endl;
        }
}   