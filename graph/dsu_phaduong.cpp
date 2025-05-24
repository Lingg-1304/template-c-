#include<bits/stdc++.h>
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
const int maxn = 1e5 + 5;
int n , m , q , parent[maxn];
ii canh[maxn];
vector<int> id , kq;
bool check[maxn];
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

int main(){
	memset(check , false , sizeof(check));
	cin >> n >> m >> q;
	for(int i = 1 ; i <= n ; i++) parent[i] = i;
	for(int i = 1 ; i <= m ; i++){
		cin >> canh[i].fi >> canh[i].se;
	}
	for(int i = 0 ; i < q ; i++){
		int x; cin >> x;
		check[x] = true;
		id.push_back(x);
	}
	int tplt = n;
	for(int i = 1 ; i <= m ; i++){
		if(!check[i]){
			if(Union(canh[i].fi , canh[i].se)) tplt--;
		}
	}
	reverse(id.begin(),id.end());
	int sz = id.size();
	for(int i = 0 ; i < sz ; i++){
		int u = canh[id[i]].fi , v = canh[id[i]].se;
		kq.push_back(tplt);
		if(Union(u,v)) tplt--;
	}
	reverse(kq.begin(),kq.end());
	for(int x : kq) cout<<x<<endl;
}