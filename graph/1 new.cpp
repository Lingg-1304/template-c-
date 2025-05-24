#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 10005;

vector<III> dsc[maxn];
int d[10006]

void bellman_ford()
{
    for(int i = 1 ; i <= n ; i++) d[i] = 1e9;
    d[s] = 0;
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            int  u = dsc[j].fi.fi , v = dsc[j].fi.se , w = dsc[j].se;
            if(d[u] != 1e9 && d[u] + w < d[v]){
                d[v] = d[u] + w;    
            }
        }
    }
}

void dijk(){
    priority_queue< II , vector<II> , greater<II> > q;
    q.push({0,s});
    d[s] = 0;
    while(!q.empty()){
        II top = q.top(); q.pop();
        int u = top.se , w = top.fi;
        if(w > d[u]) continue;
        for(II x : adj[u]){
            int v = II.fi , dw = II.se;
            if(w + dw < d[v]){
                d[v] = w + dw;
                q.push({d[v],v});
            }
        }
    }
}

int main(){
    fast;
    cin >> n >> m >> s;
    for(int i = 0 ; i < m ; i++){
        int u , v , w;
        cin >> u >> v >> w;
        dsc.push_back({{u,v},w});
    }
    bellman_ford();
}
