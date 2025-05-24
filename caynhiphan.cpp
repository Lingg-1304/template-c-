#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
vector<int> adj[100005];

int main(){
	int m; cin>>m;
	for(int i=0;i<m;i++){
		int u,v; cin>>u>>v;
		
		char c; cin>>c;
		if(c == 'L'){
			adj[u][0] = v;
		}
		else{
			adj[u].push_back(v);
		}
	}
}
