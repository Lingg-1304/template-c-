#include<bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int,int>
using namespace std;
const int maxa = 1e6 + 5;
int a[1005][1005];
ii parent[1005][1005];
int n , m , amax , dis , tmp ;
map<int,vector<ii>> mp;
ii findset(int x , int y){
	if(x == parent[x][y].fi && y == parent[x][y].se) return {x,y};
	return parent[x][y] = findset(parent[x][y].fi , parent[x][y].se);
}

bool Union(ii u , ii v){
	u = findset(u.fi , u.se);
	v = findset(v.fi , v.se);
	if(u == v) return false;
	parent[u.fi][u.se] = v;
	return true;
}

int xuly(int k , int p){
	int res = p;
	auto it = mp.lower_bound(k+1);
	for( ; (*it).fi <= dis ; it++){
		vector<ii> adj = (*it).se;
		res += adj.size();
		for(ii itt : adj){
			int x = itt.fi , y = itt.se;
			if(a[x][y-1] > k && Union({x,y} , {x,y-1})) res--;
			if(a[x-1][y] > k && Union({x,y} , {x-1,y})) res--;
			if(a[x][y+1] > k && Union({x,y} , {x,y+1})) res--;
			if(a[x+1][y] > k && Union({x,y} , {x+1,y})) res--;
		}
	}

	dis = k;

	return res;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("land.inp","r",stdin);
	// freopen("land.out","w",stdout);

	cin >> n >> m;

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			parent[i][j] = {i,j};
			cin >> a[i][j];
			mp[a[i][j]].push_back({i,j});
			amax = max(amax  , a[i][j]);
		}
	}
	mp[amax+1].push_back({0,0});
	dis = amax;
	int k; cin >> k;
	int nam[k+1] , kq[k+1];
	for(int i = 1 ; i <= k ; i++) cin >> nam[i];
	sort(nam+1,nam+k+1,greater<int>());
	kq[0] = 0;
	for(int i = 1 ; i <= k ; i++){
		if(nam[i] >= amax){
			kq[i] = 0;
		}
		else{
			kq[i] = xuly(nam[i] , kq[i-1]);
		}
	}
	for(int i = k ; i >= 1 ; i--) cout<<kq[i]<<' ';
}