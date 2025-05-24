#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
set<int> v[1001];
bool visit[1001];
void bfs(int u){
	visit[u] = true;
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int k = q.front(); q.pop();
		visit[k] = true;
		for(int x : v[k]){
			if(!visit[x]){
				cout<<x<<" ";
				q.push(x);
				visit[x] = true;
			}
		}
	}
}
int main(){
	memset(visit , false , sizeof(visit));
    fast;
    int n,m,s; cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
    	int x,y; cin>>x>>y;
    	v[x].insert(y);
	}
	cout<<s<<" ";
	bfs(s);
}
