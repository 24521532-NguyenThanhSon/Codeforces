#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
    using namespace std;
    const int N = 1e5 + 5;
    long long BIT1[N], BIT2[N];
    long long n, q, value, u, v, Type, x;
void UpdatePoint(long long b[], long long pos, long long value){
    while(pos <= n){
        b[pos] += value;
        pos += (pos & (-pos));
    }
}
void UpdateRange(long long l, long long r, long value){
    UpdatePoint(BIT1, l, value * (n - l + 1));
    UpdatePoint(BIT1, r + 1, -value * (n - r));
    UpdatePoint(BIT2, l, value);
    UpdatePoint(BIT2, r + 1, -value);
}
long long getsum(long long b[], long long pos){
    long long ans = 0;
    while(pos > 0){
        ans = ans + b[pos];
        pos -= (pos & (-pos));
    }
    return ans;
}
        signed main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);  cout.tie(NULL);     
        cin >> n >> q;
        for(long i = 0; i <= n; i++){
            BIT1[i] = 0;
            BIT2[i] = 0;
        }
        for(long long i = 1; i <= n; i++){
            cin >> value;
            UpdateRange(i, i, value);
        }
        while(q--){
            cin >> Type;
            if(Type == 1){
                cin >> u >> v >> x;
                UpdateRange(u, v, x);
            }
            else{
                cin >> u >> v;
                cout << getsum(BIT1, v) - getsum(BIT2, v) * (n-v) - getsum(BIT1, u - 1) + getsum(BIT2, u - 1) * (n - u + 1) << endl;
            }
        }
}