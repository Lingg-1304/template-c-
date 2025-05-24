#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<long long,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 5e5;

ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) *  b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 0;
    ll a , b , c ;
    ll n;
    cin >> n >> a >> b >> c;
    vector<ll> v;
    for(ll i = 1 ;  i <= sqrt(n) ; i++){
        if(n % i == 0){
            if(i == n/i){
                v.push_back(i);
            }
            else{
                v.push_back(i);
                v.push_back(n/i);
            }
        }
    }
    // for(ll i : v){
    //     if((i % a == 0 && i % b == 0) || (i % a == 0 && i % c == 0) || (i % b == 0 && i % c == 0)){
    //         //cout << i << endl;
    //         cnt++;
    //     }
    // }
    ll m = lcm(a,b);
    ll q = lcm(a,c);
    ll p = lcm(c,b);
    for(ll i : v){
        if(i % m == 0 || i % q == 0 || i % p == 0){
            //cout << i << endl;
            cnt++;
        }
    }
    cout << cnt;
}