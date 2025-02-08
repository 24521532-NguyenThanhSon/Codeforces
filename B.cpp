#include<iostream>
#include<stdio.h>
    using namespace std;

long long MIN = 1e18;
long long a[200005], LeftMAX[200005], RightMAX[200005], pre[200005];
long long n, k;
    signed main(){
        cin >> n >> k;
        for(long i = 1; i <= n; i++)    cin >> a[i];
        for(long i = 1; i <= n; i++)    pre[i] = pre[i-1] + a[i];
        for(long i = k; i <= n; i++)    LeftMAX[i] = max(LeftMAX[i-1], pre[i] - pre[i-k]);
        for(long i = n - k + 1; i >= 1; i--){
            RightMAX[i] = max(RightMAX[i+1], pre[i + k - 1] - pre[i-1]);
        }
        for(long i = k; i <= n; i++){
            MIN = min(MIN, max(LeftMAX[i-k], RightMAX[i+1]));
        }
        cout << MIN << endl;
}