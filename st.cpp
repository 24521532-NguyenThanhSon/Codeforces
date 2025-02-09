#include<iostream>
#include<stdio.h>
    using namespace std;
    string s;
    signed main(){
        cin >> s;
        for(long i = s.size(); i >= 1; i--){
            for(long j = 0; j <= s.size() -  i; j++){               
                for(long k = j; k <= j + i - 1; k++)    cout << s[k];
                cout << endl;
            }
        }
}