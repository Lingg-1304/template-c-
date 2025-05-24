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
vector<int> adj[105];
int d[105][105];
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
int main(){
    fast;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[i][j] = 1e9;
        }
    }
    for(int i=0;i<m;i++){
        int x,y,w; cin>>x>>y>>w;
        adj[x].push_back(y);
        adj[y].push_back(x);
        d[x][y] = d[y][x] = w;
    }
    for(int i=1;i<=n;i++){
        d[i][i] = 0;
    }
    int test; cin>>test;
    floyd();
    for(int i=1;i<=test;i++){
        int u,v; cin>>u>>v;
        cout<<d[u][v]<<endl;
    }
}
