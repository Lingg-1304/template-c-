#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define ii pair<int,int>
#define ll long long
#define fast ios::sync_with_stdio(0)
int da[100001],db[100001],d[100001];
int n,m,k,a,b;
vector<ii> adj[100001];
void dij(int s){
	d[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > q;
	q.push(mp(0,s));
	while(!q.empty()){
		int u = q.top().se , t = q.top().fi;
		q.pop();
		if(d[u] != t) continue;
		for(int i=0;i<adj[u].size();i++){
			ii uu = adj[u][i];
			int v = uu.fi, w = uu.se;
			if(d[u] + w < d[v]){
				d[v] = d[u] + w;
				q.push(mp(d[v],v));
			}
		}
	}
}
int main(){
//	freopen("mday.inp","r",stdin);
//	freopen("mday.out","w",stdout);
	fast;
	cin>>n>>m>>k;
	cin>>a>>b;
	ii hoa[k];
	for(int i=0;i<k;i++){
		cin>>hoa[i].fi>>hoa[i].se;
	}
	for(int i=0;i<m;i++){
		int x,y,t; cin>>x>>y>>t;
		adj[x].push_back(mp(y,t));
		adj[y].push_back(mp(x,t));
	}
	for(int i=1;i<=n;i++){
		d[i] = 2e9;
	}
	dij(a);
	for(int i=1;i<=n;i++){
		da[i] = d[i];
		d[i] = 2e9;
	}
	dij(b);
	for(int i=1;i<=n;i++){
		db[i] = d[i];
	}
	int kq = 2e9;
	for(int i = 0;i < k ;i++){
		int p = da[hoa[i].fi] + db[hoa[i].fi] + hoa[i].se;
		if(p < kq) kq = p;
	}
	cout<<kq<<endl;
}
