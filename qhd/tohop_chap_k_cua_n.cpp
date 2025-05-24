#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll C[1005][1005];
int mod = 1e9 + 7;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for(int i = 0 ; i <= 1001 ; i++){
		for(int j = 0 ; j <= 1001 ; j++){
			if(i == j) C[i][j] = 1;
			else{
				C[i][j] = C[i-1][j] + C[i-1][j-1];
				C[i][j] %= mod;
			}
		}
	}
	

	int test ; cin >> test;
	while(test--){
		int n , k; cin >> n >> k;
		cout<<C[n][k]%mod<<endl;
	}
}