#include<bits/stdc++.h>
using namespace std;
int n , s;
int dp[205][205];
int w[205], t[205];
int main(){
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     // freopen("caitui.inp","r",stdin);
     // freopen("caitui.out","w",stdout);
     cin >> n >> s;
     for(int i = 1 ; i <= n ; i++) cin >> w[i];
     for(int i = 1 ; i <= n ; i++) cin >> t[i];
     for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=w[i]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+t[i]);
            }
        }
    }
     cout<<dp[n][s]<<endl;

     //truy vet
    //  while (n > 0)
    // {
    //     if (dp[n][s] == dp[n - 1][s])
    //         --n;
    //     else 
    //     {
    //         cout<<n<<' ';
    //         s -= w[n];
    //         --n;
    //     }
    // }
}