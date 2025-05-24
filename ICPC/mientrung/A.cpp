#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<ll,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;

int n , w , h ;
ll dp[2][100005];

vector<II> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> w >> h;
    int maxc = 0;

    for(int i = 1 ; i <= n ; i++){
        II x; 
        cin >> x.fi >> x.se;
        maxc = max(maxc , x.se);
        v.push_back(x);
    }

    maxc *= n;

    int ans = 0;

    for(int i = 1 ; i <= maxc ; i++){
        dp[1][i] = 1e18;
        dp[0][i] = 1e18;
    }

    dp[0][0] = 0;
    dp[1][0] = 0;

    for(int i = 0 ; i < v.size() ; i++){
        for(int j = maxc ; j >= v[i].se ; j--){
            dp[1][j] = min(dp[1][j] , dp[1][j-v[i].se] + v[i].fi);
            dp[0][j] = min(dp[0][j] , dp[0][j-v[i].se] + v[i].fi);
            if(v[i].fi <= h) dp[1][j] = min(dp[1][j] , dp[0][j-v[i].se]);
        }
    }

    for(int i = maxc ; i >= 1 ; i--){
        if(dp[1][i] <= w){
            ans = max(ans , i);
        }
        if(dp[0][i] <= w){
            ans = max(ans , i);
        }
    }

    cout << ans;
}