#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod =  987654321;
const int maxn = 5e5;

long long Try(ll n){
    if(n < 3) return 0;
    if(n == 3) return 1;
    else if(n % 2 == 0){
        ll k = (n - 2)/2 + 1;
        return k + Try(n - k);
    }
    else if(n % 2 == 1){
        ll k = (n - 2 - 1)/2 + 1;
        return k + Try(n - k);
    }
    //else return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    cout << Try(n);
}