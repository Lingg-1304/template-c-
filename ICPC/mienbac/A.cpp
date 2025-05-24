#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 5e5;

vector<ll> v;
map<ll,int> mp;

void solve(ll n){
    set<string> se;
    ll ans = 1;
    ll last = 3;
    int pos = lower_bound(v.begin() , v.end() , n) - v.begin();
    for(int j = 0 ; j <= pos ; j++){
        //if(last <= v[j]) continue;
        ll k = n;
        string s;
        for(int i = j ; i < v.size() ; i++){
            while(k % v[i] == 0){
                s += to_string(v[i]) + ' ';
                k /= v[i];
                last = v[i];
            }
        }
        //if(k != 1 &&) continue;
        if(s != "") se.insert(s);
    }
    for(string s : se) cout << s << endl;
    cout << se.size() << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("hi.inp" , "r" , stdin);
    // freopen("hi.out" , "w" , stdout);

    ll a[5];
    a[1] = 1 , a[2] = 1 , a[3];
    mp[1] = 1;
    while(a[3] <= 1e18){
        a[3] = a[1] + a[2];
        a[1] = a[2];
        a[2] = a[3];
        mp[a[3]] = 1;
        v.push_back(a[3]);
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        solve(n);
    }

    //for(ll x : v) cout << x << endl;
}