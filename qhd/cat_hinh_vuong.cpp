#include<bits/stdc++.h>
using namespace std;
int f[10005][10005];
int run(int n , int m){
	int res = 1e9;
	if(n == m) return 0;
	if(f[n][m] > 0) return f[n][m];
	for(int i = 1 ; i < m ; i++){
		res = min(res , run(n,i) + run(n,m-i) + 1);
	}
	for(int i = 1 ; i < n ; i++){
		res = min(res , run(i,m) + run(n-i,m) + 1);
	}
	f[n][m] = res;
	return res;
}
int main(){
	int n,m; cin >> n >> m;
	int kq = run(n,m);
	cout<<kq+1<<endl;
}