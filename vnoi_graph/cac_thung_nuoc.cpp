#include<bits/stdc++.h>
using namespace std;
int n;
int parent[1000005];
int findset(int u){
	if(u == parent[u]) return u;
	return parent[u] = findset(parent[u]);
}
bool Union(int u, int v,int z){
	u = findset(u);
	v = findset(v);
	if(u == v) return false;
	if(z == 1){
		parent[u] = v;
	    return true;
	}
	return true;
}
int main(){
	cin>>n;
	for(int i=1;i<=1e6;i++) parent[i] = i;
	while(n--){
		int x,y,z; cin>>x>>y>>z;
		if(z == 1) Union(x,y,z);
		else{
			if(!Union(x,y,z)){
				cout<<"1"<<endl;
			}
			else cout<<"0"<<endl;
		}
	}
}
