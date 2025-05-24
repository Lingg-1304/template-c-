#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
vector<int> v[1001];
bool visit[1001];
void dfs(int u,int s, int t){
	visit[u]=true;
	for(int x : v[u]){
		if((u == s && x == t) || (u == t && x == s)){
			continue;
		}
		if(!visit[x]) dfs(x,s,t);
	}
}
vector<II> dsc;
int main(){
    fast;
    int n,m,res=0,kq=0; cin>>n>>m;
    for(int i=1;i<=m;i++){
    	int x,y; cin>>x>>y;
    	v[x].push_back(y);
    	v[y].push_back(x);
    	dsc.push_back({x,y});
	}
	memset(visit , false , sizeof(visit));
	for(int i=1 ; i<=n ; i++){
		if(!visit[i]){
			res++;
			dfs(i,0,0);
		}
	}
	for(II i : dsc){
		int dem=0;
		memset(visit , false , sizeof(visit));
		for(int j=1 ; j<=n ; j++){
		    if(!visit[j]){
			    dem++;
			    dfs(j,i.fi,i.se);
		    }
	    }
	    if(dem > res){
	    	kq++;
	    	cout<<i.fi<<" "<<i.se<<endl;
		}
	}
	cout<<kq;
}
