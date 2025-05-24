#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ii pair<int,int>
#define ll long long
int n,m,s;
ll d[1005];
vector<int> adj[1005];
int w[1005][1005];
void dijkstra(int s){
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, s});
    while(!q.empty()){
        ii t = q.top(); q.pop();
        int dis = t.first, u = t.second;
        if(dis == d[u]){
            for(int v : adj[u]){
                if(d[v] > d[u] + w[u][v]){
                    d[v] = d[u] + w[u][v];
                    q.push({d[v], v});
                }
            }
        }
    }
} 
int main(){
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		int x,y,t; cin>>x>>y>>t;
		adj[x].push_back(y);
		adj[y].push_back(x);
		w[x][y] = w[y][x] = t;
	}
	for(int i=1;i<=n;i++) d[i] = 1e9;
	d[s] = 0;
	dijkstra(s);
	for(int i=1;i<=n;i++) cout<<d[i]<<" ";
}
