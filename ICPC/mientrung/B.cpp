#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<ll,ll> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 1e6 + 5;
int n , a[maxn];
ll f[maxn];
map<ll,int> mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    for(int i = 1 ; i <= n ; i++){
        f[i] = f[i-1] + a[i];
    }
    ll maxi = -1e18 , maxx = - 1e18 , minn = 1e18 , mini = 1e18;
    for(int pos = 1 ; pos <= n ; pos++){
        mini = min(mini , f[pos]);
        maxi = max(maxi , f[pos]);
        maxx = max(maxx , f[pos] + maxi);
        minn = min(minn , f[pos] + mini);
    } 
    ll dem1 = 0 , dem2 =  0;
    for(int pos = 1 ; pos <= n ; pos++){
        if(f[pos] == mini) dem1++;
    }
    dem1 = dem1*(dem1+1)/2;
        
    for(int pos = 1 ; pos <= n ; pos++){
        if(f[pos] == maxi) dem2++;
    }
    dem2 = dem2*(dem2+1)/2;
    
    if(abs(maxx - f[n]) > abs(f[n] - minn)){
        cout << abs(maxx - f[n]) << ' ' << dem2;
    }
    else if(abs(maxx - f[n]) < abs(f[n] - minn)){
        cout << abs(f[n] - minn) << ' ' << dem1;
    }
    else{
        if(maxx != minn) cout << abs(maxx - f[n]) << ' ' << dem1 + dem2;
        else cout << abs(maxx - f[n]) << ' ' << dem1;
        //if(maxx - f[n] == abs(f[n] - minn) || abs(maxx - f[n]) == f[n] - minn) cout << abs(maxx - f[n]) << ' ' << dem1 + dem2;
    }
    // cout << endl << maxx - f[n] << ' ' << f[n] - minn << endl;
    // cout << endl << maxx << ' ' << minn << endl;
    // for(int i =1 ; i <= n ; i++) cout << f[i] << ' ';
}