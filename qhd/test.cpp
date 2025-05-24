#include<bits/stdc++.h>
using namespace std;
int f[1005][1005];
int main(){
	int n , s; cin >> n >> s;
	int w[n+1] , t[n+1];
	for(int i = 1; i <= n ; i++) cin >> w[i];
	for(int i = 1; i <= n ; i++) cin >> t[i];
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= s ; j++){
			if(j >= w[i]){
				f[i][j] = max(f[i-1][j] , f[i][j-w[i]] + t[i]);
			}
			else{
				f[i][j] = f[i-1][j];
			}
		}
	}
	cout<<f[n][s];
	while(n > 0){
		if(f[n][s] == f[n-1][s]) n--;
		else{
			cout<<n<<' ';
			s -= w[n];
			n--;
		}
	}
}