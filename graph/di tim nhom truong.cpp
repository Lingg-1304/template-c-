#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
int n,m;
vector<int> adj[1005];
int parent[1005];
int Find(int u){
	if(u == parent[u]) return u;
	return parent[u] = Find(parent[u]);
}
bool Union(int u,int v){
	u = Find(u);
	v = Find(v);
	if(u == v) return false;
	else{
		if(adj[u].size() == adj[v].size()){
			if(u<v) parent[v] = u;
			else parent[u] = v;
		}
		else if(adj[u].size() > adj[v].size()){
			parent[v] = u;
		}
		else parent[u] = v;
		return true;
	}
}
int main(){
	set<int> se;
    fast;
    cin>>n>>m;
    vector<II> canh;
    for(int i=0;i<m;i++){
    	int x,y; cin>>x>>y;
    	canh.push_back({x,y});
    	adj[x].push_back(y);
    	adj[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		parent[i] = i;
	}
	for(II k : canh){
		Union(k.fi,k.se);
	}
	for(int i=1;i<=n;i++){
		Find(i);
	}
	for(int i=1;i<=n;i++){
		se.insert(parent[i]);
	}
	for(int x : se) cout<<x<<" ";
}
