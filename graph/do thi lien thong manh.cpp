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
void dfs(int u){
    visit[u]=true;
    for(int x : v[u]){
        if(!visit[x]){
        	dfs(x);
		}
    }
}
int main(){
    fast;
    int n,m; cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y; cin>>x>>y;
        v[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
    	memset(visit , false , sizeof(visit));
    	dfs(i);
    	for(int j=1;j<=n;j++){
    		if(!visit[j]){
    			cout<<"0";
    			return 0;
			}
		}
	}
	cout<<"1";
}
