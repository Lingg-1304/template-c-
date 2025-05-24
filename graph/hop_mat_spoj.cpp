#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
int d[10001],kq=0;
vector<int> nguoi;
bool visit[10001];
vector<int> adj[10001];
void dfs(int u){
	visit[u] = true;
	for(int v : adj[u]){
		if(!visit[v]){
			dfs(v);
		}
	}
}
int main(){
    fast;
    int k,n,m; cin>>k>>n>>m;
    for(int i=1;i<=k;i++){
    	int x; cin>>x;
    	nguoi.push_back(x);
	}
    for(int i=1;i<=m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
    }
    for(int p : nguoi){
    	memset(visit , false , sizeof(visit));
    	dfs(p);
    	for(int i=1;i<=n;i++){
    		if(visit[i]){
    			d[i]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(d[i] == k) kq++;
	}
	cout<<kq;
}
