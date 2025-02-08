#include<iostream>
#include<stdio.h>
    using namespace std;
    long long t, n, max1, max2, a[200005], b[200005];
void inp(){
    cin >> n;
    max1 = 0;
    max2 = 0;
    for(long i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        max1 = max(max1, a[i]);
        max2 = max(max2, b[i]);
    }
    cout << (max1 + max2) * 2 << endl;


    //phap test feature 1
phap 3
wtf is that
}
    signed main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);  cout.tie(NULL);
        cin >> t;
        while(t--){
            inp();
        }
        hihihi
    }
