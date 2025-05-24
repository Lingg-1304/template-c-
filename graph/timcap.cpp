#include<bits/stdc++.h>
using namespace std;
int n;
int d[1005];
vector<int> adj[1005];
int dfs(int u){
	d[u] = 1;
	for(int v : adj[u]){
		d[u]+=dfs(v);
	}
	return d[u];
}
int main(){
	cin>>n;
	for(int i=1;i<=n-1;i++){
		int x,y; cin>>x>>y;
		adj[x].push_back(y);
	}
	dfs(1);
	int kq=0;
	for(int i=1;i<=n;i++){
	//	cout<<d[i]<<" ";
		kq+=d[i];
	}
	cout<<kq;
}
