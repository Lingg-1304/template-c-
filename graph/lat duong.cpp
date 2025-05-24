#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
int n,m,dem;
int kq = 1;
int parent[100005];
int sz[100005];
int Find(int u){
	if(u == parent[u]) return u;
	return parent[u] = Find(parent[u]);
}
bool Union(int u,int v){
	u = Find(u);
	v = Find(v);
	if(u == v) return false;
	else{
		parent[v] = u;
		sz[u] += sz[v];
		kq = max(kq,sz[u]);
		return true;
	}
}
int main(){
    fast;
    cin>>n>>m;
    dem = n;
    for(int i = 1; i<=n ;i++){
    	parent[i] = i;
    	sz[i] = 1;
	}
	for(int i=0;i<m;i++){
		int x,y; cin>>x>>y;
		if(Union(x,y)){
			dem--;
		}
		cout<<dem<<" "<<kq<<endl;
	}
}
