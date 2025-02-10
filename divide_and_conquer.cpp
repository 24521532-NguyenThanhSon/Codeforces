#include<iostream>
#include<stdio.h>
#include<vector>
    using namespace std;

    const int maxn = 1e6 + 5;
    long a[maxn], b[maxn], c[2*maxn];
    long n, m, t;
    long prf[maxn], suf[maxn];
    long p[maxn], bit[maxn];
long Cal(long bi, long l, long r){  
    prf[l-1] = prf[r + 1] = 0;
    for(long i = l; i <= r; i++)   prf[i] = prf[i-1] + (a[i] > bi);
    for(long i = r; i >= l; i--)   suf[i] = suf[i+1] + (a[i] < bi);
    long pos = l;
    for(long i = l + 1; i <= r; i++){
        if(prf[pos-1] + suf[pos] > prf[i-1] + suf[i]){
            pos = i;
        }
    }
    return pos;
}
void compute(long l, long r, long optl, long optr){
    if(l > r)   return;
    long m = (l + r) / 2;
    p[m] = Cal(b[m], optl, optr);
    compute(l, m - 1, optl, p[m]);
    compute(m + 1, r, p[m], optr);
    
}
void compress_c(long n){
    vector<int> tmp(c + 1, c + n + 1);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for(long i = 1; i <= n; i++){
        c[i] = lower_bound(tmp.begin(), tmp.end(), c[i]) - tmp.begin() + 1;
    }
}
long get(long pos){
    int res = 0;
    for(; pos <= n; pos += (pos & -pos))    res += bit[pos];
    return res;
}
void up(long pos, long value){
    for(; pos; pos = pos ^ (pos& -pos)) bit[pos] += value;
}
void inp(){
    cin >> n >> m;
    for(long i = 1; i <= n; i++)    cin >> a[i];
    for(long i = 1; i <= m; i++)    cin >> b[i];
    sort(b + 1, b + m + 1);
    compute(1, m, 1, n + 1);
    long sz = 0;
    long j = 1;
    for(long i = 1; i <= n + 1; i++){
        while(p[j] == i and j <= m) c[++sz] = b[j++];
        if(i <= n)  c[++sz] = a[i];
    }
    n += m;
    compress_c(n);
    fill(bit + 1, bit + n + 1, 0);
    long long res = 0;
    for(long i = 1; i <= n; i++){
        res += get(c[i] + 1);

        up(c[i], 1);
    }
    cout << res << endl;
}
    signed main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);  cout.tie(NULL);
        freopen("test.inp","r",stdin);
        freopen("test.out","w",stdout);
        cin >> t;
        while(t--){
            inp();
        }
}