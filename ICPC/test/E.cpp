#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ii pair<int,int>
const int maxn = 1e4 + 5;
int par[maxn] , n , up[maxn][17] , d[maxn] , h[maxn] , S , Q , H;
bool visited[maxn];
vector<ii> adj[maxn];
vector<pair<ii,int>> canh;
vector<int> lang;
void dfs(int u){
	visited[u] = true;
	for(ii x : adj[u]){
		int v = x.fi , w = x.se;
		if(!visited[v]){
			par[v] = u;
			h[v] = h[u] + 1;
			d[v] = d[u] + w;
			dfs(v);
		}
	}
}
void preprocess() {
    for (int u = 1; u <= n; ++u) up[u][0] = par[u];
    for(int i = 1 ; i < 17 ; i++){
    	for(int j = 1 ; j <= n ; j++){
    		up[j][i] = up[up[j][i-1]][i-1];
    	}
    }

}
int ancestor_k(int u, int k) {
    for (int j = 16; j >= 0; --j)
        if (k >= (1 << j)) u = up[u][j], k -= 1 << j;
    return u;
}
int lca(int u, int v) {
    if (h[u] != h[v]){
        if (h[u] < h[v]) swap(u, v);
        u = ancestor_k(u,h[u] - h[v]);
    }
    if (u == v) return u;
    
    int k = __lg(h[u]);
    for (int j = k; j >= 0; --j)
        if (up[u][j] != up[v][j]) 
            u = up[u][j], v = up[v][j];
    return up[u][0];
}

int kc(int x , int y){
    return d[x] + d[y] - 2*d[lca(x,y)];
}

void Solve(){
    int sc , u; cin >> sc >> u;
    
}

int main(){
	cin >> n >> S >> Q >> H;
	for(int i = 1 ; i <= n ; i++) visited[i] = false;
	for(int i = 1 ; i <= n - 1 ; i++){
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
        canh.push_back({{u,v},w});
	}
	dfs(1);
	preprocess();


    for(int i = 1 ; i <= S ; i++){
        int c; cin >> c;
        lang.push_back(c);
    }

	while(Q--){
        Solve();
	}
	cout << lca(5,9);
}
