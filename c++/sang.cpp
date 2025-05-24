#include<bits/stdc++.h>
using namespace std;
int dp[10000001];
void sang(){
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=sqrt(1e7);i++){
        for(int j=i*i;j<=1e7;j+=i){
            dp[j]=1;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    sang();
    return 0;
}
