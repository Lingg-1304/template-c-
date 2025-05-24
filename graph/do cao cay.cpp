#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
int n;
vector<int> adj[1005];
bool visit[1005];
int d[1005];
void bfs(int u){
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int k = q.front(); q.pop();
		visit[k] = true;
		for(int v : adj[k]){
			if(!visit[v]){
				d[v] = d[k] + 1;
				q.push(v);
			}
		}
	}
}
int main(){
    fast;
    memset(visit , false , sizeof(visit));
    cin>>n;
    for(int i=0;i<n-1;i++){
    	int x,y;
    	cin>>x>>y;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
	}
	bfs(1);
	for(int i=1;i<=n;i++) cout<<d[i]<<" ";
}
