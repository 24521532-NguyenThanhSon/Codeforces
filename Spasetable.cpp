#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cmath> // Thư viện toán học chuẩn trong C++
using namespace std;

typedef long long ll;
    const int maxn = 1e5 + 5;
    long LG = 16;
    ll st[maxn][25]; 
    ll a[maxn];
    ll n, q, l, r;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;   
    for(long i = 1; i <= n; i++){
        cin >> a[i];
        st[i][0] = a[i];
    }
    for(long j = 1; j <= LG; j++)
    for(long i = 1; i <= n; i++){
        st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j-1]);
    }
    while(q--){
        cin >> l >> r;
        ll pos = int(log2(r - l + 1));
        cout << min(st[l][pos], st[r - (1 << pos) + 1][pos]) << endl;
    }
    return 0;
}