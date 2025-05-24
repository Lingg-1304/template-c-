#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
int a[maxn] , n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	ll minn = 0 , sum = 0 , ans = -1e18;
	for(int i = 0 ; i < n ; i++){
		sum += a[i];
		ans = max(ans , sum - minn);
		minn = min(minn , sum);
	}
	cout<<ans;
}