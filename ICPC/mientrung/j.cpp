#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int maxn = 100005;

int n , h[maxn] , up[maxn][17] , par[maxn];
vector<int> adj[maxn];
bool visited[maxn];

void dfs(int u){
    visited[u] = true;
    for(int x : adj[u]){
        if(!visited[x]){
            par[x] = u;
            h[x] = h[u] + 1;
            dfs(x);
        }
    }
}

void ktao(){
    for(int u = 1 ; u <= n ; u++) up[u][0] = par[u];
    for(int i = 1 ; i < 17 ; i++){
        for(int j = 1 ; j <= n ; j++){
            up[j][i] = up[up[j][i-1]][i-1];
        }
    }
}

int totien_k(int u , int k){
    for(int j = 16 ; j >= 0 ; j--){
        if(k >= (1 << j)){
            u = up[u][j];
            k -= 1 << j;
        }
    }
    return u;
}

int lca(int u , int v){

    if(h[u] != h[v]){
        if(h[u] < h[v]) swap(u , v);
        u = totien_k(u , h[u] - h[v]);
    }

    if(u == v) return u;

    //LCA
    int k = __lg(h[u]);
    for(int j = k ; j >= 0 ; j--){
        if(up[u][j] != up[v][j]){
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0];
}

int main(){
    int test;
    cin >> n >> test;
    for(int i = 1 ; i < n ; i++){
        int u , v ; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    ktao();

    //cout<<lca(5,2);

    while(test--){
        int u , x , v; cin >> u >> x >> v;
        int pa = lca(u,v);
        int vx = lca(v,x) , ux = lca(u,x);
        if(pa == x){
            cout << "YES" << endl;
        }
        else if((vx == pa && ux == x) || (ux == pa && vx == x)){
            cout << "YES" << endl;
        }
        else if((ux == x && vx == v && pa == v) || (vx == x && ux == u && pa == u)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }

}