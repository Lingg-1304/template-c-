#include<bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int,int>
#define iii pair<long long,ii>
#define ll long long
using namespace std;
int n , parent[305] ;
ll w[305] ;
ll a[305][305];
vector<iii> canh;
vector<int> adj[305];
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
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> w[i];
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = i + 1 ; j <= n ; j++){
			canh.push_back( {a[i][j] , {i,j}} );
		}
	}
	sort(canh.begin() , canh.end());

	for(iii x : canh){
		adj[x.se.fi].push_back(x.se.se);
		adj[x.se.se].push_back(x.se.fi);
		//cout<<x.se.fi<<' '<<x.se.se<<' '<<x.fi<<endl;
	}

	ll ans = 1e18;
	for(int i = 1 ; i <= n ; i++){
		ll res = w[i];
		for(int k = 1 ; k <= n ; k++) parent[k] = k;
		ll minn = 1e18;
		for(int x : adj[i]){
			minn = min(minn , a[i][x]);
		}

		for(int x : adj[i]){
			if(a[i][x] == minn){
				Union(i,x);
				if(minn > w[x]){
					res += w[x];
				}
				else{
					res += minn;
				}
				break;
			}
		}

		for(iii x : canh){
			int u = x.se.fi , v = x.se.se , t = x.fi;
			if(Union(u,v)){
				if(t > w[v]){
					res += w[v];
				}
				else res += t;
			}
		}

		ans = min(ans, res);
	}

	cout<<ans<<endl;

}