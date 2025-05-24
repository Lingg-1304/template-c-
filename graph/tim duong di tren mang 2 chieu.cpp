#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n,s,t,u,v;
int a[1005][1005];
int dem=0;
int d[1005][1005];
int bfs(int i,int j){
    a[i][j] = 0;
    queue<II> q;
    q.push({i,j});
    while(!q.empty()){
        int x = q.front().fi; 
        int y = q.front().se;
        q.pop();
        a[x][y] = 0;
        if(x==u && y==v) return d[x][y];
        for(int k=0;k<8;k++){
            int i1 = x + dx[k];
            int j1 = y + dy[k];
            if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] == 1){
                q.push({i1,j1});
                a[i1][j1] = 0;
                d[i1][j1] = d[x][y]+1;
            }
        }     
    }
    return -1;
}
int main(){
    fast;
    cin>>n>>s>>t>>u>>v;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    d[s][t] = 0;
    cout<<bfs(s,t);
}
