#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<long long,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 5e5;
ll n , a , b , c;

ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) *  b;
}

ll ptich(ll x){
    int dem = 0;
    ll kq = 1;
    for(ll i = 2 ; i <= sqrt(x) ; i++){
        while(x % i == 0){
            dem++;
            x /= i;
        }
        if(dem > 0){
            //cout << dem << endl;
            kq *= (dem + 1);
            dem = 0;
        }
    }
    if(x > 1){
        kq *= 2;
    }
    return kq;
}

int aa , bb , cc;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> a >> b >> c;
    
    ll xx = lcm(a , b);
    ll yy = lcm(a , c);
    ll zz = lcm(b , c);
    ll tt = lcm(xx , c);
    ll ans = 0;
    if(n % xx == 0){
        aa = 1;
    }
    if(n % yy == 0){
        bb = 1;
    }
    if(n % zz == 0){
        cc = 1;
    }
    if((aa + bb + cc) == 3){
        ans += ptich(n/xx);
        ans += ptich(n/yy);
        ans += ptich(n/zz);
        ans -= 2*ptich(n/tt);
    }
    if((aa + bb + cc) == 1){
        if(n % xx == 0){
            ans += ptich(n/xx);
        }
        if(n % yy == 0){
            ans += ptich(n/yy);
        }
        if(n % zz == 0){
            ans += ptich(n/zz);
        }
    }
    cout << ans;
}   