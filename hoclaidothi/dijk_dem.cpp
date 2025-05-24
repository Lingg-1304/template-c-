#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<ll,ll> II;
int mod = 1e9+7;
int n,m;
ll dem[5005];
vector<II> adj[5005];
ll d[5005];
void dijk(){
	priority_queue<II,vector<II>,greater<II>> q;
	q.push({0,1});
	d[1] = 0;
	dem[1] = 1;
	while(!q.empty()){
		II dis = q.top(); q.pop();
		ll c = dis.fi , u = dis.se;
		if(c > d[u]) continue;
		for(II x : adj[u]){
			ll kec = x.se , v = x.fi;
			if(c + kec == d[v]){
				dem[v] += dem[u];
			}
			else if(c + kec < d[v]){
				dem[v] = dem[u];
				d[v] = c + kec;
				q.push({d[v],v});
			}
		}
	}
}
int main(){
    fast;
    cin>>n>>m;
    for(int i=0;i<m;i++){
    	int k,u,v,l; cin>>k>>u>>v>>l;
    	if(k == 1){
    		adj[u].push_back({v,l});
		}
		else{
			adj[u].push_back({v,l});
			adj[v].push_back({u,l});
		}
	}
	for(int i=1;i<=n;i++){
		d[i] = 1e18;
	}
	dijk();
	cout<<d[n]<<" "<<dem[n];
}
