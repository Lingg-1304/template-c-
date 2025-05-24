#include<bits/stdc++.h>
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
int bfs(int s,int t){
	queue< pair<int,int> > q;
	q.push({s,0});
	while(!q.empty()){
		ii k = q.front(); q.pop();
		if(k.fi == t) return k.se;
		q.push({k.fi - 1 , k.se + 1});
		if(k.fi > t) continue;
		q.push({k.fi * 2 , k.se + 1});
	}
} 
int main(){
	int t; cin>>t;
	while(t--){
		int a,b; cin>>a>>b;
		cout<<bfs(a,b)<<endl;
	}
}
