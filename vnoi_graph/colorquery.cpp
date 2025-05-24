#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n , parent[maxn] ;
#define mp map<int,int>;
vector<mp> color;

int findset(int u){
	if(u == parent[u]) return u;
	return parent[u] = findset(parent[u]);
}
bool Union(int u , int v){
	u = findset(u);
	v = findset(v);
	if(u == v) return false;
	
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int q;
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++){
		parent[i] = i;

	}
	// while(q--){
	// 	int x , u , v; cin >> x >> u >> v;
	// 	if(x == 1){
	// 		Union(u,v);
	// 	}
	// 	else{

	// 	}
	// }
}