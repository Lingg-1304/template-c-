#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
typedef pair<long long,int> II;
typedef pair <II,int> III;
int mod = 1e9+7;
const int maxn = 5e5;

int n,m;
vector<int> adj[maxn];
bool visited[maxn];

void bfs(int u){
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int k = q.front(); q.pop();
        visited[k] = true;
        for(int x : adj[k]){
			if(!visited[x]){
				cout<<x<<" ";
				q.push(x);
				visited[x] = true;
			}
		}
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(visited , false , sizeof(visited));

    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int u , v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    
}