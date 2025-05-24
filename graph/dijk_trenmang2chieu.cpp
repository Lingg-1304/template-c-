#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios::sync_with_stdio(0)
#define ll long long
using namespace std;
typedef pair<int,int> II;
typedef pair <int,II> III;
int mod = 1e9+7;
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int n,m;
int a[505][505];
int d[505][505];
void dijk(){
	d[1][1] = a[1][1];
	priority_queue<III, vector<III>, greater<III>> q;
	q.push({0,{1,1}});
	while(!q.empty()){
		III uu = q.top(); q.pop();
		int t=uu.fi, x=uu.se.fi, y=uu.se.se;
		if(t > d[x][y]) continue;
		for(int k=0;k<4;k++){
			int i1=x+dx[k], j1=y+dy[k];
			if(i1>=1 && j1>=1 && i1<=n && j1<=m){
				if(d[x][y] + a[i1][j1] < d[i1][j1]){
					d[i1][j1] = d[x][y] + a[i1][j1];
					q.push({d[i1][j1],{i1,j1}});
				}
			}
		} 
	}
}
int main(){
    fast;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		cin>>a[i][j];
    		d[i][j] = 1e9;
		}
	}
	dijk();
	cout<<d[n][m];
}
