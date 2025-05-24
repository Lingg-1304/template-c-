#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 10005;
int n , a[4][maxn] ;
ll f[17][maxn];
#define bit(n,i) ((n>>i)&1)
int main(){
	int kq = -1e9;
	vector<int> mask;
	for(int i = 0 ; i < 16 ; i++){
		bool check = true;
		for(int j = 0 ; j < 3 ; j++){
			if(bit(i,j) == 1 && bit(i,j+1) == 1){
				check = false;
				break;
			}
		}
		if(check) mask.push_back(i);
	}
	//for(int x : mask) cout<<x<<endl;
	cin >> n; 
	for(int i = 0 ; i < 4 ; i++){
		for(int j = 1 ; j <= n ; j++){
			cin >> a[i][j];
			kq = max(kq , a[i][j]);
		}
	}
	for(int j = 1 ; j <= n ; j++){
		for(int x : mask){
			ll sum = 0;
			for(int i = 0 ; i < 4 ; i++){
				if(bit(x,i) == 1) sum += a[i][j];
			}
			for(int pre : mask){
				if((pre & x) == 0){
					f[x][j] = max(f[x][j] , f[pre][j-1] + sum);
				}
			}
		}
	}
	ll ans = -1e18;
	for(int x : mask){
		ans = max(ans , f[x][n]);
	}
	if(ans == 0) cout<<kq;
	else{
		cout<<ans;
	}
}