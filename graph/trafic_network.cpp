#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
vector<II> adj[10005];
vector<II> adjn[10005];
int da[10005], db[10005];
void dijka(int s){
	priority_queue<II,vector<II>,greater<II>> q;
	q.push({0,s});
	da[s] = 0;
	while(!q.empty()){
		II dis = q.top(); q.pop();
		int kc = dis.fi , u = dis.se;
		if(kc > da[u]) continue;
		for(II x : adj[u]){
			int v = x.fi , c = x.se;
			if(kc + c < da[v]){
				da[v] = kc + c;
				q.push({da[v],v});
			}
		}
	}
}
void dijkb(int s){
	priority_queue<II,vector<II>,greater<II>> q;
	q.push({0,s});
	db[s] = 0;
	while(!q.empty()){
		II dis = q.top(); q.pop();
		int kc = dis.fi , u = dis.se;
		if(kc > db[u]) continue;
		for(II x : adjn[u]){
			int v = x.fi , c = x.se;
			if(kc + c < db[v]){
				db[v] = kc + c;
				q.push({db[v],v});
			}
		}
	}
}
void runc(){
	int n,m,k,a,b; cin>>n>>m>>k>>a>>b;
	for(int i=1;i<=n;i++){
		adj[i].clear();
		adjn[i].clear();
	}
	for(int i=1;i<=n;i++) da[i] = db[i] = 1e9;
	for(int i=0;i<m;i++){
		int x,y,c; cin>>x>>y>>c;
		adj[x].push_back({y,c});
		adjn[y].push_back({x,c});
	}
	dijka(a);
	dijkb(b);
	int kq = da[b];
	for(int i=0;i<k;i++){
		int x,y,c; cin>>x>>y>>c;
	    kq = min( kq , min( da[x] + c + db[y] , da[y] + c + db[x] ) );
	}
	
	if(kq == 1e9) cout<<"-1"<<endl;
	else cout<<kq<<endl;
}
int main(){
//	freopen("hi.inp","r",stdin);
//	freopen("hi.out","w",stdout);
    fast;
    int test; cin>>test;
    while(test--){
    	runc();
	}
}
