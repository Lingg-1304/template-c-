#include<bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int,int>
#define iii pair<int,ii> 
const int maxn = 2e5 + 5; 
using namespace std;
int n,m,parent[maxn];
vector<iii> canh;
vector<iii> duyet;
int findset(int u){
	if(u == parent[u]) return u;
	return parent[u] = findset(parent[u]);
}
bool Union(int u , int v){
	u = findset(u);
	v = findset(v);
	if(u == v) return false;
	parent[u] = v;
	return true;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 0 ; i < m ; i++){
		int u , v , w; cin >> u >> v >> w;
		canh.push_back({w,{u,v}});
		duyet.push_back({w,{u,v}});
	}
	sort(canh.begin(),canh.end());
	for(iii ka : duyet){
		for(int i = 1 ; i <= n ; i++) parent[i] = i;
		int sum = ka.fi , dem = 1;
		int a = ka.se.fi , b = ka.se.se;
		Union(a,b);
		for(iii x : canh){
			int u = x.se.fi , v = x.se.se , w = x.fi;
			if(Union(u,v)){
				sum += w;
				dem++;
			}
			if(dem == n-1) break;
		}
		cout<<sum<<endl;
	}
}