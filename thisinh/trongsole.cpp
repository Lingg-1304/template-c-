#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<long long,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 1e6 + 5;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans = 0;
    cin >> n;
    int sl = 0 , sc = 0;
    ll tc = 0 , tl = 0;
    for(int i = 0 ; i < n ; i++){
        int x; cin >> x;
        if(x % 2 == 0){
            tc += x;
            tc %= mod;
            sc++;
        }
        else{
            tl += x;
            tl %= mod;
            sl++;
        }
    }
    ans = (1ll*tc*sl)%mod + (1ll*tl*sc)%mod;
    ans %= mod;
    cout << ans;
}