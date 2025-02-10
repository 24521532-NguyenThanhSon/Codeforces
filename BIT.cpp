    #include<iostream>
    #include<stdio.h>
    #include<map>
    #include<set>
    #include<vector>
    #include<string>

    using namespace std;
    typedef long long ll;
        ll t, N, K, ans;
        ll dp[100005][20];
    void solve(){
        ans = 0;
        cin >> N  >> K;
        for(long i = 0; i <= (1 <<  N) - 1; i++)  
        for(long j = 0; j <= N; j++)    dp[i][j] = 0;
        dp[0][0] = 1;       
        
        for(long mask = 0; mask < (1 << N) - 1; mask++)
        for(long last = 1; last <= N; last++){
            if(mask == 0)   dp[mask + (1 << (last - 1))][last] += dp[mask][0];
            else{
                if(((mask >> (last - 1)) & 1)){
                    for(long newlast = 1; newlast <= N; newlast++){
                        if((!(((mask >> (newlast - 1)) & 1))) and abs(newlast - last) <= K){
                            ll newmask = mask + (1 << (newlast - 1)); 
                            dp[newmask][newlast] += dp[mask][last];
                        }
                    }
                }
            }
        }
        for(long i = 1; i <= N; i++)    ans = ans + dp[(1 << N) - 1][i];
        cout << ans << endl;
    }
        signed main(){
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);  cout.tie(NULL);
            cin >> t;
            while(t--){
                solve();
            }
        
    }