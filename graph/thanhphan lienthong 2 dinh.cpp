#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
int dem=0;
int tplt[1001];
set<int> v[1001];
bool visit[1001];
void dfs(int u){
    visit[u]=true;
    for(int x : v[u]){
        if(!visit[x]){
            dfs(x);
            tplt[x] = dem;
        }
    }
}
int main(){
    memset(visit , false , sizeof(visit));
    fast;
    int n,m; cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y; cin>>x>>y;
        v[x].insert(y);
        v[y].insert(x);
    }
    for(int i=1 ; i<=n ; i++){
        if(!visit[i]){
            dfs(i);
            tplt[i] = dem;
            dem++;
        }
    }
    int t; cin>>t;
    for(int i=0;i<t;i++){
        int x,y; cin>>x>>y;
        if(tplt[x] == tplt[y]) cout<<"1"<<endl;
        else cout<<"-1"<<endl;
    }
}
