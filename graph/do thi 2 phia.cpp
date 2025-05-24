#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
int n,m;
int color[10001];
int visit[1005];
vector<int> adj[10001];
bool bfs(int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int k = q.front(); q.pop();
        if(color[k] == 0) color[k] = 2;
        visit[k] = true;
        for(int x : adj[k]){
            if(!visit[x]){
                if(color[k] == 2){
                    color[x] = 1;
                }
                else{
                    color[x] = 2;
                }
                q.push(x);
            }
            else{
                if(color[x] == color[k]) return false;
            }
        }
    }
    return true;
}
int main(){
    fast;
    memset(visit , false , sizeof(visit));
    cin>>n>>m;
    for(int i = 0;i < m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            if(!bfs(i)){
            	cout<<"NO";
            	return 0;
			}
        }
    }
    cout<<"YES";
}
