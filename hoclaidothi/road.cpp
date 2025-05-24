#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
using T = tuple<int,int,int>;

int mod = 1e9+7;
const int maxn = 105;

int n , m , k;
int d[maxn][10005];
vector<T> adj[maxn];

void dijk(){
    d[1][0] = 0;
    priority_queue<T , vector<T> , greater<T>> q;
    q.push({0,0,1});
    while(!q.empty()){
        T Top = q.top(); q.pop();
        int l = get<0>(Top) , t = get<1>(Top) , u = get<2>(Top);
        if(l > d[u][t]) continue;

        for(T x : adj[u]){
            int v = get<0>(x) , ll = get<1>(x) , tt = get<2>(x);
            if(l + ll < d[v][tt+t] && tt + t <= k){
                d[v][t+tt] = l + ll;
                q.push({d[v][tt + t] , tt + t , v});
            }
        }
    }

    // for(int i = 1 ; i <= n ; i++) cout << d[i] << ' ';
    // cout << endl;
    // for(int i = 1 ; i <= n ; i++) cout << money[i] << ' ';
}

void Run(){
    cin >> k >> n >> m;

    for(int i = 0 ; i < m ; i++){
        int u , v , l , t;
        cin >> u >> v >> l >> t;
        adj[u].push_back({v,l,t});
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= k ; j++){
            d[i][j] = 1e9;
        }
    }

    dijk();

    int ans = 1e9;

    for(int i = 0 ; i <= k ; i++){
        ans = min (ans , d[n][i]);
    }

    if(ans == 1e9) cout << "-1" << endl;
    else cout << ans << endl;

    for(int i = 1 ; i <= n ; i++){
        adj[i].clear();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q; cin >> q;
    while(q--){
        Run();
    }
    
}