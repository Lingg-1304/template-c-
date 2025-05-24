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
stack<int> st;
vector<int> adj[10001];
vector<int> adj_nguoc[10001];
void dfs1(int u){
	visit[u] = true;
	for(int v : adj[u]){
		if(!visit[v]){
			dfs1(v);
		}
	}
	st.push(u);
}
void dfs2(int u){
	cout<<u<<" ";
	visit[u] = true;
	for(int v : adj_nguoc[u]){
		if(!visit[v]){
			dfs2(v);
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
        adj_nguoc[y].push_back(x);
    }
	for(int i=1;i<=n;i++){
		if(!visit[i]){
			dfs1(i);
		}
	}
	memset(visit , false , sizeof(visit));
	while(!st.empty()){
		int k = st.top(); st.pop();
		if(!visit[k]){
			dfs2(k);
			cout<<endl;
		}
	}
}
