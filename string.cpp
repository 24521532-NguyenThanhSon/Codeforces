#include<iostream>
#include<string>
#include<stdio.h>
    using namespace std;

bool check(char p, string &t){
    for(long i = 0; i < t.size(); i++){
        if(p == t[i])   return true;
    }
    return false;
}
    signed main(){
        string s, t, ans[10005];
        bool pos[10005];

        getline(cin, s);
        getline(cin, t);
        for(long i = 0; i < s.size(); i++){
                if(check(s[i], t) == false){
                    pos[i] = false;                    
                }
                else
                    pos[i] = true;
        }
        bool out = true;
        bool first = false;
        for(long i = 0; i < s.size(); i++){
            if(pos[i] == false){
                if(out == true){
                    cout << s[i];
                    first =true;
                }   
                else{
                    if(first == true){
                        cout << endl;
                        cout << s[i];
                    }
                    else{
                        cout << s[i];
                        first = true;
                    }
                }
                out = true;
            }
            else{
                out = false;
            }
        }
}