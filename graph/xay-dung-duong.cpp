#include<bits/stdc++.h>
using namespace std;
int w[105][105];
int n;
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				w[i][j] = min(w[i][j] , w[i][k] + w[k][j]);
			}
		}
	}
}
int main(){
	cin>>n;
	int a[4];
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	int u,v,t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			w[i][j] = 1e9;
		}
	}
	for(int i=1;i<=n;i++) w[i][i] = 0;
	while(cin>>u>>v>>t){
		w[u][v] = w[v][u] = t;
	}
	floyd();
	int ans = 1e9;
	
	do{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans = min(ans , w[i][j] + w[i][a[0]] + w[i][a[1]] + w[j][a[2]] + w[j][a[3]]);
			}
		}
	}while(next_permutation(a,a+4));
	
	
	cout<<ans;
}
