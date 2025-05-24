#include<bits/stdc++.h>
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
int n , q;
vector<ii> adj[1005];
int d[1005] , parent[1005] , h[1005];
void bfs(){
	bool visit[1005];
	for(int i = 1 ; i <= n ; i++) visit[i] = false;	
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u = q.front(); q.pop();
		visit[u] = true;
		for(ii x : adj[u]){
			int v = x.fi , w = x.se;
			if(!visit[v]){
				d[v] = d[u] + w;
				q.push(v);
				h[v] = h[u] + 1;
				parent[v] = u;
			}
		}
	}
}
int lca(int u , int v){
	if(h[v] < h[u]) swap(u,v);
	int cnt = h[v];
	while(cnt != h[u]){
		v = parent[v];
		cnt--;
	} 
	while(u != v){
		u = parent[u];
		v = parent[v];
	}
	return u;
}
int main(){
	cin >> n >> q;
	for(int i = 0 ; i < n - 1 ; i++){
		int u , v , w;
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	bfs();
	while(q--){
		int x , y;
		cin >> x >> y;
		cout<<d[x] + d[y] - 2*d[lca(x,y)]<<endl;
	}
}