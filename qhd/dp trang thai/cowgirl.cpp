#include<bits/stdc++.h>
#define bit(n,i) ((n >> i) & 1)
using namespace std;
int n , m;
bool check(int mask ,int pre_mask){
	for(int i = 0 ; i < n - 1 ; i++){
		if((bit(mask,i) & bit(pre_mask,i)) == 0 || (bit(mask,i+1) & bit(pre_mask,i+1)) == 0){
			continue;
		}
		else return false;
	}
	return true;
}
void run(){
	long long f[35][35];
	cin >> n >> m;
	if(n > m) swap(n,m);
	vector<int> old;
	for(int i = 0 ; i < (1 << n) ; i++) old.push_back(i) , f[1][i] = 1;

	long long ans = 0;
	for(int j = 2 ; j <= m ; j++){
		for(int mask : old){
			f[j][mask] = 0;
			for(int pre_mask : old){
				if(check(mask,pre_mask)){
					f[j][mask] += f[j-1][pre_mask];
				}

			}
		}
	}
	for(int x : old){
		ans += f[m][x];
	}
	cout<<ans<<endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		run();
	}
}