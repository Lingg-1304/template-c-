#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
int parent[1001];
vector<int> adj[1001];
int color[1001];
int ok = 0;
void dfs(int u){
	if(ok == 1) return;
	color[u]=1;
	for(int v : adj[u]){
		if(color[v] == 1 && v != parent[u]){
			ok = 1;
		}
		if(color[v] == 0){
			parent[v] = u;
			dfs(v);
		}
	}
	color[u]=2;
}
int main(){
    fast;
    int n,m; cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
    	if(color[i] == 0){
    		dfs(i);
		}
	}
	if(ok == 1) cout<<"1";
	else cout<<"0";
}
