#include<bits/stdc++.h>
#define ii pair<int,int>
#define fi first
#define se second
const int maxn = 1e5 + 5;
using namespace std;
int n , q , root;
vector<int> adj[maxn];
int parent[maxn] , h[maxn];
void bfs(){
	bool visit[maxn];
	for(int i = 1 ; i <= n ; i++) visit[i] = false;	
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u = q.front(); q.pop();
		visit[u] = true;
		for(int v : adj[u]){
			if(!visit[v]){
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
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	while(1){
		cin >> n;
		if(n == 0) break;
		for(int i = 1 ; i <= n ; i++){
			adj[i].clear();
			parent[i] = h[i] = 0;
		}
		for(int i = 1 ; i <= n - 1 ; i++){
			int u , v;
			cin >> u >> v;
			adj[v].push_back(u);
			adj[u].push_back(v);
		}
		bfs();
		cin >> q;
		while(q--){
			char x ;
			cin >> x;
			if(x == '?'){
				int u , v; cin >> u >> v;
				int a = lca(u,v) , b = lca(u,root) , c = lca(v,root);
				if(a == b) cout<<c<<endl;
				else if(b == c) cout<<a<<endl;
				else cout<<b<<endl;
			}
			else{
				cin >> root;
			}
		}
	}
}