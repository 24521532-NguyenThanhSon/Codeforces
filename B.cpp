#include<iostream>
#include<stdio.h>
<<<<<<< HEAD
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
        sadasdsad
}
=======
#include<map>
#include<vector>
    using namespace std;
    vector<int> ans;
    long check[2005], d[2005], a[2005];
    long n, t;
long MEX(){
    for(long i = 0; i <= n; i++){
        check[i] = 0;
    }
    for(long i = 1; i <= n; i++){
        check[i] = 1;
    }
    for(long i = 0; i <= n; i++){
        if(check[i] == 0)   return i;
    }
}
void inp(){
    ans.clear();
    cin >> n;

    for(long i = 1; i <= n; i++){
        cin >> a[i]; 
    }
    for(long i = 1; i <= n; i++){
        if(a[i] != i-1){
            for(long j = i + 1; j <= n; j++){

                if(a[j] == i-1){
                    a[j] = MEX();
                    ans.push_back(j);
                }
            }
            a[i] = MEX();
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(long j = 0; j < ans.size(); j++)    cout << ans[j] <<" ";
    cout << endl;
}
        signed main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);  cout.tie(NULL);
        cin >> t;
        while(t--){
            inp();
        }
    }
>>>>>>> a339e49 (up)
