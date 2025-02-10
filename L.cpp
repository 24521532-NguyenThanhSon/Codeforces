#include <iostream>
#include <string>
#include <cmath>
using namespace std;
long long maxHamming(string& a, string& b) {
    long long sum=0;
    long long length=max(a.length(),b.length());
    while(b.length()<length) b='0'+b;
    while(a.length()<length) a='0'+a;
    bool found=false;
    for(int i=0;i<length;i++){
        if(a[i]!=b[i]&&!found){
            found=true;
        }
        if(found){
            sum++;
        }
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    string a,b;
    cin>>a>>b;
    cout<<maxHamming(a,b);
    return 0;
}