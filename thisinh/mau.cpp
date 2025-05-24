#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define lb long double
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 5e5;

map<ll , II> mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    
    for(int i = 2 ; i <= 1e6 ; i++){
        ll k = 1 + i , pw = i;
        int gh = log(1e18) / log(i);
        for(int j = 2 ; j <= gh ; j++){
            pw *= i;
            k += pw;
            if(mp.count(k) == 0){
                mp[k] = {i,j};
            }
        }
    }

    while(t--){
        ll n; cin >> n;
        if(mp.find(n) != mp.end()){
            cout << mp[n].fi << ' ' << mp[n].se << endl;        
        }
        else{
            long double kk = n;
            long double delta = -3 + 4*kk;
            long double ans = (-1 + sqrt(delta)) / 2;
            int test = ans;
            long double tt = test;
            if(ans > 0 && tt == ans){
                cout << test << " 2" << endl;
            }
            else{
                cout << "-1" << endl;
            }
        }
    }
}