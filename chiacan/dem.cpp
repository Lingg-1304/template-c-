#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 1e5 + 5;
int n , a[maxn];
int cnt[maxn];

map<int,vector<int>> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> n >> t;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        if(a[i] <= n) cnt[a[i]]++;
    }

    vector<int> dem[n+1];
    vector<int> v;

    for(int i = 1; i <= n ; i++){
        if(cnt[i] >= i){
            v.push_back(i);
        }
    }

    for(int x : v){
        dem[x].push_back(0);
        for(int i = 1 ; i <= n ; i++){
            if(a[i] == x){
                dem[x].push_back(dem[x][i-1]+1);
            }
            else{
                dem[x].push_back(dem[x][i-1]);
            }
        }
    }

    while(t--){
        int l,r; cin >> l >> r;
        int ans = 0;
        for(int x : v){
            //cout << dem[x][r] << ' ' << dem[x][l-1] << endl;
            if(x == dem[x][r] - dem[x][l-1]){
                ans++;
            }
        }
        cout << ans << endl;      
    }                               
}