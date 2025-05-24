#include<bits/stdc++.h>
using namespace std;
int n,m,st,ed;
vector<int> adj[1005];
bool visit[1005];
int parent[1005];
void dfs(int u){
	visit[u] = true;
	for(int x : adj[u]){
		if(!visit[x]){
			parent[x] = u;
			dfs(x);
		}
		else{
			if(x != parent[u]){
				st = x; 
				ed = u;
				return;
			}
		}
	}
}
int main(){
	memset(visit,false,sizeof(visit));
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y; cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1);
	cout<<st<<" "<<ed;
}
