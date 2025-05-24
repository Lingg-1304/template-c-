#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
ll kq = 0;
int n,m,check=0;
int parent[100005];
struct canh{
	int x,y,w;
};
vector<canh> v;
bool cmp(canh a,canh b){
	return a.w < b.w;
}
int Find(int u){
	if(u == parent[u]) return u;
	return parent[u] = Find(parent[u]);
}
bool Union(int u,int v){
	u = Find(u);
	v = Find(v);
	if(u == v) return false;
	else{
		parent[u] = v;
		return true;
	}
}
int main(){
    fast;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	parent[i] = i;
	}
    for(int i=0;i<m;i++){
    	canh k;
    	cin>>k.x>>k.y>>k.w;
    	v.push_back(k);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<m;i++){
		if(check==n-1) break;
		if(Union(v[i].x,v[i].y)){
			kq+=v[i].w;
			check++; 
		}
	}
	if(check != n-1) cout<<"IMPOSSIBLE";
	else cout<<kq;
}
