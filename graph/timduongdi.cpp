#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
bool visit[1001];
set<int> v[1001];
int parent[1001];
void dfs(int u){
    visit[u]=true;
    for(int x : v[u]){
        if(!visit[x]){
        	parent[x] = u;
        	dfs(x);
		}
    }
}
void bfs(int u){
	visit[u] = true;
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int k = q.front(); q.pop();
		visit[k] = true;
		for(int x : v[k]){
			if(!visit[x]){
				q.push(x);
				visit[x] = true;
				parent[x] = k;
			}
		}
	}
}
int main(){
    fast;
    vector<int> kq;
    int n,m,s,t; cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++){
        int x,y; cin>>x>>y;
        v[x].insert(y);
        v[y].insert(x);
    }
//    dfs(s); bfs(s);
    if(visit[t] == false){
    	cout<<"-1";
    	return 0;
	}
    int x=t;
    while(x!=s){
    	kq.push_back(x);
    	x=parent[x];
	}
	reverse(kq.begin(),kq.end());
	cout<<s<<" ";
	for(int k : kq) cout<<k<<" ";
}
