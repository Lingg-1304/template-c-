#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> II;
typedef pair <II,int> III;
void run(){
	int k,n,m;
    int d[105], w[105];
	vector<III> adj[105];
	cin>>k>>n>>m;
	for(int i = 0; i < m; i++){
		int s,t,l,o;
		cin>>s>>t>>l>>o;
		adj[s].push_back({{l,o},t});
	}
	for(int i = 1; i <= n; i++) w[i] = 1e9;
	d[1] = 0;
	w[1] = 0;
	priority_queue< III , vector<III> , greater<III> > q;
	q.push({{0,0},1});
	while(!q.empty()){
		III uuu = q.top(); q.pop();
		int len = uuu.fi.fi , c = uuu.fi.se , u = uuu.se;
		if(c > w[u]) continue;
		for(III x : adj[u]){
			int v = x.se , le = x.fi.fi , tien = x.fi.se;
			if(w[u] + tien < w[v]){
				d[v] = d[u] + le;
				w[v] = w[u] + tien;
				q.push({{w[v],d[v]},v});
			}
		}
	}
	cout<<w[n]<<" "<<d[n]<<endl;
	if(w[n] <= k) cout<<d[n]<<endl;
	else cout<<"-1"<<endl;
}
int main(){
	int test; cin>>test;
	while(test--){
		run();
	}
}
