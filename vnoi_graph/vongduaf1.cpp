#include<bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int,int>
#define iii pair<ii,long long>
#define ll long long
using namespace std;
int n , m , parent[10005];
vector<iii> canh;
int findset(int u){
	if(u == parent[u]) return u;
	return parent[u] = findset(parent[u]);
}

bool Union(int u , int v){
	u = findset(u);
	v = findset(v);
	if(u == v) return false;
	parent[v] = u;
	return true; 
}

bool cmp(iii a , iii b){
	return a.se > b.se;
}
int main(){
	int ans = 0;
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
		int u , v , w; cin >> u >> v >> w;
		canh.push_back({{u,v},w});
	}
	sort(canh.begin(),canh.end(),cmp);
	for(int i = 1 ; i <= n ; i++){
		parent[i] = i;
	}
	for(iii x : canh){
		int u = x.fi.fi , v = x.fi.se , w = x.se;
		if(!Union(u,v)){
			ans += w;
		}
	}
	cout<<ans;
}