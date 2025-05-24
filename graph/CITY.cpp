#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
int const maxn = 1e4 + 5;
int n,m,a,b;
vector<ii> adj[maxn];
int d[maxn] , parent[maxn];
void dijk(int s){
	priority_queue<ii , vector<ii> , greater<ii>> q;
	q.push({0,s});
	d[s] = 0;
	parent[s] = 0;
	while(!q.empty()){
		ii k = q.top(); q.pop();
		int u = k.se , kc = k.fi;
		if(kc >= d[u]) continue;
		for(ii z : adj[u]){
			int v = z.fi , w = z.se;
			if(d[u] + w < d[v]){
				d[v] = d[u] + w;
				q.push({d[v],v});
				parent[v] = u;
			}
		}
	}
}

int main(){
	cin>>n>>m>>a>>b;
	for(int i = 0; i < m; i++){
		int u,v,w; cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	for(int i = 1; i <= n; i++) d[i] = 1e9;
	dijk(a);
	while(b != a){
		cout<<b<<" ";
		b = parent[b];
	}
}
