#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
bool visit[10001];
vector<int> adj[10001];
ll dem,res=0;
void dfs(int u){
	dem++;
	visit[u] = true;
	for(int v : adj[u]){
		if(!visit[v]){
			dfs(v);
		}
	}
}
int main(){
    fast;
    memset(visit , false , sizeof(visit));
    int n,m; cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
    	if(!visit[i]){
    		dem=0;
    		dfs(i);
    		res += 1ll* dem*(dem-1)/2;
		}
	}
	if(res==m) cout<<"YES";
	else cout<<"NO";
}
