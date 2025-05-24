#include<bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<ii,int>
#define fi first
#define se second
using namespace std;
vector<iii> dsc;
int n , m , s ;
int d[100005] , check[100005];
void bellman_ford(){
	for(int i = 1 ; i <= n ; i++) d[i] = 1e9;
	d[s] = 0;
	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			int  u = dsc[j].fi.fi , v = dsc[j].fi.se , w = dsc[j].se;
			if(d[u] != 1e9 && d[u] + w < d[v]){
				d[v] = d[u] + w;	
			}
		}
	}
}
void chutrinham(){
	int dx[100005];
	for(int i = 1 ; i <= n ; i++) dx[i] = d[i];
	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			int  u = dsc[j].fi.fi , v = dsc[j].fi.se , w = dsc[j].se;
			if(d[u] != 1e9 && d[u] + w < d[v]){
				d[v] = d[u] + w;	
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(d[i] < dx[i]){
			check[i] = false;
		}
	}
}
int main(){
	memset(check,true,sizeof(check));
	cin >> n >> m >> s;
	for(int i = 0 ; i < m ; i++){
		int u , v , w;
		cin >> u >> v >> w;
		dsc.push_back({{u,v},w});
	}
	bellman_ford();
	//chutrinham();
	for(int i = 1 ; i <= n ; i++){
		if(check[i]){
			if(d[i] == 1e9) cout<<"Impossible"<<endl;
			else cout<<d[i]<<endl;
		}
		else cout<<"-Infinity"<<endl;
	}
}