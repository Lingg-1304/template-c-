#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define ii pair<int,int>
int n,m,k,p;
vector<ii> adj[10005];
ii qua[105],nguoi[2505];
int d[10005][10005];
void dijk(int s){
	for(int i=1;i<=n;i++) d[s][i] = 1e9;
	d[s][s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > q;
	q.push(mp(0,s));
	while(!q.empty()){
		ii dis = q.top(); q.pop();
		int w = dis.fi, u = dis.se;
		if(d[s][u] != w) continue;
		for(int i=0;i<adj[u].size();i++){
			int v = adj[u][i].fi, t = adj[u][i].se;
			int test = d[s][u] + t;
			if(d[s][u] + t < d[s][v]){
				d[s][v] = d[s][u] + t;
				q.push(mp(d[s][v],v));
			}
		}
	}
}
int main(){
//	freopen("hi.inp","r",stdin);
//	freopen("hi.out","w",stdout);
	cin>>n>>m>>k>>p;
	for(int i=0;i<m;i++){
		int u,v,w; cin>>u>>v>>w;
		adj[u].push_back(mp(v,w));
		adj[v].push_back(mp(u,w));
	}
	for(int i=0;i<k;i++){
		cin>>qua[i].fi>>qua[i].se;
		dijk(qua[i].fi);
		//fi : dinh
		//se : gia qua
	}
	for(int i=0;i<p;i++){
		long long kq = 2e9;
		int s,t; cin>>s>>t;
		for(int j=0;j<k;j++){
			long long test = 1ll *(d[qua[j].fi][s] + d[qua[j].fi][t] + qua[j].se); 
			kq = min(kq,test);
		}
		if(kq == 2e9) cout<<"-1";
		else cout<<kq<<endl;
	}
}
