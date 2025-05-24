#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second
#define ii pair<ll,int>
#define iil pair<ii,ll>
const int maxn = 1e5 + 5;
int main(){
	int n;
	cin >> n;
	int a[n+1] , b[n+1];
	vector<int> v;
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	for(int i = 0 ; i < n ; i++) cin >> b[i];
	sort(b,b+n);
	b[n+1] = 2e9 + 5;
	int ans = 2e9;
	for(int i = 0 ; i < n ; i++){
		if(ans == 0) break;
		int it = lower_bound(b,b+n,-a[i]) - b;
		if(it == n){
			ans = min(ans , abs(a[i] + b[it-1]));
		}
		else if(it == 0){
			ans = min(ans , abs(a[i] + b[it]));
		}
		else{
			ans = min(ans , abs(a[i] + b[it]));
			ans = min(ans , abs(a[i] + b[it-1]));
		}
	}
	cout<<ans;
}