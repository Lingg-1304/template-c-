#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 5e5;

int n , m , k;
int d[maxn];
vector<II> adj[maxn];

void dijk(){
    priority_queue<II , vector<II>  , greater<II>> q;
    q.push({0,1});
    while(!q.empty()){
        II Top = q.top(); q.pop();
        int u = Top.se , w = Top.fi;
        if(w > d[u]) continue;
        for(II x : adj[u]){
            int v = x.fi , ww = x.se;
            if(w + ww < d[v]){
                d[v] = w + ww;
                q.push({d[v],v});
            }
        }
    }
}

void Run(){
    for(int i = 0 ; i < m ; i++){
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    for(int i = 1 ; i <= n ; i++) d[i] = 1e9;
    d[1] = 0;
    dijk();

    for(int i = 1 ; i <= n ; i++) cout << d[i] << ' ';

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    Run();

}