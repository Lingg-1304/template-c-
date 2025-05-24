#include<bits/stdc++.h>
using namespace std;
int n,k;
int gian[1005],d[1005],check[1005];
vector<int> adj[1005];
int visit[1005];
void bfs(){
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u = q.front(); q.pop();
		visit[u] = true;
		for(int v : adj[u]){
			if(!visit[v]){
				gian[v] += gian[u];
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
}
int main(){
	memset(visit,false,sizeof(visit));
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>gian[i];
	for(int i=1;i<=n-1;i++){
		int x,y; cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	bfs();
	int kq = -1;
	for(int i=1;i<=n;i++){
		cout<<gian[i]<<" "<<d[i]<<endl;
		if(gian[i] <= k){
			kq=max(kq,d[i]);
		}
	}
	cout<<kq;
}
