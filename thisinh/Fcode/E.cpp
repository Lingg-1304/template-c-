#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 1e6;

int n , a[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int c = 0 , l = 0;
    ll sumc = 0 , suml = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        if(a[i] % 2 == 0){
            sumc += a[i];
            sumc %= mod;
            c++;
        }
        else{
            suml += a[i];
            suml %= mod;
            l++;
        }
    }

    ll ans = (sumc * l)%mod + (suml * c)%mod;
    ans %= mod;
    cout << ans;

}