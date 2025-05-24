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
vector<int> v[1001];
int parent[1001];
int dfs(int u){
    //cout<<u<<" "; 
    visit[u]=true;
    for(int x : v[u]){
        if(!visit[x]){
        	parent[x]=u;
            if(dfs(x) == 1) return 1;
        }
        else if(visit[x] && x != parent[u]){
        	return 1;
		}
    }
    return 0; 
}
int main(){
    fast;
    memset(visit , false , sizeof(visit));
    int n,m; cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y; cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
    	if(!visit[i]){
    		if(dfs(i)==1){
    			cout<<"1";
    			return 0;
			}
		}
	}
    cout<<"0";
}
